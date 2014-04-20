/*
 * ****************************************************************************
 * Project	:	Compilerbau 
 * Date		:	SoSe 2014
 * File		:	loesung-01-1.c
 * Aufgabe	:	Serie 01 Aufgabe 01
 * ****************************************************************************
 * Compile: gcc -std=c99 -Wall  -o loesung loesung-01-1.c
 */

#include <stdio.h>
#include <ctype.h>

#define BASE 16

/*
 * Schreiben Sie eine C-Funktion, die eine Hexadezimale Zahl ("0x...") übergeben 
 * bekommt und eine Binärzahl zurück liefert.
 *
 *   int hex_bin(const char *hex)
 *   hex => "0x1a3b"
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
 *
 * ****************************************************************************
 * Erklaerung fuer die Berechnung der Dezimalezahl von einem char-Zeichen.
 *
 * Die Zeichen '0', '1', ..., '9' liegen hintereinader und deren dezimal Wert
 * sind auch hintereinander, also '0' => 48, '1' => 49, ..., '9' => 57.
 *
 * Die Zeichen 'a', 'b', ..., 'z' liegen hintereinader und deren dezimal Wert
 * sind auch hintereinander, also 'a' => 97, 'b' => 98, ..., 'z' => 122.
 *
 * Annahme "0x1b3a" soll in Dezimal konvertiert werden.
 * int_erg = 0
 *
 * Man nimmt das 2. Zeichen: '1'
 * 	char '1' in ASCII hat den Dezimalenwert: 49
 * 	wenn man den Dezimalenwert der ASCII von '0' von '1' abzieht, bekommt 
 * 	man den Wert von char-'1' zur Dezimal 1
 * 	int_wert = '1' - '0' = 49 - 48 = 1
 * 	
 * 	int_erg = int_erg * BASE + int_wert;	// int_erg = 1
 *
 * Man nimmt das 3. Zeichen: 'b'
 * 	char 'b' in ASCII hat den Dezimalenwert: 98
 * 	wenn man den Dezimalenwert der ASCII von 'a' von 'b' abzieht und eine 
 * 	10 hinzuaddiert, dann bekommt man den Wert von char 'b' zur Dezimal 11
 * 	int_wert = 'b' - 'a' + 10 = 98 - 97 + 10 = 11
 *
 * 	int_erg = int_erg * BASE + int_wert;	// int_erg = 27
 *
 * Man nimmt das 4. Zeichen: '3'
 * 	char '3' in ASCII hat den Dezimalenwert: 51
 * 	wenn man den Dezimalenwert der ASCII von '1' von '3' abzieht  
 * 	hinzuaddiert, dann bekommt man den Wert von char '3' zur Dezimal 3
 * 	int_wert = '3' - '0' = 51 - 48 = 3
 *
 * 	int_erg = int_erg * BASE + int_wert;	// int_erg = 435
 *
 * Man nimmt das 5. Zeichen: 'a'
 * 	char 'a' in ASCII hat den Dezimalenwert: 97
 * 	wenn man den Dezimalenwert der ASCII von 'a' von 'a' abzieht und eine 
 * 	10 hinzuaddiert, dann bekommt man den Wert von char 'a' zur Dezimal 10
 * 	int_wert = 'a' - 'a' + 10 = 97 - 97 + 10 = 10
 *
 * 	int_erg = int_erg * BASE + int_wert;	// int_erg = 6970
 *
 */
int hex_bin(const char * hex)
{

  int result = 0;	// Ergebnis speicher
  int i = 2;		// ab der dritten (2-ten) Stelle beginnt die 
			// hexadezimal Zahl

  // Jede hexadezimale Zahl beginnt mit 0x, d.h. an der 0-ten und 1-ten 
  // Stellen des char-Arrays mussen '0' und 'x' sein
  if((!hex) || ! (tolower(hex[0]) == '0' && tolower(hex[1]) == 'x') )
  {
    return -1;
  } // END - if valid

  // Ein char-Array endet mit einer 0, d.h. solange der Wert des Arrays an der
  // i-ten stelle nicht 0 ist, tue . . .
  while(hex[i])
  {
    
    result *= BASE;
    // bevor der i-te char zur result addiert wird, muss man checken, ob es ein
    // zulaessiges Zeichen ist. Da hexadezimale Zahl Buchstaben enthaelt und 
    // die Buchstaben koennten sowohl als Gross- als auch als Kleinbuchstaben 
    // vor kommen. Daher wird jeder Zeichen in Kleinbuchstaben konvertiert und
    // somit erspart man zwei Bedingungen fuer die checks ob das Zeichen zw.
    // 'A' und 'Z' liegt.
    char value = tolower(hex[i]);

    // Wenn das zeichen zw. '0' und '9' ist,
    if(value >= '0' && value <= '9')
    {
      // dann muss man die Different von dem Zeichen z.B. '0', '1', ..., '9'
      // berechnen und zu result addieren.
      result += value - '0';
    } // Sonst wenn das Zeichen zw. 'a' und 'f' liegt
    else if(value >= 'a' && value <= 'f')
    {
      // d.h. das Zeichen hat den Wert zwischen 10 und 15. Also wenn man muss
      // zu der Different von value - 'a' eine 10 addieren.
      result += value - 'a' + 10;
    } // anderen falls ist das Zeichen nicht korrekt
    else
    {
      return -1;
    } // END - if

    // und i inkrementieren um das naechste Zeichen zu dem Ergebnis zu addieren
    i++;
  } // END - while

  return result;

}


/*
 * Ein Programm zum testen der Funktion
 */

int main(void)
{
  char *hex_num = "0x1b3a";
  int ergebnis = hex_bin(hex_num);

  printf("\"%s\" =>  %d\n", hex_num, ergebnis);

  return 0;
}

