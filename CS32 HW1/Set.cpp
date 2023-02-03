#include "Set.h"
#include <iostream>
using namespace std;

Set::Set() {
	m_size = 0;
}

bool Set::empty() const {
	if (m_size == 0) { return true; }
	else { return false; }
}

int Set::size() const {
	return m_size;
}

bool Set::insert(const ItemType& value) {
	if (m_size == DEFAULT_MAX_ITEMS) { return false; }

	for (int i = 0; i < m_size; i++) {
		if (m_ITarray[i] == value) { return false; }
	}

	m_ITarray[m_size++] = value;
	return true;
}

bool Set::erase(const ItemType& value) {
	for (int i = 0; i < m_size; i++) {
		if (m_ITarray[i] == value) {
			for (int j = i; j < m_size; j++) {
				m_ITarray[j] = m_ITarray[j + 1];
			}
			m_size--;
			return true;
		}
	}

	return false;
}

bool Set::contains(const ItemType& value) const {
	for (int i = 0; i < m_size; i++) {
		if (m_ITarray[i] == value) { return true; }
	}

	return false;
}

bool Set::get(int i, ItemType& value) const {
	if ((i < 0) || (i > m_size)) { return false; }

	for (int j = 0; j < m_size; j++) {
		int greaterThan = 0;

		for (int k = j + 1; k < m_size; k++) {
			if (m_ITarray[j] > m_ITarray[k]) { greaterThan++; }
		}
		for (int l = j - 1; l >= 0; l--) {
			if (m_ITarray[j] > m_ITarray[l]) { greaterThan++; }
		}

		if (greaterThan == i) {
			value = m_ITarray[j];
			return true;
		}
	}

	return false;
}

void Set::swap(Set& other) {
	Set temp;

	temp = other;
	other = *this;
	*this = temp;

	//for (int i = 0; i < other.m_size; i++) {
	//	temp.insert(other.m_ITarray[i]); // inserts every element of other into temp
	//}

	//other.m_ITarray->clear(); // clears other 
	//other.m_size = 0;
	//for (int i = 0; i < this->m_size; i++) {
	//	other.insert(this->m_ITarray[i]); // inserts every element of this into other
	//}

	//this->m_ITarray->clear(); // clears this
	//this->m_size = 0;
	//for (int i = 0; i < temp.m_size; i++) {
	//	this->insert(temp.m_ITarray[i]); // inserts every element of temp into this
	//}
}

void Set::dump() const {
	for (int i = 0; i < m_size; i++) {
		cerr << m_ITarray[i] << " ";
	}
	cerr << "Size: " << m_size << endl;
	cerr << endl;
}