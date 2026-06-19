#ifndef MEMBERSHIP_H
#define MEMBERSHIP_H
#include <iostream>
#include <string>
using namespace std;

class Membership {
		string memType, memID;
	
	public :
		Membership(string, string);		
		bool validateMembership(string);
		string getMemberType() const;
		string getMemberID() const;
		~Membership();
};

#endif