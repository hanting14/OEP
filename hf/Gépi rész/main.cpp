#include <iostream>

#include "Enor.h"

using namespace std;

int main()
{
	Enor t("inp.txt");

	Item max;
	bool first = true;
	for( t.first(); !t.end(); t.next() )
	{
		if (first)
		{
			first = false;
			max = t.current();
		}
		if (t.current().income > max.income)
		{
			max = t.current();
		}
		//cout << t.current() << endl;
	}
	cout << max;
	return 0;
}