#include <iostream>
#include <vector>
#include "zsak.h"
#include "menu.h"

using namespace std;

#define NORMAL_MODE
#ifdef NORMAL_MODE

int main()
{
	cout << "Zsak" << endl;

    Menu Teszt;
    Teszt.Run();

	return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "zsak.h"


TEST_CASE("isEmpty()","[Bag]")
{
    Bag Q1;
    CHECK( Q1.isEmpty() == true );

	int a = 1;
    Q1.add(a);
    CHECK( Q1.isEmpty() == false );

    Q1.pop(a);
    CHECK( Q1.isEmpty() == true );
}

TEST_CASE("add","[Bag]")
{
    Bag Q;
    int e1 = 1;
	int e2 = 2;
	int e3 = 3;
	int e4 = 4;
	int e5 = 5;
	Q.add(e1);
    CHECK( 1 == Q.getLength());
	Q.add(e2);
	Q.add(e3);
	Q.add(e4);
	Q.add(e5);
    CHECK( 5 == Q.getLength());
    vector<Item> v = Q.getItems();
    CHECK( e1 == v[0].value);
	CHECK( e2 == v[1].value);
	CHECK( e3 == v[2].value);
	CHECK( e4 == v[3].value);
	CHECK( e5 == v[4].value);
}

TEST_CASE("pop","[Bag]")
{
	Bag Q;
    CHECK_THROWS(Q.pop(1));
    int e = 1;
    Q.add(e);
	CHECK_THROWS(Q.pop(0));
	Q.pop(1);
    CHECK( 0 == Q.getLength());
}

TEST_CASE("Max","[Bag]")
{
	Bag Q;
    CHECK_THROWS(Q.Max());
	int e1 = 1;
	int e2 = 2;
	Q.add(e1);
	Q.add(e2);
	CHECK( 2 == Q.Max());
	Q.pop(2);
	CHECK( 1 == Q.Max());
}

#endif