#include <iostream>
#include <string>
#include "seqinfileenumerator.hpp"
#include "counting.hpp"

using namespace std;

struct Student 
{
    string first_name;
    string last_name;
    int birth_year;
	friend istream& operator>>(istream& i, Student& s) 
	{
		i >> s.first_name >> s.last_name >> s.birth_year;
		return i;
	}
};

class Student_count : public Counting<Student> 
{
    bool cond(const Student& s) const override 
	{
		return s.last_name[0] == 'C' && s.birth_year > 2000;
    }
};

int main() 
{
    Student_count sc;
    SeqInFileEnumerator<Student> enor("input.txt");
    sc.addEnumerator(&enor);
    sc.run();
    cout << sc.result();
}
