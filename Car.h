#ifndef SDDS_CAR_H
#define SDDS_CAR_H
/* Citation and Sources...
OOP244 Final Project 
Module: Car
Filename: Car.h
Version 1.0
Author Yarince Vigil
contact@yarince.com
-----------------------------------------------------------
Date: 2020/08/05
Preliminary release: 2020/08/05
Revised History:
-First release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include "Vehicle.h"

namespace sdds {

	class Car :public Vehicle {
		bool m_wash = false;
	public:
		Car();
		Car(const char* plate, const char* model, int parking = 0, bool wash = false);
		Car(const Car&) = delete;
		Car& operator=(const Car&) = delete;
		void setEmpty();
		std::istream& read(std::istream& is = std::cin);
		std::ostream& write(std::ostream& os = std::cout) const;
	};
}
#endif // !SDDS_CAR_H