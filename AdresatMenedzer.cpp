#include "AdresatMenedzer.h"


void AdresatMenedzer::dodajAdresata()
{
	Adresat adresat;
	adresat = podajDaneNowegoAdresata();
	plikZAdresatami.dopiszAdresataDoPliku(adresat);
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
