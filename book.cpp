#include "book.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
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

void Book :: loadBooks(vector<Book> &books) {
    books.clear();
    ifstream fin("book_list.txt");
    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string isbn, title, status;
        bool PS;
        getline(ss, isbn, ',');
        getline(ss, title, ',');
        ss >> PS;
        getline(ss, status);
        books.push_back(Book(isbn, title, PS));
    }
    fin.close();
}

void Book :: saveBooks(const vector<Book> &books) {
    ofstream fout("book_list.txt", ios::trunc);
    for (const auto &b : books) {
        fout << b.getISBN() << "," << b.getTitle() << "," << b.availability() << endl;
    }
    fout.close();
}

//update and delete book
void Book :: updateDelBook() {
	string isbn;
	vector<Book> books;
    loadBooks(books);
    
    int choice;
    cout << "1. Delete \n2.Update \nEnter choice :";
    cin >> choice;
    
    cout << "Enter ISBN : ";
    cin >> isbn;
    
    if (choice == 1) {
	    bool found = false;
	    for (auto &b : books) {
	        if (b.getISBN() == isbn) {
	            string newTitle;
	            cout << "Masukkan tajuk baru: ";
	            getline(cin, newTitle);
	            b.setTitle(newTitle); // Pastikan class Book ada setTitle
	            found = true;
	            break;
	        }
	    }
	    
	    if (found) {
	        saveBooks(books);
	        cout << "Buku berjaya dikemaskini!" << endl;
	    } else {
	        cout << "Buku tidak ditemui." << endl;
	    }
	}
    
    else {
	    bool found = false;
	    for (auto it = books.begin(); it != books.end(); ++it) {
	        if (it->getISBN() == isbn) {
	            books.erase(it);
	            found = true;
	            break;
	        }
	    }
	    
	    if (found) {
	        saveBooks(books);
	        cout << "Buku berjaya dipadam!" << endl;
	    } else {
	        cout << "Buku tidak ditemui." << endl;
	    }
	}
}

Book::~Book() {}
