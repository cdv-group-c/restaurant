#include <iostream>
#include "state.hpp"

using namespace std;

void getNextStep(vector<int> currentOrder, vector<int> mealIds, string mealList);

void showMeals(string menu)
{
	cout << menu << endl;
};

bool validateMealId(vector<int> mealIds, int userChoice)
{
	bool isValid = false;
	size_t size = mealIds.size();

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

int getUserChoice(vector<int> mealIds)
{
	int userChoice;

	cout << "\nCo chcesz dzisiaj zjesc?" << endl;
	cin >> userChoice;

	bool isValid = validateMealId(mealIds, userChoice);

	if (!isValid)
	{
		cout << "\nPodaj wlasciwy numer posilku" << endl;
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
	cout << "\nIle porcji chcesz zamowic?" << endl;
	cin >> amountOfMeals;
	int MAX_AMOUNT_OF_MEALS = 5;

	bool isValid = validateAmountOfMeals(amountOfMeals, 5);

	if (!isValid)
	{
		cout << "\nMozesz zamowic maksymalnie " << MAX_AMOUNT_OF_MEALS << " porcji" << endl;
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

void addMeal()
{
	string menu = getMealsList();
	vector<int> mealIds = getMealIds();
	showMeals(menu);
	int userChoice = getUserChoice(mealIds);
	int amountOfMeals = getAmountOfMeals();
	addToBill(userChoice, amountOfMeals);
	vector<int> currentOrder = getOrderedMeals();
	showMenu();
	getNextStep(currentOrder, mealIds, menu);
}

int getMealToRemove(vector<int> mealIds)
{
	int mealToRemove;

	cout << "\nCo chcesz usunac?" << endl;
	cout << getBill() << endl;
	cin >> mealToRemove;

	bool isValid = validateMealId(mealIds, mealToRemove);

	if (!isValid)
	{
		cout << "\nNie masz takiego posilku w swoim zamowieniu" << endl;
		getMealToRemove(mealIds);
	}

	return mealToRemove;
};

bool checkOrder(vector<int> mealIds)
{
	int size = sizeof(mealIds) / sizeof(mealIds[0]);
	return size > 0;
}

void getNextStep(vector<int> currentOrder, vector<int> mealIds, string mealList)
{
	int number;
	cin >> number;

	switch (number)
	{
	case 1:
		addMeal();
		break;

	case 2:
	{
		int mealToRemove = getMealToRemove(mealIds);
		removeFromBill(mealToRemove);
		showMenu();
		vector<int> newCurrentOrder = getOrderedMeals();
		getNextStep(newCurrentOrder, mealIds, mealList);
		break;
	}

	case 3:
	{
		bool isValid = checkOrder(currentOrder);

		if (!isValid)
		{
			cout << "\nNajpierw dodaj posilek" << endl;
			addMeal();
		}
		break;
	}

	case 4:
		exit(0);
		break;
	}
}
