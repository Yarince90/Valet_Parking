#define _CRT_SECURE_NO_WARNINGS
/* Citation and Sources...
OOP244 Final Project
Module: Parking
Filename: Parking.cpp
Version 2.0
Author Yarince Vigil
contact@yarince.com
-----------------------------------------------------------
Date: 2020/08/07
Preliminary release: 2020/07/17
Revised History:
-First release
-Implemented Milestone 6 functions
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include "Utils.h"
#include "Menu.h"
#include "Parking.h"
#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"
using namespace std;

namespace sdds {
	Parking::Parking() {
		setEmpty();
	}
	Parking::Parking(const char* dataFile, int noOfSpots) {
		int i = 0;
		if (dataFile && strlen(dataFile) > 0) {
			if (noOfSpots < 10 || noOfSpots > MAX_PARKING) {
				setEmpty();
			}
			else {
				m_fileName = new char[strlen(dataFile) + 1];
				strcpy(m_fileName, dataFile);
				m_parkingSpots = noOfSpots;
				for (i = 0; i < noOfSpots; i++) {
					m_vehicles[i] = nullptr;
				}
				m_parkedVehicles = 0;
			}
		}
		else {
			setEmpty();
		}
		if (loadData()) {
			m_parkingMenu = new Menu("Parking Menu, select an action:");
			m_parkingMenu->add("Park Vehicle");
			m_parkingMenu->add("Return Vehicle");
			m_parkingMenu->add("List Parked Vehicles");
			m_parkingMenu->add("Close Parking (End of day)");
			m_parkingMenu->add("Exit Program");

			m_vehicleSelection = new Menu("Select type of the vehicle:", 1);
			m_vehicleSelection->add("Car");
			m_vehicleSelection->add("Motorcycle");
			m_vehicleSelection->add("Cancel");
		}
		else {
			cout << "Error in data file" << endl;
			setEmpty();
		}
	}
	void Parking::saveData() {
		int i = 0;
		if (!isEmpty()) {
			ofstream file(m_fileName, ios::out);
			if (file.is_open()) {
				for (i = 0; i < m_parkingSpots; i++) {
					if (m_vehicles[i]) {
						m_vehicles[i]->setCsv(true);
						m_vehicles[i]->write(file);
					}
				}
				file.close();
			}
		}
	}
	bool Parking::loadData() {

		bool status = false;
		bool result = false;
		char v_Type = { '\0' };
		int i = 0;

		if (!isEmpty()) {

			ifstream file;
			file.open(m_fileName, ios::in);

			if (file.is_open()) {
				status = true;
			}
			if (status) {
				result = true;
				do {

					Vehicle* tempVehicle = nullptr;
					v_Type = file.get();
					file.ignore();

					if (v_Type == 'C' || v_Type == 'M') {

						if (v_Type == 'M') {
							tempVehicle = new Motorcycle();
						}
						else if (v_Type == 'C') {
							tempVehicle = new Car();
						}
						tempVehicle->setCsv(true);
						tempVehicle->read(file);
						file.clear();

						bool empty = false;
						int spot = 0;

						for (i = 0; i < m_parkingSpots && empty == false; i++) {
							if (m_vehicles[i] == nullptr) {
								empty = true;
								spot = i;
							}
						}
						if (empty) {
							m_vehicles[spot] = tempVehicle;
							m_parkedVehicles++;
							m_vehicles[spot]->setParkingSpot(spot + 1);
							result = true;
						}
						else {
							delete tempVehicle;
							tempVehicle = nullptr;
							result = false;
						}
					}
				} while (file.good() && this->m_parkedVehicles < this->m_parkingSpots);

			}
			file.clear();
			file.close();
		}
		if (isEmpty() || !status) {
			result = true;
		}
		return result;
	}
	void Parking::setEmpty() {
		int i = 0;
		m_fileName = nullptr;
		m_parkingMenu = nullptr;
		m_vehicleSelection = nullptr;
		m_parkedVehicles = 0;
		m_parkingSpots = 0;
		for (i = 0; i < MAX_PARKING; i++) {
			m_vehicles[i] = nullptr;
		}
	}
	int Parking::run() {

		bool running = false;
		int option = 0;
		int status = 0;


		if (!isEmpty()) {
			do {
				running = true;

				parkingStatus();

				option = m_parkingMenu->run();


				if (option == 1)
				{
					running = true;

					parkVehicle();
				}
				else if (option == 2)
				{
					running = true;

					returnVehicle();
				}
				else if (option == 3)
				{
					running = true;

					listParkedVehicles();
				}

				else if (option == 4)
				{
					if (closeParking())
					{
						running = false;
					}
				}
				else if (option == 5)
				{
					if (exitParkingApp()) {
						running = false;
						saveData();
						cout << "Exiting program!" << endl;

					}
					else
					{
						option = 1;
					}
				}
			} while (running == true);
		}
		if (isEmpty()) {
			status = 0;
		}
		else {
			status = 1;
		}
		return status;
	}
	bool Parking::isEmpty()const {
		return m_fileName == nullptr;
	}
	void Parking::parkVehicle() {
		int option = 0;
		int i = 0;
		if (this->m_parkedVehicles == this->m_parkingSpots) {
			cout << "Parking is full" << endl;
		}
		else {

			option = this->m_vehicleSelection->run();

			if (option == 3) {
				cout << "Parking cancelled" << endl;
			}
			else {
				Vehicle* vehicle = nullptr;
				if (option == 1) {
					vehicle = new Car();
				}
				else if (option == 2) {
					vehicle = new Motorcycle();
				}
				vehicle->setCsv(false);
				vehicle->read();

				bool availible = false;
				int spot = 0;

				for (i = 0; i < this->m_parkingSpots && !availible; i++) {
					if (m_vehicles[i] == nullptr) {
						spot = i;
						availible = true;
					}
				}
				m_vehicles[spot] = vehicle;
				m_vehicles[spot]->setParkingSpot(spot + 1);
				m_parkedVehicles++;
				cout << endl << "Parking Ticket" << endl;
				m_vehicles[spot]->write();
				cout << endl;
			}
		}
	}
	void Parking::parkingStatus() {
		cout << "****** Seneca Valet Parking ******" << endl;
		cout << "*****  Available spots: ";
		cout.setf(ios::left);
		cout.width(4);
		cout << m_parkingSpots - m_parkedVehicles;
		cout.unsetf(ios::left);
		cout << " *****" << endl;
	}
	void Parking::listParkedVehicles() {
		int i = 0;
		cout << "*** List of parked vehicles ***" << endl;
		for (i = 0; i < this->m_parkingSpots; i++) {
			if (this->m_vehicles[i]) {
				this->m_vehicles[i]->setCsv(false);
				this->m_vehicles[i]->write();
				cout << "-------------------------------" << endl;
			}
		}
	}
	void Parking::returnVehicle() {
		bool found = false;
		int spot = 0;
		int i = 0;
		char tempLPlate[100 + 1] = { '\0' };

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
		}

		cout << "Return Vehicle" << endl;
		cout << "Enter Licence Plate Number: ";

		cin.getline(tempLPlate, 100);
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
		}
		if (invalidLiscenceP(tempLPlate)) {
			do {
				cout << "Invalid Licence Plate, try again: ";
				cin.getline(tempLPlate, 100);
			} while (invalidLiscenceP(tempLPlate));
		}

		toUpperCase(tempLPlate);

		for (i = 0; i < this->m_parkingSpots && !found; i++) {
			found = *m_vehicles[i] == tempLPlate;

			if (found) {
				spot = i;
			}
		}

		if (found) {
			cout << endl << "Returning: " << endl;
			m_vehicles[spot]->setCsv(false);
			m_vehicles[spot]->write();
			delete this->m_vehicles[spot];
			this->m_vehicles[spot] = nullptr;
			this->m_parkedVehicles--;
			found = true;
			cout << endl;
		}
		else {
			cout << endl << "License plate " << tempLPlate << " Not found" << endl << endl;
		}
	}
	bool Parking::closeParking() {
		int i = 0;
		bool closeParking = false;

		if (this->m_parkedVehicles == 0) {
			cout << "Closing Parking" << endl;
			closeParking = true;
		}
		else {
			cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
			cout << "Are you sure? (Y)es/(N)o: ";
			if (yes()) {
				cout << "Closing Parking" << endl;
				for (i = 0; i < this->m_parkingSpots; i++) {
					if (this->m_vehicles[i]) {
						cout << endl << "Towing request" << endl;
						cout << "*********************" << endl;
						this->m_vehicles[i]->setCsv(false);
						this->m_vehicles[i]->write();
						delete this->m_vehicles[i];
						this->m_vehicles[i] = nullptr;
						this->m_parkedVehicles--;
					}
				}
				closeParking = true;
			}
			else {
				cout << "Aborted!" << endl;
				closeParking = false;
			}
		}

		return closeParking;
	}

	bool Parking::exitParkingApp() {

		cout << "This will terminate the program!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";

		return yes();

	}

	Parking::~Parking() {	
		saveData();
		cin.ignore(1000, '\n');
		delete[] m_fileName;
		delete m_parkingMenu;
		delete m_vehicleSelection;
		
		int i = 0;
		for (i = 0; i < MAX_PARKING; i++) {
			if (this->m_vehicles[i]) {
				delete this->m_vehicles[i];
			}
		}
		setEmpty();
	}
}