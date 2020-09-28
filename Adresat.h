#ifndef ADRESAT_H
#define ADRESAT_H
#include <iostream>
using namespace std;

class Adresat
{
	int id, idUzytkownika;
	string imie, nazwisko, numerTelefonu, email, adres;
	
	public:
	void ustawID (int noweID);
	void ustawIdUzytkownika (int idZalogowanegoUzytkownika);
	void ustawImie(string IMIE);
	void ustawNazwisko(string NAZWISKO);
	void ustawNrTelefonu(string TELEFON);
	void ustawEmail(string EMAIL);
	void ustawAdres(string ADRES);
	
	Adresat (int id = 0, int idUzytkownika = 0, string imie = "", string nazwisko = "", string numerTelefonu = "", string email = "", string adres = "")
	{
		this -> id = id;
		this -> idUzytkownika = idUzytkownika;
		this -> imie = imie;
		this -> nazwisko = nazwisko;
		this -> numerTelefonu = numerTelefonu;
		this -> email = email;
		this -> adres = adres;
		
	}
	int pobierzID();
	int pobierIdUzytkownika();
	string pobierzImie();
	string pobierzNazwisko();
	string pobierzNrTelefonu();
	string pobierzEmail();
	string pobierzAdres();
	void wypiszDaneAdresata();
	
};

#endif
