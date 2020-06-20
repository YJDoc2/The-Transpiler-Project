/*
 * This contains function realted to declration and parsing of classes
 */
#include "class_decl.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "functions.h"
#define CLASSMAP_INIT_SIZE 20
#define ATTRMAP_INIT_SIZE 20
#define METHODMAP_INIT_SIZE 20

Hashmap classmap;

FILE* tempcode = NULL;
FILE* temphead = NULL;
extern char* type_arr[];
extern FILE *code, *header;
extern char* main_file_headname;
extern Class* current_class;

char* class_method_format = "_%s_%s";
/*
 * initializes all required DS and allocated memory in this module
 * Must be called before any other function call in this module
 */
void __init_classes__() {
  classmap = make_hashmap(CLASSMAP_INIT_SIZE, __hash_str__, __compair__str__);
}

// helper functions to free classmap

void __delete_attr__(void* key, void* val) {
  free(key);
  free(val);
}

void __delete_paramlist__(void* val) {
  Param* p = (Param*)val;
  free(p->name);
  free(val);
}

void __delete_method__(void* key, void* value) {
  free(key);
  method* fn = (method*)value;
  free(fn->print_name);
  fn->is_ret_class ? free(fn->ret_t.class) : NULL;
  fn->param_list == NULL ? /*nothing*/
                         : ll_delete(fn->param_list, __delete_paramlist__);
  free(fn->param_list);
  free(fn);
}
void __delete_classmap__(void* key, void* val) {
  free(key);
  Class* c = (Class*)val;
  hm_delete(*(c->attr), __delete_attr__);
  free(c->attr);
  hm_delete(*(c->methods), __delete_method__);
  free(c->methods);
  // no need to free name in class as it is the key as well
  free(val);
}

/*
 * cleans up and frees the memory allocated in this module
 * Should be called before exiting the program
 */
void __cleanup_classes__() { hm_delete(classmap, __delete_classmap__); }

/*
 * Function to create and add a class struct in classmap
 * gives error is class already exists
 * Params :
 * name : name of the class
 * Returns : Pointer to the new class
 */
Class* add_class(char* name, int line) {
  Class* t = (Class*)hm_get(&classmap, name);
  if (t != NULL) {
    yyerror("Class with name %s is already defined on line %d.", name,
            t->declaration);
    return t;
  }
  char* temp = strdup(name);
  Class* c = (Class*)calloc(1, sizeof(Class));
  c->name = temp;
  c->attr = (Hashmap*)calloc(1, sizeof(Hashmap));
  c->methods = (Hashmap*)calloc(1, sizeof(Hashmap));
  *(c->attr) = make_hashmap(ATTRMAP_INIT_SIZE, __hash_str__, __compair__str__);
  *(c->methods) =
      make_hashmap(METHODMAP_INIT_SIZE, __hash_str__, __compair__str__);
  hm_add(&classmap, temp, c);
  c->declaration = line;
  return c;
}

/*
 * Function to add an attribute in the class
 * Gives error is the attribute already exists
 * NOTE the modifier must only be NONE_TYPE of CONST_TYPE, static must not be
 * used.
 *  Params :
 * class : pointer to the class m : modifier of the attribute
 * m : modifier of the attr, must be either NONE_TYPE or CONST_TYPE
 * name : name of the attribute, duplicated inside so can be freed after call
 * is_array : is the attribute an array
 *
 * Returns : void
 */
void add_attr(Class* class, modifier m, type t, char* name, bool is_arr,
              int line) {
  void* find = hm_get(class->attr, name);
  if (find != NULL) {
    yyerror("Attribute %s is already declared for class %s on line %d", name,
            class->name, ((attr*)find)->declaration);
    return;
  }
  char* temp = strdup(name);
  attr* a = (attr*)calloc(1, sizeof(attr));
  a->is_arr = is_arr;
  a->m = m;
  a->is_class = false;
  a->t.t = t;
  a->name = temp;
  a->declaration = line;
  hm_add(class->attr, temp, a);
}

