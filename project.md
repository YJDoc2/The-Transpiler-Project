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

(I am going to just remove this)Parse Function...all kind...(?)(What did I meant by this ???)(I guess includeing built in and inbuilt C functions...)<br/>

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
make header file generating function , generate header file after successful code compiling.(Maybe keep this for the very last stage after everything else is done...?)<br />
