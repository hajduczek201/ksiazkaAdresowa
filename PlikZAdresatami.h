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
	const string nazwaPlikuZAdresatami;
	
	bool czyPlikJestPusty ();
	public:
	PlikZAdresatami (string PLIK):nazwaPlikuZAdresatami(PLIK){};
	void dopiszAdresataDoPliku (Adresat adresat);
	vector <Adresat> wczytajAdresatowZPliku (int nrZalogowanegoUzytkownika);
	void dopiszAresataDoPliku();		
};

#endif
