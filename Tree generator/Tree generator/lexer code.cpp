/*

Kim-Lan Hoang - khoangl@csu.fullerton.edu
Jared Vanotterdyk - oracleryuu@csu.fullerton.edu


CS323

Lexer Project
This a brief program that takes input of user and translate into tokens

*/



#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <deque>
#include <stack>
#include "tokenobj.h"
#include "symObj.h"
#include "ruleobj.h"
#include "Header.h"
#include "TreeNode.h"

using namespace std;

void checkString(string &search_store, queue<tokenobj*> &tokenQ, string keywords[], int keywordNum[], int linecount, int &varcount, fstream &myfile); //function that check if string exist
void lexerParser(queue<tokenobj*> &tokenQ);

int main() {
	//hello;
	fstream myfile;

	string input; // present implementation for what we’re reading in, will switch to file later
	string search_store = ""; //presently empty string, will store characters to comparison to keywords
	string keywords[] = { "prog", "main", "fcn", "class", "float", "int", "string", "if", "elseif", "else",
		"while", "input", "print", "new", "return" }; //list of keyword to compare with search_store
	int keywordNum[] = { 1, -1, -1, -1, -1, -1, -1, 5, 6, 7, 4, 2, 3, -1 };

	myfile.open("input.txt", ios::out | ios::trunc);
	cout << "Write into text file (-quit to exit)\n";

	if (myfile.is_open()) {
		while (input != "-quit") //write down text into file
		{
			getline(cin, input);
			if (input != "-quit")
			{
				myfile << input; //insert input
				myfile << endl; //create new line
			}
		}
		myfile.close();
	}
	myfile.open("input.txt", ios::in);
	if (myfile.is_open()) {
		myfile.seekg(0);
	}

	//input.append("d");

	char b;
	int linecount = 1; // counts number of lines
	int varcount = 1; //counts number of variables and symbols

	queue<tokenobj*> tokenQ;
	int tokenCount = 0;

	cout << "(:lang A3" << endl;
	while (myfile.get(b)) // for loop goes through every character in the string variable ‘input’
	{
		//cout << "(:token ";
	swtch_reboot:
		switch (b) { // Jared implement cases for punctuation //----------------------------------

		case '=':														//equal
			checkString(search_store, tokenQ, keywords, keywordNum, linecount, varcount, myfile);


			if (myfile.peek() == '=') { cout << "(:token " << linecount << " opec)" << endl; myfile.get(b); } 
			else { cout << "(:token " << linecount << " equal)" << endl;
			tokenQ.push(new tokenobj("equal", 23, "="));
			}
			varcount++;
			//cout << "=" << endl;
			break;

		case '<':
			checkString(search_store, tokenQ, keywords, keywordNum, linecount, varcount, myfile);


			if (myfile.peek() == '=') { cout << "(:token " << linecount << " ople)" << endl; myfile.get(b); }
			else if (myfile.peek() == '<') { cout << "(:token " << linecount << " opshl)" << endl; myfile.get(b); }
			else { cout << "(:token " << linecount << " angle1)" << endl; }
			varcount++;
			break;
		case '>':
			checkString(search_store, tokenQ, keywords, keywordNum, linecount, varcount, myfile);


			if (myfile.peek() == '=') { cout << "(:token " << linecount << " opge)" << endl; myfile.get(b); }
			else if (myfile.peek() == '>') { cout << "(:token " << linecount << " opshr)" << endl; myfile.get(b); }
			else { cout << "(:token " << linecount << " angle2)" << endl; }
			varcount++;
			break;

		case '!':
			checkString(search_store, tokenQ, keywords, keywordNum, linecount, varcount, myfile);


			if (myfile.peek() == '=') { cout << "(:token " << linecount << " opne)" << endl; myfile.get(b); }
			else { cout << "(:token " << linecount << " excl)" << endl; }
			varcount++;
			//cout << "=" << endl;
			break;
		case '-':															//minus
			checkString(search_store, tokenQ, keywords, keywordNum, linecount, varcount, myfile);


			if (myfile.peek() == '>') { cout << "(:token " << linecount << " oparrow)" << endl; myfile.get(b); } //check if next character is '>'
			else if (myfile.peek() == '0' | myfile.peek() == '1' | myfile.peek() == '2' | myfile.peek() == '3' | myfile.peek() == '4' |
				myfile.peek() == '5' | myfile.peek() == '6' | myfile.peek() == '7' | myfile.peek() == '8' | myfile.peek() == '9') //check if next character is a digit
			{
				search_store += b;
				myfile.get(b);
				bool once = false;

				while (b == '0' | b == '1' | b == '2' | b == '3' | b == '4' | b == '5' | b == '6' | b == '7' | b == '8' | b == '9' | b == '.') { //while the next character is a digit

					if (myfile.peek() == EOF) //If the pointer reach the end of the file
					{
						if (b == '0' | b == '1' | b == '2' | b == '3' | b == '4' |
							b == '5' | b == '6' | b == '7' | b == '8' | b == '9') //check if last character is digit
							search_store += b;

						else
							myfile.seekg(-1, myfile.end); //move pointer back if last character is not (it will move pointer forward when it starts over)

						break;

					}
					else if (b == '.' && !once)
					{
						search_store += b;
						myfile.get(b);
						once = true;
					}
					else if (b == '.' && once)
						break;

					else
					{
						search_store += b;
						myfile.get(b);
					}


				}

				if (once)
				{
					tokenQ.push(new tokenobj("float", 16, search_store));
					tokenCount++;

					cout << "(:token float str: \"" << search_store << "\") " << endl;
					search_store = "";
				}
				else
				{
					tokenQ.push(new tokenobj("int", 15, search_store));
					tokenCount++;

					cout << "(:token int str: \"" << search_store << "\") " << endl;
					search_store = "";
				}


			}

			else { cout << "(:token " << linecount << " minus)" << endl; 
			tokenQ.push(new tokenobj("minus", 19, "-"));
			tokenCount++;
			}
			varcount++;
			//cout << "=" << endl;
			break;



		case ',':														//comma done
			checkString(search_store, tokenQ, keywords, keywordNum, linecount, varcount, myfile);
			cout << "(:token " << linecount << " comma)" << endl;
			tokenQ.push(new tokenobj("comma", 13, ","));
			tokenCount++;
			varcount++;

			break;

		case ';':														//semi done
			checkString(search_store, tokenQ, keywords, keywordNum, linecount, varcount, myfile);
			cout << "(:token " << linecount << " semi)" << endl;
			tokenQ.push(new tokenobj("semicolon", 12, ";"));
			tokenCount++;
			varcount++;

			break;

		case '{':														//brace1 done
			checkString(search_store, tokenQ, keywords, keywordNum, linecount, varcount, myfile);
			cout << "(:token " << linecount << " brace1)" << endl;
			tokenQ.push(new tokenobj("brace1", 8, "{"));
			tokenCount++;
			varcount++;

			break;

		case '}':														//brace2 done
			checkString(search_store, tokenQ, keywords, keywordNum, linecount, varcount, myfile);
			cout << "(:token " << linecount << " brace2)" << endl;
			tokenQ.push(new tokenobj("brace2", 9, "}"));
			tokenCount++;
			varcount++;

			break;

		case '[':
			checkString(search_store, tokenQ, keywords, keywordNum, linecount, varcount, myfile);
			cout << "(:token " << linecount << " bracket1)" << endl;
			varcount++;

			break;

		case ']':
			checkString(search_store, tokenQ, keywords, keywordNum, linecount, varcount, myfile);
			cout << "(:token " << linecount << " bracket2)" << endl;
			varcount++;

			break;

		case '(':														//praen1
			checkString(search_store, tokenQ, keywords, keywordNum, linecount, varcount, myfile);
			cout << "(:token " << linecount << " parans1)" << endl;
			tokenQ.push(new tokenobj("paren1", 10, "("));
			tokenCount++;
			varcount++;

			break;

		case ')':														//paren2
			checkString(search_store, tokenQ, keywords, keywordNum, linecount, varcount, myfile);
			cout << "(:token " << linecount << " parans2)" << endl;
			tokenQ.push(new tokenobj("paren2", 11, ")"));
			tokenCount++;
			varcount++;

			break;

		case '*':														//aster
			checkString(search_store, tokenQ, keywords, keywordNum, linecount, varcount, myfile);
			cout << "(:token " << linecount << " aster)" << endl;
			tokenQ.push(new tokenobj("aster", 20, "*"));
			tokenCount++;
			varcount++;

			break;

		case '^':														//caret
			checkString(search_store, tokenQ, keywords, keywordNum, linecount, varcount, myfile);
			cout << "(:token " << linecount << " caret)" << endl;
			tokenQ.push(new tokenobj("caret", 22, "^"));
			tokenCount++;
			varcount++;

			break;

		case ':':
			checkString(search_store, tokenQ, keywords, keywordNum, linecount, varcount, myfile);
			cout << "(:token " << linecount << " colon)" << endl;
			varcount++;

			break;

		case '.':
			checkString(search_store, tokenQ, keywords, keywordNum, linecount, varcount, myfile);
			cout << "(:token " << linecount << " dot)" << endl;
			varcount++;

			break;

		case '+':														//plus
			checkString(search_store, tokenQ, keywords, keywordNum, linecount, varcount, myfile);
			cout << "(:token " << linecount << " plus)" << endl;
			tokenQ.push(new tokenobj("plus", 18, "+"));
			tokenCount++;
			varcount++;

			break;

		case '/':														//slash
			checkString(search_store, tokenQ, keywords, keywordNum, linecount, varcount, myfile);
			if (myfile.peek() == '/')
			{
				while (myfile.peek() != '\n')
				{
					myfile.get(b);
				}

			}
			else
			{
				cout << "(:token " << linecount << " slash)" << endl;
				tokenQ.push(new tokenobj("slash", 21, "/"));
				tokenCount++;
			}
				

			varcount++;
			break;


		case '"':

			//search_store += b;
			myfile.get(b);

			while (b != '"') //Loop until next quotation mark is found
			{
				if (b == '\\') //If bashlash is found, move pointer to next character
					myfile.get(b);

				search_store += b;
				myfile.get(b);
			}

			//search_store += b; //store end quotation mark

			cout << "(:token " << linecount << " string :str " << search_store << ")" << endl;
			tokenQ.push(new tokenobj("string", 17, search_store));
			tokenCount++;
			search_store = "";
			varcount++;

			break;

		case ' ':	//switch(search_store){}; // kim-implement cases for all the keywords
			checkString(search_store, tokenQ, keywords, keywordNum, linecount, varcount, myfile);


			break;

		case '_':

			search_store += b;

			break;

		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		floatcheck:
			if (myfile.peek() == '.'&& b != ' ') {
				//cout << "shit you have a float mate" << endl;
				search_store += b;
				myfile.get(b);
				if (myfile.peek() == '0' |
					myfile.peek() == '1' |
					myfile.peek() == '2' |
					myfile.peek() == '3' |
					myfile.peek() == '4' |
					myfile.peek() == '5' |
					myfile.peek() == '6' |
					myfile.peek() == '7' |
					myfile.peek() == '8' |
					myfile.peek() == '9') {
					//cout << "float." << endl;
					search_store += b;
					myfile.get(b);

				}
				else {
					cout << "(:token " << linecount << " int str: \"" << search_store << " \") " << endl;
					tokenQ.push(new tokenobj("float", 16, search_store));
					tokenCount++;
					search_store = "";
					goto swtch_reboot;
				}
			}



			while (b == '0' |
				b == '1' |
				b == '2' |
				b == '3' |
				b == '4' |
				b == '5' |
				b == '6' |
				b == '7' |
				b == '8' |
				b == '9')
			{
				//if(myfile.peek()!= EOF

				search_store += b;  //stores the present value into search_store
				if (myfile.peek() == EOF) { goto intloopend; }//skips potentially inccorectly rewriting to
				myfile.get(b);

				if (myfile.peek() == EOF)
				{
					if (b == '0' |
						b == '1' |
						b == '2' |
						b == '3' |
						b == '4' |
						b == '5' |
						b == '6' |
						b == '7' |
						b == '8' |
						b == '9')
					{
						search_store += b;
						goto intloopend;
					}
					else {
						cout << "(:token " << linecount << " int str: \"" << search_store << "\") " << endl;
						tokenQ.push(new tokenobj("int", 15, search_store));
						tokenCount++;
						search_store = "";
						goto swtch_reboot;
					}
					/*	if(isdigit(myfile.peek()))
					{
					search_store += b;
					}*/

				}

				goto floatcheck;
			}
		intloopend:
			for (char& c : search_store)
			{
				if (c == '.')
				{
					goto floatloopend;
				}
			}
			cout << "(:token " << linecount << " int str: \"" << search_store << "\") " << endl;
			tokenQ.push(new tokenobj("int", 15, search_store));
			tokenCount++;
			search_store = "";
			varcount++;
			if (b == '\n')
				goto newLineJump;

			break;

		floatloopend:
			cout << "(:token " << linecount << " float str: \"" << search_store << "\") " << endl;
			tokenQ.push(new tokenobj("float", 16, search_store));
			search_store = "";
			varcount++;
			if (b == '\n')
				goto newLineJump;

			break;


		case '\n': //check if at end of line
		newLineJump:

			checkString(search_store, tokenQ, keywords, keywordNum, linecount, varcount, myfile);

			linecount++;
			varcount = 1;

			break;

		default:
			search_store += b;

			break;

		}

		//count++;
		//b=c;
	}

	checkString(search_store, tokenQ, keywords, keywordNum, linecount, varcount, myfile);
	cout << ")" << endl;

	lexerParser(tokenQ);

	system("pause");
	return 0;
}


