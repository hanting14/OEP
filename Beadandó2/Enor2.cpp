#include "Enor2.h"
#include <sstream>
#include <iostream>

using namespace std;

Enor2::Enor2(const std::string &str)
{
    f.open(str);
	filename = str;
    if(f.fail()) throw MissingInputFile;
}

void Enor2::next()
{
	Enor t(filename);
	t.first();
	for (int i = count; i > 0; i--)
	{
		if (t.end())
		{
			_end = true;
		}
		else { t.next(); }
	}
	cur.contest = t.current().contest;
	cur.fish = t.current().fish;
	int i;
	do
	{
		i = count;
		checkContest(i, cur.contest);
		if (i > 1)
		{
			t.next();
			cur.contest = t.current().contest;
			cur.fish = t.current().fish;
			count++;
		}
		if (t.end()) { _end = true; }
	}while(i>1 && !t.end());
	if (!_end)
	{
		for (t.next(); !t.end(); t.next() )
		{
			if (cur.contest == t.current().contest)
			{
				cur.fish += t.current().fish;
			}
		}
		count++;
	}
}

void Enor2::checkContest(int &i, std::string contest)
{
	Enor tt(filename);
	tt.first();
	while (i > 0 && tt.current().contest != contest)
	{
		tt.next();
		i--;
	}
}