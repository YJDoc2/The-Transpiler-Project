# The Transpiler project

input bool = nonzero true, zero false<br />
input complex two floats, real then img<br />
only single line string<br />

Funtion declaration suntax is fn name(paramlist) -> ret type {...} because otherwise there were Shift/reduce conflicts topstmt in declaration and fndeclaration And I didn't want to use GLR.<br />

Note that in denoting complex numbers (a,b) a is part which will not be multipiled by I and b is part which will be multiplied by I.
In case the a and/or be themselves are complex, the resulting number will be formed by the said multiplications of I.<br />