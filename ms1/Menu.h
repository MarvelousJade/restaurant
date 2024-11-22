#ifndef SENECA_MENU_H
#define SENECA_MENU_H
#include <iostream>

namespace seneca {
   class MenuItem {
      char* m_content;
      size_t m_indentations;
      size_t m_indentationSize;
      int m_rowNumber;
      void setEmpty();
   public:
      MenuItem(const char*,size_t,size_t, int);
      MenuItem(const MenuItem&) = delete;
      MenuItem& operator=(const MenuItem&) = delete;
      ~MenuItem();
      operator bool() const;
      std::ostream& display(std::ostream& = std::cout) const;
   };

}
#endif // !SENECA_MENU_H


