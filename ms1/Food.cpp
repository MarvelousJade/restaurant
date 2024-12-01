#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "Food.h"
#include "Billable.h"
#include "Utils.h"
#include "Menu.h"
using namespace std;
namespace seneca {
   void Food::setCustomize(const char* customize) {
     if (customize && customize[0] != '\0') {
       ut.alocpy(m_customize, customize);
     } else {
       delete[] m_customize;
       m_customize = nullptr;
     }
   }
   Food::Food() {
      m_ordered =false;
      m_child = false;
      m_customize = nullptr;
   }
   Food::Food(Food& source) : Billable(source) {
      if(source.name()) {
         m_ordered = source.m_ordered;
         m_child = source.m_child;
         m_customize = nullptr;
         ut.alocpy(m_customize, source.m_customize);
      }
   }
   Food& Food::operator=(const Food& source) {
       if(this != &source) {
          Billable::operator=(source);
          delete m_customize;
          m_ordered = source.m_ordered;
          m_child = source.m_child;  
          ut.alocpy(m_customize, source.m_customize);
       }
       return *this;
   }
   Food::~Food() {
      m_ordered =false;
      m_child = false;
      delete[] m_customize;
   }
   ostream& Food::print(ostream& ostr) const{
      ios::fmtflags originalFlags = ostr.flags();
      char originalFill = ostr.fill();

      ostr.width(28);
      ostr.setf(ios::left);
      ostr.fill('.');
      string str; 
      str.assign(name());
      ostr << str.substr(0, 30);
      if(ordered()) {
         if(m_child) {
            ostr << "Child";
         } else {
            ostr << "Adult";
         }
      } else {
         ostr << ".....";
      }

      ostr.width(7);
      ostr.setf(ios::right);
      ostr.setf(ios::fixed);
      ostr.precision(2);
      ostr.fill(' ');
      ostr << price();

      if(m_customize && &ostr == &cout) {
         str.assign(m_customize);
         ostr << " >> " << str.substr(0, 30);
      }


      ostr.flags(originalFlags);
      ostr.fill(originalFill);

      return ostr;
   }
   bool Food::order() {
      size_t size{};

      Menu sizeMenu("Food Size Selection", "Back", 1, 9);         
      sizeMenu << "Adult" << "Child";

      size = sizeMenu.select();

      switch (size) {
      case 1:
         m_child = false;    
         m_ordered = true;
         break;
      case 2:
         m_child = true;    
         m_ordered = true;
         break;
      default:
         m_ordered = false;
         delete[] m_customize;
         break;
      }
      
      if(m_ordered) {
         char tempCustomize[101];
         cout << "Special instructions\n" << "> ";
         cin.getline(tempCustomize, 100);

         if(tempCustomize[0] != '\0') {
            setCustomize(tempCustomize);
         } else {
            setCustomize(nullptr);
         }
      }

      return m_ordered;
   }
   bool Food::ordered() const {
      return m_ordered; 
   }
   ifstream& Food::read(ifstream& inf) {
      string line;
      if (getline(inf, line)) {
         m_child = false; 
         m_ordered = false;
         delete[] m_customize;
         m_customize = nullptr;

         string tempName{};
         string tempPriceStr{};
         double tempPrice{};
         stringstream ss(line); 

         if (getline(ss, tempName, ',')) setName(tempName.c_str());      
         if (getline(ss, tempPriceStr)) tempPrice = stod(tempPriceStr);
         setPrice(tempPrice);
      }
      return inf;
   }
   double Food::price() const {
      if(m_ordered && m_child) {
         return Billable::price() / 2;
      } else {
         return Billable::price();
      }        
   }
   ostream& operator<<(ostream& os, const Food& food) {
      os << food.name(); 
      return os;
   }
}
