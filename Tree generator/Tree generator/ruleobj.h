#pragma once
#include<string>
using namespace std;


class ruleobj {
public:
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
	ruleArray[2]->setRhs(2, 9);

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
	ruleArray[8]->setRhs(0, 14);
	ruleArray[8]->setRhs(1, 23);
	ruleArray[8]->setRhs(2, 29);

	ruleArray[9] = new ruleobj(9, 29, 1);
	ruleArray[9]->setRhs(0, 2);

	ruleArray[10] = new ruleobj(10, 29, 1);
	ruleArray[10]->setRhs(0, 36);

	ruleArray[11] = new ruleobj(11, 30, 4);
	ruleArray[11]->setRhs(0, 3);
	ruleArray[11]->setRhs(1, 10);
	ruleArray[11]->setRhs(2, 34);
	ruleArray[11]->setRhs(3, 11);

	ruleArray[12] = new ruleobj(12, 31, 3);
	ruleArray[12]->setRhs(0, 4);
	ruleArray[12]->setRhs(1, 41);
	ruleArray[12]->setRhs(2, 25);

	ruleArray[13] = new ruleobj(13, 32, 4);
	ruleArray[13]->setRhs(0, 5);
	ruleArray[13]->setRhs(1, 41);
	ruleArray[13]->setRhs(2, 25);
	ruleArray[13]->setRhs(3, 33);

	ruleArray[14] = new ruleobj(14, 33, 4);
	ruleArray[14]->setRhs(0, 6);
	ruleArray[14]->setRhs(1, 41);
	ruleArray[14]->setRhs(2, 25);
	ruleArray[14]->setRhs(3, 33);

	ruleArray[15] = new ruleobj(15, 33, 2);
	ruleArray[15]->setRhs(0, 7);
	ruleArray[15]->setRhs(1, 25);

	ruleArray[16] = new ruleobj(16, 34, 2);
	ruleArray[16]->setRhs(0, 36);
	ruleArray[16]->setRhs(1, 35);

	ruleArray[17] = new ruleobj(17, 35, 2);
	ruleArray[17]->setRhs(0, 13);
	ruleArray[17]->setRhs(1, 34);

	ruleArray[18] = new ruleobj(18, 36, 2);
	ruleArray[18]->setRhs(0, 38);
	ruleArray[18]->setRhs(1, 37);

	ruleArray[19] = new ruleobj(19, 37, 3);
	ruleArray[19]->setRhs(0, 43);
	ruleArray[19]->setRhs(1, 38);
	ruleArray[19]->setRhs(2, 37);

	ruleArray[20] = new ruleobj(20, 38, 2);
	ruleArray[20]->setRhs(0, 40);
	ruleArray[20]->setRhs(1, 39);

	ruleArray[21] = new ruleobj(21, 39, 3);
	ruleArray[21]->setRhs(0, 44);
	ruleArray[21]->setRhs(1, 40);
	ruleArray[21]->setRhs(2, 39);

	ruleArray[22] = new ruleobj(22, 40, 1);
	ruleArray[22]->setRhs(0, 41);

	ruleArray[23] = new ruleobj(23, 40, 1);
	ruleArray[23]->setRhs(0, 42);

	ruleArray[24] = new ruleobj(24, 41, 3);
	ruleArray[24]->setRhs(0, 10);
	ruleArray[24]->setRhs(1, 36);
	ruleArray[24]->setRhs(2, 11);

	ruleArray[25] = new ruleobj(25, 42, 1);
	ruleArray[25]->setRhs(0, 14);

	ruleArray[26] = new ruleobj(26, 42, 1);
	ruleArray[26]->setRhs(0, 15);

	ruleArray[27] = new ruleobj(27, 42, 1);
	ruleArray[27]->setRhs(0, 16);

	ruleArray[28] = new ruleobj(28, 42, 1);
	ruleArray[28]->setRhs(0, 17);

	ruleArray[29] = new ruleobj(29, 43, 1);
	ruleArray[29]->setRhs(0, 18);

	ruleArray[30] = new ruleobj(30, 43, 1);
	ruleArray[30]->setRhs(0, 19);

	ruleArray[31] = new ruleobj(31, 44, 1);
	ruleArray[31]->setRhs(0, 20);

	ruleArray[32] = new ruleobj(32, 44, 1);
	ruleArray[32]->setRhs(0, 21);

	ruleArray[33] = new ruleobj(33, 44, 1);
	ruleArray[33]->setRhs(0, 22);


}