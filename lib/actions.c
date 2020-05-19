#include "actions.h"

#define ACT_MAP_INIT_SIZE 20

Linked_list arglist;
Hashmap act_map;

char* type_str_arr[] = {
    "%d", "%f", "%lf", "%s", "%f %s %fi", "%ld", "%d", "void",
};

void __print_var__(void* v) {
  Variable* var = (Variable*)v;
  switch (var->t) {
    case VOID_TYPE:
      yyerror("error : cannot print value of variable of type void : %s",
              var->name);
      break;

    default:
      printcode("%s ", type_str_arr[var->t]);
      break;
  }
}

void action_print() {
  printcode("printf(\"");
  ll_for_each(&arglist, __print_var__);
  printcode("\"");
  link* _t = arglist.start;
  while (_t != NULL) {
    printcode(",");
    Variable* var = (Variable*)_t->data;
    if (var->t == COMPLEX_TYPE) {
      printcode("crealf(%s),cimagf(%s)>=0 ? \"+\" : \"\\b\",cimagf(%s)",
                var->name, var->name, var->name);
    } else {
      printcode("%s", var->name);
    }
    _t = _t->next;
  }
  printcode(");\n");
  return;
}

// Interface function from here

void __init_actions__() {
  act_map = make_hashmap(20, __hash_str__, __compair__str__);
  arglist = make_linkedlist();
  hm_add(&act_map, "print", action_print);
}

int find_action(char* s) {
  if (hm_get(&act_map, s) != NULL) {
    return 1;
  } else {
    return 0;
  }
}

void perform_action(char* s) {
  void (*action)(void) = hm_get(&act_map, s);
  if (action == NULL) return;
  action();
}

void __del_hm__(void* a, void* b) { return; }

void __cleanup_actions__() {
  delete_hashmap(act_map, __del_hm__);
  ll_clear(&arglist);
}