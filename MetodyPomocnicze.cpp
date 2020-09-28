#include "MetodyPomocnicze.h"

string MetodyPomocnicze::konwerjsaIntNaString(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}
string MetodyPomocnicze::wczytajLinie()
{
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}
bool MetodyPomocnicze::czyKontynuowac()
{
	cout << "Czy chcesz kontynuowac? t/n" << endl;
	char odp;
	cin >> odp;
	cin.ignore(256, '\n');
	if (odp == 't' || odp == 'T')
		return true;
	else
		return false;
	
}

