#pragma once
#include "Carte.h"
#include <vector>
#include <fstream>
class Repo {
private:
	vector<Carte> v;
	string fileName;
	void readFromFile() {
		ifstream fin(fileName);
		Carte c;
		while (fin >> c)
			v.push_back(c);
		fin.close();
	}
	void writeToFile() {
		ofstream fout(fileName);
		for (auto& c : v)
			fout << c;
		fout.close();
	}
public:
	Repo(string f) :fileName{ f } {
		readFromFile();
	}
	void add(Carte& c);
	void dilit(Carte& c);
	vector<Carte>& getAll() {
		return v;
	}
};