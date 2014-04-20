/*                                                                                                      
 * ****************************************************************************
 * Project      :       Compilerbau 
 * Date         :       SoSe 2014
 * File         :       config_scanner.l
 * Aufgabe      :       Scanner einer init-file schreiben. Die init-file sieht:
 *			key:value
 * ****************************************************************************
 * 
 */
%{
#include "config_scanner.h"
%}

DIGIT		[0-9]
ALFA		[a-zA-Z]
ALFANUM		[a-zA-Z0-9]

%%
:		return DOP_PUNKTE;
"username"	return USERNAME;
"password"	return PASSWORD;
"host"		return HOST;
"memory"	return MEMORY;
"port"		return PORT;

{ALFA}({ALFANUM}|_)*	return THEVALUE;



%%


