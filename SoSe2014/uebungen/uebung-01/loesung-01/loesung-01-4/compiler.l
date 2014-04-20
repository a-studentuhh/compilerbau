%{
#include "compiler.h"
%}

%option yylineno

SPACE		[ \n\t]
REGISTER	"i"[0-7]
CONSTANTS	(0x|X)?[0-9a-fA-F]*
CMD_END		[ \n\t]*;


%%

"jp"{SPACE}*={SPACE}*{CONSTANS}{CMD_END}	return JP;

"call"{SPACE}+{CONSTANTS}{CMD_END}		return CALL;

"RET"{CMD_END}					return RET;

{REGISTER}{SPACE}*={SPACE}*{CONSTANS}{CMD_END}	return IR_EQ_N;

{REGISTER}{SPACE}*={SPACE}*{REGISTER}{SPACE}*&{SPACE}*{REGISTER}{CMD_END} {
  return IR_EQ_IT_AND_IS;
}

"io("{SPACE}*{CONSTANS}{SPACE}*")"{SPACE}*={SPACE}*{REGISTER}{CMD_END}	{
  return IO_A_EQ_IT;
}

.		ECHO;
%%

int yywrap(void)
{
  return 1;
}
