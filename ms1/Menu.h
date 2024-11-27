#ifndef SENECA_MENU_H
#define SENECA_MENU_H
#include <iostream>

namespace seneca {
   class Manu {
      friend class MenuItem; 
   };
   class MenuItem {
      char* m_content;
      size_t m_indentationsCount;
      size_t m_indentationSize;
      int m_rowNumber;
      void setEmpty();

      MenuItem(const char*,size_t,size_t, int);
      MenuItem(const MenuItem&) = delete;
      MenuItem& operator=(const MenuItem&) = delete;
      ~MenuItem();
      operator bool() const;
      std::ostream& display(std::ostream& = std::cout) const;
   };

}
#endif // !SENECA_MENU_H


