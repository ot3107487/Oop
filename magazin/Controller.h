#pragma once
#include "repo.h"
#include "Validator.h"
#include <algorithm>
class Controller {
private:
	Repo& r;
	Validator v;
public:
	Controller(Repo& rep) :r{ rep }{};
	void add(Produs& p);
	vector<Produs>& getAll();
	static void testeCtr() {
		Repo r{ "Text.txt" };
		Controller c{ r };
		try{
			c.add(Produs{ 3,"a","c",100.0 });
			assert(false);
		}
		catch (exception ex) {
			assert(true);
		}
	}
};