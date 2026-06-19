#ifndef BASICMEMBER_HPP
#define BASICMEMBER_HPP
#include "membership.h"
using namespace std;

class BasicMember : public Membership{
	private:
		int borrowLimit;
	
	public:
		BasicMember(string type, string idValue, int limit);
		int getBorrowLimit();
		bool getPremium();
};

#endif