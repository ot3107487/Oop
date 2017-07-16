#pragma once
#include <string>
#include <assert.h>
#include <vector>
using namespace std;
class Task {
private:
	int id;
	string descriere;
	string programatori;
	string stare;
public:
	//constructors
	Task() = default;
	Task(int i, string d, string p, string st) :id{ i }, descriere{ d }, programatori{ p }, stare{ st } {};
	Task(const Task& t) {
		this->id = t.id;
		this->descriere = t.descriere;
		this->programatori = t.programatori;
		this->stare = t.stare;
	}
	//getters
	int getId()const {
		return this->id;
	}
	string getDescriere()const {
		return this->descriere;
	}
	string getProgramatori() const{
		return this->programatori;
	}
	string getStare()const {
		return this->stare;
	}
	//overriding operators
	friend istream& operator>>(istream& is,Task& t) {
		is >> t.id >> t.descriere >> t.stare >> t.programatori;
		return is;
	}
	friend ostream& operator<<(ostream& os, Task& t) {
		os << t.id << " " << t.descriere << " " << t.stare <<" "<< t.programatori <<endl;
		return os;
	}
	bool operator==(const Task& t) {
		return this->id == t.getId();
	}
	//teste
	static void testeDomeniu() {
		Task t{ 1,"d","Bogdan","bun" };
		assert(t.getId() == 1);
		assert(t.getDescriere() == "d");
		assert(t.getProgramatori() == "Bogdan");
		assert(t.getStare() == "bun");
	}
};