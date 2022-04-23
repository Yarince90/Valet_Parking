#define _CRT_SECURE_NO_WARNINGS
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
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Utils.h"
#include "Menu.h"
using namespace std;

namespace sdds {
	MenuItem::MenuItem() {
		m_menuItem = nullptr;
	}
	MenuItem::MenuItem(const char* item) {
		setItem(item);
	}
	void MenuItem::setItem(const char* item) {

		if (item != nullptr && item[0] != '\0') {

			if (m_menuItem != nullptr) {
				deleteMenuItem();
			}

			m_menuItem = new char[strlen(item) + 1];
			strcpy(m_menuItem, item);

		}
		else {
			if (m_menuItem != nullptr) {
				deleteMenuItem();
			}
			m_menuItem = nullptr;
		}
	}
	void MenuItem::deleteMenuItem() {
		delete[] this->m_menuItem;
		this->m_menuItem = nullptr;
	}
	ostream& MenuItem::display(ostream& os) const {
		os << this->m_menuItem << endl;
		return os;
	}
	MenuItem::~MenuItem() {
		delete[] m_menuItem;
		m_menuItem = nullptr;
	}
	Menu::Menu() {
		setEmpty();
	}
	Menu::Menu(const Menu& menu) {

		setEmpty();

		if (menu.m_title) {

			m_title = new char[strlen(menu.m_title) + 1];
			strcpy(m_title, menu.m_title);

			m_indentation = menu.m_indentation;
			m_numOfItems = menu.m_numOfItems;

			for (int i = 0; i < menu.m_numOfItems; i++) {
				m_menuItems[i] = new MenuItem;
				m_menuItems[i]->setItem(menu.m_menuItems[i]->m_menuItem);
			}

		}

	}
	Menu::Menu(const char* menuTitle, int indent) {

		setMenu(menuTitle, indent);

	}
	void Menu::setMenu(const char* setTitle, int indent) {

		setEmpty();

		if (setTitle) {

			m_title = new char[strlen(setTitle) + 1];
			strcpy(m_title, setTitle);
			m_indentation = indent;
			m_numOfItems = 0;

		}
	}
	void Menu::add(const char* newItem) {

		if (newItem) {
			if (!isEmpty()) {
				if (m_numOfItems < 10) {

					m_menuItems[m_numOfItems] = new MenuItem;
					m_menuItems[m_numOfItems]->m_menuItem = nullptr;
					m_menuItems[m_numOfItems]->setItem(newItem);
					m_numOfItems++;
				}
			}
		}
		else {

			deleteMenu();
		}
	}
	bool Menu::isEmpty() const {
		return m_title == nullptr;
	}
	void Menu::setEmpty() {
		int i = 0;
		m_title = nullptr;
		m_numOfItems = 0;
		m_indentation = 0;

		for (i = 0; i < MAX_NO_OF_ITEMS; i++) {
			m_menuItems[i] = nullptr;
		}

	}
	void Menu::deleteMenu() {
		int i = 0;
		for (i = 0; i < m_numOfItems; i++) {
			m_menuItems[i]->deleteMenuItem();
			delete m_menuItems[i];
			m_menuItems[i] = nullptr;
		}
		delete[] m_title;
		m_title = nullptr;
		m_numOfItems = 0;
		m_indentation = 0;
	}
	int Menu::run(istream& is, ostream& os) const {
		int option = 0;
		bool isValid = false;

		display(os);

		if (!isEmpty() && m_numOfItems > 0) {

			do {
				is >> option;
				if (!is) {
					os << "Invalid Integer, try again: ";
					is.clear();
				}
				else if (option <= 0 || option > m_numOfItems) {
					os << "Invalid selection, try again: ";
					is.clear();
				}
				else {
					isValid = true;
				}
				is.ignore(1000, '\n');
				is.clear();
			} while (isValid == false);
		}
		return option;
	}
	Menu::operator bool() const {
		return !isEmpty();
	}
	Menu::operator int() const {
		return run();
	}
	Menu& Menu::operator=(const Menu& newMenu) {

		deleteMenu();

		if (this != &newMenu) {
			if (newMenu.m_title) {

				m_title = new char[strlen(newMenu.m_title) + 1];
				strcpy(m_title, newMenu.m_title);

				m_indentation = newMenu.m_indentation;
				m_numOfItems = newMenu.m_numOfItems;
				
				int i = 0;
				
				for (i = 0; i < newMenu.m_numOfItems; i++) {
					m_menuItems[i] = new MenuItem;
					m_menuItems[i]->setItem(newMenu.m_menuItems[i]->m_menuItem);
				}

			}
			else {
				setEmpty();
			}

		}
		return *this;
	}

	Menu& Menu::operator=(const char* newMenu) {

		if (newMenu) {

			delete[] m_title;

			m_title = new char[strlen(newMenu) + 1];
			strcpy(m_title, newMenu);

		}
		else {
			if (m_numOfItems > 0) {
				int i = 0;
				for (i = 0; i < m_numOfItems; i++) {
					m_menuItems[i]->deleteMenuItem();
				}
			}

			deleteMenu();
		}

		return *this;
	}
	Menu& Menu:: operator<<(const char* itemName) {
		add(itemName);
		return *this;
	}
	ostream& Menu::display(ostream& os) const {

		if (isEmpty()) {
			os << "Invalid Menu!" << endl;
		}
		else {
			int i = 0;
			for (i = 0; i < m_indentation; i++) {
				os << setfill(' ') << setw(4) << ' ';
			}
			os << m_title << endl;
			if (m_numOfItems <= 0) {

				os << "No Items to display!" << endl;

			}
			else {
				for (i = 0; i < m_numOfItems; i++) {
					for (int i = 0; i < m_indentation; i++) {
						os << setfill(' ') << setw(4) << ' ';
					}
					os << i + 1 << "- ";
					m_menuItems[i]->display();
				}
				for (i = 0; i < m_indentation; i++) {
					os << setfill(' ') << setw(4) << ' ';
				}
				os << "> ";
			}
		}

		return os;
	}
	Menu::~Menu() {
		deleteMenu();
	}
}