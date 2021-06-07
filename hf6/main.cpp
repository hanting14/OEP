#include <iostream>
#include "recipeEnor.hpp"
#include "mostIngredient.hpp"

using namespace std;

int main()
{
	MostIngredient mi;	
	RecipeEnor re("inp.txt");
	mi.addEnumerator(&re);
	mi.run();
	cout << mi.optElem().recipe << "-nak volt a legtobb hozzavaloja: " << mi.opt() << endl;
	return 0;
}
