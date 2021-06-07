#include <iostream>
#include "hunter.hpp"
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));
	Hunter h(42, "Jeff");
	ElephantThrophy e("Asia", "6.9", 100, 10);
	ElephantThrophy f("Africa", "9.14", 500, 56);
	RhinoTrophy r("Asia", "7.4", 250, 24);
	RhinoTrophy p("Africa", "9.14", 300, 32);
	h.AddTrophy(&e);
	h.AddTrophy(&f);
	h.AddTrophy(&r);
	h.AddTrophy(&p);
	for (int i = 0; i < 6; i++)
	{
		if (int r = rand() % 2 == 0)
		{
			LionTrophy* t = new LionTrophy("Africa", "1.12", 666, LionGender::FEMALE);
			h.AddTrophy(t);
		}	
		else
		{
			LionTrophy* t = new LionTrophy("Asia", "4.20", 420, LionGender::MALE);
			h.AddTrophy(t);
		}
	}
	cout << "Vadasz: " << h.name() << ", " << h.age() << " eves." << " Trofeai: " << endl;
	for (Trophy* v : h.trophies())
	{
		cout << "Faj: " << v->species << ",  Helyszin: " << v->location << ",  Datum: " << v->date << ",  Sulya: " << v->weight << " kg,";
		if (ElephantThrophy* e = dynamic_cast<ElephantThrophy*>(v))
			cout << "  Agyaranak hossza: " << e->tusk() << " cm.";
		else if (RhinoTrophy* e = dynamic_cast<RhinoTrophy*>(v))
			cout << "  Szarv sulya: " << e->horn() << ".";
		else if (LionTrophy* e = dynamic_cast<LionTrophy*>(v))
			cout << "  Neme: " << (e->sex() == LionGender::FEMALE ? "nosteny" : "him");
		cout << endl;
	}
	cout << h.Males() << " db him oroszlant lott." << endl;
	
}