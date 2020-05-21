# The Transpiler project

input bool = nonzero true, zero false<br />
input complex two floats, real then img<br />
only single line string<br />

Funtion declaration suntax is fn name(paramlist) -> ret type {...} because otherwise there were Shift/reduce conflicts topstmt in declaration and fndeclaration And I didn't want to use GLR.<br />
