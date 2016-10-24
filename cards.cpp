#include "cards.h"
#include <cstdlib>
#include <iostream>

/*
You might or might not need these two extra libraries
#include <iomanip>
#include <algorithm>
*/


/* *************************************************
Card class
************************************************* */

/*
Default constructor for the Card class.
It could give repeated cards. This is OK.
Most variations of Blackjack are played with
several decks of cards at the same time.
*/
Card::Card() {
	int r = 1 + rand() % 4;
	switch (r) {
	case 1: suit = OROS; break;
	case 2: suit = COPAS; break;
	case 3: suit = ESPADAS; break;
	case 4: suit = BASTOS; break;
	default: break;
	}

	r = 1 + rand() % 10;
	switch (r) {
	case  1: rank = AS; break;
	case  2: rank = DOS; break;
	case  3: rank = TRES; break;
	case  4: rank = CUATRO; break;
	case  5: rank = CINCO; break;
	case  6: rank = SEIS; break;
	case  7: rank = SIETE; break;
	case  8: rank = SOTA; break;
	case  9: rank = CABALLO; break;
	case 10: rank = REY; break;
	default: break;
	}
}

// Accessor: returns a string with the suit of the card in Spanish 
string Card::get_spanish_suit() const {
	string suitName;
	switch (suit) {
	case OROS:
		suitName = "oros";
		break;
	case COPAS:
		suitName = "copas";
		break;
	case ESPADAS:
		suitName = "espadas";
		break;
	case BASTOS:
		suitName = "bastos";
		break;
	default: break;
	}
	return suitName;
}

// Accessor: returns a string with the rank of the card in Spanish 
string Card::get_spanish_rank() const {
	string rankName;
	switch (rank) {
	case AS:
		rankName = "As";
		break;
	case DOS:
		rankName = "Dos";
		break;
	case TRES:
		rankName = "Tres";
		break;
	case CUATRO:
		rankName = "Cuatro";
		break;
	case CINCO:
		rankName = "Cinco";
		break;
	case SEIS:
		rankName = "Seis";
		break;
	case SIETE:
		rankName = "Siete";
		break;
	case SOTA:
		rankName = "Sota";
		break;
	case CABALLO:
		rankName = "Caballo";
		break;
	case REY:
		rankName = "Rey";
		break;
	default: break;
	}
	return rankName;
}


// Accessor: returns a string with the suit of the card in English 
// This is just a stub! Modify it to your liking.
string Card::get_english_suit() const {
	string suit_in_english;
	switch (suit) {
	case OROS:
		suit_in_english = "golds";
		break;
	case COPAS:
		suit_in_english = "cups";
		break;
	case ESPADAS:
		suit_in_english = "swords";
		break;
	case BASTOS:
		suit_in_english = "clubs";
		break;
	default: break;
	}
	return suit_in_english;
}

// Accessor: returns a string with the rank of the card in English 
string Card::get_english_rank() const {
	string rank_in_english;
	switch (rank) {
	case AS:
		rank_in_english = "One";
		break;
	case DOS:
		rank_in_english = "Two";
		break;
	case TRES:
		rank_in_english = "Three";
		break;
	case CUATRO:
		rank_in_english = "Four";
		break;
	case CINCO:
		rank_in_english = "Five";
		break;
	case SEIS:
		rank_in_english = "Six";
		break;
	case SIETE:
		rank_in_english = "Seven";
		break;
	case SOTA:
		rank_in_english = "Jack";
		break;
	case CABALLO:
		rank_in_english = "Queen";
		break;
	case REY:
		rank_in_english = "King";
		break;
	default: break;
	}
	return rank_in_english;
}


// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
	return static_cast<int>(rank) + 1;
}

// Gets the value of a card
double Card::get_value() const {
	if (this->get_spanish_rank() == "Sota" || this->get_spanish_rank() == "Caballo" || this->get_spanish_rank() == "Rey")
		return 0.5;
	else
		return this->get_rank();
}

// show the card on screen
void Card::show_card() const {
	cout << "\t" << this->get_spanish_rank() << " de " << this->get_spanish_rank() << "\t" << "(" << this->get_english_rank() << " of " << this->get_english_suit() << ")" << endl;
}


// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
	return rank < card2.rank;
}

/* *************************************************
Hand class
************************************************* */

/*
Default constructor for the Card class.
It could give the cards a player has in 
his or her hand.
*/
Hand::Hand() {}

// add a card to a player's hand
Card Hand::add_card() {
	Card new_card = Card();
	hand_of_cards.push_back(new_card);
	return new_card;
}

// count the values of cards in a player's hand
double Hand::hand_sum() {
	double sum = 0;
	for (auto const& i : hand_of_cards) {
		sum += i.get_value();
	}
	return sum;
}

// print out the cards in a hand
void Hand::show_hand() const{
	for (auto const& i : hand_of_cards) {
		i.show_card();
	}
}

/* *************************************************
Player class
************************************************* */
/*
Default constructor for the Player class.
It initializes the hand of cards and the 
money a player gets at first.
*/
Player::Player(int m) {
	money = m;
}

// get the money a player owns
int& Player::get_money() {
	return money;
}

// subtract the money a player loses
int Player::lose_money(int m) {
	money -= m;
	return money;
}

// add the money a player wins
// Error corrected by collaborator Tianyi (Sid) Shi
Player::win_money(int m) {
	int money += m;
	return money;
}
