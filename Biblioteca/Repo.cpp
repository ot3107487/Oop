#include "Repo.h"

void Repo::add(Carte & c)
{
	v.push_back(c);
	writeToFile();
}

void Repo::dilit(Carte & c)
{
	auto it = find(v.begin(), v.end(), c);
	v.erase(it);
	writeToFile();
}
