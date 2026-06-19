/*NAME : LILY AMIRA BATRISYA BINTI SHAHRUL SHAM
MATRIC : A25CS0082*/
#include "admin.hpp"
#include <iostream>
#include <string>
using namespace std;

// Default Constructor
Admin::Admin() : name(""), IdAdmin("") {}

// Constructor 
Admin::Admin(string n, string id) {
    name = n;
    IdAdmin = id;
} 

// Destructor 
Admin::~Admin() {}

// Accessor
string Admin::getName() const { 
    return name; 
}

string Admin::getIdAdmin() const { 
    return IdAdmin; 
}

// Mutator
void Admin::setName(string n) { 
    name = n; 
}

void Admin::setIdAdmin(string id) { 
    IdAdmin = id; 
}

//Main methods
void Admin::manageBook(string bookID) const {
    cout << "Admin " << name << " is processing book reference: " << bookID << endl;
}

// Manage user system
void Admin::manageUser(User* userPtr) const {
    if (userPtr != nullptr) {
        cout << "Admin " << name << " (ID: " << IdAdmin 
             << ") is modifying profile settings for user: " 
             << userPtr->getUsername() << endl;
    } else {
        cout << "No user assigned to manage." << endl;
    }
}