## Stage 1

create basic required Data structures, define lexer and parser.<br />
Parse RAW and assignment staement , checks for duplicate assignment and valid types for basic types.<br />
Update build system using makefiles

## Stage 2

make data structures required for functions and actions(inbuilt funtions, expanding to C functions after compiling)<br />
\# test1.c transpiled from test1.ttp for testig of print function(variables only) <br />
Add support for literals and add string literals... <br />
Add print action...and input action <br />
\# test2.c transpiled from test2.tpp for testing print and input funtion (variables and literals)
Add string declaration. <br />
Add function declaration and scoping<br />
\# test3.c transpiled from test3.tpp for testing function declaration and scoping (variables and literals) <br />
<strong>test1.ttp test2.ttp do not work from here on as top level statements can only be variable declarations or functionn definations </strong><br />
Added function params varification (for fns declared before as well as later , but no declarations in header yet) <br />
\# test4.c transpiled from test4.tpp for testing function param varifications <br />
verifies for return type. if not void shows error if corresponding high level(not inside other constructs like if, for etc) return statement is not found, does not show error for void type.<br />

## Stage 3

Add multiple declaration in same line support, compacted normal and assignment declaratin in single rule <br />
Changed representation of complex numbers to (real,img) and added mod keyword for % operation <br />
Add expressions (without fncall) and type varification, but more testing is required. <br />
\# test5.c transpiled from test5.tpp for testing expressions without fncall (more testing is required)<br />
use stack to parser nested fncall, revamp the expression and remove unneccessary fns <br />

\# test6.c transpiled from test6.tpp for testing expressions with fncall<br />

setup and use Valgrind to check and remove memory leaks; <br />
Commment Document and refactor code <br />
Added typecasting <br />

## Stage 4

Added Basic Arrays, array declaration and assignment <br />
Added Using Array values as value <br />
\# test7.c transpiled from test7.tpp for testing Basic array assignment, and value access<br />

Add Array support : No nested array <br />
Assignment to arrays at declaration stage<br />
Support String Arrays<br />

Add charbuf to support input-able buffers for string<br>

Support individual character assignment in Strings ? NO , only array of strings.<br />
Added Array Params, Access to Array elements.<br />
The return type does not need array type, as we cannot assign array base once declared, and there is no support for pointers.
So only sensible return type that can be array is char \*, which is already used as string type.<br />

\# test8.c transpiled from test8.tpp for testing array params in functions<br />
Added @decl return to support raw return types <br />
Add Assignment statement <br />
Add comment parsing <br />
\# test9.c transpiled from test9.tpp for testing assignment and comments<br />

## Stage 5

Added Conditions and if statements : if.. , if..else... , if..else if..
\# test10.c transpiled from test10.tpp for testing if..else if.. and nested if<br />

Added while loop <br />
\# test11.c transpiled from test11.tpp for testing while loop<br />

Added better condition support : now conditions are expressions as well, which in downside allows expressions to to be used in place of conditions, like C does, but also allows assignment to bool vars directly with conditions , i.e. bool b = a < b .<br />
This was done so that in same amount of conflicts as before, one can use assignments to bool, as well as return statements with conditions etc.<br />
But this still does not allow for multiple assignments (a =b= 6) and assignments instead conditions,so not too bad...?
\# test12.c transpiled from test12.tpp for testing the updated conditions in expressions<br />

Added for loop <br />
\# test13.c transpiled from test13.tpp for testing For loops<br />

make file generating function , generate header file after successful code compiling.<br />
NOTE : all test before now contains some redundant code that uses raw to hardcode fn declarations <br />
Added comment detecting in preparser and prelexer<br />
Added break and continue statements<br />
Added un-supported C tokens error in lexer<br />
Added #line in the generated codefile, for every line, nNOTE that for a generated code structure, like loops,
this may show incorrect/slightly off line numbers<br />
\# test14.c transpiled from test14.tpp for testing file generation and header generation<br />
Added let syntax for declaring variables whose type can be concretely inferred from their expression., Note that for string type the type will always be char \*, if one needs input-able string, one must explicitly use charbuf[] <br/>
\# test15.c transpiled from test15.tpp for testing let syntax<br />

## Stage 6

In case of classes definitions must be defined before use, i.e classes must be defined before other code,
and class methods must be defined before they are called.Also all attributes before methods. <br />

added initial class support <br />
Can define attributes , creates new .h and .c files <br />
\# test16.c transpiled from test16.tpp for testing class definitions only with attributes<br />
Now after class definition , it adds a #include for each class in the main file

\# test17.c transpiled from test17.tpp for testing method declarations<br />
Added method declaration printing in class header files, also added extern declaration in main file header for non-static global variables
\# test18.c transpiled from test18.tpp for testing multiple class declaration and file generations<br />

Added assignment to class attrs, by separating varvals, which denote values which can be assigned to<br />
Added let assignment for class type

Added verification of class type and check for class in all var access, in expr<br />
Added class support in exprs <br />
let statements for class type assignments <br />

\# test19.c transpiled from test19.tpp for testing multiple class declaration , method declarations, class variable declarations, class variable assignment, class variable declarations in let syntax, class variable declaration in decl syntax<br />

## Stage 7

how to create new class(struct), specifically those involving const elements?

Added support for classes in for statements
Added support for classes in params
\# test20.c transpiled from test20.tpp for testing class type function params

test for making sure expr combing works as expected on class types

add support for classes in fn return types
add support for accessing their methods

add use syntax ?
change action input and print to accommodate classes
Maybe merge add_var and add_array method in single as crate_class_var has done
DO some formatting and pretty-printing of the parser and lexer
