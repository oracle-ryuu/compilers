#pragma once
#include<string>
using namespace std;


class ruleobj {
public:
	ruleobj(int ID, int _lhs, int count) {
		ruleID = ID;	lhs = _lhs; kidCount = count;
	}
	ruleobj(int ID) : ruleID(ID)

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
	void setRhs(int slot, int inputsym) { rhs[slot] = inputsym; }

};
ruleobj* ruleArray[33];

void populateRuleArray() 
{
	ruleArray[0] = new ruleobj(0, 0, 0);

	ruleArray[1] = new ruleobj(1, 24, 2);
	ruleArray[1]->setRhs(0, 1);
	ruleArray[1]->setRhs(1, 25);

	ruleArray[2] = new ruleobj(2, 25, 3);
	ruleArray[2]->setRhs(0, 8);
	ruleArray[2]->setRhs(1, 26);
	ruleArray[3]->setRhs(2, 9);

	ruleArray[3] = new ruleobj(3, 26, 3);
	ruleArray[3]->setRhs(0, 27);
	ruleArray[3]->setRhs(1, 12);
	ruleArray[3]->setRhs(2, 26);

	ruleArray[4] = new ruleobj(4, 27, 1);
	ruleArray[4]->setRhs(0, 30);

	ruleArray[5] = new ruleobj(5, 27, 1);
	ruleArray[5]->setRhs(0, 31);

	ruleArray[6] = new ruleobj(6, 27, 1);
	ruleArray[6]->setRhs(0, 32);

	ruleArray[7] = new ruleobj(7, 27, 1);
	ruleArray[7]->setRhs(0, 28);

	ruleArray[8] = new ruleobj(8, 28, 3);
	ruleArray[8]->setRhs(0, 18);
	ruleArray[8]->setRhs(1, 23);
	ruleArray[8]->setRhs(2, 29);

	ruleArray[9] = new ruleobj(9, 29, 1);
	ruleArray[9]->setRhs(0, 2);

	ruleArray[10] = new ruleobj(10, 29, 1);
	ruleArray[10]->setRhs(0, 36);


}