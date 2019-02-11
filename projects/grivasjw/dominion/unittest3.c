/*********************************************************************************************
 * Author: William Grivas, Jr.
 * Title: Assignment 3
 * Class: CS362 Software Engineering II
 * File: unittest3.c
 * Description: Unit test for updateCoins(int player, struct gameState *state, int bonus);
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
	struct gameState state;
	int i = 0;
	//int result = 0;
	
 	printf("\n--------------------Start Test: updateCoins() function--------------------\n");
	
	
	//COPPER TESTS
	printf("\nTesting zero Copper cards in the hand\n");
	for (i = 0; i < 10; i++){
		state.hand[0][i] = silver;
	}
		
	updateCoins(0, &state, 0);
	
	compareStates(state.coins, 0);
	printf(" - Copper is %d/0\n", state.coins);
	
	
	printf("\nTesting one Copper cards in the hand\n");
	for (i = 0; i < 10; i++){
		if(i == 0){
			state.hand[0][i] = copper;
		}else{
			state.hand[0][i] = curse;
		}
	}
		
	updateCoins(0, &state, 0);
	
	compareStates(state.coins, 1);
	printf(" - Copper is %d/1\n", state.coins);
	
	
	printf("\nTesting ten Copper cards in the hand\n");
	for (i = 0; i < 10; i++){
		state.hand[0][i] = copper;
	}
		
	updateCoins(0,&state, 0);
	
	compareStates(state.coins, 10);
	printf(" - Copper is %d/10\n", state.coins);
	
	
	//SILVER
	printf("\nTesting zero Silver cards in the hand\n");
	for (i = 0; i < 10; i++){
		state.hand[0][i] = copper;
	}
		
	updateCoins(0, &state, 0);
	
	compareStates(state.coins, 0);
	printf(" - Silver is %d/0\n", state.coins);
	
	
	printf("\nTesting one Silver cards in the hand\n");
	for (i = 0; i < 10; i++){
		if(i == 0){
			state.hand[0][i] = silver;
		}else{
			state.hand[0][i] = curse;
		}
	}
		
	updateCoins(0, &state, 0);
	
	compareStates(state.coins, 2);
	printf(" - Silver is %d/2\n", state.coins);
	
	
	printf("\nTesting ten Silver cards in the hand\n");
	for (i = 0; i < 10; i++){
		state.hand[0][i] = silver;
	}
		
	updateCoins(0,&state, 0);
	
	compareStates(state.coins, 20);
	printf(" - Silver is %d/20\n", state.coins);
	
	
	
	
	//GOLD
	printf("\nTesting zero Gold cards in the hand\n");
	for (i = 0; i < 10; i++){
		state.hand[0][i] = copper;
	}
		
	updateCoins(0, &state, 0);
	
	compareStates(state.coins, 0);
	printf(" - Gold is %d/0\n", state.coins);
	
	
	printf("\nTesting one Gold cards in the hand\n");
	for (i = 0; i < 10; i++){
		if(i == 0){
			state.hand[0][i] = gold;
		}else{
			state.hand[0][i] = curse;
		}
	}
		
	updateCoins(0, &state, 0);
	
	compareStates(state.coins, 3);
	printf(" - Gold is %d/3\n", state.coins);
	
	
	printf("\nTesting ten Gold cards in the hand\n");
	for (i = 0; i < 10; i++){
		state.hand[0][i] = gold;
	}
		
	updateCoins(0,&state, 0);
	
	compareStates(state.coins, 30);
	printf(" - Gold is %d/30\n", state.coins);
	
	
	
	//COPPER + BONUS
	printf("\nTesting zero Copper cards in the hand + 1 Bonus\n");
	for (i = 0; i < 10; i++){
		state.hand[0][i] = silver;
	}
		
	updateCoins(0, &state, 1);
	
	compareStates(state.coins, 1);
	printf(" - Copper + 1 Bonus is %d/1\n", state.coins);
	
	
	printf("\nTesting one Copper cards in the hand + 1 Bonus\n");
	for (i = 0; i < 10; i++){
		if(i == 0){
			state.hand[0][i] = copper;
		}else{
			state.hand[0][i] = curse;
		}
	}
		
	updateCoins(0, &state, 1);
	
	compareStates(state.coins, 2);
	printf(" - Copper + 1 Bonus is %d/2\n", state.coins);
	
	
	printf("\nTesting ten Copper cards in the hand + 1 Bonus\n");
	for (i = 0; i < 10; i++){
		state.hand[0][i] = copper;
	}
		
	updateCoins(0,&state, 1);
	
	compareStates(state.coins, 11);
	printf(" - Copper is %d/11\n", state.coins);
	
 	printf("\n--------------------End Test: updateCoins() function--------------------\n\n");
	
	return 0;
}




/********************************************************************************************* 
 *  Copy of updateCoins() function from dominion.c for reference
 ********************************************************************************************/

/* 
int updateCoins(int player, struct gameState *state, int bonus)
{
  int i;
	
  //reset coin count
  state->coins = 0;

  //add coins for each Treasure card in player's hand
  for (i = 0; i < state->handCount[player]; i++)
    {
      if (state->hand[player][i] == copper)
	{
	  state->coins += 1;
	}
      else if (state->hand[player][i] == silver)
	{
	  state->coins += 2;
	}
      else if (state->hand[player][i] == gold)
	{
	  state->coins += 3;
	}	
    }	

  //add bonus
  state->coins += bonus;

  return 0;
}
*/