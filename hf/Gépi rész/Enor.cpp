#include "Enor.h"

using namespace std;

Enor::Enor(const string &str)
{
	f.open(str);
	if(f.fail()) throw FILEERROR;
}

void Enor::next()
{	
	_end = (abnorm == _sx);
	if (!_end) {
		_cur.food = _dx.food;
		_cur.income = 0;
		for( ; norm==_sx && _dx.food == _cur.food ; read() )
		{
			_cur.income += _dx.price*_dx.count;
		}
	}
}

void Enor::read()
{
	f >> _dx;
	if ( f.fail() ) _sx = abnorm;
	else _sx= norm;
}