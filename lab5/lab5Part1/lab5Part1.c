#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//function declarations ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool validateChoices(int choices[], const int ChoicesNum, const int BoxesNum);
void takeUserChoices(int userOne[], int userTwo[], const int ChoicesNum, const int BoxesNum);
void populateBoxes(int boxes[], const int BoxesNum);
// main function ~~~~~~~~~~~~~~~~~

int main(void) {
  const int BoxesNum = 20;
  const int ChoicesNum = 5;
  int boxes[BoxesNum], userOne[ChoicesNum], userTwo[ChoicesNum];
  populateBoxes(boxes, BoxesNum);
  takeUserChoices(userOne, userTwo, ChoicesNum, BoxesNum);
  return 0;
}

//function definitions ~~~~~~~~~~~~~~~~~~~~~~~~~~~`

void takeUserChoices(int userOne[], int userTwo[], const int ChoicesNum,
                     const int BoxesNum) {
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