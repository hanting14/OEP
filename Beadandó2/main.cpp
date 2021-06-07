#include <iostream>
#include "Enor.h"
#include "Enor2.h"

using namespace std;

bool first_task(const string &name, Line &e)
{
    Enor t(name);
	bool l = false;
	t.first();
	Line max = t.current();
    for(; !t.end(); t.next())
	{
        if (t.current().fish >= max.fish)
		{
			max = t.current();
			l = true;
		}
    }
	if (max.fish <= 0)
	{
		l = false;
	}
	e = max;
    return l;
}

bool second_task(const std::string& name, int &null_fish)
{
	Enor2 t(name);
	bool l = false;
	null_fish = 0;
	int i = 0;
	for (t.first(); !t.end(); t.next()) 
	{
		if (t.current().fish == 0)
		{
			null_fish++;
		}
		i++;
	}
	if (null_fish > 0)
	{
		l = true;
	}
	return l;
}

#define NORMAL_MODE
#ifdef NORMAL_MODE

int main()
{
	string filename;
    cout << "Adja meg a fajl nevet: ";
	cin >> filename;

    //First task
    cout << "Elso feladat\n";
    try 
	{
        Line e;
        if(first_task(filename, e))
		{
            cout << e.angler << " fogott " << e.fish << " halat a " << e.contest << " versenyen." << endl;
        }
		else
		{
            cout << "Egyik versenyen sem fogtak egy halat sem.\n";
        }
    }
	catch(Enor::FileError err)
    {
        cerr << "Nem lehet talalni a " << filename << " fajlt." << endl;
    }
	cout << "Masodik feladat\n";
	try 
	{
		int null_fish;
		if (second_task(filename, null_fish))
		{
			cout << null_fish << " versenyen nem fogtak egy halat sem.\n";
		}
		else
		{
			cout << "Minden versenyen fogtak legalabb egy halat.\n";
		}
	}
	catch (Enor::FileError err)
	{
        cerr << "Nem lehet talalni a " << filename << " fajlt." << endl;
	}
	return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Enor.h"

TEST_CASE("both tasks, empty file", "t0.txt") 
{
    Line e;
	int null_fish;
    CHECK_FALSE(first_task("t0.txt", e));
	CHECK_FALSE(second_task("t0.txt", null_fish));
}

TEST_CASE("first task, no fish", "t1.txt") 
{
    Line e;
    CHECK_FALSE(first_task("t1.txt", e));
}

TEST_CASE("first task, first one caught the most", "t2.txt") 
{
    Line e;
    CHECK(first_task("t2.txt", e));
	CHECK(e.angler == "JANIBA");
}

TEST_CASE("first task, last one caught the most", "t3.txt") 
{
    Line e;
    CHECK(first_task("t3.txt", e));
	CHECK(e.angler == "KARIBA");
}

TEST_CASE("second task, all contest with fish", "t4.txt") 
{
	int null_fish;
    CHECK_FALSE(second_task("t4.txt", null_fish));
}

TEST_CASE("second task, one contest with no fish", "t5.txt") 
{
	int null_fish;
    CHECK(second_task("t5.txt", null_fish));
	CHECK(null_fish == 1);
}

TEST_CASE("second task, all contest with no fish", "t6.txt") 
{
	int null_fish;
    CHECK(second_task("t6.txt", null_fish));
	CHECK(null_fish == 3);
}
#endif

