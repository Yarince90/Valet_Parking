#define _CRT_SECURE_NO_WARNINGS
/* Citation and Sources...
OOP244 Final Project
Module: Motorcycle
Filename: Motorcycle.cpp
Version 1.0
Author Yarince Vigil
contact@yarince.com
-----------------------------------------------------------
Date: 2020/08/01
Preliminary release: 2020/08/01
Revised History:
-First release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <iostream>
#include <cstring>
#include "Utils.h"
#include "Motorcycle.h"
using namespace std;

namespace sdds {

	Motorcycle::Motorcycle() {
		setEmpty();
	}
	Motorcycle::Motorcycle(const char* plate, const char* model, int parking, bool sideCar) : Vehicle(plate, model, parking) {
		m_sideCar = sideCar;
	}
	void Motorcycle::setEmpty() {
		Vehicle::deleteVehicle();
		m_sideCar = false;
	}
	istream& Motorcycle::read(istream& is) {

		if (isCsv()) {
			Vehicle::read(is);
			is >> m_sideCar;
			is.ignore();
		}
		else {
			cout << endl;
			cout << "Motorcycle information entry" << endl;
			Vehicle::read(is);
			cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
			m_sideCar = yes();
		}

		return is;
	}
	ostream& Motorcycle::write(ostream& os) const {
		if (isEmpty()) {
			os << "Invalid Motorcycle Object" << endl;
		}
		else {
			if (isCsv()) {
				os << "M,";
				Vehicle::write(os);
				os << int(m_sideCar) << endl;
			}
			else {
				os << "Vehicle type: Motorcycle" << endl;
				Vehicle::write(os);
				if (m_sideCar) {
					os << "With Sidecar" << endl;
				}
			}
		}

		return os;
	}
}