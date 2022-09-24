/* Ramsha Bilal
Problem Set 3
bilal_week3_ps
PC */
#include <iostream>
#include <string> 
#include <iomanip> 
#include "bilal_week3_ps3.h"

using namespace std;

enum Items
{
    HOTDOG, FRIES, SODA
};
int noOfHotdogs, noOfSodas, noOfFries;
int customerOrder[2];

string returnDollarAmount(double finalAmount);
void finalDisplay(double subT, double disc, double taxA, string finString);

void problem1()
{
    double returnSubtotal, returnDiscount, returnTax, returnFinalTotal;
    const double HOTDOG_COST = 3.5, FRIES_COST = 2.50, SODA_COST = 1.25, TAX_RATE = 6.25, DISCOUNT = 10;
    const double prices[3] = { HOTDOG_COST, FRIES_COST, SODA_COST };
    string returnFinalString;


    getItemOrder(HOTDOG_COST, FRIES_COST, SODA_COST);

    returnSubtotal = calculateSubtotal(HOTDOG_COST, FRIES_COST, SODA_COST);

    returnDiscount = calculateDiscountAmount(returnSubtotal, DISCOUNT);
    returnSubtotal -= returnDiscount;  // so that tax rate is applied on the discounted subtotal

    returnTax = calculateTaxAmount(returnSubtotal, TAX_RATE);

    returnFinalTotal = calculateFinalTotal(returnSubtotal, returnTax);

    returnFinalString = returnDollarAmount(returnFinalTotal);

    finalDisplay(returnSubtotal, returnDiscount, returnTax, returnFinalString);
}

void getItemOrder(const double x, const double y, const double z)
{
    displayMenu(x, y, z);
    int orderItem;

    do
    {
        cout << "Choose an item to order.\n"
            << "(Order by item number, choose 0 to stop.)";
        cin >> orderItem;
        if (orderItem == 1)
        {
            cout << "How many orders of hotdog do you want?\n";
            cin >> noOfHotdogs;
            customerOrder[HOTDOG] += noOfHotdogs;

            cout << "hotdogs no is " << customerOrder[HOTDOG];
        }
        if (orderItem == 2)
        {
            cout << "How many orders of fries do you want?\n";
            cin >> noOfFries;
            customerOrder[FRIES] += noOfFries;
        }
        if (orderItem == 3)
        {
            cout << "How many orders of soda do you want?\n";
            cin >> noOfSodas;
            customerOrder[SODA] += noOfSodas;
        }
        displayOrder();
    } while (orderItem != 0);
}

void displayMenu(const double x, const double y, const double z)
{
    cout << "Welcome to Joe's Hotdogs" << endl;
    cout << "MENU\n"
        << "Item:            Price: \n"
        << "1. Hotdogs       " << x << endl
        << "2. Fries         " << y << endl
        << "3. Soda          " << z << endl;
}

void displayOrder()
{
    cout << "Your order :" << endl
        << customerOrder[HOTDOG] << " Hotdogs" << endl
        << customerOrder[FRIES] << " Fries" << endl
        << customerOrder[SODA] << " Sodas" << endl << endl;
}

double calculateSubtotal(const double x, const double y, const double z) //returns subtotal
{
    double subtotal = 0;
    subtotal = (x * customerOrder[HOTDOG] + y * customerOrder[FRIES] + z * customerOrder[SODA]);
    if (subtotal == 0)
        cout << "Your order is empty" << endl;

    return subtotal;
}

double calculateDiscountAmount(double total, double discount)
{
    double discountAmount = 0;
    if (total >= 20)
        discountAmount = (discount / 100 * total);

    return discountAmount;
}

double calculateTaxAmount(double totalCost, double tax)
{
    double taxAmount = 0;
    taxAmount = ((tax / 100) * (totalCost));
    return taxAmount;
}

double calculateFinalTotal(double subTotal, double taxTotal)
{
    double finalTotal = 0;
    finalTotal = subTotal - taxTotal;
    return finalTotal;
}

string returnDollarAmount(double finalAmount)
{

    int finalAmountInto100 = (finalAmount * 100);  /*ignoring the warning as I intend to cause a loss of data by
                                                   converting double to int to create a two decimal place number*/
    double amount = static_cast<double>(finalAmountInto100) / 100;
    string dollarAmount;
    dollarAmount = to_string(amount);
    if (amount < 1000)
        dollarAmount = dollarAmount.substr(0, 5);
    else if (amount < 100)
        dollarAmount = dollarAmount.substr(0, 4);
    else if (amount < 10)
        dollarAmount = dollarAmount.substr(0, 3);

    return dollarAmount;
}

void finalDisplay(double subT, double disc, double taxA, string finString)
{
    cout << fixed;
    cout << setprecision(2);
    cout << "Subtotal:   " << subT << endl
        << "Discount:   " << disc << endl
        << "Tax:   " << taxA << endl
        << "Total: " << finString << endl;
}