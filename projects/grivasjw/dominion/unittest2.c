/*********************************************************************************************
 * Author: William Grivas, Jr.
 * Title: Assignment 3
 * Class: CS362 Software Engineering II
 * File: unittest2.c
 * Description: Unittest for getCost(int cardNumber);
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
	int costReturned = 0;
	
	printf("\n--------------------Start Test: getCost() function--------------------\n");
	
	for(int i; i < 27; i++){
		costReturned = getCost(i);
	
		if(i == 0)			//Curse: 0
		{
			printf("\nTest: Curse\n");
			compareStates(costReturned, 0);
			printf(" Curse returned %d.\n", costReturned);	
		}
		else if (i == 1)	//Estate: 2
		{			 
			printf("\nTest: Estate\n");
			compareStates(costReturned, 2);
			printf(" Estate returned %d.\n", costReturned);	
		}
		else if (i == 2)	//Duchy: 5
		{
			printf("\nTest: Duchy\n");
			compareStates(costReturned, 5);
			printf(" Duchy returned %d.\n", costReturned);
		}
		else if (i == 3)	//Province: 8
		{
			printf("\nTest: Province\n");
			compareStates(costReturned, 8);
			printf(" Province returned %d.\n", costReturned);
		}
		else if (i == 4)	//Copper: 0
		{
			printf("\nTest: Copper\n");
			compareStates(costReturned, 0);
			printf(" Copper returned %d.\n", costReturned);
		}
		else if (i == 5)	//Silver: 3
		{
			printf("\nTest: Silver\n");
			compareStates(costReturned, 3);
			printf(" Silver returned %d.\n", costReturned);
		}
		else if (i == 6)	//Gold: 6
		{
			printf("\nTest: Gold\n");
			compareStates(costReturned, 6);
			printf(" Gold returned %d.\n", costReturned);
		}
		else if (i == 7)	//Adventurer: 6
		{
			printf("\nTest: Adventurer\n");
			compareStates(costReturned, 6);
			printf(" Adventurer returned %d.\n", costReturned);
		}
		else if (i == 8)	//Council_Room: 5
		{
			printf("\nTest: Council_Room\n");
			compareStates(costReturned, 5);
			printf(" Council_Room returned %d.\n", costReturned);
		}
		else if (i == 9)	//Feast: 4
		{
			printf("\nTest: Feast\n");
			compareStates(costReturned, 4);
			printf(" Feast returned %d.\n", costReturned);
		}
		else if (i == 10)	//Gardens: 4
		{
			printf("\nTest: Gardens\n");
			compareStates(costReturned, 4);
			printf(" Gardens returned %d.\n", costReturned);
		}
		else if (i == 11)	//Mine: 5
		{
			printf("\nTest: Mine\n");
			compareStates(costReturned, 5);
			printf(" Mine returned %d.\n", costReturned);
		}
		else if (i == 12)	//Remodel: 4
		{
			printf("\nTest: Remodel\n");
			compareStates(costReturned, 4);
			printf(" Remodel returned %d.\n", costReturned);
		}
		else if (i == 13)	//Smithy: 4
		{
			printf("\nTest: Smithy\n");
			compareStates(costReturned, 4);
			printf(" Smithy returned %d.\n", costReturned);
		}
		else if (i == 14)	//Village: 3
		{
			printf("\nTest: Village\n");
			compareStates(costReturned, 3);
			printf(" Village returned %d.\n", costReturned);
		}
		else if (i == 15)	//Baron: 4
		{
			printf("\nTest: Baron\n");
			compareStates(costReturned, 4);
			printf(" Baron returned %d.\n", costReturned);
		}
		else if (i == 16)	//Great_Hall: 3
		{
			printf("\nTest: Great_Hall\n");
			compareStates(costReturned, 3);
			printf(" Great_Hall returned %d.\n", costReturned);
		}
		else if (i == 17)	//Minion: 5
		{
			printf("\nTest: Minion\n");
			compareStates(costReturned, 5);
			printf(" Minion returned %d.\n", costReturned);
		}
		else if (i == 18)	//Steward: 3
		{
			printf("\nTest: Steward\n");
			compareStates(costReturned, 3);
			printf(" Steward returned %d.\n", costReturned);
		}
		else if (i == 19)	//Tribute: 5
		{
			printf("\nTest: Tribute\n");
			compareStates(costReturned, 5);
			printf(" Tribute returned %d.\n", costReturned);
		}
		else if (i == 20)	//Ambassador: 3
		{
			printf("\nTest: Ambassador\n");
			compareStates(costReturned, 3);
			printf(" Ambassador returned %d.\n", costReturned);
		}
		else if (i == 21)	//Cutpurse: 4
		{
			printf("\nTest: Cutpurse\n");
			compareStates(costReturned, 4);
			printf(" Cutpurse returned %d.\n", costReturned);
		}
		else if (i == 22)	//Embargo: 2
		{
			printf("\nTest: Embargo\n");
			compareStates(costReturned, 2);
			printf(" Embargo returned %d.\n", costReturned);
		}
		else if (i == 23)	//Outpost: 5
		{
			printf("\nTest: Outpost\n");
			compareStates(costReturned, 5);
			printf(" Outpost returned %d.\n", costReturned);
		}
		else if (i == 24)	//Salvager: 4
		{
			printf("\nTest: Salvager\n");
			compareStates(costReturned, 4);
			printf(" Salvager returned %d.\n", costReturned);
		}
		else if (i == 25)	//Sea_Hag: 4
		{
			printf("\nTest: Sea_Hag\n");
			compareStates(costReturned, 4);
			printf(" Sea_Hag returned %d.\n", costReturned);
		}
		else if (i == 26)	//Treasure_Map: 4
		{
			printf("\nTest: Treasure_Map\n");
			compareStates(costReturned, 4);
			printf(" Treasure_Map returned %d.\n", costReturned);
		}
	}
	 
	printf("\n--------------------End Test: getCost() function--------------------\n\n");

	return 0;
}




/********************************************************************************************* 
 *  Copy of getCost() function from dominion.c for reference
 ********************************************************************************************/

/* 
int getCost(int cardNumber)
{
  switch( cardNumber ) 
    {
    case curse:
      return 0;
    case estate:
      return 2;
    case duchy:
      return 5;
    case province:
      return 8;
    case copper:
      return 0;
    case silver:
      return 3;
    case gold:
      return 6;
    case adventurer:
      return 6;
    case council_room:
      return 5;
    case feast:
      return 4;
    case gardens:
      return 4;
    case mine:
      return 5;
    case remodel:
      return 4;
    case smithy:
      return 4;
    case village:
      return 3;
    case baron:
      return 4;
    case great_hall:
      return 3;
    case minion:
      return 5;
    case steward:
      return 3;
    case tribute:
      return 5;
    case ambassador:
      return 3;
    case cutpurse:
      return 4;
    case embargo: 
      return 2;
    case outpost:
      return 5;
    case salvager:
      return 4;
    case sea_hag:
      return 4;
    case treasure_map:
      return 4;
    }
	
  return -1;
}

*/