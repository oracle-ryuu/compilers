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
//-----Terminal--------   		 kwdprog | kwdinput |kwdprint |kwdwhile |kwdif |kwdelseif |kwdelse | brace1 |brace2
string parsTable[22][24] = { { "kwdprog Block", "N/A", "N/A" , "N/A" , "N/A" , "N/A" , "N/A" , "eps" , "N/A" , "N/A" , "N/A" , "N/A" , "N/A" , "N/A" , "N/A" , "N/A" , "N/A" , "N/A" , "N/A" , "N/A" , "N/A" , "N/A" , "N/A" , "eps } };


#endif #pragma once
