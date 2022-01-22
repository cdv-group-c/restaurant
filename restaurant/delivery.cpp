#include <iostream>
#include <ctime>
#include <windows.h>
#include <winbase.h>
#include <cstdlib>
#include <string>

using namespace std;

const int OPEN_HOUR = 12;
const int CLOSE_HOUR = 22;

string getUserName()
{
	string userName;

	cout << "Jak masz na imie?" << endl;
	cin >> userName;

	return userName;
}

int getInsideOrTakeaway()
{
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

int getTableNumber()
{

	const int NUMBER_OF_TABLES = 20;

	srand(time(NULL));
	int tableNumber = rand() % NUMBER_OF_TABLES + 1;

	cout << "Twoj numer stolika to: " << tableNumber << endl;

	return tableNumber;
}

string getAddress()
{
	string address;

	cout << "Podaj swoj adres zamieszkania" << endl;

	cin.ignore();

	getline(cin, address);

	return address;
}

void showOpenHours()
{
	cout << "==========================================================" << endl;
	cout << "Restauracja czynna jest codziennie w godzinach " << OPEN_HOUR << ":00-" << CLOSE_HOUR << ":00" << endl;
	cout << "==========================================================" << endl;
}

void setDeliveryTime()
{

}


string getPreferredDeliveryTime()
{
	string preferredDeliveryTime;

	bool isInvalid = false;

	SYSTEMTIME st;
	GetSystemTime(&st);
	do
	{
		int day = 0;
		int month = 0;
		int hours = 0;
		int minutes = 0;
		
		cout << "Podaj dzien dostarczenia zamowienia" << endl;
		cin >> day;
		cout << "Podaj miesiac dostarczenia zamowienia" << endl;
		cin >> month;

		int currentMonth = st.wMonth;
		int currentDay = st.wDay;
		int currentMinutes = st.wMinute;
		int currentHours = st.wHour + 1;

		bool isDayInThePast = day < currentDay && month <= currentMonth;
		bool isInDaysRange = (day > 0 && day <= 31) && (month > 0 && month <= 12);
		bool isCurrentDay = day == currentDay && month == currentMonth;

		if (isDayInThePast || !isInDaysRange)
		{
			cout << "Podaj prawidlowa date" << endl;
			isInvalid = true;
			continue;
		}

		cout << "Podaj godzine dostarczenia zamowienia" << endl;
		cin >> hours;
		cout << "Podaj minute dostarczenia zamowienia" << endl;
		cin >> minutes;

		bool isHourInThePast = hours <= currentHours && minutes < currentMinutes;
		bool isInHoursRange = (hours >= 0 && hours < 24) && (minutes >= 0 && minutes < 60);

		if (!isInHoursRange || isDayInThePast ||  (isCurrentDay && isHourInThePast))
		{
			cout << "Podaj prawidlowa godzine" << endl;
			isInvalid = true;
			continue;
		}

		if (hours < OPEN_HOUR || hours >= CLOSE_HOUR)
		{
			cout << "Nie pracujemy w tych godzinach" << endl;
			isInvalid = true;
			continue;
		}
		
		int fastestDeliveryHours = currentHours + 1;

		bool isTooFastDeliveryTime = hours < fastestDeliveryHours || (hours == fastestDeliveryHours && minutes < currentMinutes);

		if (isCurrentDay && isTooFastDeliveryTime)
		{
			hours = fastestDeliveryHours;
			minutes = currentMinutes;
		}

		preferredDeliveryTime = to_string(day) + "-" + to_string(month) + "-2022" + " " + to_string(hours) + ":" + to_string(minutes);

		return preferredDeliveryTime;
	} while (isInvalid);

}
