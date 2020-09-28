#include "Adresat.h"
void Adresat::ustawID (int noweID)
{
	if (noweID>0)
		id = noweID;
}
void Adresat::ustawIdUzytkownika (int idZalogowanegoUzytkownika)
{
	idUzytkownika = idZalogowanegoUzytkownika;
}
void Adresat::ustawImie(string IMIE)
{
	imie = IMIE;
}
void Adresat::ustawNazwisko(string NAZWISKO)
{
	nazwisko = NAZWISKO;
}
void Adresat::ustawNrTelefonu(string TELEFON)
{
	numerTelefonu = TELEFON;
}
void Adresat::ustawEmail(string EMAIL)
{
	email = EMAIL;
}
void Adresat::ustawAdres(string ADRES)
{
	adres = ADRES;
}
int Adresat::pobierzID()
{
	return id;
}
int Adresat::pobierIdUzytkownika()
{
	return idUzytkownika;
}
string Adresat::pobierzImie()
{
	return imie;
}
string Adresat::pobierzNazwisko()
{
	return nazwisko;
}
string Adresat::pobierzNrTelefonu()
{
	return numerTelefonu;
}
string Adresat::pobierzEmail()
{
	return email;
}
string Adresat::pobierzAdres()
{
	return adres;
}
void Adresat::wypiszDaneAdresata()
{
	cout << "ID: " << pobierzID() << endl;
	cout << "Imie: " << pobierzImie() << endl;
	cout << "Nazwisko: " << pobierzNazwisko() << endl;
	cout << "Numer telefonu: " << pobierzNrTelefonu() << endl;
	cout << "Email: " << pobierzEmail() << endl;
	cout << "Adres: " << pobierzAdres() << endl;	
}
