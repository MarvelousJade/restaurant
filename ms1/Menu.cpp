#include "Menu.h"
#include <cstddef>
using namespace std;
namespace seneca {
	Menu::Menu(const char* title, const char* exitOption, size_t indentationsCount, size_t indentationSize) 
	: m_indentationsCount(indentationsCount),
	  m_indentationSize(indentationSize),
	  m_menuItemsCount(0),
	  m_title(title, m_indentationsCount, m_indentationSize, -1),
	  m_exitOption(exitOption, m_indentationsCount, m_indentationSize, 0),
	  m_entryPrompt("> ", m_indentationsCount, m_indentationSize, -1) 
	{
		for(size_t i =0; i < MaximumNumberOfMenuItems; i++) {
			m_menuItems[i] = nullptr;		 
		}
	}
	Menu::~Menu() {
		for(size_t i =0; i < m_menuItemsCount; i++) {
				delete[] m_menuItems[i];		 
				m_menuItems[i] = nullptr;
			}
	}
	Menu& Menu::operator<<(const char* content){
		if(m_menuItemsCount < MaximumNumberOfMenuItems) {
			m_menuItems[m_menuItemsCount] = new MenuItem(content, m_indentationsCount, m_indentationSize, m_menuItemsCount + 1);
			m_menuItemsCount++;
		}		
		return *this;
	}
	size_t Menu::select() const{
		if(m_title) {
			m_title.display(cout);
			cout << "\n";
		}
		for(size_t i =0; i < m_menuItemsCount; i++) {
			m_menuItems[i]->display(cout);
			cout << "\n";
		}
		m_exitOption.display(cout);
		cout << "\n";
		m_entryPrompt.display(cout);
		return ut.getInt(0, 4);	
	}
	size_t operator<<(ostream& ostr, const Menu& menu) {
		if(&ostr == &cout) return menu.select();
		cin.clear();
		cin.ignore(2000, '\n');
		return 0;
	}
	void MenuItem::setEmpty() {
		m_content = nullptr;
		m_indentationsCount = 0;
		m_indentationSize = 0;
		m_rowNumber = 0;
	}
	MenuItem::MenuItem(const char* content, size_t Indentations, size_t IndentationSize, int rowNumber) {
		setEmpty();
		if (content == nullptr || 
			ut.isspace(content) ||
			Indentations > 4 ||
			IndentationSize > 4) {
			setEmpty();
		}
		else {
			m_content = ut.alocpy(content);
			m_indentationsCount = Indentations;
			m_indentationSize = IndentationSize;
			m_rowNumber = rowNumber;
		}
	}
	/*MenuItem::~MenuItem() {*/
	/*	delete[] m_content;*/
	/*	m_content = nullptr;*/
	/*	m_indentationsCount = 0;*/
	/*	m_indentationSize = 0;*/
	/*	m_rowNumber = 0;*/
	/*}*/
	MenuItem::operator bool() const {
		return m_content != nullptr;
	}
	ostream& MenuItem::display(ostream& ostr) const {
		if (*this) {
			for (size_t i = 0; i < m_indentationsCount; i++) {
				for (size_t j = 0; j < m_indentationSize; j++) {
					ostr << " ";
				}
			}
			if (m_rowNumber >= 0 && m_rowNumber < 10) ostr << " ";
			if (m_rowNumber >= 0) {
				ostr.setf(ios::fixed);
				ostr.precision(2);
				ostr << m_rowNumber << "- ";
			}
			const char* ptr = m_content;
			while (ut.isspace(*ptr)) {
				ptr++;
			}
			ostr << ptr;
		}
		else {
			ostr << "??????????";
		}
		return ostr;
	}
}
