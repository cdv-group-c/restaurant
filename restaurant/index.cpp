#include <iostream>
#include "state.hpp"
#include "delivery.hpp"
#include "menu.hpp"
#include "summary.hpp"

using namespace std;

int main()
{
	int tableNumber;
	string address;
	string preferredDeliveryTime;
	// TODO
	int mealIds[] = { 1, 2, 3, 4, 5 };

	showRestaurantName();

	string userName = getUserName();

	
	bool insideOrTakeaway = getInsideOrTakeaway();


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

	string menu = getMealsList();

	addMeal(mealIds, menu);
	getNextStep(mealIds, menu);

	showDeliveryDetails(address, preferredDeliveryTime);
}

