#pragma once

#include <fstream>

struct Line 
{
	int id;
	std::string food;
	std::string time;
	int count;
	int price;
};

struct Item
{
	std::string food;
	int income;
};

inline std::istream& operator>>(std::istream& is, Line& x)
{
    is >> x.id >> x.food >> x.time >> x.count >> x.price;
    return is;
}

inline std::ostream& operator<<(std::ostream& os, const Item& e) 
{
	os << "Etel: " << e.food << ", bevetele: " << e.income;
	return os;
}

class Enor
{
	public:
		enum Errors { FILEERROR };
		enum Status { abnorm, norm };
		Enor(const std::string &str);
		void first() { read(); next(); }
		void next();
		Item current() const { return _cur; }
		bool end() const { return _end; }
	private:
		std::ifstream f;
		Status _sx;
		Line _dx;
		Item _cur;
		bool _end;
		void read();
};