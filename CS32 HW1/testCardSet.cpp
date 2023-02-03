#include "newSet.h"
#include "CardSet.h"

#include <iostream>
#include <cassert>

using namespace std;

int main() {
	CardSet c;
	c.add(9753);
	c.print();
	assert(c.size() == 1);
	c.add(1401);
	c.add(9753);
	c.add(4450);
	c.add(6053);
	assert(c.size() == 4);
	c.print();

	cerr << "PASSED ALL TESTS" << endl;
}