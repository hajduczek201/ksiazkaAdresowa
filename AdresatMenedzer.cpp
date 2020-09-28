#include "AdresatMenedzer.h"


void AdresatMenedzer::dodajAdresata()
{
	Adresat adresat;
	adresat = podajDaneNowegoAdresata();
	plikZAdresatami.dopiszAdresataDoPliku(adresat, plikZAdresatami.pobierzNazwePlikuZAdresatami());
	adresaci.push_back(adresat);
}
Adresat AdresatMenedzer::podajDaneNowegoAdresata()
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
	adresat.ustawID(plikZAdresatami.pobierzIdOstatniegoAdresata()+1);
	adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);
	return adresat;
}
bool AdresatMenedzer::zaakceptujUsuniecieBadzModyfikacje(Adresat adresat)
{
	adresat.wypiszDaneAdresata();
	char odp;
	cout << "Czy na pewno chcesz usunac/zmodyfikowac? t/n" << endl;
	cin >> odp;
	cin.ignore(256, '\n');
	if (odp == 't' || odp == 'T')
		return true;
	else
		return false;
}
void AdresatMenedzer::wypiszWszystkichAdresatow()
{
	for (int i = 0; i < adresaci.size(); i++ )
	{
		adresaci[i].wypiszDaneAdresata();
	}
	system("pause");
}
void AdresatMenedzer::wylogujUzytkownika()
{
	adresaci.clear();
}
void AdresatMenedzer::wyszukajPoImieniu()
{
	string imieDoZnalezienia;
	bool czyZnaleziono = false;
	cout << "Podaj imie do wyszukania: ";
	getline (cin, imieDoZnalezienia);
	
	for (int i = 0; i < adresaci.size(); i++)
	{
		if (imieDoZnalezienia == adresaci[i].pobierzImie())
		{
			czyZnaleziono = true;
			adresaci[i].wypiszDaneAdresata();
		}
		if (i+1 == adresaci.size() && czyZnaleziono == false)
		{
			cout << "Brak osob o tym imieniu!";
			system ("pause");
			return;
		}
	}		
	system ("pause");
}
void AdresatMenedzer::wyszukajPoNazwisku()
{
	string nazwiskoDoZnalezienia;
	bool czyZnaleziono = false;
	cout << "Podaj imie do wyszukania: ";
	getline (cin, nazwiskoDoZnalezienia);
	
	for (int i = 0; i < adresaci.size(); i++)
	{
		if (nazwiskoDoZnalezienia == adresaci[i].pobierzNazwisko())
		{
			czyZnaleziono = true;
			adresaci[i].wypiszDaneAdresata();
		}
		if (i+1 == adresaci.size() && czyZnaleziono == false)
		{
			cout << "Brak osob o tym nazwisku!";
			system ("pause");
			return;
		}
	}		
	system ("pause");
}
void AdresatMenedzer::usunAdresata()
{
	int idDoUsuniecia;
	cout << "Podaj ID Adresata do usuniecia: ";
	cin >> idDoUsuniecia;
	cin.ignore(256, '\n');
	bool znaleziono = false;
	for (int i = 0; i < adresaci.size(); i++)
	{
		if (adresaci[i].pobierzID() == idDoUsuniecia)
		{
			znaleziono = true;
			if (zaakceptujUsuniecieBadzModyfikacje(adresaci[i]))
			{
				adresaci.erase(adresaci.begin() + i);
				cout << "Rekord usuniety/zmodyfikowany" << endl;
				if (idDoUsuniecia == plikZAdresatami.pobierzIdOstatniegoAdresata())
				{
					plikZAdresatami.odejmijJedenOdIdOstatniegoAdresata();
				}
				plikZAdresatami.przepiszPlikZAdresatami(ID_ZALOGOWANEGO_UZYTKOWNIKA,adresaci);
				system ("pause");
				return;	
			}
			else
				return;
		}
		if (i + 1 == adresaci.size() && znaleziono == false)
		{
			cout << "W twojej ksiazce adresowej nie ma adresata o wskazanym ID " << endl;
			system ("pause");
		}
	}
}
