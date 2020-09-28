#ifndef PLIKZADRESTAMI_H
#define PLIKZADRESTAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <string>
#include <windows.h>
#include <sstream>
#include "Adresat.h"
#include "MetodyPomocnicze.h"

class PlikZAdresatami
{
	const string NAZWA_PLIKU_Z_ADRESATAMI;
	const string NAZWA_PLIKU_TYMCZASOWEGO;
	int idOstatniegoAdresata;
	
	void wczytajIdOstatniegoAdresata ();
	
	public:
	PlikZAdresatami (string nazwaPlikuZAdresatami, string nazwaPlikuTymczasowego):NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami), NAZWA_PLIKU_TYMCZASOWEGO(nazwaPlikuTymczasowego)
	{
		wczytajIdOstatniegoAdresata	();
	};
	void dopiszAdresataDoPliku (Adresat adresat, string nazwaPliku);
	vector <Adresat> wczytajAdresatowZPliku (int nrZalogowanegoUzytkownika);
	int pobierzIdOstatniegoAdresata	();
	void odejmijJedenOdIdOstatniegoAdresata();
	void przepiszPlikZAdresatami(int nrZalogowanegoUzytkownika, vector <Adresat> adresaci);
	const string pobierzNazwePlikuZAdresatami();
	const string pobierzNazwePlikuTymczasowego();
};

#endif
