#ifndef SDDS_READWRITABLE_H
#define SDDS_READWRITABLE_H
/* Citation and Sources...
OOP244 Final Project
Module: ReadWritable
Filename: ReadWritable.h
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

namespace sdds {
	class ReadWritable {
		bool m_commaSeparatedValues = false;
	public:
		ReadWritable();
		void setCsv(bool value);
		bool isCsv()const;
		virtual ~ReadWritable();
		virtual std::istream& read(std::istream& is = std::cin) = 0;
		virtual std::ostream& write(std::ostream& os = std::cout)const = 0;
	};
	std::ostream& operator<<(std::ostream& os, const ReadWritable& rw);
	std::istream& operator>>(std::istream& is, ReadWritable& rw);
}
#endif // !SDDS_READWRITABLE_H
