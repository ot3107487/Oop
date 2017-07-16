#pragma once
#include "Repository.h"
#include "Observer.h"
#include <algorithm>
class Controller:public Observer {
private:
	Repo& r;
public:
	//constructor
	Controller(Repo& r) :r{ r } {};
	void add(Task& t);//adauga un task
	vector<Task> filtru(string programator) {
		//filtrare task-uri dupa programatori
		vector<Task> t;
		for (auto& el : r.getAll())
			if (strstr(el.getProgramatori().c_str(),programator.c_str()))
				t.push_back(el);
		sort(t.begin(), t.end(), [](Task& a, Task& b) {
			return a.getStare() < b.getStare();
		});
		return t;
	}
	vector<Task>& getAll() {
		//returneaza task-urile ordonate dupa stare;
		sort(r.getAll().begin(), r.getAll().end(), [](Task& a, Task& b) {
			return a.getStare() < b.getStare();
		});
		return r.getAll();
	}
	int program(const string programator) {
		int i = 0;
		int j = 0;
		while (j != programator.length()) {
			if (programator[j] == ':')
				i++;
			j++;
		}
		return i + 1;
	}
	static void testeCtr() {
		Repo r{ "testCtr.txt" };
		Controller c{ r };
		assert(c.getAll()[0].getId() == 1);
		c.add(Task{ 2,"c","bogdan","rares" });
		assert(c.getAll().back().getDescriere() == "c");
		assert(c.program("bun") == 1);
		assert(c.filtru("bun").size() == 1);
	}
};