#include "book.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
using namespace std;

Book::Book(string isbn, string t, bool PS){
    ISBN = isbn;
    title = t;
    isPremium = PS;
    status = "Available";
}

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

void Book :: borrowBook(map<string, Book> &b) {
	ifstream fin("book_list.txt");
    string line;
    
    while (getline(fin, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string bookTitle, isbn, isPrem, s;
        
        if (getline(ss, isbn, ',') &&
			getline(ss, bookTitle, ',') && 
			getline(ss, isPrem, ',') &&
			getline(ss, s)) {
            Book readBook;
            readBook.setTitle(bookTitle);
            readBook.setISBN(isbn);
            readBook.setPremiumStatus(isPrem == "1");
            readBook.setAvailability(s);
            
            b[bookTitle] = readBook;
        }
    }
    fin.close();
            
	cout << "\n--- Search Book ---" << endl;
	
	string searchtitle;
	cout << "Enter book title : ";
	cin.ignore();
	getline(cin, searchtitle);
	
	for (int i = 0; i < searchtitle.size(); i++)
		searchtitle[i] = toupper(searchtitle[i]);
		
	auto p = b.find(searchtitle);
	
	
	if (p != b.end()) {
		cout << "Book found\n";
		if (p->second.availability() == "0") {
            status = "Not Available";
            cout << "----------------------------------------" << endl;
            return;
        }
		p->second.displayInfo();
		char borrow = 'n';
		if (p->second.availability() == "1") {
			cout << "Borrow ? (y/n) : ";
			cin >> borrow;
			if (borrow == 'y' || borrow == 'Y'){
				p->second.setAvailability("0"); 
		        cout << "\nSuccess: Book successfully borrowed !" << endl;
		    }
		}
	}
	
	else {
		cout << "Book not found\n";
		status = "Not Available";
	}
	
	
}

void Book :: setAvailability(string s) {
	status = s;
}

string Book :: availability() const{
    return status;
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
    cout << "Book Status : " << status;
    premiumBook();
}

Book::~Book() {}
