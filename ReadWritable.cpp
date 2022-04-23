#define _CRT_SECURE_NO_WARNINGS
/* Citation and Sources...
OOP244 Final Project
Module: ReadWritable
Filename: ReadWritable.cpp
Version 1.0
Author Yarince Vigil
contact@yarince.com
-----------------------------------------------------------
Date: 2020/07/21
Preliminary release: 2020/07/22
Revised History:
-First release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <iostream>
#include "ReadWritable.h"
using namespace std;

namespace sdds {
	ReadWritable::ReadWritable() {
		m_commaSeparatedValues = false;
	}
	void ReadWritable::setCsv(bool value) {
		m_commaSeparatedValues = value;
	}
	bool ReadWritable::isCsv()const {
		return m_commaSeparatedValues;
	}
	istream& ReadWritable::read(istream& is)
	{
		is >> m_commaSeparatedValues;
		return is;
	}
	ostream& ReadWritable::write(ostream& os)const
	{
		os << m_commaSeparatedValues;
		return os;
	}
	ostream& operator<<(ostream& os, const ReadWritable& rw)
	{
		rw.write(os);
		return os;
	}
	istream& operator>>(istream& is, ReadWritable& rw)
	{
		rw.read(is);
		return is;
	}
	ReadWritable::~ReadWritable() {};
}