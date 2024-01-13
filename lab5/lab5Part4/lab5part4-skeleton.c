#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void populateBoxes(int[], int);
void takeUserChoices(int[], int[], const int, const int);
bool validateChoices(int[], const int, const int);
void calculateScore(int[], const int, int[], int[], const int, int*,
                    int*);  // calculate the score of each user
void appendStatistics(int[], const int, int[]);
int frequentBox(int[], const int);
// function declarations above ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//main function starts here ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`
int main(void) {
  // don't set srand!
  const int BoxesNum = 20;
  const int ChoicesNum = 5;
  int boxes[BoxesNum], userOne[ChoicesNum], userTwo[ChoicesNum], histogramUserOne[BoxesNum], histogramUserTwo[BoxesNum];

  int userOneScore = 0, userTwoScore = 0, scoreDifference = 0;

// implement loop that runs as long as difference in user score < 50
// after each run of the loop, update difference variable 

while (scoreDifference <= 50) {

  for (int i = 0; i < BoxesNum; i++) {
      histogramUserOne[i] = 0;
      histogramUserTwo[i] = 0;
    }

      populateBoxes(boxes, BoxesNum);

      takeUserChoices(userOne, userTwo, ChoicesNum, BoxesNum);

      calculateScore(boxes, BoxesNum, userOne, userTwo, ChoicesNum, &userOneScore,
                    &userTwoScore);

      // Append Statistics for User One
      appendStatistics(userOne, ChoicesNum, histogramUserOne);
      // Append Statistics for User Two

      appendStatistics(userTwo, ChoicesNum, histogramUserTwo);

      printf("Player 1: %d.\nPlayer 2: %d.\n", userOneScore, userTwoScore);

    

  //updating scoreDifference
    if (userOneScore > userTwoScore) {

      scoreDifference = userOneScore - userTwoScore;
    } else if (userOneScore < userTwoScore) {

      scoreDifference = userTwoScore - userOneScore;
    } else {
      scoreDifference = userOneScore - userTwoScore; 
    }

} //end of while loop

if (userOneScore > userTwoScore) {
      printf("User 1 wins, ");
      printf("and the first box they chose most frequently is: %d\n", frequentBox(histogramUserOne, BoxesNum));
    } else {
      printf("User 2 wins, ");
      printf("and the first box they chose most frequently is: %d\n", frequentBox(histogramUserTwo, BoxesNum));
    }
    
  return 0;
}
//main function ends here ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`

void takeUserChoices(int userOne[], int userTwo[], const int ChoicesNum, const int BoxesNum) {
  // Can check if the inputs are distinct and if they are between 1 and BoxesNum
  // - 1
  do {
    printf("Player 1, please enter distinct box choices between 0 and 19: ");
    for (int choiceInd = 0; choiceInd < ChoicesNum; choiceInd++) {
      scanf("%d", &userOne[choiceInd]);
    }
  } while (!validateChoices(userOne, ChoicesNum, BoxesNum));

  do {
    printf("Player 2, please enter distinct box choices between 0 and 19: ");
    for (int choiceInd = 0; choiceInd < ChoicesNum; choiceInd++) {
      scanf("%d", &userTwo[choiceInd]);
    }
  } while (!validateChoices(userTwo, ChoicesNum, BoxesNum));
}

//warning ; function from test case 3 hasn't been checked for tset cases
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
              printf("-10 from player 2 score.]n");
            } else {

              // no one picked the bomb
            }

          } //end of isBomb else

      } else{/**/}

    }

    //Match user choices to box

    //Update user score
}


void appendStatistics(int userChoice[], const int ChoicesNum, int histogram[]) {

  //fill histogram array; each box can only be picked once
  
  for (int i = 0; i < ChoicesNum; i++) {
    //getting the userChoices

    int currentChoice = userChoice[i];

    //increment histogram entries

    histogram[currentChoice]++;   
  }

  //printing histogram (no need, program will do it itself)
  

}

int frequentBox(int histogram[], const int BoxesNum) {

  int largestNum = histogram[0];
  int largestIndex = 0;
  
  for (int i = 0; i < BoxesNum; i++) {

    if (largestNum < histogram[i]) {

      largestNum = histogram[i];
      largestIndex = i;

    }

  }

  return largestIndex;

}


void populateBoxes(int boxes[], const int BoxesNum) {

    for (int i = 0; i < BoxesNum; i++) { //if randNum = 0, nothing, 10 = candy, -10 = bomb

        int randNum = (rand() % 3) + 1;
            if (randNum == 1) { //now if statements to map the random numbers to either 0, 10, or -10
                boxes[i] = -10;
            } else if (randNum == 2) {
                boxes[i] = 0;
            } else if (randNum == 3) {
                boxes[i] = 10;
            }

        printf("%d: %d, ", i, boxes[i]); //prints content of each box (i is box, boxes[i] is content of box)

    }
        printf("\n");
}
bool validateChoices(int choices[], const int ChoicesNum, const int BoxesNum) {
  bool valid = true;

    //verify that all elements are within valid range
        for (int i = 0; i < ChoicesNum; i++) {

            int temp = choices[i];
            
                if ((temp > 19)||(temp < 0)) {

                    valid = false;
                    return valid;
                } else {
                    //ayya
                }

        }
    //verify that elements in choice array are all unique
    
        for (int i = 0; i < ChoicesNum; i++) {
            int currentChoice = choices[i];
            for (int j = i+1; j < ChoicesNum; j++) {

                int cyclingChoice = choices[j];
                if (currentChoice == cyclingChoice) {
                    valid = false;
                    return valid;
                }
            }

            if (valid == false) {
            return valid;
            }

        }

  return valid;
}