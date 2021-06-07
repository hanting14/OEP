#pragma once

class Pet
{
	protected:
		std::string _name;
		int _hp;
	public:
		Pet(std::string x, int y) : _name(x), _hp(y) {}
		virtual void badDay() = 0;
		virtual void normalDay() = 0;
		virtual void goodDay() = 0;
		std::string name() { return _name; }
		int hp() { return _hp; }
};

class Bird : public Pet
{
	public:
		Bird(std::string x, int y) : Pet(x,y) {}
		virtual void badDay() override
		{
			if (_hp - 3 < 0)
				_hp = 0;
			else
				_hp-=3;
		}
		virtual void normalDay() override
		{
			if (_hp - 1 < 0)
				_hp = 0;
			else
				_hp-=1;
		}
		virtual void goodDay() override
		{
			if (_hp + 2 > 100)
				_hp = 100;
			else if (_hp != 0)
				_hp+=2;
		}
};

class Dog : public Pet
{
	public:
		Dog(std::string x, int y) : Pet(x,y) {}
		virtual void badDay() override
		{
			if (_hp - 10 < 0)
				_hp = 0;
			else
				_hp-=10;
		}
		virtual void normalDay() override
		{
			if (_hp + 3 > 100)
				_hp = 100;
			else if (_hp != 0)
				_hp+=3;
		}
		virtual void goodDay() override
		{
			if (_hp + 3 > 100)
				_hp = 100;
			else if (_hp != 0)
				_hp+=3;
		}
};

class Fish : public Pet
{
	public:
		Fish(std::string x, int y) : Pet(x,y) {}
		virtual void badDay() override
		{
			if (_hp - 5 < 0)
				_hp = 0;
			else
				_hp-=5;
		}
		virtual void normalDay() override
		{
			if (_hp - 3 < 0)
				_hp = 0;
			else
				_hp-=3;
		}
		virtual void goodDay() override
		{
			if (_hp + 1 > 100)
				_hp = 100;
			else if (_hp != 0)
				_hp+=1;
		}
};