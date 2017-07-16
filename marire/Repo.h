#pragma once
#include <vector>
#include "Joc.h"
#include <algorithm>
#include <fstream>
class Repo {
	vector<Joc> v;
	string fileName;
	void writeToFile() {
		//functia scrie in fisier datele din repository
		ofstream fout(fileName);
		for (const auto& joc : v)
			fout << joc;
		fout.close();
	}
	void readFromFile() {
		//functia citeste si introduce in repository date din fisier
		ifstream fin(fileName);
		Joc j;
		while (fin >> j)
			v.push_back(j);
		fin.close();
	}
public:
	//constructor
	Repo(string f) :fileName{ f } { readFromFile(); };
	void add(Joc& j) {
		//adaugare joc in fisier
		v.push_back(j);
		writeToFile();
	}
	void modify(Joc& j) {
		//modifica un joc din repository
		auto it = find(v.begin(), v.end(), j);
		if (it != v.end()) {
			replace(v.begin(), v.end(), *it, j);
			writeToFile();
		}
	}
	vector<Joc>& getAll(){
		//returneaza lista de jocuri
		return v;
	}
	static void teste() {
		Repo r{ "testRepo.txt" };
		assert(r.getAll()[0].getId() == 1);
		r.add(Joc{ 2,"X","x","terminat" });
		assert(r.getAll()[1].getId() == 2);
		r.modify(Joc{ 2,"a","c","neinceput" });
		assert(r.getAll()[1].getJucator() == "c");
		r.getAll().pop_back();
		r.writeToFile();
	}
};