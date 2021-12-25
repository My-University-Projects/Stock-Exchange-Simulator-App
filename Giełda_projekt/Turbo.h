#pragma once
#include"Stock.h"


/*
* Class representanting a Turbo certificate
*/
class Turbo : public Stock
{
	friend class Menu;
	friend class FilesOperations;
	friend class TurbosOperations;
	friend class Client;
	string type;
	int lever;
public:
	
	/*
	* 5- args constructor
	*/
	Turbo(string name_, string type_, float current_value_, int lever_, int count_, list<float> last_values_);

	/*
	* 6- args constructor
	*/
	Turbo(string name_, string type_, float current_value_, int lever_, int count_, int quantity_);

	/*
	* 7- args constructor
	*/
	Turbo(string name_, string type_, float current_value_, int lever_, int count_, int quantity_, float value_when_purchased_);

	/*
	* Destructor
	*/
	~Turbo();

	/*
	* Method that changes current value of turbo
	* @param current value
	*/
	void changeCurrentValue(float current_value_) override; 

	/*
	* Function that updates turbo values
	* @param pointer to the turbos list
	* @param bool if thread with this function has to terminate
	*/
	friend void updateTurbosValues(unique_ptr<list<Turbo>>& Turbos_list, bool& flag);
};
