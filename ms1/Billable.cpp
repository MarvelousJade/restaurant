#include "Billable.h"
#include "Utils.h"
namespace seneca {
   void Billable::setPrice(double price) {
		m_price = price;
	}
   void Billable::setName(const char* name) {
		m_name = ut.alocpy(name);	
	}
	Billable::Billable() {
		m_price = 0.0;
	   m_name = nullptr;
	}
	Billable::Billable(Billable& source) {
		m_price = source.m_price;
		m_name = ut.alocpy(source.m_name);	
	}
	Billable& Billable::operator=(const Billable& source) {
		if(this != &source) {
			delete m_name;
			m_price = source.m_price;
			m_name = ut.alocpy(source.m_name);	
		}
		return *this;
	}
	Billable::~Billable() {
		m_price = 0.0;
		delete m_name;
	}
	const char* Billable::name() const {
		return m_name;
	}
	double Billable::price() const {
		return m_price;
	}  
   double operator+(double money, const Billable& B) {
		return money + B.price();
	}
   double& operator+=(double& money, const Billable& B) {
		return money += B.price();
	}
}
