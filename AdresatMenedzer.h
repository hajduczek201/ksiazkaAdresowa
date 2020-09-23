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

//	int idZalogowanegoUzytkownika;
	int idOstatniegoAdresata;
	PlikZAdresatami plikZAdresatami;
   // int idUsunietegoAdresata;	
    vector <Adresat> adresaci;
    
    int pobierzIdNowegoAdresata();
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika);
    
	public:
	AdresatMenedzer(string nazwaPlikuZAdresatami):plikZAdresatami(nazwaPlikuZAdresatami){
	};
    void dodajAdresata(int idZalogowanegoUzytkownika);
    void wczytajAdresatowZPliku(int idZalogowanegoUzytkownika);
    void wypiszWszystkichAdresatow();
    void wylogujUzytkownika();
};

#endif
