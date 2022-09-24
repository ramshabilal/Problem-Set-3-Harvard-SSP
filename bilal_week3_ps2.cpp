/*Ramsha Bilal
Problem Set 3 - problem 2
bilal_week3_ps
PC
*/
//Problem 2 - References 

#include "bilal_week3_ps3.h" 
#include <iostream> 
#include <iomanip> 
#include <string> 
using namespace std;

enum suit
{
	club, diamond, heart, spade
};

int dealACard(suit& suitOfCard, string& rankOfCard);
int displayACard(suit& suitCard, string& rankCard);

/*problem2() uses function dealACard to get three values of three different cards
  and adds those values to display them to the user.*/
void problem2()
{

	suit cardSuit;
	string cardRank;
	int value1, value2, value3, totalValue;


	value1 = displayACard(cardSuit, cardRank);   //using rand() to produce random cards
	value2 = displayACard(cardSuit, cardRank);   //seeded srand with time so that cards are very random and hence different
	value3 = displayACard(cardSuit, cardRank);
	totalValue = value1 + value2 + value3;
	cout << "Total value of the three cards is: " << totalValue << endl << endl;
}

/*dealACard() uses rand() to produce random number between 1 and 4, each corresponding 
to a particular suit of card and then assigns that suit to a card. it also generates random 
number between 1 and 13, each corresponding to a particular rank and assigns that rank to 
the card. It finally returns value of the card. */
int dealACard(suit& suitOfCard, string& rankOfCard) 
{
	int valueOfCard;
	int randForRank, randomNumber = rand() % 4;
	if (randomNumber == 0)
		suitOfCard = club;
	else if (randomNumber == 1)
		suitOfCard = diamond;
	else if (randomNumber == 2)
		suitOfCard = heart;
	else if (randomNumber == 3)
		suitOfCard = spade;

	randForRank = rand() % 13 + 1;
	if (randForRank == 1)
	{
		rankOfCard = "Ace";
		valueOfCard = 1;
	}

	else if (randForRank == 11)
	{
		rankOfCard = "Jack";
		valueOfCard = 10;
	}
	else if (randForRank == 12)
	{
		rankOfCard = "Queen";
		valueOfCard = 10;
	}
	else if (randForRank == 13)
	{
		rankOfCard = "King";
		valueOfCard = 10;
	}
	else
	{
		rankOfCard = to_string(randForRank);
		valueOfCard = randForRank;
	}

	return valueOfCard;

}
/* displayACard uses dealACard() to display a card. it then  
   displays its suit and rank and returns its value. */
int displayACard(suit& suitCard, string& rankCard)
{
	string suits[4] = { "club", "diamond", "hearts", "spades" };

	int cardValue = dealACard(suitCard, rankCard);
	cout << "A " << rankCard << " of " << suits[suitCard] << endl;
	return cardValue;
}


