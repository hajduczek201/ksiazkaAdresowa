#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>
#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"

using namespace std;

class KsiazkaAdresowa
{
	UzytkownikMenedzer uzytkownikMenedzer;
	AdresatMenedzer adresatMenedzer;
	int idZalogowanegoUzytkownika;
	public:
	
	KsiazkaAdresowa(string plik, string plik2):uzytkownikMenedzer(plik), adresatMenedzer(plik2){
	uzytkownikMenedzer.wczytajUzytkownikowZPliku();
	idZalogowanegoUzytkownika = 0;
	};
	void rejestracjaUzytkownika();
	void wypiszWszystkichUzytkownikow();
	void logowanieUzytkownika();
	void wylogujUzytkownika();
	int pobierzIdZalogowanegoUzytkownika();
	void zmianaHaslaZalogowanegoUzytkownika();
	void dodajAdresata(int idZalogowanegoUzytkownika);
	void wypiszWszystkichAdresatowDanegouzytkownika ();
	void menuLogowania();
	void menuUzytkownika();
};

#endif
