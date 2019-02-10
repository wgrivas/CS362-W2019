#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function
    char array[9] = {'[','(','{',' ','a','x','}',')',']'};	//array of all chars from the target statement

    return array[rand() % sizeof(array)];					//return a random char from the array
}

char *inputString()
{
    // TODO: rewrite this function
	int i;													//for loop counter
    char array[5] = {'r','e','s','e','t'};					//array of all chars in the string from the target statement
    char *temp = malloc(sizeof(char)*strlen(array)+1);		//allocate string array
    
	for (i = 0; i < sizeof(array); i++)						//loop to populate string array with random chars
      temp[i] = array[rand() % sizeof(array)];
    temp[i] = '\0';											//NULL termintor

    return temp;											//return string array
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
