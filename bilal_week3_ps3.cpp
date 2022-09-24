/*Ramsha Bilal
Problem Set 3 - problem 3
bilal_week3_ps
PC
*/
//Problem 3 - isPalindrome 
/*Steps: 
1. isPalindrome() --> calls cleanText()
2.cleanText() --> calls reverseTex()
3.reverseText 
4. isPalindrome compares clean and reverse text and returns true or false accordingly.
*/
#include "bilal_week3_ps3.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

char wordCleaned[80];
char wordReversed[100];
int flag = 1, length = 0;


/*isPalindrome calls cleanText so the wordToTest has no spaces, punctuations, and is lowercase. cleanText calls reverseText, 
  which produces the reverse array. then, isPalindrome() tests if the original wordToTest is equal to the reverse 
  array - if yes, it returns true indicating that string is a palindrome and vice versa*/

bool isPalindrome(char wordToTest[], int len)
{
	cleanText(wordToTest, len);  // removes spaces and punctuation, converts letters 
	                             // to lowercase, and calls reverseText().
	
	for (int i = 0; i < length; i++)
	{
		if ((wordCleaned[i]) != (wordReversed[i]))
		{
			flag = 0; 
			break;
		}
	}
	if (flag == 0)
		return false;
	else
		return true;
}


/*cleanText() takes a word or sentence as parameter - it removes all the spaces and all the
  punctuations, converts all characters to lower case, finally saving them in a new array.*/

void cleanText(char wordToClean[], int wordLength)
{
	int j = 0;
	for (int i = 0; i < wordLength; i++)
	{
		if ((wordToClean[i] >= 'a') && (wordToClean[i] <= 'z'))
		{
			wordCleaned[j] = wordToClean[i];
			j++;
			length++;
		}
		else if ((wordToClean[i] >= 'A') && (wordToClean[i] <= 'Z'))
		{
			wordCleaned[j] = tolower(wordToClean[i]);
			j++;
			length++;
		}
		else
			continue;
	}

	/*  //DEBUG MODE
	cout << "testing cleanText(). the output should "   
		 << "show the input string without spaces or "
		 << "punctuation and in all lowercase: " 
		 << endl;
	for (int i = 0; i < wordLength; i++)  // FOR DEBUGGING/TESTING  
	cout << wordCleaned[i]; 
	cout << endl << endl; 
	*/

	reverseText(wordCleaned, wordReversed, length);
}

/*reverseText() takes the cleanedArray and an empty reverseArray as parameters along 
  with length of cleanArray. It reverse the clean array by placing its first letter
  on the last index of reverseArray, second letter on second last index of reverseArray 
  and so on. */

void reverseText(char originalArray[], char reverseArray[], int lengthOfArray)
{
	for (int i = 0; i < lengthOfArray; i++)
	{
		reverseArray[lengthOfArray - i - 1] = originalArray[i];
	}
	for (int i = 0; i < lengthOfArray; i++)
		wordReversed[i] = reverseArray[i];

	/* //DEBUG MODE
	cout << "testing reverseText() - expected output:"  
		 << "original string is reversed" << endl;
	for (int i = 0; i < lengthOfArray; i++)
		cout << wordReversed[i];
	cout << endl << endl; 
	*/
	
} 
