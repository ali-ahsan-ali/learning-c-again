#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int roll_dice(void);
bool play_game(void);

int main (void) {
  char play_again[1];
  int count_win = 0;
  int count_loss = 0;

  time_t t;
  /* Intializes random number generator */
  srand((unsigned) time(&t));

  while (true){
    if (play_game()) {
      printf("You win!\n\n");
      count_win++;
    } else {
      printf("You lose!\n\n");
      count_loss++;
    }
    printf("Play again? ");
    scanf(" %c", play_again);
    printf("\n");
    if ( *play_again != 'y' && *play_again != 'Y') {
      break;
    }
  }
  printf("Wins: %d Losses:%d \n", count_win, count_loss);
}

int roll_dice(void){
  int dice_roll_1 = (rand() % 6) + 1;
  int dice_roll_2 = (rand() % 6) + 1;

  return dice_roll_1 + dice_roll_2;
}

bool play_game(void) {
  bool exit = false;
  int index = 0;
  int initial_point;

  while (exit != true) {
    int roll = roll_dice();
    printf("You rolled: %d\n", roll);
    if (index == 0) {
      initial_point = roll;
      if (roll == 7 || roll == 1) {
        return true;
      } else if (roll == 2 || roll == 3 || roll == 12 ){
        return false; 
      }      
      printf("You point is %d\n", initial_point);
    } else {
      if (roll == initial_point) {
        return true;
      } else if (roll == 7 ){
        return false; 
      }
    } 
    index++;
  }
}


