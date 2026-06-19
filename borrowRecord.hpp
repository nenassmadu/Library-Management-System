#ifndef BORROWRECORD_HPP
#define BORROWRECORD_HPP
#include <iostream>
#include <string>
#include "book.hpp"
using namespace std;

class BorrowRecord{
    int borrowDay;
    int returnDay;

    Book* borrowedBook;

    public:
       BorrowRecord(int bDay = 0, int rDay = 0, Book* bookPtr = nullptr);
       ~BorrowRecord();

       int getBorrowDay() const;
       int getReturnDay() const;
       Book* getBorrowedBook() const;

       void setBorrowDay(int);
       void setReturnDay(int);
       void setBorrowedBook(Book* bookPtr);

       double calcFine() const;
       int getDuration() const;
       void displayRecord() const;
};

#endif