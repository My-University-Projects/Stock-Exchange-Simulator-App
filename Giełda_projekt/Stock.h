#pragma once
#include"Person.h"

/*
* Abstact class representanting a stock
*/
class Stock
{
protected:

	friend class Client;
	friend class Menu;
	friend class FilesOperations;
	friend class ETFOperations;

	string name;
	int count;
	int quantity;
	float valueWhenPurchased;
	float currentValue;
	list<float>lastValues;
public:
	
	/*
	* No args constructor
	*/
	Stock(); 

	/*
	* 3- args constructor
	*/
	Stock(string name_, float current_value_, int count_);

	/*
	* 4- args constructor
	*/
	Stock(string name_, float current_value_, int count_, int quantity_); 

	/*
	* 5- args constructor
	*/
	Stock(string name_, float current_value_, int count_, int quantity_, float value_when_purchased_); 

	/*
	* Destructor
	*/
	~Stock();

	/*
	* 
	*/
	virtual void changeCurrentValue(float new_value_);
};
