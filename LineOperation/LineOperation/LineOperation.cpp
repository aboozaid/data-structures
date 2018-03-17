// LineOperation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void main()
{
	string word, lword, rword;
	size_t colonpos;
	cout << "enter two strings seperated by colon" << endl;
	cin >> word;
	colonpos = word.find(':');
	if (colonpos != -1) {
		lword.assign(word,0, colonpos);
		rword.assign(word, colonpos+1);
		if (lword.length() > rword.length())
			cout << "\nL means left side larger than right side" << endl;
		else if (lword == rword)
			cout << "\nS means left side same as right side" << endl;
		else if (lword.length() < rword.length()) {
			cout << "\nR means right side larger than left side" << endl;
		}
		else
		{
			reverse(rword.begin(), rword.end());
			if (rword == lword)
				cout << "\nM means left side same as right side but in mirror" << endl;
			else
				cout << "\nD means left side not same as right side" << endl;
		}
	}
	else
		cout << "\nN means not found colon" << endl;
}

