/*
 * Food.cpp
 *
 *  Created on: 03-Feb-2024
 *      Author: giris
 */

#include "Food.h"

using namespace std;

Food::Food(std::string name, std::string shop, std::time_t until,
		bool needsCooling) : Item(name, shop, until), needsCooling(needsCooling)
{
}

Food::~Food()
{
}

bool Food::getNeedsCooling() const
{
	return this->needsCooling;
}

std::set<std::string> Food::getNotes() const
{
	if(needsCooling == false)
	{
		return set<string>();
	}

	set<string> result;

	result.insert("one or more items require cooling");
	return result;
}

std::string Food::toString() const
{
	string itemString = Item::toString();

	string foodString;

	if(needsCooling == true)
	{
		foodString = itemString + "[Keep cool!]";
	}

	return foodString;
}

void Food::save(std::ostream &to) const
{
	to << "Food;" << getName() << ";" << getShop() << ";" << to_string(getUntil())
			<< ";" << to_string(this->needsCooling);
}

Food* Food::restore(std::string line)
{
	extern string splitAt(string& remainder, char separator);

	string type = splitAt(line, ';');
	string name = splitAt(line, ';');
	string shop = splitAt(line, ';');
	string untilStr = splitAt(line, ';');
	bool needsCooling = (splitAt(line, '\n') == "true") ? true : false;

//	cout << "type: " << type << " name: " << name << " shop: " << shop << " until: "
//			<< untilStr << " needs: " << needsCooling << endl;

	if(boost::algorithm::icontains(type, "Food"))
	{
		Food* newfood = new Food(name, shop, static_cast<time_t>(stol(untilStr)), needsCooling);

		return newfood;
	}
	else
	{
		return nullptr;
	}
}
