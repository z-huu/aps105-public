#include <stdio.h>

void appendStatistics(int userChoice[], const int ChoicesNum, int histogram[]);
int frequentBox(int histogram[], const int BoxesNum);

int main(void) {
  const int BoxesNum = 20;
  const int ChoicesNum = 5;

  int userOne[ChoicesNum], userOneHisto[BoxesNum];

  for (int i = 0; i < BoxesNum; i++) {
    userOneHisto[i] = 0;
  }

  int numOfTimes = 0;
  while (numOfTimes <= 5) {
    printf("Enter choices: ");
    for (int i = 0; i < 5; i++) {
      scanf("%d", &userOne[i]);
    }
    appendStatistics(userOne, ChoicesNum, userOneHisto);
    numOfTimes++;
  }
  printf("The smallest and most frequently used box is: %d\n",
         frequentBox(userOneHisto, BoxesNum));
  return 0;
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
