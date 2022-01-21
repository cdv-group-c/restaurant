#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdio>

/*Robisz zarz¹dzanie ca³ym stanem zamówienia:
wczytanie z pliku, *
funkcje do dodawania i usuwania pozycji z zamówienia na podstawie id,
które wyœle Ci Adrian, zliczanie ceny i zapis zamówienia do pliku.*/

using namespace std;
int id;
int bill_i = 0;
float bill = 0;

vector<string> readRecordFromFile(string file_name, string search_term);



void print_menu()
{
	for (int i = 1; i <= 5; i++) {
		string str = to_string(i);
		vector<string> data = readRecordFromFile("menu.csv", str);
		cout << "Id: " << data[0] << " | name: " << data[1] << " | price: " << data[2] << endl;

	}
}

void add_to_bill()
{
	cin >> id;
	string str = to_string(id);
	vector<string> data = readRecordFromFile("menu.csv", str);
	fstream file;
	file.open("bill.txt", ios::out | ios::app);
	file << data[0] << "," << data[1] << "," << data[2] << endl;
	bill += stof(data[2]);
	bill_i += 1;
	file.close();
}

void remove_from_bill()
{
	string line;
	string rm;

	cin >> id;

	string str = to_string(id);
	vector<string> data = readRecordFromFile("menu.csv", str);
	rm = "Id: " + data[0] + " | name: " + data[1] + " | price: " + data[2] + "\n";

	cout << rm << endl;
	bill -= stof(data[2]);
	bill_i -= 1;

	ifstream in("bill.txt");
	ofstream out("bill_temp.txt");

	while (getline(in, line))
	{
		cout << line;
		cout << rm;
		if (line != rm)
			out << line << "\n";
	}
	in.close();
	out.close();

	remove("bill.txt");
	rename("bill_temp.txt", "bill.txt");
}

void print_bill()
{
	for (int i = 1; i <= bill_i; i++) {
		string str = to_string(i);
		vector<string> data = readRecordFromFile("menu.csv", str);
		cout << "Id: " << data[0] << " | name: " << data[1] << " | price: " << data[2] << endl;


	}
	cout << "In summary: " << bill << endl;
}
void cash_bill()
{
	fstream file;
	file.open("bill.txt", ios::out | ios::app);
	file << "In summary: " << bill << endl;
	for (int i = 1; i <= bill_i; i++) {
		string str = to_string(i);
		vector<string> data = readRecordFromFile("menu.csv", str);
		cout << "Id: " << data[0] << " | name: " << data[1] << " | price: " << data[2] << endl;
	}
	cout << "In summary: " << bill << endl;
	file.close();
}



int main()
{
	int x;
	print_menu();
	bool warunek = false;
	while (!warunek) {
		cout << endl;
		cout << "1. Dodaj" << endl;
		cout << "2. usun" << endl;
		cout << "3. wyswietl" << endl;
		cout << "4. zaplac" << endl;
		cout << "5. exit" << endl;

		cin >> x;

		switch (x) {
		case 1: add_to_bill(); break;
		case 2: remove_from_bill(); break;
		case 3: print_bill(); break;
		case 4: cash_bill(); break;
		case 5: warunek = true; break;
		};
	}
	return 0;

}vector<string> readRecordFromFile(string file_name, string search_term)
{
	vector<string> record;


	//int num= stoi(string);
	//int num=69;
	//string str = to_string(num);
	ifstream file;
	file.open(file_name);

	bool found_record = false;

	string id_;
	string name_;
	string price_;

	while (getline(file, id_, ',') && !found_record)
	{
		getline(file, name_, ',');
		getline(file, price_, '\n');
		if (id_ == search_term)
		{
			found_record = true;
			record.push_back(id_);
			record.push_back(name_);
			record.push_back(price_);
		}

	}

	return record;


}
