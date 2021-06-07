#include <iostream>
#include "menu.h"
#include "read.hpp"
#include <sstream>
#define menudb 6

using namespace std;

bool check(int a){ return a>=0 && a<=menudb; }

void Menu::Run()
{
	int v;
	do
	{
		v = MenuPrint();
		switch(v)
		{
			case 1:
                Zsakba();
                KiirZsak();
                break;
            case 2:
                Zsakbol();
                KiirZsak();
                break;
			case 3:
                Legnagyobb();
                KiirZsak();
                break;	
            case 4:
                Urese();
                KiirZsak();
                break;
            case 5:
                KiirZsak();
                break;
            case 6:
                TerhelesTeszt();
                break;
            default:
                cout << "\nViszontlatasra!\n";
                break;
		}
		
	}while(v != 0);
}

int Menu::MenuPrint()
{
    int valasz;
    cout << "\n****************************************\n";
    cout << "0. Kilepes\n";
    cout << "1. Zsakba berak\n";
    cout << "2. Zsakbol kivesz\n";
	cout << "3. Legnagyobb elem kiirasa\n";
    cout << "4. Ures-e vizsgalat\n";
    cout << "5. Zsakot kiir\n";
    cout << "6. Terheles teszt (mennyi elemet tudunk a zsakba tenni)\n";
    cout << "****************************************\n";
    ostringstream s;
    s << "0 es " << menudb << " kozotti egesz szam legyen!";
    string errmsg = s.str();
    valasz = read<int>("Valasztas:",errmsg,check);

    return valasz;
}

void Menu::Zsakba()
{
    int e;
    cout << "Mit tegyunk be?\n";
    cin >> e;
    Q.add(e);
}

void Menu::Zsakbol()
{
	cout << "Mit vegyunk ki?\n";
    int e;
	int f;
	cin >> f;
    bool hiba = false;
    try
	{
        Q.pop(f);
    }
	catch(Bag::BagError err)
    {
        hiba = true;
        if(err == Bag::EMPTY_BAG)
            cerr << "A kiveves nem sikerult! A zsak ures!\n";
	   else if(err == Bag::NOT_CONTAINS)
            cerr << "A kiveves nem sikerult! A zsak nem tartalmazza az elemet!\n";
        else
            cerr << "Programhiba, forduljon a program keszitojehez :-))\n";
    }
    if(!hiba) cout << "A kiveves sikeres volt.\n";
}

void Menu::Legnagyobb()
{
	bool hiba = false;
	try
	{
		Q.Max();
		
	}
	catch(Bag::BagError err)
	{
		hiba = true;
		if(err == Bag::EMPTY_BAG)
            cerr << "A kiveves nem sikerult! A zsak ures!\n";
        else
            cerr << "Programhiba, forduljon a program keszitojehez :-))\n";
	}
	if(!hiba) cout << "Zsak legnagyobb eleme: " << Q.Max() << endl;
	
}

void Menu::Urese()
{
    if(Q.isEmpty())
        cout << "A zsak ures.\n";
    else
        cout << "A zsak nem ures.\n";
}

void Menu::KiirZsak()
{
    cout << Q;
}

void Menu::TerhelesTeszt()
{
    const int meret = 100000;
    Bag Q;
    cout << "A zsak pillanatnyi elemszamat kovetheti:\n";
    try{
        for(int i=1; i<meret; ++i)
        {
            if(i % 10000 == 0) cout << i << endl;
            Q.add(i);
        }
    }catch(...)
    {
        cerr<<"Elfogyott a szabad memoria!\n";
        cerr<<"A vector merete: " << Q.getCapacity() << endl;
    }
}
