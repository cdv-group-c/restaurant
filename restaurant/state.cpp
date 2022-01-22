#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

const string MENU_FILE_NAME = "menu.txt";
const string BILL_FILE_NAME = "bill.txt";

vector<int> orderedMeals;
vector<int> mealIds;

vector<string> readRecordFromFile(string fileName, string searchTerm);

string getMealsList()
{
	int amountOfMeals = 0;
	string tempLine;
	string mealsList;
	ifstream file;
	
	file.open(MENU_FILE_NAME);

	while (getline(file, tempLine))
	{
		amountOfMeals++;

		string mealId = to_string(amountOfMeals);
		vector<string> data = readRecordFromFile(MENU_FILE_NAME, mealId);
		mealsList += mealId + ". | name: " + data[1] + " | price: " + data[2] + " | ingredients: " + data[3] + "\n";

		mealIds.push_back(amountOfMeals);
	}

	return mealsList;
}

vector<int> getMealIds()
{
	return mealIds;
}

void addToBill(int id, int amountOfMeals)
{
	for (int i = 0; i < amountOfMeals; i++)
	{
		orderedMeals.push_back(id);
	}
}

void removeFromBill(int id)
{
	orderedMeals.erase(orderedMeals.begin() + id - 1);
}

vector<int> getOrderedMeals()
{
	return orderedMeals;
}

double cashBill()
{
	double price = 0.0;
	for (int i = 0; i < orderedMeals.size(); i++)
	{
		vector<string> data = readRecordFromFile(MENU_FILE_NAME, to_string(orderedMeals[i]));
		double mealPrice = stod(data[2]);
		price += mealPrice;
	}
	double roundedPrice = ceil(price * 100.0) / 100.0;
	return roundedPrice;
}

string getBill()
{
	string bill;
	for (int i = 0; i < orderedMeals.size(); i++)
	{
		vector<string> data = readRecordFromFile(MENU_FILE_NAME, to_string(orderedMeals[i]));
		bill += to_string(i + 1) + ". | nazwa: " + data[1] + " | cena: " + data[2] + "\n";
	}
	bill += "Cena calkowita: " + to_string(cashBill()) + " zl";
	return bill;
}

vector<string> readRecordFromFile(string fileName, string searchTerm)
{
	vector<string> record;

	ifstream file;
	file.open(fileName);

	bool foundRecord = false;

	string id;
	string name;
	string price;
	string ingredients;

	const char SEPARATOR = '|';

	while (getline(file, id, SEPARATOR) && !foundRecord)
	{
		getline(file, name, SEPARATOR);
		getline(file, price, SEPARATOR);
		getline(file, ingredients, '\n');
		if (id == searchTerm)
		{
			foundRecord = true;
			record.push_back(id);
			record.push_back(name);
			record.push_back(price);
			record.push_back(ingredients);
		}
	}

	return record;
}

void saveBillToFile(string content)
{
	ofstream file;
	file.open(BILL_FILE_NAME, ios::trunc);
	file << content;
	file.close();
}
