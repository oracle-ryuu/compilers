#pragma once
#include<string>
using namespace std;


class ruleobj {
	ruleobj(int ID, int _lhs, int count) {
		ruleID = ID;	lhs = _lhs; kidCount = count;
	}
private:
	int ruleID;
	int lhs;// referring to symbols array

	int rhs[10] = { 0,0,0,0,0,0,0,0,0,0 };//referring to symbols array
	int kidCount;
public:
	int getID() { return ruleID; }
	int getLhs() { return lhs; }
	int getRhs(int slot) { return rhs[slot]; }
	int getCount() { return kidCount; }
	void setRhs(int slot, int inputrule) { rhs[slot] = inputrule; }

};
