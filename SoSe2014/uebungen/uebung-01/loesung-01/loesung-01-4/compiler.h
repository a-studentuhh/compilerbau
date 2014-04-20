/* ****************************************************************************
 * Project      :       Compilerbau 
 * Date         :       SoSe 2014
 * File         :       loesung-01-1.c
 * Aufgabe      :       Serie 01 Aufgabe 01
 * ****************************************************************************
 * Compile: gcc -std=c99 -Wall  -o loesung loesung-01-1.c
 *
 */

#define JP 		1
#define CALL		2
#define RET		3
#define	IT_EQ_N		4
#define	IR_EQ_IT_AND_IS	5
#define	IO_A_EQ_IT	6

int cmd_jp(const char *cmd);

int cmd_call(const char *cmd);

int cmd_ret(const char *cmd);

int cmd_load(const char *cmd);

int cmd_and(const char *cmd);

int cmd_io(const char *cmd);

int hex_int(const char *hex);
