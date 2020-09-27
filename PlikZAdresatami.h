#ifndef PLIKZADRESTAMI_H
#define PLIKZADRESTAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <windows.h>
#include <sstream>
#include "Adresat.h"
#include "MetodyPomocnicze.h"

class PlikZAdresatami
{
	const string NAZWA_PLIKU_Z_ADRESATAMI;
	int idOstatniegoAdresata;
	
	void wczytajIdOstatniegoAdresata ();
	
	public:
	PlikZAdresatami (string PLIK):NAZWA_PLIKU_Z_ADRESATAMI(PLIK)
	{
		wczytajIdOstatniegoAdresata	();
	};
	void dopiszAdresataDoPliku (Adresat adresat);
	vector <Adresat> wczytajAdresatowZPliku (int nrZalogowanegoUzytkownika);
	int pobierzIdOstatniegoAdresata	();
};

#endif
