/*Ramsha Bilal
Problem Set 3
bilal_week3_ps
PC
*/

#include "bilal_week3_ps3.h" 
#include <iostream>
#include<string>
using namespace std;

//main starts here

int main()
{ 
	//problem 1
	cout << "Problem 1 starts here.\n";
	problem1();

	//problem 2
	cout << "Problem 2 starts here.\n";
	srand(static_cast<unsigned int>(time(0)));
	problem2();


	//problem 3 
	cout << "Problem 3 starts here\n"; 

	int length;
	bool returnFlag;
	char checkWord[100];

	cout << "Enter string to check if it is a palindrome.\n";
	cin.getline(checkWord, 100);
	length = strlen(checkWord);

	returnFlag = isPalindrome(checkWord, length);   
	if (returnFlag == true)
		cout << "Yes, it is a palindrome.\n";
	else 
		cout << "No, it is not a palindrome.\n";

	return 0; 
}
