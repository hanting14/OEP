#include "Enor.h"
#include <sstream>

using namespace std;

Enor::Enor(const std::string &str)
{
    f.open(str);
    if(f.fail()) throw MissingInputFile;
}

void Enor::next()
{
    string line;
    getline(f , line);
    if( !(_end = f.fail()) )
	{
        istringstream is(line);
		is >> cur.angler >> cur.contest;
		if (!is.fail())
		{
			cur.fish = 0;
			string fish;
			int size;
			for( is >> fish >> size ; !is.fail(); is >> fish >> size )
			{
				cur.fish++;
			}
		}
		else
		{
			cur.fish = -1;
		}
    }
}