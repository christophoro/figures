//-------------------------------------------------------------------------------------------------
//
//	PROJEKT 2, zadanie 41
//																					*******
//	Program rysuje figurê jak na rys. obok, o zadanej przez u¿ytkownika				 *    *	
//		d³ugoœci boku i wykorzystuj¹c wprowadzony z klawiatury dowolny znak.		  *   *
//		Umo¿liwia przesuwanie tej figury w lewo/prawo/górê/dó³ za pomoc¹ klawiszy	   *  *
//		strza³ek oraz zmniejszanie/zwiêkszanie jej rozmiaru przy pomocy klawiszy	    * *
//		[+] oraz [-].																	 **
//																						  X
//	Program wykrywa krawêdzie ekranu i uniemo¿liwia przesuwanie lub powiêkszanie		  **
//		rozmiaru figury jeœli znajduje siê ona przy krawêdzi. Do kasowania				  * *
//		czêœci ekranu wykarzystano w³asn¹, bardzo wydajn¹ funkcjê kasuj().				  *  *
//																						  *   *
//	Punkt zaczepienia figury znajduje siê na œrodku (znak X na rys obok).				  *    *
//																						  *******
//  Program napisano technik¹ obiektow¹.
//
//	Wykona³:																			
//	Krzysztof Umiñski (nr albumu 167971), informatyka 1 nst., 2016/2017
//  s167971@student.pg.gda.pl
//
//-------------------------------------------------------------------------------------------------
#include "stdafx.h"
#include "Konsola.h"
#include "stale.h"
#include "funkcje.h"
using namespace std;
//--------------------------------------------------------------------------------------------------
int main() {
	int x = 38, y = 12, bok;
	char klawisz, znak;
	ekran_startowy();
	znak = pobierz_znak();
	bok = pobierz_bok(bokmax);
	system("cls");
	do {
		figura F;
		F.x = x;
		F.y = y;
		F.bok = bok;
		F.znak = znak;
		F.rysuj();
		legenda();
		klawisz = _getch();											// obsluga klawiatury
		F.znak = ' ';												// kasowanie figury
		F.rysuj();
		switch (klawisz) {
		case '+': {													// powiekszenie
					  if (x - bok > xmin && x + bok < xmax &&
						  y - bok > ymin && y + bok < ymax &&
						  bok < bokmax)
						  bok++; break;
		}
		case '-': { if (bok > bokmin) bok--; break; }				// zmniejszenie
		case 75:  { if (x - bok > xmin) x--; break; }				// przesuniecie w lewo
		case 77:  { if (x + bok < xmax) x++; break; }				// przesuniecie w prawo
		case 72:  { if (y - bok > ymin) y--; break; }				// przesuniecie do gory
		case 80:  { if (y + bok < ymax) y++; break; }				// przesuniecie do dolu
		}
	} while (klawisz != 27);										// koniec programu
	ShowCursor();
	return 0;
}
//--------------------------------------------------------------------------------------------------

