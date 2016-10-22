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

// Non member functions implementations (if any)

// Stub for main
int main() {
	/* The main class starts the game of siete-y-medio */
	Player dealer = Player(1000);
	Player gamer = Player(100);
	while (gamer.get_money() > 0 && gamer.get_money() < 1000) {
		cout << "You have $" << gamer.get_money() << "." << " Enter bet: ";
		int bet;
		cin << bet;
		gamer.hand.add_hand();
		cout << "Your cards:" << endl;
		cout << "Your total is " << gamer.hand.hand_sum() << ". " << "Do you want to another card (y/n)?";
		// need some modification
		string bool;
		cin << bool;
		if (bool == "n") {

		}
		else if (bool == "y") {

		}
		else {
			cout << "Please provide the correct input. Try again (y/n): ";
		}


	}
	return 0;
}