#ifndef SDDS_MENU_H
#define SDDS_MENU_H
/* Citation and Sources...
OOP244 Final Project
Module: Menu
Filename: Menu.h
Version 1.0
Author Yarince Vigil
contact@yarince.com
-----------------------------------------------------------
Date: 2020/07/09
Preliminary release: 2020/07/09
Revised History:
-First release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

namespace sdds {
	const int MAX_NO_OF_ITEMS = 10;
	class Menu;

	class MenuItem {
		friend class Menu;
		char* m_menuItem = nullptr;
		MenuItem();
		MenuItem(const MenuItem&) = delete;
		explicit MenuItem(const char* item);
		void setItem(const char* item);
		void deleteMenuItem();
		std::ostream& display(std::ostream& os = std::cout) const;
		~MenuItem();
	};
	class Menu {
		char* m_title = nullptr;
		MenuItem* m_menuItems[MAX_NO_OF_ITEMS] = { '\0' };
		int m_numOfItems = 0;
		int m_indentation = 0;
	public:
		Menu();
		Menu(const Menu& menu);
		Menu(const char* menuTitle, int indentation = 0);
		void setMenu(const char* setTitle, const int indent = 0);
		void add(const char* newItem);
		bool isEmpty() const;
		void setEmpty();
		void deleteMenu();
		int run(std::istream& is = std::cin, std::ostream& os = std::cout) const;
		operator bool() const;
		operator int() const;
		Menu& operator=(const Menu& newMenu);
		Menu& operator=(const char* newMenu);
		Menu& operator<<(const char* itemName);
		std::ostream& display(std::ostream& os = std::cout) const;
		~Menu();
	};
}
#endif // !SDDS_MENU_H