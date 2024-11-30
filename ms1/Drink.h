#ifndef SENECA_DRINK_H
#define SENECA_DRINK_H
#include "Billable.h"
#include <ostream>

namespace seneca {
   class Drink : public Billable {
      char m_size;
   public:
      std::ostream& print(std::ostream &ostr = std::cout) const override;
      bool order() override;
      bool ordered() const override;
      std::ifstream & read(std::ifstream &file) override;
      double price() const override;
   };
   std::ostream& operator<<(std::ostream& os, const Drink&);
}
#endif // !SENECA_DRINK_H


