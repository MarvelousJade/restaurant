/***********************************************************************
// OOP244 Project, Utils Module
//
// File	Utils.h
// Version 0.1
// Date 2024-9-11
// started by Fardad
// Description
// utility function to be used in the project
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Shaoyu Fan      2024-11-13      Preliminary release
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include <cctype>
#include "Utils.h"
using namespace std;
namespace seneca {
   Utils ut;

   char* Utils::alocpy(const char* src) const{
      char* des{};
      return alocpy(des, src);
   }

   char* Utils::alocpy(char*& des, const char* src)const {
      delete[] des;
      des = nullptr;
      if (src) {
         des = new char[strlen(src) + 1];
         strcpy(des, src);
      }
      return des;
   }
   char* Utils::strcpy(char* des, const char* src)const {
      int i;
      for (i = 0; src[i]; i++) des[i] = src[i];
      des[i] = char(0);
      return des;
   }
   int Utils::strlen(const char* str)const {
      int len;
      for (len = 0; str[len]; len++);
      return len;
   }

   bool Utils::isspace(char ch)const {
      return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r';
   }

   bool Utils::isspace(const char* cstring) const{
      while (cstring && isspace(*cstring)) {
         cstring++;
      }
      return cstring && *cstring == 0;
   }

   int Utils::getInt() {
      string input;
      int validInt;
      
      while(true) {
         getline(cin, input);
         
         if(input.empty()) {
            cout << "You must enter a value: ";
            continue;
         }
         
         stringstream ss(input); 
         if(!(ss >> validInt)) {
            cout << "Invalid integer: ";
            continue;
         }

         char trailing;
         if(ss >> trailing) {
            cout << "Only an integer please: ";
            continue;
         }
         
         return validInt;
      }
   }

   int Utils::getInt(int min, int max) {
      int validInt;
      while(true) {
         validInt = getInt();
         
         if(validInt >= min && validInt <= max) {
            return validInt;
         } else {
            cout << "Invalid value: [" << min << "<= value <=" << max << "], try again: ";
         }
      }
   }
}
