#ifndef BOOK_HPP
#define BOOK_HPP
#include <iostream>
#include <map>
using namespace std;

class Book{
    string ISBN;
    string title;
    bool isPremium;
    string status;

    public:
       Book(string isbn = " ", string t = " ", bool PS = false);
       string getISBN() const;
       string getTitle() const;
       bool getPremiumStatus() const;
       void setISBN(string);
       void setTitle(string);
       void setPremiumStatus(bool);
       void borrowBook(map<string, Book> &b);
       void setAvailability(string s);
       string setAvailability(string) const;
       string availability() const;
       void premiumBook() const;
       void displayInfo() const;
       ~Book();
};

#endif
