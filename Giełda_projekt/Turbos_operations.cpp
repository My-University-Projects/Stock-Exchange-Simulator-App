#include "Turbos_operations.h"

void TurbosOperations::show_list(unique_ptr<list<Turbo>>& Turbos_list)
{
	cout << "Certyfikaty Turbo: " << endl;
	list<Turbo>::iterator i = Turbos_list->begin();
	for (i; i != Turbos_list->end(); i++)
	{
		cout << i->count << ". " << i->name << " \t" << i->type << " \t" << "aktualny kurs: \t  " << i->current_value << "zl \t " << "wysokosc dzwigni:\t" << i->lever << endl << endl;
	}
}