#include <iostream>
#include <ctime>
#include <windows.h>
#include <winbase.h>
#include <cstdlib>
#include <string>


using namespace std;

string getUserName() {
	string userName;

	 cout << "Jak masz na imie?" << endl;
	 cin >> userName;

	return userName;
}

int getInsideOrTakeaway() {
	int insideOrTakeaway;

	 cout << "Czy spakowac zamowienie na wynos?" << endl
			 << "Wybierz [1] Tak lub [0] Nie" << endl;
	 cin >> insideOrTakeaway;

	 if (insideOrTakeaway == 1 || insideOrTakeaway == 0)
	 {
		 return insideOrTakeaway;
	 }

	 cout << "Chyba sie nie zrozumielismy" << endl;
	 getInsideOrTakeaway();
}

int getTableNumber() {

	const int NUMBER_OF_TABLES = 20;

	srand(time(NULL));
	int tableNumber = rand() % NUMBER_OF_TABLES + 1;

	cout << "Twoj numer stolika to: " << tableNumber << endl;

	return tableNumber;
}

string getAddress() {
	string address;

	cout << "Podaj swoj adres zamieszkania" << endl;

// nie dziala
	cin >> address;
	getline(cin, address);

	return address;
}

string getPreferredDeliveryTime() {
	string preferredDeliveryTime;
	int day;
	int month;
	int hours = 0;
	int minutes = 0;

	const int OPEN_HOUR = 12;
	const int CLOSE_HOUR = 24;


	SYSTEMTIME st;
	GetSystemTime(&st);

	cout << "==========================================================" << endl;
	cout << "Restauracja czynna jest codziennie w godzinach " << OPEN_HOUR <<":00-" << CLOSE_HOUR << ":00" << endl;
	cout << "==========================================================" << endl;

	cout << "Podaj dzien dostarczenia zamowienia" << endl;
	cin >> day;
	cout << "Podaj miesiac dostarczenia zamowienia" << endl;
	cin >> month;

	int currentMonth = st.wMonth;
	int currentDay = st.wDay;
	int currentMinutes = st.wMinute;
	int currentHours = st.wHour + 1;

	if (day < currentDay && month <= currentMonth)
	{
		cout << "Podaj prawidlowa date";
	}
	else
	{
		cout << "Podaj godzine dostarczenia zamowienia" << endl;
		cin >> hours;
		cout << "Podaj minute dostarczenia zamowienia" << endl;
		cin >> minutes;
	}

	if (hours >= OPEN_HOUR && hours < CLOSE_HOUR) 
	{
		if (hours <= currentHours && minutes < currentMinutes)
		{
			cout << "Podaj prawidlowa godzine";
		}else 
		{
			preferredDeliveryTime = to_string(day) + "-" + to_string(month) + "-2022" + " " + to_string(hours) + ":" + to_string(minutes);
		}
		
	}else
	{
		cout << "Nie pracujemy w tych godzinach";
	}



	return preferredDeliveryTime;
}

