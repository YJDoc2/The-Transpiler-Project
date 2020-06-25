# The Transpiler project

A Transpiler which compiles from the custom syntax to pure C, using Flex and Bison.<br />
This was done as a project while learning Flex and Bison

## About

This is a basically very simple syntax converter, which converts from the custom syntax as stated in <a href='https://github.com/YJDoc2/The-Transpiler-Project/blob/master/syntax.md'>syntax.md</a>, to pure C files.
This supports only Basic of C syntax , and does not support :

<ul>
    <li> Multi-dimensional Arrays</li>
    <li> Any kind of pointers </li>
    <li> asm and compiler directives, along with preprocessor commands</li>
    <li>bitwise operators</li>
    <li>enums and unions</li>
    <li>etc...</li>
</ul>

This just supposed to be a fun project, not to be used in production environment<br />

This introduces some things that are not directly supported in C , like :

<ul>
    <li>let a = ...</li>
    <li>for i in ... loops</li> 
    <li>classes ... or glorified structs </li>
</ul>

See the <a href='https://github.com/YJDoc2/The-Transpiler-Project/blob/master/project.md'>project.md</a> for how the features were developed step-wise

## Build instructions

This can be directly built on linux systems using the outermost Makefile, and is built and tested on Ubuntu 20.04

For Windows, a program capable of running makefile is needed such as : <a href = 'http://gnuwin32.sourceforge.net/packages/make.htm'>this</a>. Note this is not tested, and should be used on one's own risk.
This assumes that the C compiler is linked to the name 'gcc' , in case the name is different , change it to correct name in the Makefile-windows in variable named CC. This also assumes archiving program ar is lined to name 'ar' change accordingly if name is different.
Once successfully run, this will generate an executable file named 'ttp' in the outermost folder.

<strong>NOTE</strong> that for normal use, the files in transpiler folder should not be modified at all, or an accidental modification to any
.l or .y file will force Make to run flex and bison programs on next building attempt, and as those are not strictly needed for non-development purposes, this may not allow to create the binary again.

## Usage :

The command line syntax is :
ttp filename [ -hkl ][-o outfile]
where filename is the name of file to be transpiiled, which is necessary argument
h flag displays help
k flag keeps the generated files even if there were any errors in the transpilation, which are otherwise deleted
l prints the line numbers as pre-processor directives, which can be used by compilers to show the lines in original file, instead of generated, but these may be a bit off that actual
o flag requires a name, which is given to the generated file instead of the name of input file.<strong>NOTE</strong> that this does not affect the generated class files, which are always named as 'class_classname.h' and 'class_classname.c'

## For general Users :

These are few points to be noted before use :

In code the Order would be maintained in generated files, but not the adjacency.
that is the line 1 and line 2 are two consecutive lines, in generated files, line 1 will come before line 2, but there may be some extra generated code between those two lines<br />

this does not check well for void-type function returns, so that 5+ test() or test() +5 where test is a void returning function is transpiled without ay error message, even though in C these are incorrect

For input using input action :
for bool = nonzero true, zero false<br />
for complex two floats, real then img<br />

In defining string in the code,only single line strings are accepted<br />

Note that in denoting complex numbers (a,b) a is part which will not be multiplied by I and b is part which will be multiplied by I.
In case the a and/or be themselves are complex, the resulting number will be formed by the said multiplications of I.<br />

Does Not Support bitwise operators & | ~ ^ << >>, enums and unions<br />

Only 1D arrays supported<br/>
the string should be used for read only / print only strings. for input-able string use charbuf : see <a href='https://github.com/YJDoc2/The-Transpiler-Project/blob/master/syntax.md'>syntax.md</a>

Note that it is not necessary to declare function before use, or to use function that are declared in this file only.
This works in two stages for scanning all function signatures before actual parsing, and any non-declared function is assumed as void-type, which must be type casted.<br/>

in for loops for var in a .. b, there must be a space in a and '..' and '..' and b</br>
Also note that for using for loop over arrays, the array must be declared in the scope , enclosing scope or globally.This will not work on arrays passed as parameters to the functions<br/>

variables declared with let must have an expression assigned to them, whose type can be inferred. also these variables will be of normal type, i.e. niether static nor const.<br/>

Note that one cannot access the fields of class if brackets are put around the variable, i.e. if class var A has a field B one can access by A.B but not by (A).B . Same applies for fn / method calls, if fn F returns Class type var, which has a field B, one can access it by

<ul>
<li> F().B </li>
<li>classname A = F();<br />
    A.B</li>
</ul>
but cannot access as (F()).B
<br />

## For those who will look into code

Project is divided in three folders : lib contains all the functions that are used in parser, util contains Data structures required for parser, adn transpiler contains all bison and flex files<br />

Do not go looking for ASTs as they are not there, as this has to print the expressions in the infix format only in C , ASTs are not used.
This is the very reason why it has a poor error detection for void return functions, as is void check is put between expr sign (here) expr, it gives a lot of Shift reduce errors, and if put on value, it gives error for externally declared functions,even though they are type casted.<br />

Funtion declaration suntax is fn name(paramlist) -> ret type {...} because otherwise there were Shift/reduce conflicts topstmt in declaration and fndeclaration And I didn't want to use GLR.<br />

The scheme used for recursively varifying expressionf in fncalls is (kind-of) ad-hoc. It basically pushes the arglist ptr and current type of expression in two individual stacks and when it completes parsing a fncall it pops those two back.<br />

For using Valgrind for leack checks : if normal installation gives error because of strlen bug, try uninstalling , then either : making from latest source or installing from apt-get/ respective package manages instead of snaps, also install libc6-dbg:i386 using package manager.
The snap of valgrind didn't work because of strlen error.<br />

for input-able strings, charbuf is introduced. it translates to char [ ][ ],and can be declared with [expr], [expr] = {...},[] = {...}, [expr][expr], [expr][expr] = {...}, [][expr] = {...}. these essentially creates char double array, where one can take in input.As C itself allows to take input in statically allocated strings, eg : char c[] = "...", ttp allows that as well by taking input in strings, but this will cause a seg fault at runtime, so it is best to create a charbuf [] to take string input, and charbuf[][] to make an array of input-able strings. <br />

the reason for for loops working only on arrays in scope not passed as pointers is because C can track size of arrays declared in the scope/globally but once it reduces to pointer, the scheme used for determining the size of array : sizeof(a)/sizeof(a[0]) does not work.<br/>
