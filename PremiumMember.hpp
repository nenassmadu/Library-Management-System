#ifndef PREMIUMMEMBER_HPP
#define PREMIUMMEMBER_HPP
#include "membership.h"
using namespace std;

class PremiumMember:public Membership{
	private:
		int borrowLimit;
		double discountRate;
	
	public:
		PremiumMember(string type, string idValue, int limit, double rate);
		int getBorrowLimit();
		double calcDiscountRate(double price);
		bool getPremium();
};

#endif
