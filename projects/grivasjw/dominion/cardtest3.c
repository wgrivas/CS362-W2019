/*********************************************************************************************
 * Author: William Grivas, Jr.
 * Title: Assignment 3
 * Class: CS362 Software Engineering II 
 * File: cardtest3.c
 * Description: Cardtest for the Village Card
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
    //int i;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int player=0;
	
	struct gameState state, test;
	
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
			
	//int count1 = 0, count2 = 0;

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &state);

	printf("\n--------------------Start Test: Village Card--------------------\n");

	
	// copy the game state to a test case
	memcpy(&test, &state, sizeof(struct gameState));
	
	//player = whoseTurn(&test);
	//printf("Whose turn: %d\n", player);
	
	cardEffect(village, choice1, choice2, choice3, &state, handpos, &bonus);

	player = whoseTurn(&test);
	//printf("Whose turn: %d\n", player);
	
	
	//Deck Count
	printf("\nTest: Deck Count - Pass if correct, Fail if not correct\n");
	compareStates(test.deckCount[player]-1, state.deckCount[player]);
	
	//Check players hand
	printf("\n\nTest: Village Card in Player's Hand - Pass if present, Fail if not present\n");
	if(state.hand[player][test.handCount[player]-1] != -1)
		printf("Result: PASSED");
	else
		printf("Result: FAILED");
	
	//Check if player played Village card
	printf("\n\nTest: Played Village Card - Pass if played, Fail if not played\n");
	compareStates(test.playedCardCount+1, state.playedCardCount);

	//Discard Test: Check if card was discarded
	printf("\n\nTest: Village Card Discarded - Pass if discarded, Fail if not discarded\n");
	compareStates(test.discardCount[player], state.discardCount[player]);
	
	//Action Test: Check if the +2 Action was added
	printf("\n\nTest: +2 Action Added - Pass if 2 actions added, Fail if 2 actions not added\n");
	compareStates(test.numActions+2, state.numActions);
	
	
	printf("\n\n--------------------End Test: Village Card--------------------\n\n");
}




/********************************************************************************************* 
 *  Copy of Village card function from dominion.c for reference
 ********************************************************************************************/
/*
 *	Village card refactored from the switch statement of the cardEffect() function
 *	Bugs added: 1)	Increment state->numActions by +1 instead of +2, this will add only 1 action instead of the
 *					intended 2 actions
 *
 *  Parameters from cardEffect:
 *  int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)  
 */
/*  
int villageEffect(int currentPlayer, struct gameState *state, int handPos){
	//+1 Card
    drawCard(currentPlayer, state);
			
    //+2 Actions
    state->numActions = state->numActions + 1;  //BUG: state->numActions increments by 1 instead of 2
			
    //discard played card from hand
    discardCard(handPos, currentPlayer, state, 0);
    return 0;
}
*/



//cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)

/*Layout of Village in Dominion
    case village:
      //+1 Card
      drawCard(currentPlayer, state);
			
      //+2 Actions
      state->numActions = state->numActions + 2;
			
      //discard played card from hand
      discardCard(handPos, currentPlayer, state, 0);
      return 0;
*/