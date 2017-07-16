#pragma once
#include <string>
#include <assert.h>
using namespace std;
class Carte {
private:
	int it;
	string titlu, autor, gen;
public:
	Carte()=default;
	Carte(int i, string t, string a, string g) :it{ i }, titlu{ t }, autor{ a }, gen{ g } {};
	Carte(const Carte& c) {
		this->it=c.it;
		this->titlu = c.titlu;
		this->autor = c.autor;
		this->gen = c.gen;
	}
	int getId()const {
		return this->it;
	}
	string getTitlu()const {
		return this->titlu;
	}
	string getAutor()const {
		return this->autor;
	}
	string getGen()const {
		return this->gen;
	}
	friend ostream& operator<<(ostream& os, Carte& c) {
		os << c.getId() << " " << c.getTitlu() << " " << c.getAutor() << " " << c.getGen() << endl;
		return os;
	}
	friend istream& operator >> (istream& is, Carte& c) {
		is >> c.it >> c.titlu >> c.autor >> c.gen;
		return is;
	}
	bool operator==(const Carte& c) {
		return this->it == c.getId();
	}
	static void testCarte() {
		Carte c{ 1,"a","b","c" };
		assert(c.getId() == 1);
		assert(c.getTitlu() == "a");
		assert(c.getAutor() == "b");
		assert(c.getGen() == "c");
	}
};