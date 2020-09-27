#include "PlikZAdresatami.h"

void PlikZAdresatami::wczytajIdOstatniegoAdresata()
{
	Adresat adresat;
	fstream plikTekstowy;
	string pom;
	int nrWyrazu = 1;
	int max = 0;
	plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
	if (plikTekstowy.good() == true)
	{
		while (getline(plikTekstowy, pom, '|'))
		{
			switch (nrWyrazu)
			{
				case 1:
					adresat.ustawID(atoi(pom.c_str()));				break;
				case 2:
					adresat.ustawIdUzytkownika(atoi(pom.c_str()));	break;
				case 3:
					adresat.ustawImie(pom);					break;
				case 4:
					adresat.ustawNazwisko(pom);				break;
				case 5:
					adresat.ustawNrTelefonu(pom);			break;
				case 6:
					adresat.ustawEmail(pom);				break;
				case 7:
					adresat.ustawAdres(pom);				
					if (adresat.pobierzID()>max)
					{
						max = adresat.pobierzID();
					}
					nrWyrazu = 0;
					break;
			}
			nrWyrazu++;
		}
	}
	else 
	{
		cout << "Nie udalo sie otworzyc pliku"<< endl;
		system("pause");
	}
	plikTekstowy.close();
	idOstatniegoAdresata = max;
}
vector <Adresat> PlikZAdresatami::wczytajAdresatowZPliku (int nrZalogowanegoUzytkownika)
{
	Adresat adresat;
	fstream plikTekstowy;
	string pom;
	int nrWyrazu = 1;
	vector<Adresat> adresaci;
	plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
	if (plikTekstowy.good() == true)
	{
		while (getline(plikTekstowy, pom, '|'))
		{
			switch (nrWyrazu)
			{
				case 1:
					adresat.ustawID(atoi(pom.c_str()));				break;
				case 2:
					adresat.ustawIdUzytkownika(atoi(pom.c_str()));	break;
				case 3:
					adresat.ustawImie(pom);					break;
				case 4:
					adresat.ustawNazwisko(pom);				break;
				case 5:
					adresat.ustawNrTelefonu(pom);			break;
				case 6:
					adresat.ustawEmail(pom);				break;
				case 7:
					adresat.ustawAdres(pom);				break;
			}
			if (nrWyrazu == 7)
			{
				nrWyrazu = 0;
				if(adresat.pobierIdUzytkownika() == nrZalogowanegoUzytkownika)
				{
					adresaci.push_back(adresat);
				}
			}
			nrWyrazu++;
		}
	}
	else 
	{
		cout << "Nie udalo sie otworzyc pliku"<< endl;
		system("pause");
	}
	plikTekstowy.close();
	return adresaci;
}
void PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat)
{
	fstream plikTekstowy;
	plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::app);
	if (plikTekstowy.good() == true)
	{
		plikTekstowy << adresat.pobierzID() << '|';
		plikTekstowy << adresat.pobierIdUzytkownika() << '|';
		plikTekstowy << adresat.pobierzImie() << '|';
		plikTekstowy << adresat.pobierzNazwisko() << '|';
		plikTekstowy << adresat.pobierzNrTelefonu()<< '|';
		plikTekstowy << adresat.pobierzEmail()<< '|';
		plikTekstowy << adresat.pobierzAdres() << '|' << endl;
	}
	plikTekstowy.close();
	idOstatniegoAdresata++;
} 

int PlikZAdresatami::pobierzIdOstatniegoAdresata()
{
	return idOstatniegoAdresata;
}
