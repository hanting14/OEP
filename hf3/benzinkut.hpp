#pragma once
#include <vector>

class Toltohely
{
	public:
		Toltohely() : kijelzo(0) {}
		int getKijelzo() { return kijelzo; }
		void setKijelzo(int x) { kijelzo = x; }
		void tolt(int liter) { kijelzo += liter; }
	private:
		int kijelzo;
};

class Penztar
{
	public:
		Penztar(int x) : egysegar(x) {}
		bool fizet(Toltohely& toltohely, int& penz) 
		{
			int fizetett = egysegar * toltohely.getKijelzo();
			toltohely.setKijelzo(0);
			penz -= fizetett;
			if (penz > 0)
				return true;
			else
				return false;
		}
	private:
		int egysegar;

};

class Benzinkut
{
	public:
		Benzinkut(int ar) : toltohelyek(6), penztarak(2)
		{
			for (int i = 0; i < 6; ++i)
				toltohelyek[i] = new Toltohely();
			for (int i = 0; i < 2; ++i)
				penztarak[i] = new Penztar(ar);
		}
		enum Errors { OVERINDEXED };
		Toltohely& getToltohely(int i) 
		{
			if (i > 0 && i < 7)
				return *toltohelyek[i];
			else throw OVERINDEXED;
		}
		Penztar& getPenztar(int i)
		{
			if (i > 0 && i < 3)
			{
				--i;
				return *penztarak[i];
			}
			else
				throw OVERINDEXED;
		}
		
	private:
		std::vector<Toltohely*> toltohelyek;
		std::vector<Penztar*> penztarak;
};

class Autos
{
	public:
		Autos(Benzinkut& b, int x) : benzinkut(&b), money(x) {}
		bool tankol(int toltohely_ind, int liter, int penztar_ind)
		{
			penztar = &benzinkut->getPenztar(penztar_ind);
			toltohely = &(benzinkut->getToltohely(toltohely_ind));
			toltohely->tolt(liter);
			if (penztar->fizet(*toltohely, money)) {
				toltohely->setKijelzo(0);
				return true;
			}
			else return false;
		}
	private:
		Benzinkut* benzinkut;
		Toltohely* toltohely;
		Penztar* penztar;
		int money;
};