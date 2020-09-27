#include <iostream>
#include <windows.h>
#include "KsiazkaAdresowa.h"
using namespace std;

int main()
{
	KsiazkaAdresowa ksiazkaAdresowa ("Uzytkownicy.txt", "Adresaci.txt");
	while (true)
	{
		if (!(ksiazkaAdresowa.czyUzytkownikJestZalogowany()))
		{
			char wybor = 0;
			ksiazkaAdresowa.menuLogowania();
			cin >> wybor;
			cin.ignore(256, '\n');
			switch (wybor)
			{
				case '1':
					ksiazkaAdresowa.rejestracjaUzytkownika();
					break;
				case '2':
					ksiazkaAdresowa.logowanieUzytkownika();
					break;
				case '9':
					exit (0);
				default:
					cout << "Bledny wybor, sproboj ponownie" << endl;
					Sleep (2000);
					break;
			}
		}
		else 
		{
			ksiazkaAdresowa.menuUzytkownika();
			char wybor = 0;
			cin >> wybor;
			cin.ignore(256, '\n');
			switch (wybor)
			{
				case '1':
					ksiazkaAdresowa.dodajAdresata();
					break;
				case '2':
					ksiazkaAdresowa.wypiszWszystkichAdresatowDanegouzytkownika();
					break;
				case '8':
					ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
					break;
				case '0':
					ksiazkaAdresowa.wylogujUzytkownika();
					break;
				default:
					cout << "Bledny wybor, sproboj ponownie" << endl;
					Sleep (2000);
					break;
			}
			
		}
	}
	return 0;
}
