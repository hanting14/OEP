#pragma once
#include "pet.hpp"
#include <vector>
#include <fstream>

class Pisti
{
	private:
		std::vector<Pet*> _pets;
		std::string _days;
		std::ifstream f;
	public:
		enum FileError{MissingInputFile};
		std::string days() { return _days; }
		std::vector<Pet*> pets() { return _pets; }
		Pisti(const std::string filename) 
		{
			f.open(filename);
			if(f.fail()) throw MissingInputFile;
			int petNumber, hp;
			f >> petNumber;
			std::string species, name;
			for (int i = 0; i<petNumber; i++)
			{
				f >> species >> name >> hp;;
				if (species == "h")
				{
					_pets.push_back(new Fish(name, hp));
				}
				else if (species == "k")
				{
					_pets.push_back(new Dog(name, hp));
				}
				else if (species == "m")
				{
					_pets.push_back(new Bird(name, hp));
				}
			}
			f >> _days;
		}
		void writePets()
		{
			for (auto p : _pets)
			{
				if (Dog* d = dynamic_cast<Dog*>(p))
					std::cout << "Kutya neve: " << d->name() << ", eletkedve: " << d->hp() << std::endl;
				else if (Bird* b = dynamic_cast<Bird*>(p))
					std::cout << "Madar neve: " << b->name() << ", eletkedve: " << b->hp() << std::endl;
				else if (Fish* f = dynamic_cast<Fish*>(p))
					std::cout << "Hal neve: " << f->name() << ", eletkedve: " << f->hp() << std::endl;
			}
		}
		void saddestPets()
		{
			int min = 100;
			for (auto p : _pets)
			{
				if (p->hp() < min && p->hp() > 0)
				{
					min = p->hp();
				}
			}
			std::cout << "Legszomorubb allatok:" << std::endl;
			for (auto p : _pets)
			{
				if (p->hp() == min)
				{
					if (Dog* d = dynamic_cast<Dog*>(p))
						std::cout << "Kutya neve: " << d->name() << ", eletkedve: " << d->hp() << std::endl;
					else if (Bird* b = dynamic_cast<Bird*>(p))
						std::cout << "Madar neve: " << b->name() << ", eletkedve: " << b->hp() << std::endl;
					else if (Fish* f = dynamic_cast<Fish*>(p))
						std::cout << "Hal neve: " << f->name() << ", eletkedve: " << f->hp() << std::endl; 
				}
			}
		}
		bool spiritLift()
		{
			for (auto p : _pets)
			{
				if (p->hp() < 5 && p->hp() > 0)
				{
					return false;
				}
			}
			return true;
		}
		void goodDays()
		{
			std::cout << "Pistinek jo napja volt." << std::endl;
			for (auto p : _pets)
			{
				p->goodDay();
			}
		}
		void normalDays()
		{
			std::cout << "Pistinek atlagos napja volt." << std::endl;
			for (auto p : _pets)
			{
				p->normalDay();
			}
		}
		void badDays()
		{
			std::cout << "Pistinek rossz napja volt." << std::endl;
			for (auto p : _pets)
			{
				p->badDay();
			}
		}
		void run()
		{
			for (int i = 0; i<_days.length(); i++)
			{
				std::cout << i+1 << ".nap: " << std::endl;
				if (_days[i] == 'j')
				{
					goodDays();
				}
				else if (_days[i] == 'a')
				{
					if (spiritLift())
						goodDays();
					else
						normalDays();
				}
				else if (_days[i] == 'r')
				{
					if (spiritLift())
						normalDays();
					else
						badDays();
				}
				writePets();
				std::cout << std::endl;
			}
			saddestPets();
		}
};