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
	plikTekstowy.close();
	return adresaci;
}
void PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat, string nazwaPliku)
{
	fstream plikTekstowy;
	plikTekstowy.open(nazwaPliku.c_str(), ios::app);
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
	if (nazwaPliku == NAZWA_PLIKU_Z_ADRESATAMI)
		idOstatniegoAdresata++;
} 

int PlikZAdresatami::pobierzIdOstatniegoAdresata()
{
	return idOstatniegoAdresata;
}
void PlikZAdresatami::przepiszPlikZAdresatami(int nrZalogowanegoUzytkownika, vector <Adresat> adresaci)
{
	{
	Adresat adresat;
	fstream plikTekstowy;
	string pom;
	int nrWyrazu = 1;
	plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
	if (plikTekstowy.good() == true)
	{
		while (getline(plikTekstowy, pom, '|'))
		{
			switch (nrWyrazu)
			{
				case 1:
					adresat.ustawID(atoi(pom.c_str()));	
					break;
				case 2:
					adresat.ustawIdUzytkownika(atoi(pom.c_str()));
					break;
				case 3:
					adresat.ustawImie(pom);					
					break;
				case 4:
					adresat.ustawNazwisko(pom);
					break;
				case 5:
					adresat.ustawNrTelefonu(pom);			
					break;
				case 6:
					adresat.ustawEmail(pom);
					break;
				case 7:
					adresat.ustawAdres(pom);	
					nrWyrazu = 0;
					if(adresat.pobierIdUzytkownika() != nrZalogowanegoUzytkownika)
					{
						dopiszAdresataDoPliku(adresat,NAZWA_PLIKU_TYMCZASOWEGO);
					}
					break;
			}
			nrWyrazu++;
		}
		for (int i = 0; i< adresaci.size(); i++)
		{
			dopiszAdresataDoPliku(adresaci[i], NAZWA_PLIKU_TYMCZASOWEGO);
		}
	}
	plikTekstowy.close();
	remove(NAZWA_PLIKU_Z_ADRESATAMI.c_str());
	rename(NAZWA_PLIKU_TYMCZASOWEGO.c_str(), NAZWA_PLIKU_Z_ADRESATAMI.c_str());
	}
}
const string PlikZAdresatami::pobierzNazwePlikuZAdresatami()
{
	return NAZWA_PLIKU_Z_ADRESATAMI;
}
const string PlikZAdresatami::pobierzNazwePlikuTymczasowego()
{
	return NAZWA_PLIKU_TYMCZASOWEGO;
}
void PlikZAdresatami::odejmijJedenOdIdOstatniegoAdresata()
{
	idOstatniegoAdresata--;
}
