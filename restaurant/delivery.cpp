#include <iostream>
#include <ctime>
#include <windows.h>
#include <winbase.h>
#include <cstdlib>
#include <string>

using namespace std;

const int OPEN_HOUR = 12;
const int CLOSE_HOUR = 22;

void showRestaurantName()
{
	cout << "==========================" << endl;
	cout << "Witamy w restauracji AKAKE" << endl;
	cout << "==========================" << endl;
}

string getUserName()
{
	string userName;

	cout << "\nJak masz na imie?" << endl;
	cin >> userName;

	return userName;
}

int getInsideOrTakeaway()
{
	int insideOrTakeaway;

	cout << "\nCzy spakowac zamowienie na wynos?" << endl
			 << "Wybierz [1] Tak lub [0] Nie" << endl;
	cin >> insideOrTakeaway;

	if (insideOrTakeaway == 1 || insideOrTakeaway == 0)
	{
		return insideOrTakeaway;
	}

	cout << "\nChyba sie nie zrozumielismy" << endl;
	getInsideOrTakeaway();
}

int getTableNumber()
{

	const int NUMBER_OF_TABLES = 20;

	srand(time(NULL));
	int tableNumber = rand() % NUMBER_OF_TABLES + 1;

	return tableNumber;
}

string getAddress()
{
	string address;

	cout << "\nPodaj swoj adres zamieszkania" << endl;

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

string getNumberWithTrailingZero(int number)
{
	if (number > 0 && number < 10)
	{
		return "0" + to_string(number);
	}

	return to_string(number);
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

		cout << "\nPodaj dzien dostarczenia zamowienia" << endl;
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
			cout << "\nPodaj prawidlowa date" << endl;
			isInvalid = true;
			continue;
		}

		cout << "\nPodaj godzine dostarczenia zamowienia" << endl;
		cin >> hours;
		cout << "Podaj minute dostarczenia zamowienia" << endl;
		cin >> minutes;

		bool isHourInThePast = hours <= currentHours && minutes < currentMinutes;
		bool isInHoursRange = (hours >= 0 && hours < 24) && (minutes >= 0 && minutes < 60);

		if (!isInHoursRange || isDayInThePast || (isCurrentDay && isHourInThePast))
		{
			cout << "\nPodaj prawidlowa godzine" << endl;
			isInvalid = true;
			continue;
		}

		if (hours < OPEN_HOUR || hours >= CLOSE_HOUR)
		{
			cout << "\nNie pracujemy w tych godzinach" << endl;
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

		preferredDeliveryTime = getNumberWithTrailingZero(day) + "-" + getNumberWithTrailingZero(month) + "-2022" + " " + getNumberWithTrailingZero(hours) + ":" + getNumberWithTrailingZero(minutes);

		return preferredDeliveryTime;
	} while (isInvalid);
}
