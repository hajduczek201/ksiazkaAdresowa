#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>
#include <sstream>
#include "Adresat.h"
#include "UzytkownikMenedzer.h"
#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"

using namespace std;

class AdresatMenedzer
{

	const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
	PlikZAdresatami plikZAdresatami;
    vector <Adresat> adresaci;
    
    void pobierzIdNowegoAdresata();
    Adresat podajDaneNowegoAdresata();
    bool zaakceptujUsuniecieBadzModyfikacje(Adresat adresat);
    
	public:
	AdresatMenedzer(string nazwaPlikuZAdresatami, string nazwaPlikuTymczasowego, int id_zalogowanego_uzytkownika):plikZAdresatami(nazwaPlikuZAdresatami, nazwaPlikuTymczasowego),
	ID_ZALOGOWANEGO_UZYTKOWNIKA(id_zalogowanego_uzytkownika)
	{
		adresaci = plikZAdresatami.wczytajAdresatowZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
	};
    void dodajAdresata();
    void wypiszWszystkichAdresatow();
    void wylogujUzytkownika();
    void wyszukajPoImieniu();
    void wyszukajPoNazwisku ();
    void usunAdresata();
};

#endif
