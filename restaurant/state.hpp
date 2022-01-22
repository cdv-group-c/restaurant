#ifndef state_hpp
#define state_hpp
using namespace std;
#include <vector>

string getMealsList();
void addToBill(int id, int amountOfMeals);
vector<int> getOrderedMeals();
vector<int> getMealIds();
string getBill();
void removeFromBill(int id);
void saveBillToFile(string content);
double cashBill();

#endif // !state_hpp
