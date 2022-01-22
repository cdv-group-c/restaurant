#include <iostream>
#include "state.hpp"

using namespace std;

void showMeals(string menu)
{
	cout << menu;
};

bool validateMealId(int mealIds[], int userChoice)
{
	bool isValid = false;
	int size = sizeof(mealIds) / sizeof(mealIds[0]);

	for (int i = 0; i < size; i++)
	{
		if (mealIds[i] == userChoice)
		{
			isValid = true;
			break;
		}
	}

	return isValid;
}

int getUserChoice(int mealIds[])
{
	int userChoice;

	cout << "Co chcesz dzisiaj zjesc?" << endl;
	cin >> userChoice;

	bool isValid = validateMealId(mealIds, userChoice);

	if (!isValid)
	{
		cout << "Podaj wlasciwy numer posilku" << endl;
		getUserChoice(mealIds);
	}

	return userChoice;
};

bool validateAmountOfMeals(int amountOfMeals, int maxAmountOfMeals)
{
	return amountOfMeals < maxAmountOfMeals;
}

int getAmountOfMeals()
{
	int amountOfMeals;
	cout << "Ile porcji chcesz zamowic?" << endl;
	cin >> amountOfMeals;
	// TODO: add dynamic max amount
	bool isValid = validateAmountOfMeals(amountOfMeals, 5);

	if (!isValid)
	{
		cout << "Podaj odpowiednia ilosc porcji" << endl;
		getAmountOfMeals();
	}

	return amountOfMeals;
};

void showMenu()
{
	cout << "1. Dodaj kolejne danie" << endl;
	cout << "2. Usun danie" << endl;
	cout << "3. Przejdz do platnosci" << endl;
	cout << "4. Wyjdz z programu" << endl;
}

void addMeal(int mealIds[], string mealList)
{
	showMeals(mealList);
	int userChoice = getUserChoice(mealIds);
	addToBill(userChoice);
	getAmountOfMeals();
	showMenu();
}

int getMealToRemove(int mealIds[])
{
	int mealToRemove;

	cout << "Co chcesz usunac?" << endl;
	cin >> mealToRemove;

	bool isValid = validateMealId(mealIds, mealToRemove);

	if (!isValid)
	{
		cout << "Nie masz takiego posilku w swoim zamowieniu" << endl;
		getMealToRemove(mealIds);
	}

	return mealToRemove;
};

bool checkOrder(int mealIds[])
{
	int size = sizeof(mealIds) / sizeof(mealIds[0]);
	cout << size;
	return size > 0;
}

void getNextStep(int mealIds[], string mealList)
{
	int tab2[1] = {0};
	int number;
	cin >> number;

	switch (number)
	{
	case 1:
		addMeal(mealIds, mealList);
		break;

	case 2: {
		int mealToRemove = getMealToRemove(tab2);
		// TODO: add remove function
		break;
	}
		

	case 3:
	{
		bool isValid = checkOrder(tab2);

		if (!isValid)
		{
			cout << "Najpierw dodaj posilek" << endl;
			addMeal(mealIds, mealList);
		}
		break;
	}

	case 4:
		exit(0);
		break;
	}
}
