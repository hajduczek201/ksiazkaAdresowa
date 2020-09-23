#include "AdresatMenedzer.h"

int AdresatMenedzer::pobierzIdNowegoAdresata()
{
	Adresat adresat;
	fstream plikTekstowy;
	string pom;
	int nrWyrazu = 1;
	int max = 0;
	plikTekstowy.open("Adresaci.txt", ios::in);
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
	return max+1;
}
void AdresatMenedzer::dodajAdresata(int idZalogowanegoUzytkownika)
{
	Adresat adresat;
	adresat = podajDaneNowegoAdresata(idZalogowanegoUzytkownika);
	plikZAdresatami.dopiszAdresataDoPliku(adresat);
	adresaci.push_back(adresat);
}
Adresat AdresatMenedzer::podajDaneNowegoAdresata(int idZalogowanegoUzytkownika)
{
	//UzytkownikMenedzer uzytkownikMenedzer("Uzytkownicy.txt");
	Adresat adresat;
	cout << "Podaj imie: ";
	string imie = MetodyPomocnicze::wczytajLinie();
	adresat.ustawImie(imie);
	cout << "Podaj nazwisko: ";
	string nazwisko = MetodyPomocnicze::wczytajLinie();
	adresat.ustawNazwisko(nazwisko);
	cout << "Podaj nr telefonu: ";
	string nrTel = MetodyPomocnicze::wczytajLinie();
	adresat.ustawNrTelefonu(nrTel);
	cout << "Podaj adres e-mail: ";
	string email = MetodyPomocnicze::wczytajLinie();
	adresat.ustawEmail(email);
	cout << "Podaj adres: ";
	string adres = MetodyPomocnicze::wczytajLinie();
	adresat.ustawAdres(adres);
	adresat.ustawID(pobierzIdNowegoAdresata());
	adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);
	return adresat;
}
void AdresatMenedzer::wczytajAdresatowZPliku(int idZalogowanegoUzytkownika)
{
	//UzytkownikMenedzer uzytkownikMenedzer("Uzytkownicy.txt");
	adresaci = plikZAdresatami.wczytajAdresatowZPliku(idZalogowanegoUzytkownika);
}
void AdresatMenedzer::wypiszWszystkichAdresatow()
{
	for (int i = 0; i < adresaci.size(); i++ )
	{
		cout << adresaci[i].pobierzID() << endl;
		cout << adresaci[i].pobierIdUzytkownika() << endl;
		cout << adresaci[i].pobierzImie() << endl;
		cout << adresaci[i].pobierzNazwisko() << endl;
		cout << adresaci[i].pobierzNrTelefonu() << endl;
		cout << adresaci[i].pobierzEmail() << endl;
		cout << adresaci[i].pobierzAdres() << endl;
	}
	system("pause");
}
void AdresatMenedzer::wylogujUzytkownika()
{
	adresaci.clear();
}
