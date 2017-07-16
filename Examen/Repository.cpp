#include "Repository.h"

void Repo::add(Task & t)
{
	v.push_back(t);
	writeToFile();
}
