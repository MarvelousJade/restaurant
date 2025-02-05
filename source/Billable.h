#ifndef SENECA_BILLABLE_H
#define SENECA_BILLABLE_H
#include <iostream>
#include <ostream>
namespace seneca {
   class Billable {
      char* m_name;
      double m_price;
   protected:
      void setPrice(double value);
      void setName(const char* name);
   public:
      Billable();
      Billable(Billable&);
      Billable& operator=(const Billable&);
      virtual ~Billable();
      virtual const char* name() const;
      virtual double price() const;  
      virtual std::ostream& print(std::ostream& ostr=std::cout) const = 0;
      virtual bool order() = 0;
      virtual bool ordered()const = 0;
      virtual std::ifstream& read(std::ifstream& file) = 0;
   };
   double operator+(double money, const Billable& B);
   double& operator+=(double& money, const Billable& B);
}
#endif // !SENECA_BILLABLE_H
