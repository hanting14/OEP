#pragma once
#include "gtlib/enumerator.hpp"
#include "gtlib/seqinfileenumerator.hpp"
#include "recipe.hpp"
#include "recipeCount.hpp"


class RecipeEnor : public Enumerator<RecipeType>
{
	private:
		SeqInFileEnumerator<Line> fileEnor;
		bool _end;
		RecipeType dx;	
	public:
		RecipeEnor(const std::string& fileName) : fileEnor(fileName) {}
		virtual void first() override { fileEnor.first(); next(); }
		virtual void next() override 
		{
			_end = fileEnor.end();
			if (!_end)
			{
				dx.recipe = fileEnor.current().recipe;
				//itt példányosítanunk kell egy összegzést, hogy összesítsük az egy tanuló adatait
				RecipeCount rc(fileEnor.current().recipe);
				rc.addEnumerator(&fileEnor);
				rc.run();
				dx.ingredients = rc.result();
			}
		}	
		virtual bool end() const override { return _end; }
		virtual RecipeType current() const override { return dx; }
};
