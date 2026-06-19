/*NAME : LILY AMIRA BATRISYA BINTI SHAHRUL SHAM
MATRIC : A25CS0082*/
#ifndef USER_HPP
#define USER_HPP
#include <iostream>
#include <string>
using namespace std;

class User {
private:
    string username;
    string password;

public:
    // Constructor and Destructor
    User();
    User(string un, string pw);
    ~User();

    // Accessors - do not modify data
    string getUsername() const;
    string getPassword() const;

    // Mutators          
    void setUsername(string un);
    void setPassword(string pw);

    // Core methods
    bool login(string username, string password) const;
    bool validateLogin() const;
};

#endif