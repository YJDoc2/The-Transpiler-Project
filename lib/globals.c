/*
 * Defines convenience function to call all init functions
 */
#include "actions.h"
#include "class_access.h"
#include "class_decl.h"
#include "expressions.h"
#include "filenames.h"
#include "forloop.h"
#include "functions.h"
#include "literals.h"
#include "parserfn.h"
#include "scope.h"
#include "variables.h"

/*
 * Function which invokes all init functions from library files
 */
void global_init() {
  __init_io__("./test.ttp", (void*)0);
  __init_literals__();
  __init_vars__();
  __init_actions__();
  __init_functions__();
  __init_scopes__();
  __init_expr__();
  __init_classes__();
}

/*
 * Function which invokes all cleanup funtions from library files
 */
void global_cleanup() {
  __cleanup_classes__();
  __cleanup_expr__();
  __cleanup_scopes__();
  __cleanup_functions__();
  __cleanup_actions__();
  __cleanup_vars__();
  __cleanup_literals__();
  __cleanup_io__();
}