/*
 * A function to add class attributes, which themselves are of class type
 *
 * Params :
 * class : Pointer to class to which the attribute is to be added
 * m : modifier of attribute,must be either NONE_TYPE or CONST_TYPE
 * name : name of the attribute, duplicated inside so can be freed after call
 * is_array : is the attribute an array
 * line : line number on which the attribute is declared
 */
void add_class_type_attr(Class* class, modifier m, char* classname, char* name,
                         bool is_arr, int line) {
  void* find = hm_get(class->attr, name);
  if (find != NULL) {
    yyerror("Attribute %s is already declared for class %s on line %d", name,
            class->name, ((attr*)find)->declaration);
    return;
  }
  Class* c = hm_get(&classmap, classname);
  char* temp = strdup(name);
  attr* a = (attr*)calloc(1, sizeof(attr));
  a->is_arr = is_arr;
  a->m = m;
  a->is_class = true;
  a->t.class = c->name;
  a->name = temp;
  a->declaration = line;
  hm_add(class->attr, temp, a);
}

/*
 * A function to add a method to the class
 *
 * Params :
 * class : pointer to the class
 * name : name of the method to be added, duplicated inside
 *        so can be freed after call
 * ret_t : return type of method
 * is_static : is the method static
 * paramlist : linedlist pointer of the parmalist of methods,
 *              must persist after call till end of program
 *              will be freed in __cleanup_classes__()
 *
 * Returns : void
 */
void add_method(Class* class, char* name, type ret_t, bool is_static,
                Linked_list* paramlist, int line) {
  void* find = hm_get(class->methods, name);
  if (find != NULL) {
    yyerror("method %s is already declared for class %s on line %d", name,
            class->name, ((method*)find)->declaration);
    return;
  }
  char* keyname = strdup(name);

  char* printname =
      (char*)calloc(1, strlen(keyname) + strlen(class->name) +
                           3);  // 2 ofr _ before and after classname, 1 for \0
  sprintf(printname, class_method_format, class->name, keyname);
  method* fn = (method*)calloc(1, sizeof(method));
  fn->is_static = is_static;
  fn->param_list = paramlist;
  fn->print_name = printname;
  fn->is_ret_class = false;
  fn->ret_t.t = ret_t;
  fn->declaration = line;
  hm_add(class->methods, keyname, fn);
}

/*
 * A function to add a method to the class
 *
 * Params :
 * class : pointer to the class
 * name : name of the method to be added, duplicated inside
 *        so can be freed after call
 * ret_class : name of the returning class, duplicated inside, so can be freed
 * is_static : is the method static
 * paramlist : linedlist pointer of the parmalist of methods,
 *              must persist after call till end of program
 *              will be freed in __cleanup_classes__
 *
 * Returns : void
 */
void add_class_ret_method(Class* class, char* name, char* ret_class,
                          bool is_static, Linked_list* paramlist, int line) {
  void* find = hm_get(class->methods, name);
  if (find != NULL) {
    yyerror("method %s is already declared for class %s on line %d", name,
            class->name, ((method*)find)->declaration);
    return;
  }
  char* keyname = strdup(name);

  char* printname =
      (char*)calloc(1, strlen(keyname) + strlen(class->name) +
                           3);  // 2 ofr _ before and after classname, 1 for \0
  sprintf(printname, class_method_format, class->name, keyname);
  method* fn = (method*)calloc(1, sizeof(method));
  fn->is_static = is_static;
  fn->param_list = paramlist;
  fn->print_name = printname;
  fn->is_ret_class = true;
  fn->ret_t.class = strdup(ret_class);
  fn->declaration = line;
  hm_add(class->methods, keyname, fn);
}

// Helper function to print method start
void print_method_start(Class* class, method* fn) {
  printcode("%s %s ( ",
            fn->is_ret_class ? fn->ret_t.class : type_arr[fn->ret_t.t],
            fn->print_name);

  ll_link* iter = fn->param_list == NULL ? NULL : fn->param_list->start;
  if (!fn->is_static) {
    printcode("%s *this", class->name);
    if (iter != NULL) printcode(" , ");
  }
  while (iter != NULL) {
    Param* p = (Param*)iter->data;
    printcode("%s %s", p->is_class ? p->t.class : type_arr[p->t.t], p->name);
    if (p->is_arr) {
      printcode("[]");
    }
    if (iter->next != NULL) {
      printcode(" , ");
    }
    iter = iter->next;
  }
}

