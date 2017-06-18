#define funkcje
#include <limits>
#undef max
//--------------------------------------------------------------------------------------------------
void ekran_startowy();
char pobierz_znak();
int pobierz_bok(int bokmax);
void legenda();
//--------------------------------------------------------------------------------------------------
class punkt {
protected:
	void rysuj_pkt();
public:
	char znak;
};

class odcinek : public punkt {
private:
	int i;
protected:
	void rysuj_ab();
	void rysuj_bc();
	void rysuj_ca();
	void rysuj_ad();
	void rysuj_de();
	void rysuj_ea();
public:
	int x, y, bok;
};

class figura : public odcinek {
protected:
	void rysuj_srodek();
public:
	void rysuj();
};
//--------------------------------------------------------------------------------------------------