void checkString(string &search_store, queue<tokenobj*> &tokenQ, string keywords[], int keywordNum[], int linecount, int &varcount, fstream &myfile) //function that check if string exist
{
	if (search_store != "") //check if search_store contains a string
	{
		cout << "(:token " << linecount;
		int i;
		int j;
		for (i = 0; i < 15; i++) //go through list and compare keywords
		{
			if (search_store == keywords[i])
			{
				cout << " kwd" << keywords[i] << ")" << endl;
				j = i;
				i = 20;
			}
		}
		if (i == 15)
		{
			cout << " ident :ix " << varcount << " :str \"" << search_store << "\")" << endl; //}
			tokenQ.push(new tokenobj("id", 14, search_store));

		}
			
		else
		{
			if (keywordNum[j] != -1)
			{
				tokenQ.push(new tokenobj("kwd" + keywords[j], keywordNum[j], search_store));
			}
			
		}

		search_store = "";
		varcount++;
	}
}

void lexerParser(queue<tokenobj*> &tokenQ)
{
	populatesymArray();
	populateRuleArray();

	stack<symObj*> symS;
	symS.push(symArray[0]);
	symS.push(symArray[24]);
	SymTabNode head;
	int findRule = 0;

	while (!tokenQ.empty())
	{
		if (symS.top()->getSymid() == tokenQ.front()->tokenID())
		{
			cout << symS.top()->getSymName() << " found. popping off..." << endl;
			symS.pop(); tokenQ.pop();
		}
		else
		{
			findRule = parsTable[symS.top()->getSymid() - 24][tokenQ.front()->tokenID() - 1];
			symS.pop();
			cout << "use rule # " << findRule << endl;
			if (findRule == -1)
			{
				cerr << "The fudge man?! you type something wrong!" << endl;
				break;
			}
			else if (findRule == 0)
			{
				cout << "just pop it off." << endl;
			}
			else
			{
				for (int i = ruleArray[findRule]->getCount() - 1; i >= 0; i--)
				{
					symS.push(symArray[ruleArray[findRule]->getRhs(i)]);
				}
			}
		}
	}

}




