#ifndef BOOK_HPP
#define BOOK_HPP
#include <string>
using namespace std;

class Book{
    string ISBN;
    string title;
    bool isPremium;

    public:
       Book(string isbn = " ", string t = " ", bool PS = false);
       ~Book();
       string getISBN() const;
       string getTitle() const;
       bool getPremiumStatus() const;
       void setISBN(string);
       void setTitle(string);
       void setPremiumStatus(bool);
       void findBook() const;
       void availability() const;
       void premiumBook() const;
       void displayInfo() const;
};

#endif