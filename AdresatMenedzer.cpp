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
bool AdresatMenedzer::zaakceptujUsuniecieBadzModyfikacje()
{
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
			adresaci[i].wypiszDaneAdresata();
			if (zaakceptujUsuniecieBadzModyfikacje())
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
void AdresatMenedzer::zmodyfikujAdresata() 
{
	int idAdresataDoModyfikacji;
	cout << "Podaj id adresata do modyfikacji: ";
	cin >> idAdresataDoModyfikacji;
	cin.ignore(256, '\n');
	bool znaleziono = false;
	for (int i = 0; i < adresaci.size(); i++)
	{
		if (adresaci[i].pobierzID() == idAdresataDoModyfikacji)
		{
			znaleziono = true;
			do
			{
				adresaci[i].wypiszDaneAdresata();
				menuModyfikacji();
				char wybor;
				string zmodyfikowanaLinia ="";
				cin >> wybor;
				cin.ignore(256, '\n');
				switch (wybor)
				{
					case '1':
						cout << "Podaj nowe imie: ";
						zmodyfikowanaLinia = MetodyPomocnicze::wczytajLinie();
						if (zaakceptujUsuniecieBadzModyfikacje())
							adresaci[i].ustawImie(zmodyfikowanaLinia);
						break;
					case '2':
						cout << "Podaj nowe nazwisko: ";
						zmodyfikowanaLinia = MetodyPomocnicze::wczytajLinie();
						if (zaakceptujUsuniecieBadzModyfikacje())
							adresaci[i].ustawNazwisko(zmodyfikowanaLinia);
						break;
					case '3':
						cout << "Podaj nowy numer telefonu: ";
						zmodyfikowanaLinia = MetodyPomocnicze::wczytajLinie();
						if (zaakceptujUsuniecieBadzModyfikacje())
							adresaci[i].ustawNrTelefonu(zmodyfikowanaLinia);
						break;
					case '4':
						cout << "Podaj nowy adres e-mail: ";
						zmodyfikowanaLinia = MetodyPomocnicze::wczytajLinie();
						if (zaakceptujUsuniecieBadzModyfikacje())
							adresaci[i].ustawEmail(zmodyfikowanaLinia);
						break;
					case'5':
						cout << "Podaj nowy adres: ";
						zmodyfikowanaLinia = MetodyPomocnicze::wczytajLinie();
						if (zaakceptujUsuniecieBadzModyfikacje())
							adresaci[i].ustawAdres(zmodyfikowanaLinia);
						break;
					case '0':
						return;
					default:
						cout << "Niepoprawny wybor, sproboj ponownie ";
						system ("pause");
				}	
				plikZAdresatami.przepiszPlikZAdresatami(ID_ZALOGOWANEGO_UZYTKOWNIKA, adresaci);
				if (MetodyPomocnicze::czyKontynuowac())
					continue;
				else
					break;
			}while (true);
		}
		if (i + 1 == adresaci.size() && znaleziono == false)
		{
			cout << "W twojej ksiazce adresowej nie ma adresata o wskazanym ID " << endl;
			system ("pause");
		}
	}
}
void AdresatMenedzer::menuModyfikacji()
{
	cout << " MENU MODYFIKACJI" << endl;
	cout << "------------------" << endl;
	cout << "1. Zmodyfikuj imie" << endl;
	cout << "2. Zmodyfikuj nazwisko" << endl;
	cout << "3. Zmodyfikuj numer telefonu" << endl;
	cout << "4. Zmodyfikuj email" << endl;
	cout << "5. Zmodyfikuj adres" << endl;
	cout << "0. Anuluj "<< endl;
}
