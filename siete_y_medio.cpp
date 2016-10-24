#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
using namespace std;

// Global constants (if any)

// Non member functions declarations (if any)
void show_gamer_card(Hand gamer_hand);
void show_dealer_card(Player dealer);
void show_new_card(Card new_card);

// Non member functions implementations (if any)
void show_gamer_card(Hand gamer_hand) {
	cout << "Your cards:" << endl;
	gamer_hand.show_hand();
	cout << "Your total is " << gamer_hand.hand_sum() << ". " << "Do you want to another card (y/n)?";
}

void show_dealer_card(Hand dealer_hand) {
	cout << "Dealer's cards:" << endl;
	dealer_hand.show_hand();
	cout << "The dealer's total is " << dealer_hand.hand_sum() << "." << endl;
 }

void show_new_card(Card new_card) {
	cout << "New card:" << endl;
	new_card.show_card();
	cout << endl;
}

// Stub for main
int main() {
	/* The main class starts the game of siete-y-medio */
	Player dealer = Player(1000);
	Player gamer = Player(100);
	while (gamer.get_money() > 0 && gamer.get_money() < 1000) {
		cout << "You have $" << gamer.get_money() << "." << " Enter bet: ";
		int bet;
		cin >> bet;
		cin.ignore(10000, '\n');

		// create a hand for both dealer and player
		Hand gamer_hand = Hand();
		Hand dealer_hand = Hand();

		Card first_gamer_card = gamer_hand.add_card();
		Card first_dealer_card = dealer_hand.add_card();
		show_gamer_card(gamer_hand);
		string boolean;
		getline(cin, boolean);
		while (boolean == "y") {
			Card new_card = gamer_hand.add_card();
			show_new_card(new_card);
			show_gamer_card(gamer_hand);
			getline(cin, boolean);
		}
		if (boolean == "n") {
			while (dealer_hand.hand_sum() < 5) {
				show_dealer_card(dealer_hand);
				cout << endl;
				Card new_card = dealer_hand.add_card();
				show_new_card(new_card);
				cout << endl;
			}
			if (gamer_hand.hand_sum() <= 7.5 && dealer_hand.hand_sum() <= 7.5) {
				if (gamer_hand.hand_sum() > dealer_hand.hand_sum()) {
					gamer.win_money(bet);
					cout << "You win " << bet << "." << endl;
					cout << endl;
				}
				else if (gamer_hand.hand_sum() < dealer_hand.hand_sum()) {
					gamer.lose_money(bet);
					cout << "Too bad. You lose " << bet << endl;
					cout << endl;
				}
				else {
					cout << "Nobody wins." << endl << endl;
				}
			}
			else if (gamer_hand.hand_sum() > 7.5 && dealer_hand.hand_sum() <= 7.5) {
				gamer.lose_money(bet);
				cout << "You lose by busting" << endl;
				cout << endl;
			}
			else if (gamer_hand.hand_sum() <= 7.5 && dealer_hand.hand_sum() > 7.5) {
				gamer.win_money(bet);
				cout << "Dealer loses by busting" << endl;
				cout << endl;
			}
			else {
				cout << "Noboday wins. Both busted." << endl;
			}
		}
		else {
			cout << "Please provide the correct input.";
			return 1;
		}
	}
	cout << "You have $0. GAME OVER!" << endl;
	cout << "Come back when you have more money." << endl;
	cout << "Bye!" << endl;

	return 0;
}