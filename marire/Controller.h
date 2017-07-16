#pragma once
#include "Repo.h"
class Controller {
	Repo& r;
public:
	//constructor
	Controller(Repo& r) :r{ r } {};
	void add(Joc& j) {
		//adaugare joc
		r.add(j);
	}
	void modify(Joc& j) {
		//modificare joc
		r.modify(j);
	}
	vector<Joc>& getAll() {
		//returneaza lista de jocuri sortata
		sort(r.getAll().begin(), r.getAll().end(), [](Joc& j1, Joc& j2) {return j1.getStare() < j2.getStare(); });
		return r.getAll();
	}
	Joc& findIt(int id) {
		//gaseste un joc dupa id
		auto it = find(r.getAll().begin(), r.getAll().end(), Joc{ id,"","","" });
		if (it != r.getAll().end())
			return *it;
	}
	static void teste() {
		Repo r{ "testRepo.txt" };
		Controller ctr{ r };
		ctr.add(Joc{ 1,"a","b","c" });
		assert(ctr.getAll()[0].getId() == 1);
	}
};