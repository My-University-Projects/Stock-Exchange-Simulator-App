#include "ETF_operations.h"

void ETFOperations::showList(unique_ptr<list<ETF>>& ETF_list)
{
	cout << "Akcje: \n";
	list<ETF>::iterator i = ETF_list->begin();
	for (i; i != ETF_list->end(); i++)
	{
		cout << i->count << ". " << i->name << " \t " << "aktualny kurs: \t " << i->currentValue << "zl" << endl << endl;
	}
}