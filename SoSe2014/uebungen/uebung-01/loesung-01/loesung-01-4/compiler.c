/* ****************************************************************************
 * Project      :       Compilerbau 
 * Date         :       SoSe 2014
 * File         :       loesung-01-4.c
 * Aufgabe      :       Serie 01 Aufgabe 04
 * ****************************************************************************
 * Compile: gcc -std=c99 -Wall  -o loesung loesung-01-4.c
 */

#include <stdio.h>
#include <ctype.h>
#include "compiler.h"

/*
 * Funktionen und Variabeln werden durch externe Module bereitgestellt
 */
extern int yylex();
extern int yylineno;
extern char* yytext;

int cmd_error = 0;

int cmd_call(const char *cmd)
{
  int result = 0;
  int a = -1;

  for(int i = 0; cmd[i] != 0; i++)
  {
    // Wenn die Hexadezimale Zahl erreicht wurde
    if(cmd[i] >= '0' && cmd[i] <= '9')
    {
      // Konvertiere es zu int
      a = hex_int(cmd + i);
      break;
    } // END - IF hexadezimale Zahl
  } // END - FOR Iteration ueber den Befehl

  // Wenn da ein ungueltige hexadezimale Zahl ist
  if(a < 0)
  {
    cmd_error = 1;
    return 0;
  }

  // erstellen des Befehls
  // 0100 aa aaaa aaaa aaaa
  result = (1 << 17) | a;

  return result;
}

int cmd_jp(const char *cmd)
{
  int result = 0;
  int a = -1;

  for(int i = 0; cmd[i] != 0; i++)
  {
    // Wenn die Hexadezimale Zahl erreicht wurde
    if(cmd[i] >= '0' && cmd[i] <= '9')
    {
      // Konvertiere es zu int
      a = hex_int(cmd + i);
      break;
    } // END - IF hexadezimale Zahl
  } // END - FOR Iteration ueber den Befehl

  // Wenn da ein ungueltige hexadezimale Zahl ist
  if(a < 0)
  {
    cmd_error = 1;
    return 0;
  }

  // erstellen des Befehls
  result = a;

  return result;
}
