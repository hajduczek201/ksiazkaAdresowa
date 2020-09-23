#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>
#include <sstream>
#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"
#include "MetodyPomocnicze.h"
using namespace std;

class UzytkownikMenedzer
{
		int idZalogowanegoUzytkownika;	
		vector <Uzytkownik> uzytkownicy;
		PlikZUzytkownikami plikZUzytkownikami;
		
		Uzytkownik podajDaneNowegoUzytkownika();
	    int pobierzIdNowegoUzytkownika();
	    bool czyIstniejeLogin(string login);
	    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
	    		
		public:
		UzytkownikMenedzer (string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami){};
		void rejestracjaUzytkownika();
		void wypiszWszystkichUzytkownikow();
		void wczytajUzytkownikowZPliku();
		void logowanieUzytkownika();
		void wylogujUzytkownika();
		int pobierzIdZalogowanegoUzytkownika();
		void zmianaHaslaZalogowanegoUzytkownika(); 
};

#endif
