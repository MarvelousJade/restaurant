#include "Menu.h"
#include "Utils.h"
#include "constants.h"
using namespace std;
namespace seneca {
	void MenuItem::setEmpty() {
		m_content = nullptr;
		m_indentations = 0;
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
			m_indentations = Indentations;
			m_indentationSize = IndentationSize;
			m_rowNumber = rowNumber;
		}
	}
	MenuItem::~MenuItem() {
		delete[] m_content;
		m_content = nullptr;
		m_indentations = 0;
		m_indentationSize = 0;
		m_rowNumber = 0;
	}
	MenuItem::operator bool() const {
		return m_content != nullptr;
	}
	ostream& MenuItem::display(ostream& ostr) const {
		if (*this) {
			for (size_t i = 0; i < m_indentations; i++) {
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
