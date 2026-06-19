/*NAME : LILY AMIRA BATRISYA BINTI SHAHRUL SHAM
MATRIC : A25CS0082*/
#include "user.hpp"
#include <iostream>
#include <string>
using namespace std;

// Default constructor 
User::User() : username(""), password("") {}

// Constructor 
User::User(string un, string pw){
    username = un;
    password = pw;
}

// Destructor
User::~User() {}

// Accessor
string User::getUsername() const { 
    return username; 
}

string User::getPassword() const { 
    return password; 
}

// Mutators
void User::setUsername(string un){ 
    username = un; 
}

void User::setPassword(string pw) { 
    password = pw; 
}

// Verifies if login credentials match
bool User::login(string un, string pw) const {
    return (username == un && password == pw);
}

// Validates that fields are not empty
bool User::validateLogin() const {
    return (!username.empty() && !password.empty());
}
