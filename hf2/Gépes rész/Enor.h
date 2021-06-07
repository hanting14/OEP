#pragma once

#include <fstream>

struct Line
{
	std::string name;
	std::string ingredient;
	int quantity;
	std::string unit;
};

struct Food
{
	std::string name;
	int ingredients;
};

inline std::istream& operator>>(std::istream& is, Line& x)
{
    is >> x.name >> x.ingredient >> x.quantity >> x.unit;
    return is;
}

class Enor
{
	public:
		enum Errors { FILEERROR };
		enum Status { abnorm, norm };
		Enor(const std::string &str);
		void first() { read(); next(); }
		void next();
		Food current() const { return cur; }
		bool end() const { return _end; }
	private:
		std::ifstream f;
		Line dx;
		Status sx;
		Food cur;
		bool _end;
		void read();
};