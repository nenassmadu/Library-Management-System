#include "borrowRecord.hpp"
#include <iostream>
using namespace std;

BorrowRecord :: BorrowRecord (int bDay, int rDay, Book* bookPtr){
    borrowDay = bDay;
    returnDay = rDay;
    borrowedBook = bookPtr;
}

BorrowRecord :: ~BorrowRecord(){}

int BorrowRecord::getBorrowDay() const{ 
    return borrowDay; 
}

int BorrowRecord::getReturnDay() const{ 
    return returnDay;
 }

Book* BorrowRecord::getBorrowedBook() const{ 
    return borrowedBook; 
}

void BorrowRecord::setBorrowDay(int bday){
     borrowDay = bday; 
}

void BorrowRecord::setReturnDay(int rDay){
     returnDay = rDay; 
}

void BorrowRecord::setBorrowedBook(Book* bookPtr){ 
    borrowedBook = bookPtr; 
}

int BorrowRecord::getDuration() const {
    return returnDay - borrowDay;
}

double BorrowRecord :: calcFine () const {
    int duration = getDuration();
    int max = 5;
    double finePerDay = 0.50;

    int extraDays;

    if (duration > max){
        extraDays = duration - max;
        return extraDays * finePerDay;
    }

    return 0.0;
}

void BorrowRecord :: displayRecord() const{
    cout << "--- Borrow Record Details ---" << endl;
    cout << "Borrowed on Day : " << borrowDay << endl;
    cout << "Returned on Day : " << returnDay << endl;
    cout << "Total Duration  : " << getDuration() << " days" << endl;
    
    if (borrowedBook != nullptr) {
        std::cout << "Linked Book     : " << borrowedBook->getTitle() << " (ISBN: " << borrowedBook->getISBN() << ")" << endl;
    } else {
        cout << "No book currently linked to this record." << endl;
    }
}