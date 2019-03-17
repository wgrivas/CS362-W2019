/*********************************************************************************************
 * Author: William Grivas, Jr.
 * Title: Assignment 3
 * Class: CS362 Software Engineering II
 * File: cardtest1.c
 * Description: Cardtest for the Smithy Card
 *********************************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


// function to check if two ints are equal or not
void compareStates(int a, int b){
    if (a == b)
        printf("Result: PASSED");
    else{
        printf("Result: FAILED");
    }
}


int main(int argc, char** argv) 
{
    int i;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int player = 0;
	
	struct gameState state, test;
	
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	
	int count1 = 0, count2 = 0;

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &state);
	

	printf("\n--------------------Start Test: Smithy Card--------------------\n");

	// copy the game state to a test case
	memcpy(&test, &state, sizeof(struct gameState));
	
	//player = whoseTurn(&test);
	//printf("Whose turn: %d\n", player);
	
	cardEffect(smithy, choice1, choice2, choice3, &state, handpos, &bonus);

	player = whoseTurn(&test);
	//printf("Whose turn: %d\n", player);
	
	
	//Deck Count
	printf("\nTest: Deck Count - Pass if correct, Fail if not correct\n");
	compareStates(test.deckCount[player]-3, state.deckCount[player]);
	printf("\nTest Deck count = %i, State Deck count = %i\n", test.deckCount[player], state.deckCount[player]);
	
	//Check the player's hand count
	printf("\n\nTest: Player's Hand Count - Pass if correct, Fail if not correct\n");
	compareStates(test.handCount[player]-1, state.handCount[player]);
	
	//Check players hand
	printf("\n\nTest: Smithy Card in Player's Hand - Pass if present, Fail if not present\n");
	if(state.hand[player][test.handCount[player]] != -1)
		printf("Result: PASSED");
	else
		printf("Result: FAILED");
	
	//Check if player played Smithy card
	printf("\n\nTest: Played Smithy Card - Pass if played, Fail if not played\n");
	compareStates(test.playedCardCount+2, state.playedCardCount);
	
	//Count Smithy cards in hand
	for (i = 0; i < state.handCount[0]; i++)
        if(state.hand[0][i] == smithy);
			count1++;
		
	for (i = 0; i < test.handCount[0]; i++)
        if(test.hand[0][i] == smithy);
			count2++;

	printf("\n\nTest: # of Smithy Cards in Hand - Pass if correct, Fail if not correct\n");
	compareStates(count1, count2-1);
	
	//Check if Smithy card was discarded
	printf("\n\nTest: Smithy Card Discarded - Pass if discarded, Fail if not discarded\n");
	compareStates(test.discardCount[player], state.discardCount[player]);
	
	
	printf("\n\n--------------------End Test: Smithy Card--------------------\n\n");
		
	return 0;
}



/********************************************************************************************* 
 *  Copy of Smithy card function from dominion.c for reference
 ********************************************************************************************/
/*
 *	Smithy card refactored from the switch statement of the cardEffect() function
 *	Bugs added: 1)	In the first for loop, variable i is intiated to 1 from 0, this will cause the player's turn to
 *					draw one less card than intended
 *			    2)	In the first for loop, the loop conditional was changed to i < 2 from i < 3, this should cause
 *					the players turn to draw 2 cards instead of 3
 *				3)	With bugs 1 nd 2 combined, the players turn will draw only 1 card, rather than the 3 intended
 *
 *  Parameters from cardEffect:
 *  int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus) 
 */
/*  
int smithyEffect(int currentPlayer, struct gameState *state, int handPos){
	//+3 Cards
    for (int i = 1; i < 2; i++){			//declared int i, in previous switch i was declared an int
		drawCard(currentPlayer, state);		//BUG: i = 1 rather than i = 0
	}										//BUG: i < 2 rather than i < 3
			
    //discard card from hand
    discardCard(handPos, currentPlayer, state, 0);
    return 0;
}
*/
/*  
	Original Code:

    case smithy:
      //+3 Cards
      for (i = 0; i < 3; i++)
	{
	  drawCard(currentPlayer, state);
	}
			
      //discard card from hand
      discardCard(handPos, currentPlayer, state, 0);
      return 0;
*/