#include "book.hpp"
#include <iostream>
#include <string>
using namespace std;

Book::Book(string isbn, string t, bool PS){
    ISBN=isbn;
    title = t;
    isPremium = PS;
}

Book::~Book() {}

string Book :: getISBN() const{
    return ISBN;
}

string Book :: getTitle() const{
    return title;
}

bool Book::getPremiumStatus() const{ 
    return isPremium; 
}

void Book :: setISBN(string isbn){
    ISBN = isbn;
}

void Book :: setTitle(string t){
    title = t;
}

void Book::setPremiumStatus(bool PS){ 
    isPremium = PS; 
}

void Book :: findBook() const{
    cout << "Finding book: " << title << " (ISBN: " << ISBN << ")"<< endl;
}

void Book :: availability() const{
    cout << "Check the availability for : " << title << endl;
}

void Book::premiumBook() const { 
    if (isPremium) {
        cout << "[PREMIUM] This is a premium book. Premium membership required to borrow." << endl;
    } else {
        cout << "[REGULAR] This is a regular book. Available for all members." << endl;
    }
}

void Book :: displayInfo() const{
    cout << "------ Book Info ------" << endl;
    cout << "ISBN : " << ISBN << endl;
    cout << "Title : " << title << endl;
    cout << "Book Status : ";
    premiumBook();
}