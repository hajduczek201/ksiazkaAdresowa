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
	
	int pobierzID();
	int pobierIdUzytkownika();
	string pobierzImie();
	string pobierzNazwisko();
	string pobierzNrTelefonu();
	string pobierzEmail();
	string pobierzAdres();
	
};

#endif
