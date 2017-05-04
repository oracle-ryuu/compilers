#pragma once
#include <string>
using namespace std;
class symObj {
	symObj(int ID, string Name, bool isTerm) { symId = ID; symName = Name; isTerm == symKind; }
private:
	int symId;
	string symName;
	bool symKind; //0 for nonterminal-1 for terminal
public:

};