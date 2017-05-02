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
using namespace std;

void checkString(string &search_store, string keywords[], int linecount, int &varcount); //function that check if string exist


int main() {
	//hello;
	fstream myfile;

	string input; // present implementation for what we’re reading in, will switch to file later
	string search_store = ""; //presently empty string, will store characters to comparison to keywords
	string keywords[] = { "prog", "main", "fcn", "class", "float", "int", "string", "if", "elseif", "else",
		"while", "input", "print", "new", "return" }; //list of keyword to compare with search_store

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

	cout << "(:lang A3" << endl;
	while (myfile.get(b)) // for loop goes through every character in the string variable ‘input’
	{
		//cout << "(:token ";
	swtch_reboot:
		switch (b) { // Jared implement cases for punctuation //----------------------------------

		case '=':
			checkString(search_store, keywords, linecount, varcount);


			if (myfile.peek() == '=') { cout << "(:token " << linecount << " opec)" << endl; myfile.get(b); }
			else { cout << "(:token " << linecount << " equal)" << endl; }
			varcount++;
			//cout << "=" << endl;
			break;

		case '<':
			checkString(search_store, keywords, linecount, varcount);


			if (myfile.peek() == '=') { cout << "(:token " << linecount << " ople)" << endl; myfile.get(b); }
			else if (myfile.peek() == '<') { cout << "(:token " << linecount << " opshl)" << endl; myfile.get(b); }
			else { cout << "(:token " << linecount << " angle1)" << endl; }
			varcount++;
			break;
		case '>':
			checkString(search_store, keywords, linecount, varcount);


			if (myfile.peek() == '=') { cout << "(:token " << linecount << " opge)" << endl; myfile.get(b); }
			else if (myfile.peek() == '>') { cout << "(:token " << linecount << " opshr)" << endl; myfile.get(b); }
			else { cout << "(:token " << linecount << " angle2)" << endl; }
			varcount++;
			break;

		case '!':
			checkString(search_store, keywords, linecount, varcount);


			if (myfile.peek() == '=') { cout << "(:token " << linecount << " opne)" << endl; myfile.get(b); }
			else { cout << "(:token " << linecount << " excl)" << endl; }
			varcount++;
			//cout << "=" << endl;
			break;
		case '-':
			checkString(search_store, keywords, linecount, varcount);


			if (myfile.peek() == '>') { cout << "(:token " << linecount << " oparrow)" << endl; myfile.get(b); } //check if next character is '>'
			else if (myfile.peek() == '0' | myfile.peek() == '1' | myfile.peek() == '2' | myfile.peek() == '3' | myfile.peek() == '4' |
				myfile.peek() == '5' | myfile.peek() == '6' | myfile.peek() == '7' | myfile.peek() == '8' | myfile.peek() == '9') //check if next character is a digit
			{
				search_store += b;
				myfile.get(b);

				while (b == '0' | b == '1' | b == '2' | b == '3' | b == '4' | b == '5' | b == '6' | b == '7' | b == '8' | b == '9') { //while the next character is a digit

					if (myfile.peek() == EOF) //If the pointer reach the end of the file
					{
						if (b == '0' | b == '1' | b == '2' | b == '3' | b == '4' |
							b == '5' | b == '6' | b == '7' | b == '8' | b == '9') //check if last character is digit
							search_store += b;

						else
							myfile.seekg(-1, myfile.end); //move pointer back if last character is not (it will move pointer forward when it starts over)

						break;

					}
					else
					{
						search_store += b;
						myfile.get(b);
					}


				}

				cout << "(:token int str: \"" << search_store << "\") " << endl;
				search_store = "";

			}

			else { cout << "(:token " << linecount << " minus)" << endl; }
			varcount++;
			//cout << "=" << endl;
			break;



		case ',':
			checkString(search_store, keywords, linecount, varcount);
			cout << "(:token " << linecount << " comma)" << endl;
			varcount++;

			break;

		case ';':
			checkString(search_store, keywords, linecount, varcount);
			cout << "(:token " << linecount << " semi)" << endl;
			varcount++;

			break;

		case '{':
			checkString(search_store, keywords, linecount, varcount);
			cout << "(:token " << linecount << " brace1)" << endl;
			varcount++;

			break;

		case '}':
			checkString(search_store, keywords, linecount, varcount);
			cout << "(:token " << linecount << " brace2)" << endl;
			varcount++;

			break;

		case '[':
			checkString(search_store, keywords, linecount, varcount);
			cout << "(:token " << linecount << " bracket1)" << endl;
			varcount++;

			break;

		case ']':
			checkString(search_store, keywords, linecount, varcount);
			cout << "(:token " << linecount << " bracket2)" << endl;
			varcount++;

			break;

		case '(':
			checkString(search_store, keywords, linecount, varcount);
			cout << "(:token " << linecount << " parans1)" << endl;
			varcount++;

			break;

		case ')':
			checkString(search_store, keywords, linecount, varcount);
			cout << "(:token " << linecount << " parans2)" << endl;
			varcount++;

			break;

		case '*':
			checkString(search_store, keywords, linecount, varcount);
			cout << "(:token " << linecount << " aster)" << endl;
			varcount++;

			break;

		case '^':
			checkString(search_store, keywords, linecount, varcount);
			cout << "(:token " << linecount << " caret)" << endl;
			varcount++;

			break;

		case ':':
			checkString(search_store, keywords, linecount, varcount);
			cout << "(:token " << linecount << " colon)" << endl;
			varcount++;

			break;

		case '.':
			checkString(search_store, keywords, linecount, varcount);
			cout << "(:token " << linecount << " dot)" << endl;
			varcount++;

			break;

		case '+':
			checkString(search_store, keywords, linecount, varcount);
			cout << "(:token " << linecount << " plus)" << endl;
			varcount++;

			break;

		case '/':
			checkString(search_store, keywords, linecount, varcount);
			if (myfile.peek() == '/')
			{
				while (myfile.peek() != '\n')
				{
					myfile.get(b);
				}

			}
			else
				cout << "(:token " << linecount << " slash)" << endl;

			varcount++;
			break;


		case '"':

			search_store += b;
			myfile.get(b);

			while (b != '"') //Loop until next quotation mark is found
			{
				if (b == '\\') //If bashlash is found, move pointer to next character
					myfile.get(b);

				search_store += b;
				myfile.get(b);
			}

			search_store += b; //store end quotation mark

			cout << "(:token " << linecount << " string :str " << search_store << ")" << endl;

			search_store = "";
			varcount++;

			break;

		case ' ':	//switch(search_store){}; // kim-implement cases for all the keywords
			checkString(search_store, keywords, linecount, varcount);


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
			search_store = "";
			varcount++;
			if (b == '\n')
				goto newLineJump;

			break;

		floatloopend:
			cout << "(:token " << linecount << " float str: \"" << search_store << "\") " << endl;
			search_store = "";
			varcount++;
			if (b == '\n')
				goto newLineJump;

			break;


		case '\n': //check if at end of line
		newLineJump:

			checkString(search_store, keywords, linecount, varcount);

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

	checkString(search_store, keywords, linecount, varcount);

	cout << ")" << endl;
	system("pause");
	return 0;
}


void checkString(string &search_store, string keywords[], int linecount, int &varcount) //function that check if string exist
{
	if (search_store != "") //check if search_store contains a string
	{
		cout << "(:token " << linecount;
		int i;
		for (i = 0; i < 15; i++) //go through list and compare keywords
		{
			if (search_store == keywords[i])
			{
				cout << " kwd" << keywords[i] << ")" << endl;
				i = 20;
			}
		}
		if (i == 15)
			cout << " ident :ix " << varcount << " :str \"" << search_store << "\")" << endl; //}

		search_store = "";
		varcount++;
	}
}






