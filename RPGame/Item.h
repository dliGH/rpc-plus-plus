#pragma once
#include <string>

using std::string;

class Item
{
	protected:
		int id;
		string name;
		string description;
	public:
		Item();
		Item(int i);
		~Item();
		int getID();
		friend class Entity;
		string toString();
};

