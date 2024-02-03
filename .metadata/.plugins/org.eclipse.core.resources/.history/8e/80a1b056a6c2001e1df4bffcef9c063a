/*
 * ShoppingList.h
 *
 *  Created on: 03-Feb-2024
 *      Author: giris
 */

#ifndef SHOPPINGLIST_H_
#define SHOPPINGLIST_H_

#include <string>
#include <memory>
#include <vector>
#include <map>
#include "Item.h"

class ShoppingList
{
private:
	std::map<std::string, std::vector<std::unique_ptr<Item>>> items;

public:
	ShoppingList& operator+= (Item* item);

	void print(std::time_t until) const;

	void save(std::ostream& to) const;

	void load(std::istream& from);
};

#endif /* SHOPPINGLIST_H_ */
