#include "membership.hpp"

Membership :: Membership(string t, string id) {
	memType = t;
	memID = id;
}

bool Membership :: validateMembership(string MemberId) {
	return MemberId == memID;
}

string Membership :: getMemberType() const {
	return memType;
}

string Membership :: getMemberID() const {
	return memID;
}

Membership :: ~Membership() {}
