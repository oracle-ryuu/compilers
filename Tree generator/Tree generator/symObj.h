#pragma once
#include <string>
using namespace std;
class symObj {
public:
	symObj(int ID, string Name, bool isTerm) { symId = ID; symName = Name; isTerm == symKind; }
private:
	int symId;
	string symName;
	bool symKind; //0 for nonterminal 1 for terminal
public:

};


symObj* symArrayT[24];
symObj* symArrayNT[21];
void populateSymArrayT(){
	symArrayT[0] = new symObj(0, "epsilon", 1);
	symArrayT[1] = new symObj(1, "prog", 1);
	symArrayT[2] = new symObj(2, "input", 1);
	symArrayT[3] = new symObj(3, "print", 1);
	symArrayT[4] = new symObj(4, "while", 1);
	symArrayT[5] = new symObj(5, "if", 1);
	symArrayT[6] = new symObj(6, "elseif", 1);
	symArrayT[7] = new symObj(7, "else", 1);
	symArrayT[8] = new symObj(8, "brace1", 1);
	symArrayT[9] = new symObj(9, "brace2", 1);
	symArrayT[10] = new symObj(10, "paren1", 1);
	symArrayT[11] = new symObj(11, "paren2", 1);
	symArrayT[12] = new symObj(12, "semicolon", 1);
	symArrayT[13] = new symObj(13, "comma", 1);
	symArrayT[14] = new symObj(14, "id", 1);
	symArrayT[15] = new symObj(15, "int", 1);
	symArrayT[16] = new symObj(16, "float", 1);
	symArrayT[17] = new symObj(17, "string", 1);
	symArrayT[18] = new symObj(181, "plus", 1);
	symArrayT[19] = new symObj(19, "minus", 1);
	symArrayT[20] = new symObj(20, "aster", 1);
	symArrayT[21] = new symObj(21, "slash", 1);
	symArrayT[22] = new symObj(22, "caret", 1);
	symArrayT[23] = new symObj(23, "equal", 1);

}
void populateSymArrayNT() {
	symArrayNT[0] = new symObj(0, "PGM", 0);
	symArrayNT[1] = new symObj(1, "BLOCK", 0);
	symArrayNT[2] = new symObj(2, "STMTS", 0);
	symArrayNT[3] = new symObj(3, "STMT", 0);
	symArrayNT[4] = new symObj(4, "ASTMT", 0);
	symArrayNT[5] = new symObj(5, "Y", 0);
	symArrayNT[6] = new symObj(6, "OSTMT", 0);
	symArrayNT[7] = new symObj(7, "WSTMT", 0);
	symArrayNT[8] = new symObj(8, "FSTMT", 0);
	symArrayNT[9] = new symObj(9, "ELSE2", 0);
	symArrayNT[11] = new symObj(11, "ELIST", 0);
	symArrayNT[12] = new symObj(12, "ELIST2", 0);
	symArrayNT[13] = new symObj(13, "E", 0);
	symArrayNT[14] = new symObj(14, "Q", 0);
	symArrayNT[15] = new symObj(15, "T", 0);
	symArrayNT[16] = new symObj(16, "R", 0);
	symArrayNT[17] = new symObj(17, "F", 0);
	symArrayNT[18] = new symObj(181, "PERXPR", 0);
	symArrayNT[19] = new symObj(19, "FATOM", 0);
	symArrayNT[20] = new symObj(20, "OPADD", 0);
	symArrayNT[21] = new symObj(21, "OPMUL", 0);
	

}