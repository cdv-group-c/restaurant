#include <iostream>
#include <ctime>
#include <windows.h>
#include <winbase.h>
#include <cstdlib>
#include <conio.h>

using namespace std;

string getUserName() {
	string userName;

	cout << "Jak masz na imie?" << endl;
	cin >> userName;

	return userName;
}

bool getInsideOrTakeaway() {
	bool insideOrTakeaway;

	cout << "Czy spakowac zamowienie na wynos?" << endl
		 << "Wybierz [1] Tak lub [0] Nie" << endl;
	cin >> insideOrTakeaway;

	return insideOrTakeaway;
}


// Losowanie stolika czy wybieranie?
int getTableNumber() {

	srand(time(NULL));
	int tableNumber = rand() % 20 + 1;

	cout << "Twoj numer stolika to: " << tableNumber << endl;

	return tableNumber;
}

string getAddress() {
	string address;

	cout << "Podaj adres na ktory ma zostac dostarczone zamowienie" << endl;
	cin >> address;

	return address;
}

string getPreferredDeliveryTime() {
	string preferredDeliveryTime;
	int day;
	int month;
	int hours;
	int minutes;
	SYSTEMTIME st;

	GetSystemTime(&st);

	cout << "Restauracja czynna jest codziennie w godzinach 12:00-24:00" << endl;

	cout << "Podaj dzien dostarczenia zamowienia" << endl;
	cin >> day;
	cout << "Podaj miesiac dostarczenia zamowienia" << endl;
	cin >> month;

	int currentMonth = st.wMonth;
	int currentDay = st.wDay;
	int currentMinutes = st.wMinute;
	int currentHours = st.wHour;

	if (day >= currentDay && month >= currentMonth)
	{
		cout << "Podaj godzine dostarczenia zamowienia" << endl;
		cin >> hours;
		cout << "Podaj minute dostarczenia zamowienia" << endl;
		cin >> minutes;

		if (minutes > currentMinutes && hours > currentHours)
		{
			cout << "Data i godzina zostala zapisana";
		}else
		{
			cout << "Podaj prawidlowa godzine";
		}

	}else
	{
		cout << "Wybierz prawidlowy dzien i miesiac";
	}
		

	return preferredDeliveryTime;
}

