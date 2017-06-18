#include "stdafx.h"
#include "konsola.h"
#include "stale.h"
#include "funkcje.h"
using namespace std;
//--------------------------------------------------------------------------------------------------
void ekran_startowy() {												// ekran startowy
	polskie_litery();
	HideCursor();
	ustaw_kolor(15);
	system("cls");
	cout << "\nPROJEKT 2, zadanie 41";
	cout << "\n---------------------";
	ustaw_kolor(2);
	cout << "\n\nProgram rysuje figurę jak na rys. obok, o zadanej przez";
	cout << "\n użytkownika długości boku i wykorzystując wprowadzony";
	cout << "\n z klawiatury dowolny znak. Umożliwia przesuwanie tej figury";
	cout << "\n w lewo/prawo/górę/dół za pomocą klawiszy strzałek oraz";
	cout << "\n zmniejszanie/zwiększanie jej rozmiaru przy pomocy klawiszy";
	cout << "\n [+] oraz [-]. Program wykrywa krawędzie ekranu i uniemożliwia";
	cout << "\n przesuwanie lub zwiększanie rozmiaru figury jeśli znajduje się";
	cout << "\n ona przy krawędzi.";
	cout << "\n\nPunkt zaczepienia figury znajduje się na środku (znak X na";
	cout << "\n rys obok).";
	cout << "\n\nProgram napisano techniką obiektową.";
	ustaw_kolor(7);
	cout << "\n\nWykonał:";
	cout << "\nKrzysztof Umiński (nr albumu 167971),";
	cout << "\nInformatyka 1 nst., 2016 / 2017";
	cout << "\ns167971@student.pg.gda.pl";
	gotoxy(40, 22);
	ustaw_kolor(15);
	cout << "Naciśnij dowolny klawisz aby rozpocząć";
	figura F;
	F.x = 70;
	F.y = 9;
	F.bok = 7;
	F.znak = '*';
	F.rysuj();
	_getch();
	system("cls");
}
//--------------------------------------------------------------------------------------------------
char pobierz_znak() {												// pobiera znak z klawiatury
	char znak;
	ShowCursor();
	do {
		gotoxy(3, 3);
		cout << "Wprowadź znak z klawiatury: ";
		znak = _getch();
	} while (znak == 13);
	cout << znak;
	return znak;
}
//--------------------------------------------------------------------------------------------------
int pobierz_bok(int bokmax) {										// pobiera dlugosc boku
	int bok;
	do {
		gotoxy(3, 5);
		clreol();
		gotoxy(3, 5);
		cout << "Podaj długość boku figury (" << bokmin << " - " << bokmax << "): ";
		cin >> bok;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (cin.fail() == true || (bok < bokmin || bok > bokmax));
	HideCursor();
	return bok;
}
//-------------------------------------------------------------------------------------------------
void legenda() {													// funkcja wyswietla legende
	gotoxy(1, 24);
	ustaw_kolor(27);
	cout << " [strzałki] - przesuwanie figury, [+]/[-] - zwiększ/zmniejsz,  [esc] - koniec ";
}
//-------------------------------------------------------------------------------------------------
void punkt::rysuj_pkt() {											// rysuj punkt
	cout << znak;
	//Sleep(50);			// opoznienie rysowania figury
};

void odcinek::rysuj_ab() {											// rysowanie ukosnej w dol
	for (i = 1; i <= bok; i++) {
		gotoxy(x + i, y + i);
		rysuj_pkt();
	}
};

void odcinek::rysuj_bc() {
	for (i = 1; i <= bok; i++) {
		gotoxy(x + bok - i, y + bok);								// rysowanie dolnej poziomej
		rysuj_pkt();
	}
};

void odcinek::rysuj_ca() {											// rysowanie pionowej do srodka
	for (i = 1; i < bok; i++) {
		gotoxy(x, y + bok - i); 										
		rysuj_pkt();
	}
}

void odcinek::rysuj_ad() {											// rysowanie pionowej do gory
	for (i = 1; i <= bok; i++) {
		gotoxy(x, y - i); 												
		rysuj_pkt();
	}
}

void odcinek::rysuj_de() {											// rysowanie gornej poziomej
	for (i = 1; i <= bok; i++) {
		gotoxy(x - i, y - bok);
		rysuj_pkt();
	}
};

void odcinek::rysuj_ea() {											// rysowanie ukosnej do srodka
	for (i = 1; i < bok; i++) {
		gotoxy(x - bok + i, y - bok + i); 		 								
		rysuj_pkt();
	}
}

void figura::rysuj_srodek() {										// srodek figury
	gotoxy(x-1, y);
	cout << " X ";
}

void figura::rysuj() {
	ustaw_kolor(15);
	rysuj_srodek();
	rysuj_ab();
	rysuj_bc();
	rysuj_ca();
	rysuj_ad();
	rysuj_de();
	rysuj_ea();
};
//-------------------------------------------------------------------------------------------------
