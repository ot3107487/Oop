#pragma once
using namespace std;
#include <vector>
class Observable {
public:
	virtual void update() = 0;
};
class Observer {
protected:
	vector<Observable*> v;
public:
	void reg(Observable* o) {
		v.push_back(o);
	}
	void notifyAll() {
		for (Observable* obs : v) {
			obs->update();
		}
	}
};
