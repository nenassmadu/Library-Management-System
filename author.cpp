#include "author.hpp"
#include "book.hpp"
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
using namespace std;

Author :: Author(string n, string id, string bio) {
    name = n;
    idAuthor = id;
    biography = bio;
    totalBooks = 0;
}

void Author :: addBook(Book *b) {
	string title = b->getTitle();

    for (int i = 0; i < title.length(); i++) {
        title[i] = toupper(title[i]);
    }
    
	ofstream fout("book_list.txt", ios::app);
    
    if (fout.is_open()) {
        fout << b->getISBN() << "," 
             << title<< "," 
             << "1" << endl;
             
    fout.close();
    cout << "New book was added successfully!" << endl;
    } 
	else {
    	cout << "Error. Book cannot be added." << endl;
    }
}

void Author :: getBook(map<string, Book> &b) {    
    bool match = false;
    
    string subID = idAuthor.substr(idAuthor.size() - 1);
    
    int count = 1;
    for (auto const& p : b) {
        string isbn = p.second.getISBN();
        string subISBN = isbn.substr(isbn.size() - 1);
        
	    if (subID == subISBN) {
	    	cout << count << ". " << p.second.getTitle() << endl;
	        count++;
	    }
    }
    
    if (count == 1) {
        cout << "No books registered under this author" << endl;
	}    
}

string Author :: getAuthorID() const {
    return idAuthor;
}

string Author :: getAuthorName() const {
    return name;
}

string Author :: getBiography() const {
    return biography;
}

void Author :: findAuthor(map<string, Book> &b) {
	cout << "\n--- Search Author Info ---" << endl;
    string searchName;
    cout << "Enter Author Name : ";
    cin.ignore();
    getline(cin, searchName);
    
    for (int i = 0; i < searchName.size(); i++) {
        searchName[i] = toupper(searchName[i]);
    }

    ifstream fin("author_list.txt");

    string line;
    bool found = false;

    while (getline(fin, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string id, aName, bio;

        if (getline(ss, id, ',') && getline(ss, aName, ',') && getline(ss, bio)) {
            
            string subName;
            if (searchName.size() <= aName.size()) {
                subName = aName.substr(0, searchName.size());
            }

            if (subName == searchName) {
                idAuthor = id;
                name = aName;
                biography = bio;
                found = true;
                //break;
            }
        }
    }
        
    fin.close();

    if (found) {
        cout << endl;
        displayAuthor(b); 
    } else {
        cout << "\nResult: Author not found in the database!" << endl;
    }
}

void Author :: displayAuthor(map<string, Book> &b) {
	cout << "===== AUTHOR INFO =====" << endl;
	cout << "Author Name : " << name << endl
		 << "Author ID   : " << idAuthor << endl
		 << "Biography   : " << biography << endl;
	
	getBook(b);
}

Author :: ~Author() {}
