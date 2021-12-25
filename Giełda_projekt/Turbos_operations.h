#pragma once
#include "Stock.h"
#include"Turbo.h"

/*
* Class representanting operations on turbos list
*/
class TurbosOperations
{
public:

	/*
	* Method that prints turbos list at the console output
	* @param pointer to the turbos list
	*/
	static void showList(unique_ptr<list<Turbo>>& Turbos_list);

};

