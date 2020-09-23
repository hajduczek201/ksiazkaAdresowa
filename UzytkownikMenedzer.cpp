#include "UzytkownikMenedzer.h"
void UzytkownikMenedzer::rejestracjaUzytkownika()
{
	Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();
    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;
    string login;
  	uzytkownik.ustawID(pobierzIdNowegoUzytkownika());
    do
    {
        cout << "Podaj login: ";
        cin >> login;
        uzytkownik.ustawLogin(login);
    
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);
	
	string haslo;
    cout << "Podaj haslo: ";
    cin >> haslo;
	uzytkownik.ustawHaslo(haslo);
    return uzytkownik;
}

int UzytkownikMenedzer::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzID() + 1;
}

bool UzytkownikMenedzer::czyIstniejeLogin(string login)
{
	for (int i = 0; i<uzytkownicy.size(); i++)
	{
		if (uzytkownicy[i].pobierzLogin() == login)
		{
			cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
			return true;
		}
	}
    return false;
}
void UzytkownikMenedzer::wypiszWszystkichUzytkownikow()
{
	for (int i = 0; i<uzytkownicy.size(); i++)
	{
			cout << uzytkownicy[i].pobierzID() << endl;
			cout << uzytkownicy[i].pobierzLogin() << endl;
			cout << uzytkownicy[i].pobierzHaslo() << endl;
			cout << endl;
	}
}
void UzytkownikMenedzer::wczytajUzytkownikowZPliku()
{
	uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
}
void UzytkownikMenedzer::logowanieUzytkownika()
{
    Uzytkownik uzytkownik;
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    login = MetodyPomocnicze::wczytajLinie();

    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end())
    {
        if (itr -> pobierzLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = MetodyPomocnicze::wczytajLinie();

                if (itr -> pobierzHaslo() == haslo)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    idZalogowanegoUzytkownika = (itr -> pobierzID());
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
          	return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
  	return;
}
void UzytkownikMenedzer::wylogujUzytkownika ()
{
	idZalogowanegoUzytkownika = 0;
}
int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika()
{
	return idZalogowanegoUzytkownika;
}
void UzytkownikMenedzer::zmianaHaslaZalogowanegoUzytkownika()
{
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = MetodyPomocnicze::wczytajLinie();

    for (int i = 0; i < uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzID() == pobierzIdZalogowanegoUzytkownika())
        {
            uzytkownicy[i].ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}
