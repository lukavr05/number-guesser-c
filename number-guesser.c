#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

// generate the random number
int generateRandom(int max) {
  srand(time(NULL));
  int r = rand() % max + 1;

  return r;
}

// allow the user to guess a number
bool guessNumber(int guess, int target) {
  if (guess > target) {
    printf("Too high! Guess again:\n");
  } else if (guess < target) {
    printf("Too low! Guess again\n");
  } else {
    return true;
  }
  return false;
}

// main loop
int main(int argc, char *argv[]) {
  int MAX;

  if (argc == 1 || argc > 2){
    printf("Using default upper bound of 100, please provide ONE argument to use a custom upper bound\n");
    MAX = 100;
  } else {
    MAX = atoi(argv[1]);
  }
  
  // setting our target number
  int target = generateRandom(MAX);
    
  // take our first guess
  int guess;
  int numGuesses = 0;
  printf("Enter your guess:\n");
  scanf("%d", &guess);
  bool correct = guessNumber(guess, target);

  numGuesses++;
  // loop until the user guesses the correct number
  while (!correct) {
    scanf("%d", &guess);
    numGuesses++;
    correct = guessNumber(guess, target);
    }

  printf("Well Done!!! You guess the number correctly in %d guesses!\n", numGuesses);
}
