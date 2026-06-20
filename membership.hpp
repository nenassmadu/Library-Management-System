#ifndef MEMBERSHIP_HPP
#define MEMBERSHIP_HPP
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
