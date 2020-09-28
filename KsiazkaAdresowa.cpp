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
	if (uzytkownikMenedzer.czyUzytkownikJestZalogowany())
	{
		adresatMenedzer = new AdresatMenedzer (NAZWA_PLIKU_Z_ADRESATAMI, NAZWA_PLIKU_TYMCZASOWEGO, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
	}
}

void KsiazkaAdresowa::wylogujUzytkownika()
{
	uzytkownikMenedzer.wylogujUzytkownika();
	delete adresatMenedzer;
	adresatMenedzer = NULL;
}
void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
	uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}
void KsiazkaAdresowa::dodajAdresata()
{
	if (uzytkownikMenedzer.czyUzytkownikJestZalogowany())
	{
		adresatMenedzer->dodajAdresata();
	}
	else 
		cout << "Najpierw sie zaloguj!!!" << endl;
}
bool KsiazkaAdresowa::czyUzytkownikJestZalogowany()
{
	if (uzytkownikMenedzer.czyUzytkownikJestZalogowany())
		return true;
	else
		return false;
}
void KsiazkaAdresowa::wypiszWszystkichAdresatowDanegouzytkownika()
{
	adresatMenedzer->wypiszWszystkichAdresatow();
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
    cout << "3. Wyszukaj po imieniu" << endl;
    cout << "4. Wyszukaj po nazwisku" << endl;
    cout << "5. Usun adresata " << endl;
    cout << "6. Zmodyfikuj dane adresata " << endl;
    cout << "8. Zmiana hasla" << endl;
    cout << "0. Wyloguj" << endl;
}
void KsiazkaAdresowa::wyszukajPoImieniu()
{
	adresatMenedzer->wyszukajPoImieniu();
}
void KsiazkaAdresowa::wyszukajPoNazwisku()
{
	adresatMenedzer->wyszukajPoNazwisku();
}
void KsiazkaAdresowa::usunAdresata()
{
	adresatMenedzer->usunAdresata();
}
void KsiazkaAdresowa::zmodyfikujAdresata()
{
	adresatMenedzer->zmodyfikujAdresata();
}
