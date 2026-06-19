#ifndef AUTHOR_H
#define AUTHOR_H
#include <iostream>
#include <string>
using namespace std;

class Book;

class Author {
	string name, idAuthor, biography;
	Book *book[100];
	int totalBooks;
	
	public :
		Author(string, string, string);		
		void addBook(Book *);
		void getBook();
		string getAuthorID();
	    string getAuthorName();
	    string getBiography();
		void displayAuthor();
		~Author();
};

#endif