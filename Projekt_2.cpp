//-------------------------------------------------------------------------------------------------
//
//	PROJEKT 2, zadanie 41
//																					*******
//	Program rysuje figur� jak na rys. obok, o zadanej przez u�ytkownika				 *    *	
//		d�ugo�ci boku i wykorzystuj�c wprowadzony z klawiatury dowolny znak.		  *   *
//		Umo�liwia przesuwanie tej figury w lewo/prawo/g�r�/d� za pomoc� klawiszy	   *  *
//		strza�ek oraz zmniejszanie/zwi�kszanie jej rozmiaru przy pomocy klawiszy	    * *
//		[+] oraz [-].																	 **
//																						  X
//	Program wykrywa kraw�dzie ekranu i uniemo�liwia przesuwanie lub powi�kszanie		  **
//		rozmiaru figury je�li znajduje si� ona przy kraw�dzi. Do kasowania				  * *
//		cz�ci ekranu wykarzystano w�asn�, bardzo wydajn� funkcj� kasuj().				  *  *
//																						  *   *
//	Punkt zaczepienia figury znajduje si� na �rodku (znak X na rys obok).				  *    *
//																						  *******
//  Program napisano technik� obiektow�.
//
//	Wykona�:																			
//	Krzysztof Umi�ski (nr albumu 167971), informatyka 1 nst., 2016/2017
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

