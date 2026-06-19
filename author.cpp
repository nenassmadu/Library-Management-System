#include "author.h"
#include "book.hpp"
#include <iostream>
using namespace std;

//class Book;

Author :: Author(string n, string id, string bio) {
	name = n;
	idAuthor = id;
	biography = bio;
}

void Author :: addBook(Book *b) {
	book[totalBooks] = b;
	totalBooks++;
}

void Author :: getBook() {
	cout << "\nBooks Written By " << name << " : " << endl;
	for (int i = 0; i < totalBooks; i++)
		cout << i+1 << ". " << book[i]->getTitle() << endl;
}

string Author :: getAuthorID()
{
    return idAuthor;
}

string Author :: getAuthorName()
{
    return name;
}

string Author :: getBiography()
{
    return biography;
}

void Author :: displayAuthor() {
	cout << "\n===== AUTHOR INFO =====" << endl;
	cout << "Author Name : " << name << endl
		 << "Author ID   : " << idAuthor << endl
		 << "Biography   : " << biography << endl;
	
	getBook();
}

Author :: ~Author() {}