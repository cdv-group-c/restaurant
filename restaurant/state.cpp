#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;
int id;
int billSize = 0;
float bill = 0;
float portionNumber = 0;

const string MENU_FILE_NAME = "menu.csv";
const string BILL_FILE_NAME = "bill.txt";
int numberOfId = 0;
string tempLine;

vector<string> readRecordFromFile(string fileName, string searchTerm);

void printMenu()
{
	ifstream file;
	file.open(MENU_FILE_NAME);
	while (getline(file, tempLine)) {
		numberOfId++;
	}

	for (int i = 1; i <= numberOfId; i++) {
		string str = to_string(i);
		vector<string> data = readRecordFromFile(MENU_FILE_NAME, str);
		cout << "Id: " << data[0] << " | name: " << data[1] << " | price: " << data[2] << " | ingredients: " << data[3] << endl;
	}
}

void addToBill()
{
	cin >> id;
	if (id > numberOfId || id <= 0)
	{
		cout << "Numer poza zakresem" << endl;
	}
	else
	{
		cin >> portionNumber;
		string str = to_string(id);
		vector<string> data = readRecordFromFile(MENU_FILE_NAME, str);
		fstream file;
		file.open(BILL_FILE_NAME, ios::out | ios::app);
		file << data[0] << "," << data[1] << "," << data[2] << endl;
		bill += (stof(data[2]) * portionNumber);
		billSize += 1;
		file.close();
	}
	
}

void printBill()
{
	for (int i = 1; i <= billSize; i++)
	{
		string str = to_string(i);
		vector<string> data = readRecordFromFile(MENU_FILE_NAME, str);
		cout << "Id: " << data[0] << " | name: " << data[1] << " | price: " << data[2] << endl;
	}
	cout << "In summary: " << bill << endl;
}
void cashBill()
{
	fstream file;
	file.open(BILL_FILE_NAME, ios::out | ios::app);
	file << "In summary: " << bill << endl;
	
	for (int i = 1; i <= billSize; i++)
	{
		string str = to_string(i);
		vector<string> data = readRecordFromFile(MENU_FILE_NAME, str);
		cout << "Id: " << data[0] << " | name: " << data[1] << " | price: " << data[2] << endl;
	}
	
	cout << "In summary: " << bill << endl;
	file.close();
}
vector<string> readRecordFromFile(string fileName, string searchTerm)
{
	vector<string> record;

	ifstream file;
	file.open(fileName);

	bool foundRecord = false;

	string id_;
	string name_;
	string price_;
	string ingr_;

	const char SEPARATOR = '|';

	while (getline(file, id_, SEPARATOR) && !foundRecord)
	{
		getline(file, name_, SEPARATOR);
		getline(file, price_, SEPARATOR);
		getline(file, ingr_, '\n');
		if (id_ == searchTerm)
		{
			foundRecord = true;
			record.push_back(id_);
			record.push_back(name_);
			record.push_back(price_);
			record.push_back(ingr_);
		}
	}

	return record;
}
