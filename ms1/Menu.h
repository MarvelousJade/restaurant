#ifndef SENECA_MENU_H
#define SENECA_MENU_H
#include <cstddef>
#include <iostream>
#include "Utils.h"
#include "constants.h"


namespace seneca {
   class Menu;
   class MenuItem {
      char* m_content;
      size_t m_indentationsCount;
      size_t m_indentationSize;
      int m_rowNumber;
      friend class Menu;

      void setEmpty();

      MenuItem(const char*,size_t,size_t, int);
      MenuItem(const MenuItem&) = delete;
      MenuItem& operator=(const MenuItem&) = delete;
      ~MenuItem();
      operator bool() const;
      std::ostream& display(std::ostream& = std::cout) const;
   };
   class Menu {
      size_t m_indentationsCount;
      size_t m_indentationSize;
      int m_menuItemsCount;
      MenuItem m_title;
      MenuItem m_exitOption;
      MenuItem m_entryPrompt;
      MenuItem* m_menuItems[MaximumNumberOfMenuItems];
   public:
      Menu(const char* title, 
          const char* exitOption = "Exit", 
          size_t indentationsCount = 0, 
          size_t indentationSize = 3);

      Menu& operator<<(const char*);

      // Prevent copying
      /*Menu(const Menu&) = delete;*/
      /*Menu& operator=(const Menu&) = delete;*/

      size_t select() const;
   };

   size_t operator<<(std::ostream& ostr, const Menu& menu);
}
#endif // !SENECA_MENU_H


