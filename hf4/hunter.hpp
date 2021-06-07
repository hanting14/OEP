#pragma once
#include <vector>
#include "trophy.hpp"
class Hunter
{
private:
	int _age;
	std::string _name;
	std::vector<Trophy*> _trophies;
public:
	Hunter() : _age{}, _name{}, _trophies() {};
	Hunter(int a, std::string n) : _age(a), _name(n) {}
	int age() { return _age; }
	std::string& name() { return _name; }
	std::vector<Trophy*>& trophies() { return _trophies; }
	void AddTrophy(Trophy* t)
	{
		_trophies.push_back(t);
	}
	int Males()
	{
		int counter = 0;
		for (auto i : _trophies)
		{
			if (LionTrophy* l = dynamic_cast<LionTrophy*>(i))
			{
				if (l->sex() == LionGender::MALE)
					counter++;
			}
		}
		return counter;
	}

};