/*
 * Prints a method declaration to code file
 * print in format : type print_name (parmalist){
 * the '{' must be closed in the calling code
 *
 * Parmas :
 * class : class to which the method belongs,
 * methodname : name of the method without the class
 */
void print_method(Class* class, char* methodname) {
  method* fn = (method*)hm_get(class->methods, methodname);
  if (fn == NULL) {
    yyerror(
        "Internal error : trying to print declaration of method not inserted "
        "in class definition");
    return;
  }
  print_method_start(class, fn);
  printcode(" ) {");
}

// Helper function that prints the start of a class header
// this print include statement for header files of all classes defined before
// it and also prints the include for the header of the file currently parsing
static void print_header_start() {
  hashpair* iter = classmap.start;
  hashpair* end = iter + classmap.size;
  while (iter <= end) {
    if (iter->key != NULL || iter->value != NULL) {
      if (strcmp(iter->key, current_class->name) == 0) {
        ++iter;
        continue;  // skip if same class
      }

      fprintf(code, "#include \"class_%s.h\"\n", (char*)iter->key);
    }
    ++iter;
  }
  fprintf(code, "#include \"%s\"\n", main_file_headname);
  fprintf(code, "#ifndef __CLASS_%s__\n", current_class->name);
  fprintf(code, "#define __CLASS_%s__\n", current_class->name);
}

/*
 * A function that switches codefile and header file in parserfn to a new files
 * named as name.c and name.h
 * Also start printing definition of class :
 *  typedef struct name{
 *  the closing '}' will be done in end_class_definition
 * Params :
 * name : name of the class
 */
void start_class_definition(char* name) {
  int name_len = strlen(name);
  // 1 for _ 5 for class
  // 3 =  two for '.' and ext one for end-of-string 0
  char codename[name_len + 1 + 5 + 3];
  char headname[name_len + 1 + 5 + 3];
  sprintf(codename, "%s_%s", "class", name);
  sprintf(headname, "%s_%s", "class", name);
  strcpy(codename + name_len + 6, ".c\0");
  strcpy(headname + name_len + 6, ".h\0");
  FILE* tc = fopen(codename, "w");
  FILE* th = fopen(headname, "w");
  if (tc == NULL || th == NULL) {
    perror("cannot open file for writing.");
    //! TODO GLOBAL EXIT
    exit(EXIT_FAILURE);
  }
  tempcode = code;
  temphead = header;
  code = th;  // this is intentional, as the first things declrared must be
              // attributes, so the code must be pointing to header file
              // these will be switched to correct ones in end_attr_list
  header = tc;
  print_header_start();
  fprintf(code, "\ntypedef struct %s {\n", name);
}

void print_class_header(char* name) {
  // temporarily switching files as print_method_start prints it in codefile
  FILE* temp = code;
  code = header;
  hashpair* iter = current_class->methods->start;
  hashpair* end = iter + current_class->methods->size;
  while (iter <= end) {
    if (iter->key != NULL || iter->value != NULL) {
      method* fn = (method*)iter->value;
      print_method_start(current_class, fn);
      printcode(" );\n\n");
    }
    ++iter;
  }

  printcode("\n #endif\n");
  code = temp;  // switching back
}

/*
 * prints the class's remaining headerfile
 */
void end_class_definition(char* name) {
  print_class_header(name);
  fclose(code);
  fclose(header);
  code = tempcode;
  header = temphead;
  tempcode = temphead = NULL;
}

/*
 * closes th '{' started in start_class_definition
 * Parmas :
 * name L name of the class
 */
void end_attr_list(char* name) {
  fprintf(code, "\n} %s ;\n\n", name);
  // switching the files
  FILE* t = header;
  header = code;
  code = t;
  printcode("#include \"class_%s.h\"\n\n", name);
}
