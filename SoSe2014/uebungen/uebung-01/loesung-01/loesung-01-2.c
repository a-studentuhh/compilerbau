/*
 * ****************************************************************************
 * Project	:	Compilerbau 
 * Date		:	SoSe 2014
 * File		:	loesung-01-2.c
 * Aufgabe	:	Serie 01 Aufgabe 02
 * ****************************************************************************
 * Compile: gcc -std=c99 -Wall 
 */

#include <stdio.h>
#include <ctype.h>

#define  MAX_BASE ('z'-'a' + 10)

int base_bin(const char *str, const int base)
{
  char alfa_max = 0;
  char t; 
  int inc_alfa = -1;
  int result = 0;

  if(base <= 0 || base > MAX_BASE + 1 || !str) 
    return -1;

  // Alfabet darf in dem gegeben String vorkommen, wenn die Basis grosser als
  // 10 ist
  inc_alfa = (base - 10);
  if( inc_alfa > 0)
  {
    // groesster gueltige Alfabet ware die 'a' plus die differens, welche in 
    // inc_alfa gespeichert ist
    alfa_max = 'a' + inc_alfa;
  }

  // Ueber alle zeichen des String iterieren
  for(int i = 0; str[i] != 0; i++)
  {
    // Nach Horner-Schema, Altes Ergebnis mit der Basis multiplizieren
    result *= base;
    // man erspart sich die Ueberpruefung der gross-Buchstaben
    t = tolower(str[i]);


    if(t >= '0' && t <= '9')
    {
      result += t - '0';
    } 
    else if (t >= 'a' && t <= alfa_max)
    {
      result += t - 'a' + 10;
    }
    else
    {
      return -1;
    }
  } // END - For

  return result;

}// ENDE base_bin

int main()
{
  char inputs[512];
  int base;


  do{

    do{
      printf("Bitte die Basis {1 ... %d} eingeben:", MAX_BASE + 1);
      scanf("%d", &base);
    }while(base <= 0 || base > MAX_BASE + 1);

    printf("Bitte die Zahl eingeben, bei Hexadezimal ohne 0x:");
    scanf("%s", inputs);

    printf("%s in Basis %d :=> %d\n", inputs, base, base_bin(inputs, base) );

    printf("Wollen Sie erneut rechnen?[J/n]");

    scanf("%s", inputs);

  }while(tolower(inputs[0]) != 'n');

  return 0;
}
