#pragma once
#include "Stock.h"

/*
* Class representanting ETF certificate
*/
class ETF : public Stock
{
	friend class Menu;
	friend class FilesOperations;
	friend class ETFOperations;
	friend class Client;
public:

	/*
	* No args constructor
	*/
	ETF(); 

	/*
	* 3- args constructor
	*/
	ETF(string name_, float current_value_, int count_, list<float> last_values_);

	/*
	* 4- args constructor
	*/
	ETF(string name_, float current_value_, int count_, int quantity_);

	/*
	* 5- args constructor
	*/
	ETF(string name_, float current_value_, int count_, int quantity_, float value_when_purchased_);

	/*
	* Destructor
	*/
	~ETF();

	/*
	* Method that changes current ETFs value 
	* @param current ETFs value
	*/
	void changeCurrentValue(float current_value_) override;

	/*
	* A function that supports the process of stock price fluctuations
	* @param pointer to the ETFs list
	* @param flag if thread with this function has to terminate
	*/
	friend void updateValues(unique_ptr<list<ETF>>& ETF_list, bool& flag);
};

