#include <iostream>
#include "state.hpp"
#include "delivery.hpp"
#include "menu.hpp"
#include "summary.hpp"

using namespace std;

int main()
{
	string userName;
	int tableNumber;
	bool insideOrTakeaway;
	string address;
	string preferredDeliveryTime;



	cout << "========================" << endl;
	cout << "Witamy w restauracji xyz" << endl;
	cout << "========================" << endl;

	userName = getUserName();

	
	insideOrTakeaway = getInsideOrTakeaway();


	if (!insideOrTakeaway)
	{
	  tableNumber = getTableNumber();
	}
	else
	{
	  address = getAddress();
	  preferredDeliveryTime = getPreferredDeliveryTime();
	}
	
	cout << preferredDeliveryTime;
}

