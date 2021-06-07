#include <iostream>
#include "benzinkut.hpp"

using namespace std;

int main()
{
	Benzinkut b(1000);
	Autos a(b, 10000);
	if (a.tankol(1, 3, 2))
		cout << "Sikeresen tankolt.\n";
	else
		cout << "Nem volt eleg penze a tankolashoz.\n";
	if (a.tankol(1, 11, 2))
		cout << "Sikeresen tankolt.\n";
	else
		cout << "Nem volt eleg penze a tankolashoz.\n";
	return 0;
}