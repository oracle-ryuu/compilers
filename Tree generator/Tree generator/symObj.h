#pragma once
#include <string>
using namespace std;
class symObj {
public:
	symObj(int ID, string Name, bool isTerm) { symId = ID; symName = Name; isTerm = symKind; }
private:
	int symId;
	string symName;
	bool symKind; //0 for nonterminal 1 for terminal
public:
	int getSymid() { return symId; }
	int getSymkind() { return symKind; }
	string getSymName() { return symName; }
};


symObj* symArray[45];

void populatesymArray(){
	symArray[0] = new symObj(0, "epsilon", 1);
	symArray[1] = new symObj(1, "prog", 1);
	symArray[2] = new symObj(2, "input", 1);
	symArray[3] = new symObj(3, "print", 1);
	symArray[4] = new symObj(4, "while", 1);
	symArray[5] = new symObj(5, "if", 1);
	symArray[6] = new symObj(6, "elseif", 1);
	symArray[7] = new symObj(7, "else", 1);
	symArray[8] = new symObj(8, "brace1", 1);
	symArray[9] = new symObj(9, "brace2", 1);
	symArray[10] = new symObj(10, "paren1", 1);
	symArray[11] = new symObj(11, "paren2", 1);
	symArray[12] = new symObj(12, "semi", 1);
	symArray[13] = new symObj(13, "comma", 1);
	symArray[14] = new symObj(14, "id", 1);
	symArray[15] = new symObj(15, "int", 1);
	symArray[16] = new symObj(16, "float", 1);
	symArray[17] = new symObj(17, "string", 1);
	symArray[18] = new symObj(18, "plus", 1);
	symArray[19] = new symObj(19, "minus", 1);
	symArray[20] = new symObj(20, "aster", 1);
	symArray[21] = new symObj(21, "slash", 1);
	symArray[22] = new symObj(22, "caret", 1);
	symArray[23] = new symObj(23, "equal", 1);
	//nonterminals start here -----------------------------------------------------------
	symArray[24] = new symObj(24, "PGM", 0);
	symArray[25] = new symObj(25, "BLOCK", 0);
	symArray[26] = new symObj(26, "STMTS", 0);
	symArray[27] = new symObj(27, "STMT", 0);
	symArray[28] = new symObj(28, "ASTMT", 0);
	symArray[29] = new symObj(29, "Y", 0);
	symArray[30] = new symObj(30, "OSTMT", 0);
	symArray[31] = new symObj(31, "WSTMT", 0);
	symArray[32] = new symObj(32, "FSTMT", 0);
	symArray[33] = new symObj(33, "ELSE2", 0);
	symArray[34] = new symObj(34, "ELIST", 0);
	symArray[35] = new symObj(35, "ELIST2", 0);
	symArray[36] = new symObj(36, "E", 0);
	symArray[37] = new symObj(37, "Q", 0);
	symArray[38] = new symObj(38, "T", 0);
	symArray[39] = new symObj(39, "R", 0);
	symArray[40] = new symObj(40, "F", 0);
	symArray[41] = new symObj(41, "PERXPR", 0);
	symArray[42] = new symObj(42, "FATOM", 0);
	symArray[43] = new symObj(43, "OPADD", 0);
	symArray[44] = new symObj(44, "OPMUL", 0);
	

}