/*********************************************************************************************
 * Author: William Grivas, Jr.
 * Title: Assignment 3
 * Class: CS362 Software Engineering II
 * File: unittest1.c
 * Description: Unit test for buyCard(int supplyPos, struct gameState *state);
 *********************************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>


// function to check if two ints are equal or not
void compareStates(int a, int b){
    if (a == b)
        printf("Result: PASSED");
    else{
        printf("Result: FAILED");
    }
}


int main (int argc, char** argv)	
{
	struct gameState state1;
	struct gameState state2;
	struct gameState state3;
	struct gameState state4;
	
	int supplyPos = 2;
	
	state1.numBuys = 2;
	state1.coins = 0;
	
	state2.numBuys = 0;
	state2.coins = 0;
	
	state3.numBuys = 2;
	state3.coins = 10;
	
	state4.numBuys = 0;
	state4.coins = 10;
	
	printf("\n--------------------Start Test: buyCard() function--------------------\n");

	
	printf("\nTest: Not enough coins - Enough buys\n");
	compareStates(buyCard(supplyPos, &state1), -1);
	printf(" when testing %d coins & %d buys\n", state1.coins, state1.numBuys);
	
	
	printf("\nTest: Not enough coins - Not enough buys\n");
	compareStates(buyCard(supplyPos, &state2), -1);
	printf(" when testing %d coins & %d buys\n", state2.coins, state2.numBuys);
		
		
 	printf("\nTest: Enough coins - Enough buys\n");
	compareStates(buyCard(supplyPos, &state3), 0);
	printf(" when testing %d coins & %d buys\n", state3.coins, state3.numBuys);
		
		
 	printf("\nTest: Enough coins - Not enough buys\n");
	compareStates(buyCard(supplyPos, &state4), -1);
	printf(" when testing %d coins & %d buys\n", state4.coins, state4.numBuys);
	
		
 	printf("\n--------------------End Test: buyCard() function--------------------\n\n"); 	
	
	return 0;
}




/********************************************************************************************* 
 *  Copy of buyCard() function from dominion.c for reference
 ********************************************************************************************/

/* 
int buyCard(int supplyPos, struct gameState *state) {
  int who;
  if (DEBUG){
    printf("Entering buyCard...\n");
  }
  // I don't know what to do about the phase thing.
  who = state->whoseTurn;
  if (state->numBuys < 1){
    if (DEBUG)
      printf("You do not have any buys left\n");
    return -1;
  } else if (supplyCount(supplyPos, state) < 1){
    if (DEBUG)
      printf("There are not any of that type of card left\n");
    return -1;
  } else if (state->coins < getCost(supplyPos)){
    if (DEBUG) 
      printf("You do not have enough money to buy that. You have %d coins.\n", state->coins);
    return -1;
  } else {
    state->phase=1;
    //state->supplyCount[supplyPos]--;
    gainCard(supplyPos, state, 0, who); //card goes in discard, this might be wrong.. (2 means goes into hand, 0 goes into discard)
  
    state->coins = (state->coins) - (getCost(supplyPos));
    state->numBuys--;
    if (DEBUG)
      printf("You bought card number %d for %d coins. You now have %d buys and %d coins.\n", supplyPos, getCost(supplyPos), state->numBuys, state->coins);
  }
  //state->discard[who][state->discardCount[who]] = supplyPos;
  //state->discardCount[who]++;
    
  return 0;
}
 */