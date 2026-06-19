#include "BasicMember.hpp"
using namespace std;

BasicMember::BasicMember(string type, string idValue, int limit): Membership(type,idValue){
	borrowLimit = limit;
}

int BasicMember::getBorrowLimit(){
	return borrowLimit;
}

bool BasicMember::getPremium(){
	return false;
}