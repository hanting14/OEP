#include "Enor.h"

Enor::Enor(const std::string &str)
{
	f.open(str);
	if(f.fail()) throw FILEERROR;
}

void Enor::next()
{
	_end = (sx == abnorm);
	if (!_end)
	{
		cur.name = dx.name;
		cur.ingredients = 0;
		for ( ; norm == sx && cur.name == dx.name; read() )
		{
			cur.ingredients++;
		}
	}
}

void Enor::read()
{
	f >> dx;
	if ( f.fail() ) sx = abnorm;
	else sx = norm;
}