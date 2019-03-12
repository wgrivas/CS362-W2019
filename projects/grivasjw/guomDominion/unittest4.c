/*********************************************************************************************
 * Author: William Grivas, Jr.
 * Title: Assignment 3
 * Class: CS362 Software Engineering II
 * File: unittest4.c
 * Description: Unit test for whoseTurn(struct gameState *state);
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
	
	state1.whoseTurn = 1;
	state2.whoseTurn = 2;
	
	printf("\n--------------------Start Test: whoseTurn() function--------------------\n");
	
	printf("\nTest: Player 1's Turn\n");
	compareStates(whoseTurn(&state1), 1);
	printf(" - Current player is Player %d\n", state1.whoseTurn);
	
	
	printf("\nTest: Player 2's Turn\n");	 
	compareStates(whoseTurn(&state2), 2);
	printf(" - Current player is Player %d\n", state2.whoseTurn);
	
	
	printf("\n--------------------End Test: whoseTurn() function--------------------\n\n");
	
	return 0;
}




/********************************************************************************************* 
 *  Copy of whoseTurn() function from dominion.c for reference
 ********************************************************************************************/

/* 
int whoseTurn(struct gameState *state) {
  return state->whoseTurn;
}
*/