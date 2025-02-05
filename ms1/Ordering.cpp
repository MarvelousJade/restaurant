#include <iomanip>
#define _CRT_SECURE_NO_WARNINGS
#include "Drink.h"
#include "Food.h"
#include "Billable.h"
#include "Ordering.h"
#include "constants.h"
#include "Menu.h"
#include "Utils.h"
#include <cstdio>
#include <fstream>
using namespace std;
namespace seneca {
   Ordering::Ordering(const char* drinksFile, const char* foodsFile)
        : m_foodCounter(0), m_drinkCounter(0), m_billableCounter(0), m_billSerialNumber(1),
          m_foods(nullptr), m_drinks(nullptr) {
       size_t numDrinks = countRecords(drinksFile);
       size_t numFoods = countRecords(foodsFile);
       
       std::ifstream drinksStream(drinksFile);
       std::ifstream foodsStream(foodsFile);
       
       if (drinksStream && foodsStream) {
           m_drinks = new Drink[numDrinks];
           m_foods = new Food[numFoods];
           
           for (size_t i = 0; i < numDrinks; ++i) {
               if (m_drinks[i].read(drinksStream)) {
                   m_drinkCounter++;
               }
               else {
                   break;
               }
           }
           
           for (size_t i = 0; i < numFoods; ++i) {
               if (m_foods[i].read(foodsStream)) {
                   m_foodCounter++;
               }
               else {
                   break;
               }
           }
           
           if (m_drinkCounter != numDrinks || m_foodCounter != numFoods) {
               delete[] m_drinks;
               m_drinks = nullptr;
               delete[] m_foods;
               m_foods = nullptr;
           }
       }
   }

   Ordering::~Ordering() {
       delete[] m_drinks;
       delete[] m_foods;
       
       for (unsigned int i = 0; i < m_billableCounter; ++i) {
           delete m_billItems[i];
           m_billItems[i] = nullptr;
       }
   }

   size_t Ordering::countRecords(const char* file) const {
       size_t count = 0;
       std::ifstream fin(file);
       char ch;
       while (fin.get(ch)) {
           if (ch == '\n') count++;
       }
       return count;
   }

   Ordering::operator bool() const {
       return (m_drinks != nullptr && m_foods != nullptr);
   }

   size_t Ordering::noOfBillItems() const {
       return m_billableCounter;
   }

   bool Ordering::hasUnsavedBill() const {
       return m_billableCounter > 0;
   }

   void Ordering::listFoods() const {
       std::cout << "List Of Avaiable Meals\n";
       std::cout << "========================================\n";
       for (unsigned int i = 0; i < m_foodCounter; ++i) {
           m_foods[i].print(std::cout);
           std::cout << std::endl;
       }
       std::cout << "========================================\n";
   }

   void Ordering::listDrinks() const {
       std::cout << "List Of Avaiable Drinks\n";
       std::cout << "========================================\n";
       for (unsigned int i = 0; i < m_drinkCounter; ++i) {
           m_drinks[i].print(std::cout);
           std::cout << std::endl;
       }
       std::cout << "========================================\n";
   }

   void Ordering::orderFood() {
       Menu foodMenu("Food Menu", "Back to Order", 2, 3);
       for (unsigned int i = 0; i < m_foodCounter; ++i) {
           foodMenu << m_foods[i].name();
       }
       size_t selection = foodMenu.select();
       if (selection != 0 && selection <= m_foodCounter) {
           Food* orderedFood = new Food(m_foods[selection -1]); // Assuming copy constructor
           if (orderedFood->order()) { // Customize order
               if (m_billableCounter < MaximumNumberOfBillItems) {
                   m_billItems[m_billableCounter++] = orderedFood;
               }
               else {
                   std::cout << "Bill is full, cannot add more items.\n";
                   delete orderedFood;
               }
           }
           else {
               delete orderedFood;
           }
       }
       else if (selection == 0) {
       }
       else {
           std::cout << "Invalid selection.\n";
       }
   }

   void Ordering::orderDrink() {
       Menu drinkMenu("Drink Menu", "Back to Order", 2, 3);
       for (unsigned int i = 0; i < m_drinkCounter; ++i) {
           drinkMenu << m_drinks[i].name();
       }
       size_t selection = drinkMenu.select();
       if (selection != 0 && selection <= m_drinkCounter) {
           Drink* orderedDrink = new Drink(m_drinks[selection -1]); // Assuming copy constructor
           if (orderedDrink->order()) { // Customize order
               if (m_billableCounter < MaximumNumberOfBillItems) {
                   m_billItems[m_billableCounter++] = orderedDrink;
               }
               else {
                   std::cout << "Bill is full, cannot add more items.\n";
                   delete orderedDrink;
               }
           }
           else {
               delete orderedDrink;
           }
       }
       else if (selection == 0) {
       }
       else {
           std::cout << "Invalid selection.\n";
       }
   }

   void Ordering::printBillTitle(std::ostream& ostr) const {
       ostr << "Bill # " << std::setw(03) << std::setfill('0') << m_billSerialNumber << " =============================\n";
   }

   void Ordering::printTotals(std::ostream& ostr, double total) const {
       double tax = total * Tax;
       double grandTotal = total + tax;
       ostr << std::right << setfill(' ') << std::setw(28) << "Total: " << std::setw(12) << std::fixed << std::setprecision(2) << total << "\n";
       ostr << std::right << std::setw(26) << "Tax: " << std::setw(14) << tax << "\n";
       ostr << std::right << std::setw(32) << "Total+Tax: " << std::setw(8) << grandTotal << "\n";
       ostr << "========================================\n";
   }

   void Ordering::printBill(std::ostream& ostr) const {
       if (m_billableCounter == 0) {
           ostr << "No items in the bill.\n";
           return;
       }
       double total = 0.0;
       printBillTitle(ostr);
       for (unsigned int i = 0; i < m_billableCounter; ++i) {
           m_billItems[i]->print(ostr);
           ostr << "\n";
           total += m_billItems[i]->price();
       }
       printTotals(ostr, total);
   }

   void Ordering::resetBill() {
       if (m_billableCounter == 0) {
           std::cout << "No items to save.\n";
           return;
       }
       char billFilename[100];
       ut.makeBillFileName(billFilename, m_billSerialNumber);
       std::ofstream fout(billFilename);
       if (fout) {
           printBill(fout);
           fout.close();
           std::cout << "Saved bill number " << m_billSerialNumber << "\n";
           m_billSerialNumber++;
        
           std::cout << "Starting bill number " << m_billSerialNumber << "\n";
       }
       else {
           std::cout << "Error saving bill.\n";
           return;
       }

       // Reset bill items
       for (unsigned int i = 0; i < m_billableCounter; ++i) {
           delete m_billItems[i];
           m_billItems[i] = nullptr;
       }
       m_billableCounter = 0;
   }
}
