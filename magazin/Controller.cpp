#include "Controller.h"

void Controller::add(Produs & p)
{
	if(v.valid(p))
		r.add(p);
}

vector<Produs>& Controller::getAll()
{
	auto& all = r.getAll();
	sort(all.begin(), all.end(), [](Produs& a,Produs& b) {
		return a.getPret() > b.getPret();
	});
	return all;
}
