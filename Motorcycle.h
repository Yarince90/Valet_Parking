#ifndef SDDS_MOTORCYCLE_H
#define SDDS_MOTORCYCLE_H
/* Citation and Sources...
OOP244 Final Project
Module: Motorcycle
Filename: Motorcycle.h
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

	class Motorcycle :public Vehicle {
		bool m_sideCar = false;
	public:
		Motorcycle();
		Motorcycle(const char* plate, const char* model, int parking = 0, bool sideCar = false);
		Motorcycle(const Motorcycle&) = delete;
		Motorcycle& operator=(const Motorcycle&) = delete;
		void setEmpty();
		std::istream& read(std::istream& istr = std::cin);
		std::ostream& write(std::ostream& ostr = std::cout) const;
	};
}
#endif // !SDDS_MOTORCYCLE_H