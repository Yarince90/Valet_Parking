#define _CRT_SECURE_NO_WARNINGS
/* Citation and Sources...
OOP244 Final Project
Module: Vehicle
Filename: Vehicle.cpp
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
#include "ReadWritable.h"
#include "Vehicle.h"
using namespace std;

namespace sdds {
	Vehicle::Vehicle() {
		setEmpty();
	}
	Vehicle::Vehicle(const char* plate, const char* model, int parking) {

		setVehicle(plate, model, parking);
	}
	void Vehicle::setVehicle(const char* plate, const char* model, int parking) {

		if (m_model) {
			deleteVehicle();
		}

		if (plate && model) {
			if (strlen(plate) < MAX_LPLATE && strlen(model) > 0) {

				setLicencePlate(plate);

				setMakeModel(model);

				m_parkingSpot = parking;
			}
			else {
				deleteVehicle();
			}
		}
		else {
			deleteVehicle();
		}
	}
	void Vehicle::setEmpty() {
		m_model = nullptr;
		m_lPlate[0] = '\0';
		m_parkingSpot = 0;
	}
	bool Vehicle::isEmpty()const {
		return m_model == nullptr;
	}
	void Vehicle::setParkingSpot(int parking) {
		if (parking > 0) {
			m_parkingSpot = parking;
		}
		else {
			if (!isEmpty()) {
				deleteVehicle();
			}
		}
	}
	int Vehicle::getLicensePlate()const {
		return *m_lPlate;
	}
	int Vehicle::getMakeModel()const {
		return *m_model;
	}
	int Vehicle::getParkingSpot()const {
		return m_parkingSpot;
	}
	void Vehicle::setMakeModel(const char* model) {
		if (model) {
			if (m_model) {
				delete[] m_model;
				m_model = nullptr;
			}

			m_model = new char[strlen(model) + 1];
			strcpy(m_model, model);
		}
		else {
			if (m_model) {
				delete[] m_model;
				m_model = nullptr;
			}
			setEmpty();
		}
	}
	void Vehicle::setLicencePlate(const char* plate) {
		if (plate) {
			char temp[MAX_LPLATE + 1] = { '\0' };

			strncpy(temp, plate, MAX_LPLATE);

			if (invalidLiscenceP(temp)) {
				setEmpty();
			}
			else {
				toUpperCase(temp);
				strncpy(m_lPlate, temp, MAX_LPLATE);
			}
		}
		else {
			setEmpty();
		}
	}
	void Vehicle::deleteVehicle() {
		delete[] m_model;
		setEmpty();

	}
	bool operator==(const Vehicle& plateA, const char* plateB) {
		bool matches = false;

		if (plateA.isEmpty() || !plateB) {
			matches = false;
		}
		else {

			if (strcmp(plateA.m_lPlate, plateB) == 0) {
				matches = true;
			}
			else {
				matches = false;
			}
		}

		return matches;
	}
	bool operator==(const Vehicle& a, const Vehicle& b) {
		bool matches = false;
		if (strcmp(a.m_lPlate, b.m_lPlate) == 0) {
			matches = true;
		}
		else {
			matches = false;
		}
		return matches;
	}
	istream& Vehicle::read(istream& is) {
		char temp[100 + 1] = { '\0' };
		char tempLPlate[100 + 1] = { '\0' };
		char tempMModel[100 + 1] = { '\0' };
		int i = 0;
		if (!isEmpty()) {
			deleteVehicle();
		}
		setEmpty();
		//CsV = true
		if (isCsv()) {
			is >> m_parkingSpot;
			is.ignore();
			is.getline(this->m_lPlate, MAX_LPLATE + 1, ',');
			if (is.fail()) {
				is.clear();
				is.ignore(1000, '\n');
			}
			is.getline(temp, MAX_MODEL + 1, ',');
			if (is.fail()) {
				is.clear();
				is.ignore(1000, '\n');
			}
			setMakeModel(temp);

			int len = 0;
			len = strlen(this->m_lPlate);

			for (i = 0; i < len; i++) {
				this->m_lPlate[i] = toupper(this->m_lPlate[i]);
			}
		}
		//CsV = false
		else {
			if (is.fail()) {
				is.clear();
				is.ignore(1000, '\n');
			}
			//Get Liscence Plate
			cout << "Enter Licence Plate Number: ";
			is.getline(tempLPlate, 100);
			if (is.fail()) {
				is.clear();
				is.ignore(1000, '\n');
			}
			if (invalidLiscenceP(tempLPlate)) {
				do {
					cout << "Invalid Licence Plate, try again: ";
					is.getline(tempLPlate, 100);
				} while (invalidLiscenceP(tempLPlate));
			}
			setLicencePlate(tempLPlate);

			if (is.fail()) {
				is.clear();
				is.ignore(1000, '\n');
			}

			//Get Made and Model
			cout << "Enter Make and Model: ";
			is.getline(tempMModel, 100);
			if (is.fail()) {
				is.clear();
				is.ignore(1000, '\n');
			}
			if (invalidMakeAM(tempMModel)) {
				do {
					cout << "Invalid Make and model, try again: ";
					is.getline(tempMModel, 60);
				} while (invalidMakeAM(tempMModel));
			}
			setMakeModel(tempMModel);
		}
		return is;
	}
	ostream& Vehicle::write(ostream& os)const {

		if (isEmpty()) {
			os << "Invalid Vehicle Object" << endl;
		}
		else if (isCsv()) {
			os << m_parkingSpot << "," << m_lPlate << "," << m_model << ",";
		}
		else {
			os << "Parking Spot Number: ";
			if (m_parkingSpot > 0) {
				cout << m_parkingSpot << endl;
			}
			else {
				os << "N/A" << endl;
			}
			os << "Licence Plate: " << m_lPlate << endl;
			os << "Make and Model: " << m_model << endl;
		}

		return os;
	}
	bool invalidLiscenceP(char* c) {
		return strlen(c) < 1 || strlen(c) > MAX_LPLATE;
	}
	bool invalidMakeAM(char* c) {
		return strlen(c) < 2 || strlen(c) > MAX_MODEL;
	}
	Vehicle::~Vehicle() {
		deleteVehicle();
	}
}