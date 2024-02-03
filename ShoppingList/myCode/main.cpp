// Standard (system) header files
#include <iostream>
#include <cstdlib>

using namespace std;

// Add your project's header files here
#include "Food.h"
#include "ShoppingList.h"

#include <fstream>

string splitAt(string& remainder, char separator)
{
	auto pos = remainder.find(separator);

	string result;

	if(pos != string::npos)
	{
		result = remainder.substr(0, pos);
		remainder = remainder.substr(pos+1);
	}
	else
	{
		result = remainder;
		remainder.clear();
	}

	return result;
}
// Main program
int main ()
{
	cout << "ShoppingList started." << endl << endl;

	ShoppingList list;

	time_t inTwoDays = time(nullptr) + 2 * 24 * 3600;
	time_t inThreeDays = time(nullptr) + 3 * 24 * 3600;

	list += new Item("Paper tissues", "Super market", inThreeDays);
	list += new Food("Milk", "Super market", inTwoDays, true);
	list += new Food("Rice", "Super market", inTwoDays, false);
	list += new Food("Steak", "Butcher", inTwoDays, true);
	list += new Item("Shampoo", "Drug store", inThreeDays);
	list += new Item("Washing powder", "Drug store", inThreeDays);

	list.print(inTwoDays);

	ofstream out("data.txt");
	list.save(out);
	out.close();

	ShoppingList reloaded;

	ifstream in("data.txt");
	reloaded.load(in);

	ofstream out1("data1.txt");
	list.save(out1);
	out1.close();

	reloaded.print(inThreeDays);

	return 0;
}
