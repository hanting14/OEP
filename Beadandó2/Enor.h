#pragma once

#include <fstream>

struct Line
{
	std::string angler;
    std::string contest;
    int fish;
};

struct ContestType
{
	std::string contest;
	int fish;
};

class Enor
{
    private:
        std::ifstream f;
        Line cur;
        bool _end;
    public:
        enum FileError{MissingInputFile};
        Enor(const std::string &str);
        void first() { next(); }
        void next();
        Line current() const { return cur; }
        bool end() const { return _end; }
};