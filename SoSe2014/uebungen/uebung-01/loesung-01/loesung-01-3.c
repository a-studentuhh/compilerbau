/*
 * ****************************************************************************
 * Project	:	Compilerbau 
 * Date		:	SoSe 2014
 * File		:	loesung-01-3.c
 * Aufgabe	:	Serie 01 Aufgabe 03
 * ****************************************************************************
 * Compile: gcc -std=c99 -Wall  -o loesung loesung-01-3.c
 */

#include <stdio.h>
#include <ctype.h>

/*
 * Bezeichner in der Sprache VHDL dürfen nur aus Buchstaben, Zahlen und 
 * Unterstrichen bestehen. Nicht erlaubt sind dabei Zahlen oder Unterstriche am
 * Anfang des Bezeichners, sowie Unterstriche am Ende. Doppelte Unterstriche 
 * duerfen ebenfalls nicht vorkommen.
 *
 * Schreiben Sie eine C-Funktion isVHDLidentifier(), die eine nullterminierte 
 * Zeichenkette uebergeben bekommt und einen Integer zurück liefert. Dabei soll
 * im Falle eines gueltigen VHDL-Bezeichners, wie beschrieben, eine 1, sonst 
 * eine 0 zurückgegeben werden.
 *
 *  int isVHDLidentifier (const char *identifier)
 */ 
int is_vhdl_identifier(const char *id)
{
  // Ueberpruefen, ob der Identifier mit einer Zahl bzw. einem '_' beginnt
  if(id[0] == '_' || (id[0] >= '0' && id[0] <= '9'))
  {
    return 0;
  }
  
  for(int i = 1; id[i] != 0; i++)
  {
    // Es duerfen keine doppelt Unterstriche '__' vorkommen
    if(id[i] == '_' && id[i+1] == '_')
    {
      return 0;
    }

    // Wenn das Ende des Identifiert erreicht ist
    if(!id[i+1]) // (id[i+1] == 0)
    {
      // es wird geprueft, ob das letzte Zeichen ein '_' oder eine Ziffer ist
      if( (id[i] >= '0' && id[i] <= '9') || id[i] == '_')
      {
	// Wenn Ja, dann wird 0 als ungueltiges Resultat zurueck gegeben.
	return 0;
      }
    } // END - IF - Ende des Identifier

  } // END - For

  // Wenn keine Ungueltige Aussage auf dem Identifier zutrifft, dass ist
  // dieser ein gueltiger Identifier
  return 1;
}


int main(void)
{
  char identifier[512];
  printf("Bitte einen VHDL-Identifier eingeben und mit Enter Bestaetigen: ");
  scanf("%s", identifier);

  if(is_vhdl_identifier(identifier))
  {
    printf("Identifier \"%s\" is gueltig\n", identifier);
  } 
  else
  {
    printf("Identifier \"%s\" is nicht gueltig\n", identifier);
  }

  return 0;
}
