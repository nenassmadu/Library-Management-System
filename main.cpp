#include "BasicMember.hpp"
#include "PremiumMember.hpp"
#include "admin.hpp"
#include "author.h"
#include "book.hpp"
#include "borrowRecord.hpp"
#include "membership.h"
#include "user.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

bool verifyLogin(int loginType, string un, string pw);

bool userLogin();
bool adminLogin();
void userMenu();
void adminMenu();

int main(){
    int loginOpt;

    do {
        cout << "\n==========================================" << endl;
        cout << "             LIBRARY LOGIN MENU             " << endl;
        cout << "==========================================" << endl;
        cout << "1. Login as User" << endl;
        cout << "2. Login as Admin" << endl;
        cout << "3. Exit System" << endl;
        cout << "Enter option: ";
        cin >> loginOpt;

        if (loginOpt == 1) {
            // Call login first. If it returns true, dive into the dashboard loop!
            if (userLogin() == true) { 
                userMenu(); 
            }
        } 
        else if (loginOpt == 2) {
            if (adminLogin() == true) {
                adminMenu(); // Inside here will be the admin dashboard loop
            }
        }
        else if (loginOpt == 3) {
            cout << "\nExiting system completely. Bye!" << endl;
        }
        else {
            cout << "\nInvalid option. Try again."<< endl;
        }

    } while (loginOpt != 3);
  
    system("pause");
    return 0;
}

bool userLogin(){

    cout << "\n--- Library Management System - User Portal ---" << endl;

    string finalUsername = "";
    string finalPassword = "";
    bool userAuthenticated = false;

    // 1. Loop until a matching Username and Password pair is validated from the text file
    while (userAuthenticated == false) {
        string inputUsername;
        string inputPassword;

        cout << "\n[LOGIN SCREEN]" << endl;
        cout << "Enter Username: ";
        cin >> inputUsername;
        cout << "Enter Password: ";
        cin >> inputPassword;

        ifstream userFile("user_list.txt");
        string userLine;

        // Scan the file line by line to verify matching records
        while (getline(userFile, userLine)) {
            if (userLine.empty()) continue; // Safeguard against trailing empty lines

            size_t firstComma = userLine.find(',');
            if (firstComma != string::npos) {

                size_t secondComma = userLine.find(',', firstComma + 1);

                string currentFileUser = userLine.substr(0, firstComma);
                string currentFilePass;
                string currentFileType;

                if (secondComma != string::npos) {
                    currentFilePass = userLine.substr(firstComma + 1, secondComma - firstComma - 1);
                } else {
                    currentFilePass = userLine.substr(firstComma + 1);
                }

                // Instantiating a temporary object to call our class authentication rules
                User checkProfile(currentFileUser, currentFilePass);

                if (checkProfile.login(inputUsername, inputPassword)) {
                    finalUsername = currentFileUser;
                    finalPassword = currentFilePass;
                    userAuthenticated = true;
                    break; // Exit file scan early since we found the match
                }
            }
        }
        userFile.close();

        if (userAuthenticated == false) {
            cout << "Invalid username or password. Try again." << endl;
            cout << "----------------------------------------------------" << endl;
        }
    }

    // 2. Initialize the official active Session Object for the verified guest
    User currentUser(finalUsername, finalPassword);

    cout << "\n==========================================" << endl;
    cout << "Login Successful. Welcome back, " << currentUser.getUsername() << "!" << endl;
    cout << "==========================================" << endl;
    
    // 3. Display User Profile Attributes using Class Accessor functions
    cout << "\n[Account Profile Details]" << endl;
    cout << "Username : " << currentUser.getUsername() << endl;
    cout << "Password : " << currentUser.getPassword() << endl;
    
    // Testing object validation method logic from user.cpp
    if (currentUser.validateLogin()) {
        cout << "Status   : Active Session Verification Pass" << endl;
    }
    
    cout << "\n------------------------------------------" << endl;
    
    return true;
}


bool adminLogin(){

     cout << "\n--- Admin Control Center ---" << endl;

    string npos;// npos = no position
    string adminName = "";
    string adminId = "";
    bool adminFound = false;

    // 1. Loop until a correct Admin ID is found in the text file
    while (adminFound == false) {
        string inputAdminId;
        cout << "Enter Admin ID to log in: ";
        cin >> inputAdminId;

        ifstream adminFile("admin_list.txt");
        string adminLine;

        while (getline(adminFile, adminLine)) {
            size_t comma = adminLine.find(',');
            if (comma != string :: npos) {
                string currentId = adminLine.substr(comma + 1);
                if (currentId == inputAdminId) {
                    adminName = adminLine.substr(0, comma);
                    adminId = currentId;
                    adminFound = true;
                }
            }
        }
        adminFile.close();

        if (adminFound == false) {
            cout << "Wrong ID! Try again.\n" << endl;
        }
    }

    // Create Admin object
    Admin admin1(adminName, adminId);
    cout << "\nWelcome Back, " << admin1.getName() << "!" << endl;
    cout << "--------------------------------------\n" << endl;
    
    return true;
}

void userMenu(){
    int choice;

    do{
        cout << "\n==========================================" << endl;
        cout << "               USER DASHBOARD             " << endl;
        cout << "==========================================" << endl;
        cout << "1. Search Book (Title / ISBN)" << endl;
        cout << "2. Borrow Book" << endl;
        cout << "3. Return Book & Calculate Fine" << endl;
        cout << "4. Search Author Info" << endl;
        cout << "5. Logout" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Enter option: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "\notw cari buku" << endl;
                break;
            case 2:
                cout << "\notw pinjam buku" << endl;
                break;
            case 3:
                cout << "\notw pulang buku" << endl;
                break;
            case 4:
                cout << "\notw cari author" << endl;
                break;
            case 5:
                cout << "\notw logout, back to main menu" << endl;
                break;
            default:
                cout << "\nmasukkan no yang ada je pls"<< endl;
        }
    }while (choice !=5 );
}

void adminMenu(){
    int choice;

    do{
        cout << "\n==========================================" << endl;
        cout << "               ADMIN DASHBOARD            " << endl;
        cout << "==========================================" << endl;
        cout << "1. Add New Book" << endl;
        cout << "2. Delete / Update Book Info" << endl;
        cout << "3. Display Users (Basic & Premium)" << endl;
        cout << "4. Logout" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Enter option: ";
        cin >> choice;

        switch(choice){
            case 1:
               cout << "\notw tambah buku" << endl;
               break;
            case 2:
               cout << "\notw delete or update" << endl;
               break;
            case 3:
               cout << "\notw tengok list user" << endl;
               break;
            case 4:
               cout << "\notw logout" << endl;
               break;
            default:
               cout << "\nsalah woi" << endl;
        }
    }while (choice != 4);
}








/*flow program 
1. menu untuk pilih login as user or admin or register new user
2. login
3. menu untuk user
   -1 untuk cari buku guna tajuk or isbn, keluar sekali maklumat buku and premium ke tak 
       + available ke tak
   -2 untuk user pinjam buku. maklumat pinjam masuk dalam list file. tukar
      availability buku kpd not available
   -3 untuk pemulangan, kira fine (if ada), tukar availability buku kpd available
   -4 untuk cari author, keluar semua maklumat dia and buku yang ditulis
   -5. logout
4.menu untuk admin
   -1 tambah buku dalam list
   -2 padam or update maklumat buku
   -3 keluarkan senarai user premium dgn basic
   -4 logout*/

