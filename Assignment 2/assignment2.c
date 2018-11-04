/*
Date: 08.04.2018
Author: Atalay Küçükoğlu

This is a dart game which is played by reading the segment and
ring of each throw. First, user enters a target value. Each
throw decreases the points until it is zero.

Rules: To start decreasing the points, user must make a double
shot. To finish the game, user must make a double shot again.
Any throws that makes remaining points 1 or negative will not be
counted.

*/

#include <stdio.h>

/**
* Calculates the score for the throw
*
* @param segment: segment of the throw (a number between 1 and 20)
* @param ring: corresponding ring of the throw
* @return score
* 
*/

int calculate_score(int segment, char ring)
{

  int score = 0;

  if (ring == 'S')
    score = segment;

  else if (ring == 'D')
    score = segment * 2;

  else if (ring == 'T')
    score = segment * 3;
  
  else if (ring == 'O')
    score = 25;
  
  else if (ring == 'I')
     score = 50;
  
  return score;
}

/**
* Calculates the remaining points and checks the starting and ending rules. 
*
* @param target: Target points (obtained by user) 
* @param current: Current points 
* @param segment: Segment of the throw (a number between 1 and 20)
* @param ring: Corresponding ring of the throw
* @return points: Remaining points
* 
*/

int calculate_points(int target, int current, int segment, char ring)
{

  int points = current;

  // Checks the first double throw to start decreasing points

  if ((target == points) && ring != 'D')
    return points;

  // Calculates the score of the throw

  int score = calculate_score(segment, ring);

  // Checks if points equals to 1 or smaller than 0

  if ((points - score == 1) || (points < score))
    return points;

  // Checks the if the last throw is double

  if ((points == score) && ring != 'D')
    return points;

  // Decreases points

  points -= score;

  return points;
}

int main()
{

  // Needed variables are initialized

  int target = 0;    // target points
  int segment = 0;   // segment of the throw
  char ring;         // ring of the throw
  int current = 0;   // current points
  int remaining = 0; //remaining points

  // Asks user for the target points and reads it.

  printf("Target: ");
  scanf("%d", &target);
  printf("\n");

  current = target;

  // Asks user for the throws and prints the remaining
  // points until the points equal to zero.

  while (current > 0)
  {

    printf("Throw: ");
    scanf("%d %c", &segment, &ring);

    remaining = calculate_points(target, current, segment, ring);
    current = remaining;

    printf("Points: %d\n", remaining);
  }

  // Terminates the program when the game is over.

  return 0;
}