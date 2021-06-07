#include <iostream>
#include "pisti.hpp"
#include <time.h>

using namespace std;

#define NORMAL_MODE
#ifdef NORMAL_MODE

int main()
{
	try
	{
		Pisti p("input.txt");
		p.run();
	}
	catch(...)
	{
		cout << "Nem lehet megtalalni az input fajlt." << endl;
	}
	return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("empty input file", "test0.txt")
{
	Pisti p("test0.txt");
	CHECK(p.pets().size() == 0);
}

TEST_CASE("one dead pet", "test1.txt")
{
	Pisti p("test1.txt");
	CHECK(p.pets()[0]->hp() == 0);
	p.run();
	CHECK(p.pets()[0]->hp() == 0);
}

TEST_CASE("one good day", "test2.txt")
{
	Pisti p("test2.txt");
	CHECK(p.pets()[0]->hp() == 5);
	CHECK(p.pets()[1]->hp() == 5);
	CHECK(p.pets()[2]->hp() == 5);
	p.run();
	CHECK(p.pets()[0]->hp() == 8);
	CHECK(p.pets()[1]->hp() == 7);
	CHECK(p.pets()[2]->hp() == 6);
}

TEST_CASE("one normal day", "test3.txt")
{
	Pisti p("test3.txt");
	CHECK(p.pets()[0]->hp() == 4);
	CHECK(p.pets()[1]->hp() == 4);
	CHECK(p.pets()[2]->hp() == 4);
	p.run();
	CHECK(p.pets()[0]->hp() == 7);
	CHECK(p.pets()[1]->hp() == 3);
	CHECK(p.pets()[2]->hp() == 1);
}

TEST_CASE("one bad day", "test4.txt")
{
	Pisti p("test4.txt");
	CHECK(p.pets()[0]->hp() == 4);
	CHECK(p.pets()[1]->hp() == 4);
	CHECK(p.pets()[2]->hp() == 4);
	p.run();
	CHECK(p.pets()[0]->hp() == 0);
	CHECK(p.pets()[1]->hp() == 1);
	CHECK(p.pets()[2]->hp() == 0);
}

TEST_CASE("one normal day with spirit lift", "test5.txt")
{
	Pisti p("test5.txt");
	CHECK(p.pets()[0]->hp() == 5);
	CHECK(p.pets()[1]->hp() == 5);
	CHECK(p.pets()[2]->hp() == 5);
	p.run();
	CHECK(p.pets()[0]->hp() == 8);
	CHECK(p.pets()[1]->hp() == 7);
	CHECK(p.pets()[2]->hp() == 6);
}

TEST_CASE("one bad day with spirit lift", "test6.txt")
{
	Pisti p("test6.txt");
	CHECK(p.pets()[0]->hp() == 5);
	CHECK(p.pets()[1]->hp() == 5);
	CHECK(p.pets()[2]->hp() == 5);
	p.run();
	CHECK(p.pets()[0]->hp() == 8);
	CHECK(p.pets()[1]->hp() == 4);
	CHECK(p.pets()[2]->hp() == 2);
}
#endif