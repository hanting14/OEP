#pragma once
#include "gtlib/summation.hpp"
#include "recipe.hpp"

class RecipeCount : public Summation<Line, int>
{
	private:
		const std::string currentRecipe;
	public:
		RecipeCount(const std::string& recipe) : currentRecipe(recipe) {}
		virtual int func(const Line& e) const override { return 1; }
		virtual int neutral() const override { return 0; }
		virtual int add(const int& a, const int& b) const override { return a+b; }
		virtual bool cond(const Line& e) const override { return currentRecipe == e.recipe; }
		virtual bool whileCond (const Line& e) const override { return currentRecipe == e.recipe; }
		virtual void first() override {}	
};
