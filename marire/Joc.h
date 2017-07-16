#pragma once
using namespace std;
#include <string>
#include <assert.h>
class Joc {
private:
	int id;
	string tabla;
	string jucator;
	string stare;
public:
	//constructors
	Joc() = default;
	Joc(int i, string t, string j, string s) :id{ i }, tabla{ t }, jucator{ j }, stare{ s } {};
	Joc(const Joc& j) {
		this->id = j.id;
		this->tabla = j.tabla;
		this->jucator = j.jucator;
		this->stare=j.stare;
	}
	//getters & setters
	int getId()const {
		return this->id;
	}
	string getTabla()const {
		return this->tabla;
	}
	string getJucator()const {
		return this->jucator;
	}
	string getStare()const {
		return this->stare;
	}
	void setTabla(string t) {
		this->tabla = t;
	}
	void setJucator(string j) {
		this->jucator = j;
	}
	//suprascriere de operatori
	friend ostream& operator<<(ostream& os, const Joc& j) {
		os << j.getId() << " " << j.getTabla() << " " << j.getJucator() << " " << j.getStare() << endl;
		return os;
	}
	friend istream& operator >> (istream& is, Joc& j) {
		is>>j.id>>j.tabla>>j.jucator>>j.stare;
		return is;
	}
	bool operator==(const Joc& j) {
		return this->getId() == j.getId();
	}
	//virtual destructor
	virtual ~Joc() {};
	//teste
	static void teste() {
		Joc j{ 1,"XOXOXOXO","x","neinceput" };
		assert(j.getId() == 1);
		assert(j.getJucator() == "x");
		assert(j.getTabla() == "XOXOXOXO");
		assert(j.getStare() == "neinceput");
	}
};