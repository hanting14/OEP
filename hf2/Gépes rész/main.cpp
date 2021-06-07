#include "Enor.h"
#include <iostream>

using namespace std;

int main()
{
	Enor t("inp.txt");
	t.first();
	Food max = t.current();
	for ( ; !t.end(); t.next() )
	{
		if (max.ingredients < t.current().ingredients)
		{
			max = t.current();
		}
	}
	cout << max.name << "-nek van a legtobb hozzavaloja.";
	return 0;
}