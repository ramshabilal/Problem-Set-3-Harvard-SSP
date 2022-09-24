#ifndef BILAL_WEEK3_PS_H
#define BILAL_WEEK3_PS_H

//problem 1
void problem1();
void getItemOrder(const double x, const double y, const double z);
void displayMenu(const double x, const double y, const double z);
void displayOrder();
double calculateSubtotal(const double x, const double y, const double z);
double calculateDiscountAmount(double total, double discount);
double calculateTaxAmount(double totalCost, double tax);
double calculateFinalTotal(double subTotal, double taxTotal);


//problem 2
void problem2();


//problem 3
bool isPalindrome(char wordToTest[], int len); 
void cleanText(char wordToClean[], int wordLength);
void reverseText(char originalArray[], char reverseArray[], int lengthOfArray);
#endif 
