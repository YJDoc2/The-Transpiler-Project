# The Transpiler project

input bool = nonzero true, zero false<br />
input complex two floats, real then img<br />
only single line string<br />

Funtion declaration suntax is fn name(paramlist) -> ret type {...} because otherwise there were Shift/reduce conflicts topstmt in declaration and fndeclaration And I didn't want to use GLR.<br />

Note that in denoting complex numbers (a,b) a is part which will not be multipiled by I and b is part which will be multiplied by I.
In case the a and/or be themselves are complex, the resulting number will be formed by the said multiplications of I.<br />

The scheme used for recursively varifying expressionf in fncalls is (kind-of) ad-hoc. It basically pushes the arglist ptr and current type of expression in two individual stacks and when it completes parsing a fncall it pops those two back.<br />

Does Not Support bitwise operators & | ~ ^ << >>, enums and unions<br />

For using Valgrind for leack checks : if normal installation gives error because of strlen bug, try uninstalling then either : making from latest source or installing from apt-get/ respective package manages instead of snaps, also install libc6-dbg:i386 using package manager.
The snap of valgrind didn't work because of strlen error.<br />

Only 1D arrays supported other than charbuf : read below <br/>

for input-able strings, charbuf is introduced. it translates to char [ ][ ],and can be declared with [expr], [expr] = {...},[] = {...}, [expr][expr], [expr][expr] = {...}, [][expr] = {...}. these essentially creates char double array, where one can take in input.As C itself allows to take input in statically allocated strings, eg : char c[] = "...", ttp allows that as well by taking input in strings, but this will cause a seg fault at runtime, so it is best to create a charbuf [] to take string input, and charbuf[][] to make an array of input-able strings. <br />
