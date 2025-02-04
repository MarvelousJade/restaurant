#ifndef SENECA_ORDERING_H
#define SENECA_ORDERING_H
#include "Food.h"
#include "Drink.h"
#include "Billable.h"
#include "constants.h"
#include <iostream>
namespace seneca {
   class Ordering { 
      unsigned int m_foodCounter;
      unsigned int m_drinkCounter;
      unsigned int m_billableCounter;
      unsigned int m_billSerialNumber;
      Food *m_foods;
      Drink *m_drinks;
      Billable *m_billItems[MaximumNumberOfBillItems];

      void printBillTitle(std::ostream &ostr) const;
      void printTotals(std::ostream &ostr, double total) const;
      size_t countRecords(const char *file) const;

      // Prevent copying
      Ordering(const Ordering &) = delete;
      Ordering &operator=(const Ordering &) = delete;
   public:
      Ordering(const char *drinksFile, const char *foodsFile);
      ~Ordering();

      operator bool() const;
      size_t noOfBillItems() const;
      bool hasUnsavedBill() const;

      void listFoods() const;
      void listDrinks() const;
      void orderFood();
      void orderDrink();
      void printBill(std::ostream &ostr) const;
      void resetBill();
   };
}
#endif // !SENECA_ORDERING_H


