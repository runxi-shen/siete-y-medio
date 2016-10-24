# siete-y-medio
A card game very similar in nature to the casino game of Blackjack (also known as 21). The goal of the game is to get cards whose total value comes the closest to 71/2 without going over it. Getting a card total over 71/2 is called "busting". 


# Attribution
```C++
Copyright: Public domain
Filename: siete-y-medio.cpp 
Contact: Runxi Shen <shenrunxi@ucla.edu>
Purpose: simulate a card game called siete-y-medio. cards.cpp and cards.h ffiles contain the declration
and implementation of classes and siete_y_medio.cpp is the main function for the users to play the game
Assembler: wesley-shen
Last update: 10/23/2016
```

# Test case
```
You have $100. Enter bet: 10
Your cards:
        Sota de Sota    (Jack of cups)
Your total is 0.5. Do you want to another card (y/n)?y
New card:
        Cinco de Cinco  (Five of cups)

Your cards:
        Sota de Sota    (Jack of cups)
        Cinco de Cinco  (Five of cups)
Your total is 5.5. Do you want to another card (y/n)?n
Dealer's cards:
        As de As        (One of swords)
The dealer's total is 1.

New card:
        Caballo de Caballo      (Queen of swords)


Dealer's cards:
        As de As        (One of swords)
        Caballo de Caballo      (Queen of swords)
The dealer's total is 1.5.

New card:
        Cinco de Cinco  (Five of swords)


Too bad. You lose 10

You have $90. Enter bet: 10
Your cards:
        Seis de Seis    (Six of cups)
Your total is 6. Do you want to another card (y/n)?n
Dealer's cards:
        Sota de Sota    (Jack of cups)
The dealer's total is 0.5.

New card:
        Dos de Dos      (Two of cups)


Dealer's cards:
        Sota de Sota    (Jack of cups)
        Dos de Dos      (Two of cups)
The dealer's total is 2.5.

New card:
        Tres de Tres    (Three of clubs)


You win 10.
```
