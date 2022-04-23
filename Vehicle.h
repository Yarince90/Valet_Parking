#ifndef SDDS_VEHICLE_H
#define SDDS_VEHICLE_H
/* Citation and Sources...
OOP244 Final Project
Module: Vehicle
Filename: Vehicle.h
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
#include "ReadWritable.h"

namespace sdds {
	const int MAX_LPLATE = 8;
	const int MAX_MODEL = 60;

	class Vehicle : public ReadWritable {
		char* m_model = nullptr;
		char m_lPlate[MAX_LPLATE + 1] = { '\0' };
		int m_parkingSpot = 0;
	protected:
		void setEmpty();
		bool isEmpty()const;
		int getLicensePlate()const;
		int getMakeModel()const;
		void setMakeModel(const char* model);
		void setLicencePlate(const char* plate);
	public:
		Vehicle();
		Vehicle(const char* plate, const char* model, int parking = 0);
		Vehicle(const Vehicle&) = delete;
		Vehicle& operator=(const Vehicle&) = delete;
		int getParkingSpot()const;
		void setParkingSpot(int parking);
		void setVehicle(const char* plate, const char* model, int parking = 0);
		void deleteVehicle();
		friend bool operator==(const Vehicle& a, const char* plate);
		friend bool operator==(const Vehicle& a, const Vehicle& b);
		std::istream& read(std::istream& is = std::cin);
		std::ostream& write(std::ostream& os = std::cout)const;
		~Vehicle();
	};
	bool invalidLiscenceP(char* c);
	bool invalidMakeAM(char* c);
}
#endif // !SDDS_VEHICLE_H