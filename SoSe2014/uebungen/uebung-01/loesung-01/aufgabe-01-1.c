/*
 * ****************************************************************************
 * Project	:	Compilerbau 
 * Date		:	SoSe 2014
 * File		:	loesung-01.c
 * Aufgabe	:	Serie 01 Aufgabe 01
 * ****************************************************************************
 * Compile: gcc -std=c99 -Wall 
 */

#include <stdio.h>
#include <ctype.h>

/*
 * Schreiben Sie eine C-Funktion, die eine Hexadezimale Zahl ("0x...") übergeben 
 * bekommt und eine Binärzahl zurück liefert.
 *
 *   int hex_bin(const char *hex)
 *   hex => "0x1a2Bc3d4E5f6"
 *
 * ****************************************************************************
 * Loesungsvorlschalg und die Idee dahinter:
 * eine hexadezimal Zahl der form "0x1a3b" wird in Dezimal we folgt berechnet:
 * dezimal = 11*16^0 + 3*16^1 + 10*16^2 + 1*16^3 = 6715
 * man kann den Horner-Schema an der oberen Gleichung anwenden.
 * dezimal = 11 + 16*(3 + 16*(10 + 16*(1) ) ) = 6715.
 *
 * Wenn man die Funktion per Hand (Stift und Papier) für hex = "0x1a3b" durch-
 * laeuft, dann versteht man die Funktionsweise des Algorithmus.
 */
int hex_bin(const char * hex)
{
  int base = 16;
  int result = 0;
  int i = 2;

  // Jede hexadezimale Zahl beginnt mit 0x, d.h. an der 0-ten und 1-ten 
  // Stellen des char-Arrays mussen '0' und 'x' sein
  if((!hex) || ! (tolower(hex[0]) == '0' && tolower(hex[1]) == 'x') )
  {
    return -1;
  } // END - if valid

  // Ein char-Array endet mit einer 0, d.h. solange der Wert des Arrays an der
  // i-ten stellen nicht 0 ist
  while(*(hex+i))
  {
    
    result *= base;
    char value = tolower(*(hex+i));

    if(value >= '0' && value <= '9')
    {
      result += value - '0';
    } else if(value >= 'a' && value <= 'f')
    {
      result += value - 'a' + 10;
    } else
    {
      return -1;
    } // END - if

    i++;
  } // END - while

  return result;

}


int main(void)
{
  char *hex_num = "0x1a";

  printf("%s:  %d\n", hex_num, hex_bin(hex_num));

  return 0;
}

