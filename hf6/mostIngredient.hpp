#pragma once
#include "gtlib/maxsearch.hpp"

class MostIngredient : public MaxSearch<RecipeType,int> 
{
	virtual int func(const RecipeType& e) const { return e.ingredients; }
};
