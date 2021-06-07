#pragma once

#include <fstream>
#include "Enor.h"

struct Contest
{
    std::string contest;
    int fish;
};

class Enor2
{
    private:
	    std::ifstream f;
        Contest cur;
		int count = 0;
		std::string filename;
		bool _end = false;
    public:
        enum FileError{MissingInputFile};
        Enor2(const std::string &str);
        void first() { next(); }
        void next();
        Contest current() const { return cur; }
		bool end() const { return _end; }
		void checkContest(int &i, std::string contest);
};