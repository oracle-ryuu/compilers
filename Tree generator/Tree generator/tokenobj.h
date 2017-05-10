#pragma once

#include<iostream>
#include <string>
#include <string.h>
using namespace std;

class tokenobj {
public:

	tokenobj(string type, int id, string name) { tokType = type; tokID = id; tokName = name; }
	string tokenType() { return tokType; }
	int tokenID() { return tokID; }
	string tokenName() { return tokName; }

private:

	string tokType;
	int tokID;
	string tokName;

};

// incomplete






