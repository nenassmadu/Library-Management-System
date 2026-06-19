#include "PremiumMember.hpp"
using namespace std;

PremiumMember::PremiumMember(string type, string idValue, int limit, double rate):Membership(type,idValue){
	borrowLimit = limit;
	discountRate = rate;
}

int PremiumMember::getBorrowLimit(){
	return borrowLimit;
}

double PremiumMember::calcDiscountRate(double price){
	return price - (price*discountRate);
}

bool PremiumMember::getPremium(){
	return true;
} 