#include "newSet.h"
#include <iostream>
using namespace std;

Set::Set() {
	m_array = new ItemType[DEFAULT_MAX_ITEMS];
	m_size = 0;
	m_max = DEFAULT_MAX_ITEMS;
}

Set::Set(int size) {
	m_array = new ItemType[size];
	m_size = 0;
	m_max = size;
}

Set::Set(Set& other) {
	m_max = other.m_max;
	m_array = new ItemType[m_max];
	m_size = other.size();

	for (int i = 0; i < other.m_size; i++) {
		m_array[i] = other.m_array[i]; 
	}
}

Set& Set::operator=(const Set& other) {
	delete [] m_array;
	m_size = other.size(); 
	m_max = other.m_max; 
	m_array = new ItemType[other.m_max]; 
	for (int i = 0; i < m_size; i++) { 
		m_array[i] = other.m_array[i];
	}
	return *this;
}

Set::~Set() {
	delete [] m_array;
}

bool Set::empty() const {
	if (m_size == 0) { return true; }
	else { return false; }
}

int Set::size() const {
	return m_size;
}

bool Set::insert(const ItemType& value) {
	if (m_size == m_max) { return false; }

	for (int i = 0; i < m_size; i++) {
		if (m_array[i] == value) { return false; }
	}

	m_array[m_size++] = value;
	return true;
}

bool Set::erase(const ItemType& value) {
	for (int i = 0; i < m_size; i++) {
		if (m_array[i] == value) {
			for (int j = i; j < m_size; j++) {
				m_array[j] = m_array[j + 1];
			}
			m_size--;
			return true;
		}
	}

	return false;
}

bool Set::contains(const ItemType& value) const {
	for (int i = 0; i < m_size; i++) {
		if (m_array[i] == value) { return true; }
	}

	return false;
}

bool Set::get(int i, ItemType& value) const {
	if ((i < 0) || (i > m_size)) { return false; }

	for (int j = 0; j < m_size; j++) {
		int greaterThan = 0;

		for (int k = j + 1; k < m_size; k++) {
			if (m_array[j] > m_array[k]) { greaterThan++; }
		}
		for (int l = j - 1; l >= 0; l--) {
			if (m_array[j] > m_array[l]) { greaterThan++; }
		}

		if (greaterThan == i) {
			value = m_array[j];
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
		cerr << m_array[i] << " ";
	}
	cerr << "Size: " << m_size << endl;
	cerr << endl;
}