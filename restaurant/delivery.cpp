#include <iostream>
#include <conio.h>

using namespace std;

string getUserName() {

	string userName;

	cout << "Podaj swoje imie" << endl;
	cin >> userName;

	return userName;
}