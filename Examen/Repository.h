#pragma once
#include "Task.h"
#include <vector>
#include <fstream>
class Repo {
private:
	vector<Task> v;
	string fileName;
	//citire din fisier
	void readFromFile(){
		ifstream fin(fileName);
		Task elem;
		while (fin >> elem)
			v.push_back(elem);
		fin.close();
	}
	//scriere in fisier
	void writeToFile() {
		ofstream fout(fileName);
		for (auto& el : v)
			fout << el;
		fout.close();
	}
public:
	//constructor
	Repo(string f) :fileName{ f } { readFromFile(); }
	void add(Task& t);//adaugare task
	//read
	vector<Task>& getAll(){
		return v;
	}
	//teste specificatii
	static void testeRepo() {
		Repo r{ "testRepo.txt" };
		assert(r.getAll()[0].getId() == 1);
		r.add(Task{ 2,"c","bogdan","Rares" });
		assert(r.getAll().back().getDescriere() == "c");
	}
};