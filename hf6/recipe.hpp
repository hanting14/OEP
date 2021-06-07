#pragma once

struct Line
{
	std::string recipe;
	std::string ingredient;
	int quantity;
	std::string unit;
	friend std::istream& operator>>(std::istream& is, Line& l)
	{
		is >> l.recipe >> l.ingredient >> l.quantity >> l.unit;
		return is;
	}
};

struct RecipeType
{
	std::string recipe;
	int ingredients;
};
