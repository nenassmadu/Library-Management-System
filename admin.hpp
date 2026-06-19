/*NAME : LILY AMIRA BATRISYA BINTI SHAHRUL SHAM
MATRIC : A25CS0082*/
#ifndef ADMIN_HPP
#define ADMIN_HPP
#include <iostream>
#include <string>
#include "user.hpp"
using namespace std;

class Admin {
private:
    string name;
    string IdAdmin;

public:
    // Constructor and Destructor 
    Admin();
    Admin(string n, string id);
    ~Admin();

    // Accessors 
    string getName() const;
    string getIdAdmin() const;

    // Mutators 
    void setName(string n);
    void setIdAdmin(string id);

    // Core methods
    void manageBook(string bookID) const;
    void manageUser(User* userPtr) const; // Implements Aggregation pointer
};

#endif