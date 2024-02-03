/*
 * item.cpp
 *
 *  Created on: 03-Feb-2024
 *      Author: giris
 */

#include "Item.h"

using namespace std;

Item::Item(std::string name, std::string shop, std::time_t until)
: name(name), shop(shop), until(until)
{
}

Item::~Item()
{
}

std::string Item::getName() const
{
	return this->name;
}

std::string Item::getShop() const
{
	return this->shop;
}

std::time_t Item::getUntil() const
{
	return this->until;
}

std::string Item::toString() const
{
	return ("Item;" + this->name + ";" + this->shop + ";" + to_string(this->until));
}

std::set<std::string> Item::getNotes() const
{
	set<string> data;
	return data;
}

void Item::save(std::ostream &to) const
{
	to << "Item;" << this->name << ";" << this->shop << ";" << this->until;
}

Item* Item::restore(std::string line)
{
	extern string splitAt(string& remainder, char separator);

	string type = splitAt(line, ';');
	string name = splitAt(line, ';');
	string shop = splitAt(line, ';');
	string untilStr = splitAt(line, '\n');

	if(boost::algorithm::icontains(type, "Item"))
	{
		Item* newItem = new Item(name, shop, static_cast<time_t>(stoi(untilStr)));

		return newItem;
	}
	else
	{
		return nullptr;
	}
}
