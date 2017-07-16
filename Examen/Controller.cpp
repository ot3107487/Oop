#include "Controller.h"

void Controller::add(Task & t)
{
	r.add(t);
	notifyAll();
}
