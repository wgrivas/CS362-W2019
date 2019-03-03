/*********************************************************************************************
 * Author: William Grivas, Jr.
 * Title: Assignment 4
 * Class: CS362 Software Engineering II
 * File: randomtestadventurer.c
 * Description: Random test for the Adventurer Card
 * Note: To avoid a seg fault, the refactored code in adventurerEffect() needed to be adjusted.
 *       The second bug in the last while loop was removed.
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

    int i, j;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    //int seed = 1000;
    //int numPlayers = 2;
    int player=0;
	struct gameState state, test;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	int count1 = 0;
	int count2 = 0;
	
	for(j = 0; j < 100; j++)
	{
		int numPlayers = (rand() % 50);
		int seed = (rand() % 5000);
		
		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &state);

		printf("\n\n--------------------Testing Adventurer Card: %d of 100--------------------\n", j+1);

		// copy the game state to a test case
		memcpy(&test, &state, sizeof(struct gameState));
		cardEffect(adventurer, choice1, choice2, choice3, &state, handpos, &bonus);

		player = whoseTurn(&test);
		
		printf("Number of players: %d\n", numPlayers);
		printf("Seed: %d\n", seed);
		printf("Whose turn: %d\n", player);

	
		//Deck Count
		printf("\nTest: Deck Count - Pass if correct, Fail if not correct\n");
		compareStates(test.deckCount[player]-1, state.deckCount[player]);
	
		//Check the player hands count
		printf("\n\nTest: Player's Hand Count - Pass if correct, Fail if not correct\n");
		compareStates(test.handCount[player]-1, state.handCount[player]);
	
		//Check players hand
		printf("\n\nTest: Adventurer Card in Player's Hand - Pass if present, Fail if not present\n");
		if(state.hand[player][test.handCount[player]] != -1)
			printf("Result: PASSED");
		else
			printf("Result: FAILED");

		//Check if player played Adventurer card
		printf("\n\nTest: Played Adventurer Card - Pass if played, Fail if not played\n");
		compareStates(test.playedCardCount+2, state.playedCardCount);
	
		//Count Adventurer cards in hand
		for (i = 0; i < state.handCount[0]; i++)
			if(state.hand[0][i] == adventurer);
				count1++;
		
		for (i = 0; i < test.handCount[0]; i++)
			if(test.hand[0][i] == adventurer);
				count2++;

		printf("\n\nTest: # of Adventurer Cards in Hand - Pass if correct, Fail if not correct\n");
		compareStates(count1, count2-1);
	
		//Check if Adventurer card was discarded
		printf("\n\nTest: Adventurer Card Discarded - Pass if discarded, Fail if not discarded\n");
		compareStates(test.discardCount[player], state.discardCount[player]);
	
		//Check if Victory pile remains unchanged
		printf("\n\nTest: Victory Supply Piles Remain Unchanged - Pass if unchanged, Fail if changed:\n");
		printf("Province Cards\n");
		compareStates(test.supplyCount[province],state.supplyCount[province]);
		printf("\nDuchy Cards\n");
		compareStates(test.supplyCount[duchy],state.supplyCount[duchy]);
		printf("\nEstate Cards\n");
		compareStates(test.supplyCount[estate],state.supplyCount[estate]);
	
	
	}
	
	printf("\n\n--------------------End Test: Adventurer Card--------------------\n\n");
	
	return 0;
}




/********************************************************************************************* 
 *  Copy of Adventurer card function from dominion.c for reference
 ********************************************************************************************/
/*
 *  Adventurer card refactored from the switch statement of the cardEffect() function
 *	Bugs added:  1) made the conditional in the 1st while loop drawntreasure <= 2 rather than drawntreasure < 2, this 
 *					should cause the players turn to continue to draw cards even after two treasures are drawn
 *				 2)	in the last while loop, the variable z increments 1 instead of decrements 1, this should cause the
 *					players turn to continue to discard as the while conditional will loop infinitely
 *
 *  Parameters from cardEffect:
 *  int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
 */
/*  
int adventurerEffect(struct gameState *state, int currentPlayer, int cardDrawn, int drawntreasure, int temphand[], int z){
    while(drawntreasure<=2){  //BUG: <= 2 rather than < 2
		if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
			shuffle(currentPlayer, state);
		}
		drawCard(currentPlayer, state);
		cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
		if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
			drawntreasure++;
		else{
			temphand[z]=cardDrawn;
			state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
			z++;
		}
    }
    while(z-1>=0){
		state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
		z=z+1;  //BUG: z+1 rather than z-1
    }
    return 0;
}
*/



//cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)

/*
Layout of Adventurer in Dominion
    case adventurer:
		while(drawntreasure<2){
			if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
				shuffle(currentPlayer, state);
			}
			drawCard(currentPlayer, state);
			cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
			if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
				drawntreasure++;
			else{
				temphand[z]=cardDrawn;
				state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
				z++;
			}
		}
		while(z-1>=0){
			state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
			z=z-1;
		}
		return 0;
*/