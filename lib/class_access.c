/*
 * This contains Functions related to operations with classes such as checking
 * if it has attribute or checking if the class exists or it has method and
 * verifying calls to it etc.
 */
#include "class_access.h"

extern Hashmap classmap;
/*
 * Checks if the class with given name exits or not
 * Params :
 * name : name of the class to search
 *
 * Returns : true if class with given name exists
 *           false if no such class is declared
 */
bool is_class(char *name) {
  void *t = hm_get(&classmap, name);
  return t != NULL;
}

/*
 * Checks if the given attribute is present in the class or not
 * Params :
 * classname : name of the class to find attribute in
 * attrname : name of attribute to find
 *
 * Returns : pointer to attr if found
 *           NULL if no such attribute is declared in given class
 */
attr *find_attr(char *classname, char *attrname) {
  Class *class = (Class *)hm_get(&classmap, classname);
  if (class == NULL) return NULL;
  Hashmap *attrmap = class->attr;
  void *t = hm_get(attrmap, attrname);
  return (attr *)t;
}

/*
 * Checks if the given method is present in the class or not
 * Params :
 * classname : name of the class to find attribute in
 * methodname : name of method to find
 *
 * Returns : pointer to method if found
 *           NULL if no such method is declared in given class
 */
method *find_method(char *classname, char *methodname) {
  Class *class = (Class *)hm_get(&classmap, classname);
  if (class == NULL) return NULL;
  Hashmap *mmap = class->methods;
  void *t = hm_get(mmap, methodname);
  return (method *)t;
}

void create_class_var(modifier m, char *classname, char *name, int line) {
  Class *t = (Class *)hm_get(&classmap, classname);
  Variable *v = create_var(m, INT_TYPE, name, line);
  v->is_class = true;
  v->t.class = t->name;
}