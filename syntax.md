# Syntax

This shows the syntax of the the custom language.
This is loosely done according to how the features were implemented.
the basic rules of syntax are similar to C, and the types are same as well with few exceptions

## Types :

int,short,long,float, double,void bool, complex are supported.Note that they cannot be combined, like long int or long long int etc.
bool is used for true/false values and complex can be used to store complex values.<br/>
for defining complex use complex c = (a,b). <strong>Note</strong> that a,b are not real and imaginary parts, but a is part which will not be multiplied bu I and b is part which will be where I is square root of -1.<br />
bool can be assigned conditions or true/false

string type should be used for read/print only strings. Even though code using them to take input will transpile as well as compile in C, they are likely to cause Segmentation faults at runtime.<br />

Each of the above can be used as arrays with type var[] or type var[] = {...} syntax, similar to C

For input-able strings use charbuf.
it can be declared with
for single input-able string, where expr is int type size of the string buffer

<ul>
    <li>charbuf var[expr]</li>
    <li>charbuf var[expr] = {...}</li>
    <li>charbuf[] = {...}</li>
</ul>
for array of input-able string, where first expr is size of array and second is size of each array element
<ul>
    <li>charbuf[expr][expr]</li>
    <li>charbuf[expr][expr] = {...}</li>
    <li>charbuf[][expr] = {...}</li>
</ul>
these essentially creates char double array, where one can take in input.As C itself allows to take input in statically allocated strings, eg : char c[] = "...", ttp allows that as well by taking input in strings, but this will cause a seg fault at runtime, so it is best to create a charbuf [] to take string input, and charbuf[][] to make an array of input-able strings. <br />

## operators

+,-,/,_ are same as C.
mod is used for modulus operation.
+=,-=,_=,/= and mod= are supported
++ and -- are not supported.

## RAW

the syntax RAW<{...}> will copy every thing in between curly brackets to the generated file, without any checking.

## actions

These are special function declared only in transpiler, which will generate different code.
There are two actions defined :

<ul>
<li>
print(...). anything inside the brackets except class variables and arrays will be converted to respective printf statements.</li>
<li>
input(...). if any argument is a constant value like string or an expression, that is printed using printf. if the argument is non-constant variable the it is turned into respective scanf statements. Does not support class or array variables.</li>
</ul>

## Function declarations

Note that it is not necessary to declare function before use, or to use function that are declared in this file only.
This works in two stages for scanning all function signatures before actual parsing, and any non-declared function is assumed as void-type, which must be type casted.

function declaration syntax is : <br/>

fn function_name(arglist) -> return_type{
statement list
}

## variable declaration

variables can be declared in any of following ways :

<ul>
    <li>modifier type/classname varname1,varname2...;</li>
    <li>modifier type/classname varname1,varname2=expr....;</li>
    <li>modifier type/classname varname1[size-expr],varname2[size-expr]...;</li>
    <li>modifiertype/classname varname1[] = {values...},varname2[size-expr]={values...}....;</li>
</ul>

Where modifier is nothing(''), static or const

## declare syntax

variables declared in RAW code can be notified for the transpiler by using
@decl modifier type/classname varname1,varname2...;
@decl modifier type/classname varname1[],varname2...;

Also @decl can be used to notify transpiler or return form RAW code,
so in a function , @decl return; makes transpiler assume that funtion return statement of corresponding type/class is done from RAW code.

## let syntax

variables can also be declared using let :<br/>
let varname = expr;<br/>
let varname[] = {exprs...};<br/>
only one variable can be declared at a time, and in array type of the first element of array is considered the type of array.<br />

## Logical operators :

eql for comparing equality<br/>
not eql for checking inequality<br/>
not for negation of condition<br/>
\>,<,>=,<= have same meaning as C.

## conditionals

syntax of if is :

<ul>
<li>if condition {
    stmts
}
</li>
<li>
if condition{
    stmts
}else{
    stmts
}
</li>
<li>
if condition{
    stmts
}else if condition{
    stmts
}...{
    stmts
}else{
    stmts
}
</li>
</ul>
 <strong> NOTE</strong> that the brackets around condition are not required

## Loop

while loop is similar to C , except no brackets around condition:
while condition{
stmts;
}

Do while is not supported.

for loops :Four types of for loops are supported :

<ul>
    <li>for varname in start .. end{...}</li>
    <li>for varname in start .. end .. step{...}</li>
    <li>for varname in variable{...}, where variable is of type array</li>
    <li>for indexvar,varname in variable{...}, where variable is of type array, and indexvar will contain index of iteration 0-based, and varname will contain value at that index in the array</li>
</ul>
 <strong>NOTE</strong> that spaces are required in start, end, step expressions and the '..' also the start, end , step can be of int or float type only.

## Classes ... or glorified structs

These are not true classes in OOP sense, neither do they support OOP operations such as extending, interfaces, method overloading etc.
These just provide a convenient way to combine data in structs and methods to operate on them.<br/>
Each class is transpiled into its own respective .c and .h file, named as class_classname.c/class_classname.h

### Syntax : declaration

Please see examples in example folder for working examples.

class classname{<br/>
attributes/comments/RAW<{}>/@decl....<br/>
methods....<br/>
}

only one attribute can be declared at one time.
I.e. int a;int b; etc, not int a,b,c.. or int a=expr...is incorrect

A class cannot contain attribute of that class itself.
The attributes and methods can have a 'private' before them, which will prevent access from outside the class at transpile time.
<strong>NOTE</strong> that this prevents the access only at transpiler level, they can still be accessed in RAW<{}> code, or in the files kept after incorrect transpilation.<br/>

Methods can have @static before them, so that they can be called from the classname.These cannot use 'this' keyword.

method declaration syntax is similar to functions :
fn method_name(args)->return_type{
stmts
}

### Syntax : access

class attributes can be accessed by '.' like :
a.b, where a is instance of Class which has an attribute named b.
methods can be accessed by syntax a::method_a(args), where a is instance of class which has method named method_a

static methods can be accessed as ::Classname::static_method_name(args)

'this' keyword can be used inside non-static methods for refereeing to members of calling instance.
