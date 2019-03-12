/*********************************************************************************************
 * Author: William Grivas, Jr.
 * Title: Assignment 4
 * Class: CS362 Software Engineering II
 * File: randomtestcard1.c
 * Description: Random test for the Great Hall Card
 *********************************************************************************************/


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>


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
	srand(time(NULL));
	
    int j;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    //int seed = 1000;
    //int numPlayers = 2;
    int player=0;
	struct gameState state, test;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	for(j = 0; j < 100; j++){
		
		int numPlayers = (rand() % 50);
		int seed = (rand() % 5000);
		//int player = (rand() % 2);
		
	
		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &state);

		printf("\n\n--------------------Testing Great Hall Card: %d of 100--------------------\n", j+1);

		//copy the game state to a test case
		memcpy(&test, &state, sizeof(struct gameState));
		cardEffect(great_hall, choice1, choice2, choice3, &state, handpos, &bonus);

		player = whoseTurn(&test);
		
		printf("Number of players: %d\n", numPlayers);
		printf("Seed: %d\n", seed);
		printf("Whose turn: %d\n", player);
		
		
		//Deck Count
		printf("\nTest: Deck Count - Pass if correct, Fail if not correct\n");
		compareStates(test.deckCount[player]-1, state.deckCount[player]);
	
		//Check players hand
		printf("\n\nTest: Great Hall in Player's Hand - Pass if present, Fail if not present\n");
		if(state.hand[player][test.handCount[player]-1] != -1)
			printf("Result: PASSED");
		else
			printf("Result: FAILED");
	
		//Check if player played Great Hall card
		printf("\n\nTest: Played Great Hall Card - Pass if played, Fail if not played\n");
		compareStates(test.playedCardCount+1, state.playedCardCount);
	
		//Check if Great Hall card was discarded
		printf("\n\nTest: Great Hall Card Discarded - Pass if discarded, Fail if not discarded\n");
		compareStates(test.discardCount[player], state.discardCount[player]);
	
		//Check if the +1 Action was added
		printf("\n\nTest: +1 Action Added - Pass if 1 action added, Fail if 1 action not added\n");
		compareStates(test.numActions+1, state.numActions);
		
	}
	
	printf("\n\n--------------------End Test: Great Hall Card--------------------\n\n");
	
	return 0;
}




/********************************************************************************************* 
 *  Copy of Great Hall card function from dominion.c for reference
 ********************************************************************************************/
/*
 *	Great Hall card refactored from the switch statement of the cardEffect() function
 *	Bugs added: None
 *
 *  Parameters from cardEffect:
 *  int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus) 
 */
/*  
int great_hallEffect(int currentPlayer, struct gameState *state, int handPos){
	//+1 Card
    drawCard(currentPlayer, state);
			
    //+1 Actions
    state->numActions++;
			
    //discard card from hand
    discardCard(handPos, currentPlayer, state, 0);
    return 0;
}
*/



//cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)

/*
Layout of Great Hall in Dominion
	case great_hall:
		//+1 Card
		drawCard(currentPlayer, state);
			
		//+1 Actions
		state->numActions++;
			
		//discard card from hand
		discardCard(handPos, currentPlayer, state, 0);
		return 0;
*/