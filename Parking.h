#ifndef SDDS_PARKING_H
#define SDDS_PARKING_H
/* Citation and Sources...
OOP244 Final Project
Module: Parking
Filename: Parking.h
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
#include "Menu.h"
#include"Vehicle.h"

namespace sdds {
	const int MAX_PARKING = 100;

	class Parking {
		char* m_fileName = nullptr;
		Menu* m_parkingMenu = nullptr;
		Menu* m_vehicleSelection = nullptr;
		Vehicle* m_vehicles[MAX_PARKING] = { '\0' };
		int m_parkedVehicles;
		int m_parkingSpots;
		void saveData();
		bool loadData();
		void setEmpty();
		bool isEmpty()const;
		void parkVehicle();
		void parkingStatus();
		void listParkedVehicles();
		void returnVehicle();
		bool closeParking();
		bool exitParkingApp();
	public:
		Parking();
		Parking(const char* dataFile, int noOfSpots);
		Parking(const Parking&) = delete;
		Parking& operator=(const Parking&) = delete;
		int run();
		~Parking();
	};
}
#endif // !SDDS_PARKING_H
