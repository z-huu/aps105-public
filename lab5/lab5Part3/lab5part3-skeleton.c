#include <stdbool.h>
#include <stdio.h>

void calculateScore(int[], const int, int[], int[], const int, int*, int*);  // calculate the score of each user
int main(void) {
  const int BoxesNum = 20;
  const int ChoicesNum = 5;
  int boxes[BoxesNum], userOne[ChoicesNum], userTwo[ChoicesNum];
  printf("Enter boxes content: ");
  for (int i = 0; i < BoxesNum; i++) {
    scanf("%d", &boxes[i]);
  }
  printf("Enter player 1 choices: ");
  for (int i = 0; i < ChoicesNum; i++) {
    scanf("%d", &userOne[i]);
  }
  printf("Enter player 2 choices: ");
  for (int i = 0; i < ChoicesNum; i++) {
    scanf("%d", &userTwo[i]);
  }
  int userOneScore = 0, userTwoScore = 0;
  calculateScore(boxes, BoxesNum, userOne, userTwo, ChoicesNum, &userOneScore,
                 &userTwoScore);
  printf("Player 1: %d.\nPlayer 2: %d.\n", userOneScore, userTwoScore);

  return 0;
}
//main function above ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//Read non-zero content of box
//Read user has chosen box (if applicable)
//Update points (if applicable)
//Repeat!

//function passed test cases! ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void calculateScore(int boxes[], const int BoxesNum, int userOne[], int userTwo[], const int ChoicesNum, int* score1, int* score2) {
  // Get the score of each user

    //Read contents of each box (if any)

    for (int i = 0; i < BoxesNum; i++) { //box content for loop
      bool oneChosen = false;
      bool twoChosen = false;
      bool isBomb = false;
      int currentBox = i;
      if (boxes[i] != 0) {

          printf("Found %d in boxes[%d].\n", boxes[i], i); //print box content if non-zero

          //check if box is candy or bomb
          if (boxes[i] == 10) {

            isBomb = false;
          } else {
            isBomb = true;
          }

          for (int j = 0; j < ChoicesNum; j++) { //check if user1 has chosen this box
          //once set currentChoice J, cycle through each 
            int currentChoice = userOne[j];
            if (currentChoice == currentBox) { 

              printf("Found index %d in player 1.\n", currentChoice);
              oneChosen = true;
              break; //back into for loop
            }

          }

          for (int k = 0; k < ChoicesNum; k++) { //check if user2 has chosen this box
            int currentChoice = userTwo[k];
            if (currentChoice == currentBox) { 

              printf("Found index %d in player 2.\n", currentChoice);
              twoChosen = true;
              break; //back into for loop
            }

          }
          
          if (isBomb == false) { //if box is a candy
            if (oneChosen == true && twoChosen == true) { //deal with different point cases

              //both users get 5 points
              *score1+=5;
              *score2+=5;
              printf("+5 to players 1 and 2 scores.\n");
              
            } else if (oneChosen == true) {

              //player 1 gets 10 points
              *score1 +=10;
              printf("+10 to player 1 score.\n");

            } else if (twoChosen == true) {

              //player 2 gets 10 points
              *score2 +=10;
              printf("+10 to player 2 score.\n");

            } else {

              //no player picked the box

            }

          } else { //if box is a bomb

            if (oneChosen == true && twoChosen == true) {

              //both players lose 10 points
              *score1 +=-10;
              *score2 +=-10;
              printf("-10 from player 1 score.\n-10 from player 2 score.\n");
              
            } else if (oneChosen == true) {

              //player 1 loses 10 points
              *score1 +=-10;
              printf("-10 from player 1 score.\n");
            } else if (twoChosen == true) {

              //player 2 loses 10 points
              *score2 +=-10;
              printf("-10 from player 2 score.\n");
            } else {

              // no one picked the bomb
            }

          } //end of isBomb else

      } else{/**/}

    }

    //Match user choices to box

    //Update user score
}
