#include <iostream>

using namespace std;

void showTableNumber(int tableNumber)
{
	cout << "Twoj numer stolika to: " << tableNumber << endl;
}

void showDeliveryDetails(string deliveryAddress, string deliveryTime)
{
	cout << "Adres dostawy: " << deliveryAddress << endl;
	cout << "Przewidywany czas dostawy: " << deliveryTime << endl;
}

void showThanksText()
{
	cout << "Dziekujemy za skorzystanie z naszych uslug. Smacznego!";
}

int askForSavingToFile()
{
	int saveToFile;
	cout << "Czy chcesz zapisac zamowienie do pliku?" << endl
			 << "Wybierz [1] Tak lub [0] Nie" << endl;

	cin >> saveToFile;

	if (saveToFile == 1 || saveToFile == 0)
	{
		return saveToFile;
	}

	cout << "\nChyba sie nie zrozumielismy" << endl;
	askForSavingToFile();
}