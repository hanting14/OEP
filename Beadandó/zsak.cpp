#include "zsak.h"

using namespace std;

void Bag::add(int a)
{
	int i = 0;
	while(i<_vec.size() && a != _vec[i].value)
	{
		i++;
	}
	if (i == _vec.size())
	{
		if (_vec.size() == 0)
		{
			max = a;
		}
		else
		{
			if (a > max)
			{
				max = a;
			}
		}
		Item b;
		b.value = a;
		b.mult = 1;
		_vec.push_back(b);
	}
	else
	{
		_vec[i].mult++;
	}
}

void Bag::pop(int out)
{
    if(_vec.size() == 0) throw EMPTY_BAG;
	int i = 0;
	while (i<_vec.size() && _vec[i].value != out)
	{
		i++;
	}
	if (i == _vec.size()) throw NOT_CONTAINS;
	else
	{
		if (_vec[i].mult == 1)
		{
			if (_vec[i] == max)
			{
				_vec.erase(_vec.begin() + i);
				if (_vec.size() != 0)
				{
					max = _vec[0].value;
					for (int j = 0; j<_vec.size(); j++)
					{
						if (_vec[j].value > max)
						{
							max = _vec[j].value;
						}	
					}
				}
			}
			else
			{
				_vec.erase(_vec.begin() + i);
			}
			
		}
		else
		{
			_vec[i].mult--;
		}
	}
}

vector<Item> Bag::getItems() const
{
    vector<Item> v;
    for(int i=0; i<_vec.size(); i++)
        v.push_back(_vec[i]);
    return v;
}

ostream& operator<<(std::ostream& s, const Bag& q)
{
    s << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    s << "Bag jellemzoi:\n";
	int size = 0;
	for (int i = 0; i<q._vec.size(); i++)
	{
		size+=q._vec[i].mult;
	}
    s<<"_vec hossza:"<<q._vec.capacity()<<" Elemszam:"<<size<<"\nTartalma: "<<endl;
    for(int i = 0; i<q._vec.size(); i++){
        s<<" ("<<q._vec[i].value<<","<<q._vec[i].mult<<")";
    }
    s<<"\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n";
    return s;
}