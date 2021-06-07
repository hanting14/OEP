#ifndef ZSAK_H_INCLUDED
#define ZSAK_H_INCLUDED

#include <string>
#include <iostream>
#include <vector>
#include "read.hpp"

inline bool valid(int a){return true;}

struct Item
{
	int value;
	int mult;
	
	Item() {};
	Item(int v,int m):value(v), mult(m) {}
	
	friend std::istream& operator>>(std::istream& s, Item& e)
    {
        e.value=read<int>("Elem:","Egesz szamot kerek!",valid);
        s>>e.value;
        return s;
    }
	
	friend std::ostream& operator<<(std::ostream& s, const Item& e)
    {
        s<<"elofordulasa: "<<e.mult<<" erteke: "<<e.value<<" ";
        return s;
    }
	
	bool operator==(const int& b)
    {
        return (value==b);
    }
	
};

class Bag
{
    public:
        enum BagError{EMPTY_BAG, NOT_CONTAINS};

        void add(int a);
		void pop(int out);
        bool isEmpty() { return _vec.size()==0; }
		int Max() { if(_vec.size() == 0) throw EMPTY_BAG; else return max; }

        friend std::ostream& operator<<(std::ostream& s, const Bag& q);
        int getLength() const { return _vec.size(); }
        int getCapacity() const { return _vec.capacity(); }
        std::vector<Item> getItems() const;

    private:
        std::vector<Item> _vec;
        int max;

};

#endif
