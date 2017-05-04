#pragma once

#ifndef DEFINITION_H
#define DEFINITION_H

#include <iostream>
#include <String>

//------------------------------------------ALL CLASSES ARE DEFINED HERE------------------------------------------------------

using namespace std;
class occurence //Class define for finding occurences within the symtab
{



private:
	int lineNum;
	bool defined; //whether being defined(true) or used(false)
};


class SymTabNode
{
public:
	//Add function for deifning






private:

	string name;    //name of identifier
	string value;    //What it is equals to
	int id;   		 //identifier for finding in list

	string type;    //type of identifier
	occurence Occurences[10];    //list of occurences in the code
};

SymTabNode symTable[20];
//-----Terminal--------   		 kwdprog | kwdinput | kwdprint | kwdwhile | kwdif | kwdelseif | kwdelse | brace1 | brace2 | paraen1 | paren2 | semi | comma |  id  |  int  | float | string | plus | minus | aster | slash | caret | equal | eps
int parsTable[22][24] = {		{    1    ,	  -1    ,	 -1    ,   -1     ,	 -1   ,	    -1    ,	    -1  ,    0   ,    -1  ,    -1   ,   -1   ,   -1 ,   -1  ,  -1  ,  -1   ,   -1  ,   -1   ,  -1  ,  -1   ,  -1   ,  -1   ,  -1   ,  -1   , -1 } //PGM
								{   -1    ,	  -1    ,	  0    ,    0     ,	  0   ,	    -1    ,	    -1  ,    2   ,    -1  ,    -1   ,   -1   ,   -1 ,   -1  ,   0  ,  -1   ,   -1  ,   -1   ,  -1  ,  -1   ,  -1   ,  -1   ,  -1   ,  -1   ,  0 } //BLOCK
								{   -1    ,	  -1    ,	  3    ,    3     ,	  3   ,	    -1    ,	    -1  ,   -1   ,    -1  ,    -1   ,   -1   ,   -1 ,   -1  ,   3  ,  -1   ,   -1  ,   -1   ,  -1  ,  -1   ,  -1   ,  -1   ,  -1   ,  -1   ,  0 } //STMTS
								{   -1    ,	  -1    ,	  4    ,    5     ,	  6   ,	    -1    ,	    -1  ,    1   ,    -1  ,  	0   ,   -1   ,   -1 ,   -1  ,   7  ,  -1   ,   -1  ,   -1   ,  -1  ,  -1   ,  -1   ,  -1   ,  -1   ,   0   , -1 } //STMT
								{   -1    ,	  -1    ,	 -1    ,   -1     ,	 -1   ,	    -1    ,	    -1  ,   -1   ,    -1  ,    -1   ,   -1   ,   -1 ,   -1  ,   8  ,  -1   ,   -1  ,   -1   ,  -1  ,  -1   ,  -1   ,  -1   ,  -1   ,  -1   , -1 } //ASTMT
								{   -1    ,	   9    ,	 -1    ,   -1     ,	 -1   ,	    -1    ,	    -1  ,    0   ,    -1  ,    -1   ,   -1   ,   -1 ,   -1  ,  10  ,  10   ,   10  ,   10   ,   0  ,   0   ,   0   ,   0   ,   0   ,  -1   ,  0 } //Y
								{   -1    ,	  -1    ,	 11    ,   -1     ,	 -1   ,	    -1    ,	    -1  ,   -1   ,    -1  ,    -1   ,   -1   ,   -1 ,   -1  ,  -1  ,  -1   ,   -1  ,   -1   ,  -1  ,  -1   ,  -1   ,  -1   ,  -1   ,  -1   , -1 } //OSTMT
}


#endif #pragma once
