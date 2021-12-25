#pragma once
#include"Stock.h"
#include"ETF.h"

/*
* Class representanting operations on ETFs
*/
class ETFOperations
{
public:

	/*
	* Method that shows ETFs list at the console output
	* @param ponter to the ETFs list
	*/
	static void showList(unique_ptr<list<ETF>>& ETF_list);
	
};

