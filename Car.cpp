#define _CRT_SECURE_NO_WARNINGS
/* Citation and Sources...
OOP244 Final Project
Module: Car
Filename: Car.cpp
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
#include <string>
#include "Utils.h"
#include "Car.h"
using namespace std;

namespace sdds {
	
	Car::Car() {
		setEmpty();
	}
	Car::Car(const char* plate, const char* model, int parking, bool wash) : Vehicle(plate, model, parking) {
		m_wash = wash;
	}
	void Car::setEmpty() {
		Vehicle::deleteVehicle();
		m_wash = false;
	}
	istream& Car::read(istream& is) {

		if (isCsv()) {
			Vehicle::read(is);
			is >> m_wash;
			is.ignore();
		}
		else {
			cout << endl;
			cout << "Car information entry" << endl;
			Vehicle::read(is);
			cout << "Carwash while parked? (Y)es/(N)o: ";
			m_wash = yes();
		}

		return is;
	}
	ostream& Car::write(ostream& os) const {
		if (isEmpty()) {
			os << "Invalid Car Object" << endl;
		}
		else {
			if (isCsv()) {
				os << "C,";
				Vehicle::write(os);
				os << int(m_wash) << endl;
			}
			else {
				os << "Vehicle type: Car" << endl;
				Vehicle::write(os);
				if (m_wash) {
					os << "With Carwash" << endl;
				}
				else {
					os << "Without Carwash" << endl;
				}
			}
		}

		return os;
	}
}
