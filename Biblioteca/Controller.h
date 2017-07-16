#pragma once
#include "Repo.h"
class Controller {
	Repo& r;
public:
	Controller(Repo& r) :r{ r } {};
	void add(Carte& c);
	void dilit(Carte& c);
	int nrAutor(string a)const {
		int i = 0;
		for (const auto& e : r.getAll())
			if (e.getAutor() == a)
				i++;
		return i;
	}
	int nrGen(string g) const{
		int i = 0;
		for (const auto& e : r.getAll())
			if (e.getGen() == g)
				i++;
		return i;
	}
	vector<Carte>& getAll(){
		return r.getAll();
	}
};