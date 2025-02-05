#ifndef SENECA_FOOD_H
#define SENECA_FOOD_H
#include "Billable.h"
namespace seneca {
   class Food : public Billable {
      bool m_ordered;
      bool m_child;
      char* m_customize;
   protected:
      void setCustomize(const char* customize);
   public:
      Food();
      Food(Food&);
      Food& operator=(const Food&);
      ~Food();
      std::ostream& print(std::ostream &ostr = std::cout) const override;
      bool order() override;
      bool ordered() const override;
      std::ifstream & read(std::ifstream &file) override;
      double price() const override;
   };
   std::ostream& operator<<(std::ostream& os, const Food& food);
}
#endif // !SENECA_FOOD_H


