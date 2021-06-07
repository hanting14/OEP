#pragma once
#include <string>

enum class LionGender { FEMALE, MALE};
class Trophy
{
public:
	std::string species;
	std::string location;
	std::string date;
	int weight;
	Trophy(std::string s, std::string l, std::string d, int w) : species(s), location(l), date(d), weight(w) {}
	virtual ~Trophy() = default;
};

class ElephantThrophy : public Trophy
{
private:
	int tusk_length;
public:
	ElephantThrophy(std::string l, std::string d, int w, int a) : Trophy("elephant", l, d, w), tusk_length(a) {}
	int tusk() { return tusk_length; }
};

class RhinoTrophy : public virtual Trophy
{
private:
	int horn_weight;
public:
	RhinoTrophy(std::string l, std::string d, int w, int a) : Trophy("rhino", l, d, w), horn_weight(a) {}
	int horn() { return horn_weight; }
};
class LionTrophy : public virtual Trophy
{
private:
	LionGender gender;
public:
	LionTrophy(std::string l, std::string d, int w, LionGender g) : Trophy("lion", l, d, w), gender(g) {}
	LionGender sex() { return gender; }
};