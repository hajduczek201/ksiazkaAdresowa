#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>
#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"

using namespace std;

class KsiazkaAdresowa
{
	UzytkownikMenedzer uzytkownikMenedzer;
	AdresatMenedzer *adresatMenedzer;
	const string NAZWA_PLIKU_Z_ADRESATAMI;
	
	public:
	
	KsiazkaAdresowa(string plik, string plik2):uzytkownikMenedzer(plik), NAZWA_PLIKU_Z_ADRESATAMI(plik2)
	{
		adresatMenedzer = NULL;
	};
	~KsiazkaAdresowa()
	{
		delete adresatMenedzer;
		adresatMenedzer = NULL;
	}
	void rejestracjaUzytkownika();
	void wypiszWszystkichUzytkownikow();
	void logowanieUzytkownika();
	void wylogujUzytkownika();
	bool czyUzytkownikJestZalogowany();
	void wyszukajPoImieniu();
    void wyszukajPoNazwisku();
	void zmianaHaslaZalogowanegoUzytkownika();
	void dodajAdresata();
	void wypiszWszystkichAdresatowDanegouzytkownika ();
	void menuLogowania();
	void menuUzytkownika();
};

#endif
