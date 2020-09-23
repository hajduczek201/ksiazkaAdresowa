#include "KsiazkaAdresowa.h"


void KsiazkaAdresowa::rejestracjaUzytkownika()
{
	uzytkownikMenedzer.rejestracjaUzytkownika();
}
void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
	uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}
void KsiazkaAdresowa::logowanieUzytkownika()
{
	uzytkownikMenedzer.logowanieUzytkownika();
	idZalogowanegoUzytkownika = uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika();
	adresatMenedzer.wczytajAdresatowZPliku(idZalogowanegoUzytkownika);
}
int KsiazkaAdresowa::pobierzIdZalogowanegoUzytkownika()
{
	return idZalogowanegoUzytkownika;
}
void KsiazkaAdresowa::wylogujUzytkownika()
{
	uzytkownikMenedzer.wylogujUzytkownika();
	adresatMenedzer.wylogujUzytkownika();
	idZalogowanegoUzytkownika = uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika();
}
void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
	uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}
void KsiazkaAdresowa::dodajAdresata(int idZalogowanegoUzytkownika)
{
	adresatMenedzer.dodajAdresata(idZalogowanegoUzytkownika);
}
void KsiazkaAdresowa::wypiszWszystkichAdresatowDanegouzytkownika()
{
	adresatMenedzer.wypiszWszystkichAdresatow();
}
void KsiazkaAdresowa::menuLogowania()
{
  	system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
}
void KsiazkaAdresowa::menuUzytkownika()
{
	system("cls");
	cout << "  >>> MENU  UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wypisz adresatow" << endl;
    cout << "8. Zmiana hasla" << endl;
    cout << "0. Wyloguj" << endl;
}

