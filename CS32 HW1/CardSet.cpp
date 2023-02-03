#include "newSet.h"
#include "CardSet.h"


#include <iostream>

using namespace std;

CardSet::CardSet() : m_cardSet() {
	
}

bool CardSet::add(unsigned long cardNumber) {
	if (!m_cardSet.contains(cardNumber)) {
		m_cardSet.insert(cardNumber);
		return true;
	}

	return false;
}

int CardSet::size() const {
	return m_cardSet.size();
}

void CardSet::print() const {
	for (int i = 0; i < m_cardSet.size(); i++) {
		unsigned long x;
		m_cardSet.get(i, x);
		cout << x << endl;
	}
}