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
	string preferredDeliveryTime;

	userName = getUserName();
	cout << userName;
}

