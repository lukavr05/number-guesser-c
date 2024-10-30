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
bool checkGuess(int guess, int target) {
  if (guess > target) {
    printf("Too high!\n");
  } else if (guess < target) {
    printf("Too low!\n");
  } else {
    return true;
  }
  return false;
}

void guessLimited(int guess, int numGuesses, int target, int attempts) {
  printf("Enter your guess:\n");
  scanf("%d", &guess);
  bool correct = checkGuess(guess, target);

  numGuesses++;
  attempts--;


  // loop until the user guesses the correct number
  while (!correct && attempts > 0) {
    printf("You have %d attempts remaining!\n", attempts);
    scanf("%d", &guess);
    numGuesses++;
    attempts--;
    correct = checkGuess(guess, target);
  }

  if (attempts == 0) {
    printf("\nYou ran out of attempts!\n");
  } else {
    printf("Well Done!!! You guess the number correctly in %d guesses!\n", numGuesses);
  }
}

void guessMain(int guess, int numGuesses, int target) {
  printf("Enter your guess:\n");
  scanf("%d", &guess);
  bool correct = checkGuess(guess, target);

  numGuesses++;
  // loop until the user guesses the correct number
  while (!correct) {
    scanf("%d", &guess);
    numGuesses++;
    correct = checkGuess(guess, target);
  }
  printf("Well Done!!! You guess the number correctly in %d guesses!\n", numGuesses);
}

// main loop
int main(int argc, char *argv[]) {
  int MAX;
  int attempts = 0;

  if (argc == 1){
    printf("Using default upper bound of 100, please provide one argument to use a custom upper bound, and optionally another to specify the number of attempts\n");
    MAX = 100;
  } else if (argc == 2){
    MAX = atoi(argv[1]);
  } else {
    MAX = atoi(argv[1]);
    attempts = atoi(argv[2]);
  }
  
  // setting our target number
  int target = generateRandom(MAX);
    
  // take our first guess
  int guess = 0;
  int numGuesses = 0;

  if (attempts > 0) {
    printf("You have %d attempts to guess the number! Good luck!!\n", attempts);
    guessLimited(guess, numGuesses, target, attempts);
  } else {
    guessMain(guess, numGuesses, target);
  }
 }
