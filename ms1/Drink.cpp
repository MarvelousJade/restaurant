#include <sstream>
#include <fstream>
#include <string>
#include "Drink.h"
#include "Billable.h"
#include "Menu.h"

using namespace std;
namespace seneca {
   ostream& Drink::print(ostream& ostr) const{
      ios::fmtflags originalFlags = ostr.flags();
      char originalFill = ostr.fill();

      ostr.width(28);
      ostr.setf(ios::left);
      ostr.fill('.');
      string str; 
      str.assign(name());
      ostr << str.substr(0, 25);
      switch(m_size) {
         case 'S':
            ostr << "SML..";
            break;
         case 'M':
            ostr << "MID..";
            break;
         case 'L':
            ostr << "LRG..";
            break;      
         case 'X':
            ostr << "XLR..";
            break; 
         default:
            ostr << ".....";
      }

      ostr.width(7);
      ostr.setf(ios::right);
      ostr.setf(ios::fixed);
      ostr.precision(2);
      ostr.fill(' ');
      ostr << price();

      ostr.flags(originalFlags);
      ostr.fill(originalFill);

      return ostr;
   }
   bool Drink::order() {
      size_t size{};

      Menu sizeMenu("Drink Size Selection", "Back", 1, 3);         
      sizeMenu << "Small" << "Medium" << "Large" << "Extra Large";

      size = sizeMenu.select();

      switch (size) {
      case 1:
         m_size = 'S';    
         return true;
      case 2:
         m_size = 'M';    
         return true;
      case 3:
         m_size = 'L';    
         return true;
      case 4:
         m_size = 'X';    
         return true;
      default:
         m_size = '\0';
         return false;
      }
   }
   bool Drink::ordered() const {
      if(m_size == 'S' 
         || m_size == 'M' 
         || m_size == 'L' 
         || m_size == 'X') {
      return true;
      } else {
         return false;
      }
   }
   ifstream& Drink::read(ifstream& inf) {
      string line;
      m_size = '\0'; 
      if (getline(inf, line)) {
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
   double Drink::price() const {
      switch (m_size) {
      case 'S':
         return Billable::price() / 2;
      case 'M':
         return Billable::price() * 3 / 4;
      case 'X':    
         return Billable::price() * 3 / 2;
      default:
         return Billable::price();
      }
   }
   ostream& operator<<(ostream& os, const Drink& drink) {
      os << drink.name(); 
      return os;
   }
}
