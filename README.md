# ShoppingList_SoSe2020

## Class Item

![ShoppingList_UML](https://github.com/GirishTabaraddi/ShoppingList_SoSe2020/blob/feature/add-repo/ShoppingList_UML.png)

1.1 Header file

/**
* A shopping list item. Items have a name, they must be bought at
* a particular shop (bread at the bakery, meat from a butcher etc.),
* and they are required until a particular date/time. (In reality, some
* items can be bought at several places --meat from the butcher or from
* the super market-- but this isn't modelled here.)
*/\
class Item  
{  
private:  
    std::string name;  
    std::string shop;  
    std::time_t until;  
public:  
	/**  
	* Create a new item with the given properties.   
	*/ 
	Item(std::string name, std::string shop, std::time_t until);  
	virtual ~Item();  
	std::string getName() const;  
	std::string getShop() const;  
	std::time_t getUntil() const;  
	/**  
	* Special kinds of items (see class Food) may require one or more  
	* notes to be appended to the shopping list. This function returns  
	* the notes required by an item.  
	*/  
	virtual std::set<std::string> getNotes() const;  
	/**  
	* Returns a string with the name of the item followed by the shop  
	* in parenthesis.  
	*/  
	virtual std::string toString() const;  
	/**  
	* Writes to the given ostream the string "Item;" and then  
	* all attributes separated by semicolon and a final newline.  
	* Example: Item;Soap;Drug store;6597989  
	*/  
	virtual void save(std::ostream& to) const;  
	/**  
	* Creates a new instance on the heap, using the values from  
	* the given string. The string must have the format used by  
	* method save. If the string does not start with "Item;", a  
	* nullptr is returned. (Use function splitAt in main for the  
	* implementation.)  
	*/  
	static Item* restore(std::string line);  
	};  
	std::ostream& operator << (std::ostream& lhs, const Item& item);  

## Class FoodItem  

2.1 Header file  

/**  
* Food is a special item. What makes it special is that it may require  
* cooling (in summer) during transport.  
*/  
class Food: public Item   
{  
private:  
	bool needsCooling;  
public:  
	/**  
	* Creates a new food item with the given properties.  
	*/  
	Food(std::string name, std::string shop, std::time_t until,  
	bool needsCooling);  
	bool getNeedsCooling() const;  
	/**  
	* Returns a set containing a string that indicates the requirement  
	* for cooling during transport if the "needsCooling" flag is set.  
	*/  
	std::set<std::string> getNotes() const;  
	/**  
	* Calls the base class's toString() method and returns the result.  
	* If needsCooling is set, appends " [Keep cool!]" before returning  
	* the result.  
	*/  
	virtual std::string toString() const;  
	/**  
	* Writes to the given ostream the string "Food;" and then  
	* all attributes separated by semicolon and a final newline.  
	* Example: Item;Steak;Butcher;6597989;true  
	*/  
	virtual void save(std::ostream& to) const;  
	/**  
	* Creates a new instance on the heap, using the values from  
	* the given string. The string must have the format used by  
	* method save. If the string does not start with "Food;", a  
	* nullptr is returned. (Use function splitAt in main for the  
	* implementation.)  
	*/  
	static Food* restore(std::string line);  
};  

2.2 Implementation

// Task 1: Provide constructor implementation (2 points)  
Food::Food(string name, string shop, time_t until, bool needsCooling)  
{  
}  

bool Food::getNeedsCooling() const  
{  
        return needsCooling;  
}  

set<string> Food::getNotes() const  
{  
	if (!needsCooling)  
	{
		return set<string>();  
	}  
	set<string> result;  
	result.insert("One or more items require cooling!");  
	return result;  
}  

// Task 2: Provide toString implementation (4 points)  
string Food::toString() const   
{  
}  

// Task 3: Provide implementation of save (5 points)  
void Food::save(ostream& to) const   
{  
}  

// Task 4: Provide implementation of restore (8 points)  
Food* Food::restore(string line)   
{  
	extern string splitAt(string& remainder, char separator);  
}  

## Class ShoppingList  

3.1 Header file  

class ShoppingList  
{  
private:  
	std::map<std::string, std::vector<std::unique_ptr<Item>>> items;  

public:  
	/**  
	* Adds the given item to the shopping list. The item must  
	* have been allocated on the heap. The shopping list is  
	* responsible for removing it from the heap when it goes  
	* out of existence.  
	*/  
	ShoppingList& operator+= (Item* item);   
	/**  
	* Print all items from the shopping list which must be bought  
	* until the given time. The output is grouped by shops. At the  
	* end of the output all collected notes from the items are  
	* printed. Identical notes are printed only once. Example:  
	*  
	* Shopping List:  
	* * Butcher:  
	* - Steak (Butcher) [Keep cool!]  
	*  
	* * Drug store:  
	*  
	* * Super market:  
	* - Milk (Super market) [Keep cool!]  
	* - Rice (Super market)  
	*  
	* Notes:  
	* [1] One or more items require cooling!  
	*/  
	void print(std::time_t until) const;  
	/**  
	* Writes to the given ostream all items by invoking their  
	* save method.  
	*/  
	void save(std::ostream& to) const;  
	/**   
	* Reads from the given istream all items by invoking the  
	* different types' restore methods until a valid pointer  
	* to an object (not a nullptr) is returned.  
	*/  
	void load(std::istream& from);  
};  

3.2 Implementation

// Task 5: Provide implementation of operator += (3 points)  
ShoppingList& ShoppingList::operator +=(Item *item)   
{  
}  

// Task 6: Provide implementation of print (15 points)  
void ShoppingList::print(time_t until) const   
{  
	// Hint: use a set to collect all notes from the various items  
	// and print its content at the end.  
}  

// Task 7: Provide implementation of save (3 points)  
void ShoppingList::save(std::ostream& to) const   
{  
}  

// Task 8: Provide implementation of load (10 points)   
void ShoppingList::load(std::istream &from)   
{  
}  

## File main.cpp


// Main program
int main (void) 
{
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
	reloaded.print(inThreeDays);

	return 0;
}
