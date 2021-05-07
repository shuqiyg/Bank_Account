/* W05 LAB
   Name: Shuqi Yang
   Std ID: 132162207
   Email: syang136@myseneca.ca
   Date: 02-15-2021
   -------------------------------------------------------
   I have done all the coding by myself and only copied the
   code that my professor provided to complete my workshops
   and assignments.

 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance >= 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }
   Account::operator bool()const {
       return m_number >= 10000 && m_number <= 99999
           && m_balance >= 0;
   }
   Account::operator int()const {
       return m_number;
   }
   Account::operator double()const {
       return m_balance;
   }
   bool Account::operator~() const{
       return m_number == 0;
   }
   Account& Account::operator=(int acc_num) {
       if (m_number == 0) {
           if (acc_num < 10000 || acc_num > 99999) {
               setEmpty();
           }
           else {
               this->m_number = acc_num;
           }
       }
       return *this;
   }
   Account& Account::operator=(Account& right) {
       if (bool(right) && int(*this) == 0) {
           this->m_balance = right.m_balance;
           right.m_balance = 0;
           this->m_number = right.m_number;
           right.m_number = 0;
       }
       return *this;
   }
   Account& Account::operator+=(double deposit) {
       if (bool(*this) && deposit >= 0 ) {
           this->m_balance += deposit;
       }
       return *this;
   }
   Account& Account::operator-=(double withdraw) {
       if (bool(*this) && withdraw >= 0 && double(*this) >= withdraw) {
           this->m_balance -= withdraw;
       }
       return *this;
   }
   Account& Account::operator<<(Account& right) {
       if (bool(*this) && bool(right) && int(*this) != int(right)) {
           this->m_balance += right.m_balance;
           right.m_balance = 0;
       }
       return *this;
   }
   Account& Account::operator>>(Account& right) {
       if (bool(*this) && bool(right) && int(*this) != int(right)) {
           right.m_balance += this->m_balance;
           this->m_balance = 0;
       }
       return *this;
   }
   double operator+(const Account& left, const Account& right) {
       if (bool(left) && bool(right)) {
           return double(left) + double(right);
       }
       return 0;
   }
   double operator+=(double& left, const Account& right) {
       if (left >= 0 && bool(right)) {
           return left += double(right);
       }
       return left;
   }
}