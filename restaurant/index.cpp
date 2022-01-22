#include <iostream>
#include <vector>
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
  showRestaurantName();

  string userName = getUserName();

  bool isTakeaway = getInsideOrTakeaway();

  if (!isTakeaway)
  {
    tableNumber = getTableNumber();
  }
  else
  {
    address = getAddress();
    preferredDeliveryTime = getPreferredDeliveryTime();
  }

  addMeal();
  vector<int> orderedMeals = getOrderedMeals();

  if (isTakeaway)
  {
    showDeliveryDetails(address, preferredDeliveryTime);
  }
  else
  {
    showTableNumber(tableNumber);
  }
  string bill = getBill();

  cout << bill << endl;

  int saveToFile = askForSavingToFile();
  if (saveToFile == 1)
  {
    saveBillToFile(bill);
  }
  showThanksText();
}
