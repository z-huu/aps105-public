#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void printBoard(int Size, int grid[][Size]);
void getInput(int* row, int* col, int Size);
void getLevelAndDimensions(int* size, int* difficultyLevel, const int maxDim);
bool validRowCol(int row, int col, int Size);

int main(void) {
  const int maxDim = 23;
  int Size = 0, difficultyLevel = 0;

  getLevelAndDimensions(&Size, &difficultyLevel, maxDim);

  int copy[23][23] = {
      {1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1},
      {1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1},
      {0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0},
      {1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1},
      {1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1},
      {0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0},
      {1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1},
      {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
      {1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1},
      {1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
      {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0},
      {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1},
      {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
      {0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1},
      {1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1},
      {0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1},
      {0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
      {0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1},
      {1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0},
      {1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1},
      {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1},
      {1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1}};

  int grid[Size][Size];
  for (int row = 0; row < Size; row++) {
    for (int col = 0; col < Size; col++) {
      grid[row][col] = copy[row][col];
    }
  }
  printBoard(Size, grid);

  int userInputRow = 0, userInputCol = 0;
  getInput(&userInputRow, &userInputCol, Size);
  printf("row, col = %d, %d\n", userInputRow, userInputCol);
  grid[userInputRow][userInputCol] = 9;  // any arbitrary number
  printBoard(Size, grid);

  return 0;
}
//Functions passed test cases ***********************88
void getInput(int* row, int* col, int Size) { 
//prompts user for coordinate of line
  *col = 0, *row = 0;
  bool validInputs = false;
  
    printf("Enter user input: ");
    scanf("%d %d", row, col);
    validInputs = validRowCol(*row, *col, Size);

  while (!validInputs) {

    printf("Please enter your row and col to be between 0 and Size - 1: ");
    scanf("%d %d", row, col);
    validInputs = validRowCol(*row, *col, Size);

  }

  

}

bool validRowCol(int row, int col, int Size) {
//row & col are valid if they are inbetween 0 and Size-1
  bool valid = true;

  if (row < 0 || row > (Size-1)) {
    valid = false;
  }

  if (col < 0 || col > (Size-1)) {
    valid = false;
  }

  return valid;

}

void getLevelAndDimensions(int* Size, int* levelOfDiff, const int maxDim) {

    *levelOfDiff = 0;
    printf("Enter the difficulty level: ");
    scanf("%d", levelOfDiff);

    //getting difficulty level from user, setting dereferenced value of pointer equal to user input
    while (*levelOfDiff < 1 || *levelOfDiff > maxDim) {

    printf("Please enter a difficulty level between 1 and 23: ");
    scanf("%d", levelOfDiff);

    }

    printf("Enter the dimensions of the grid: ");
    scanf("%d", Size);

    while (*Size < 4) {

      printf("Please enter dimensions >= 4: ");
      scanf("%d", Size);
      
    }

}

void printBoard(int Size, int grid[][Size]) {

  //the 2d array represents a square grid; #rows = #cols
  for (int i = 0; i < Size; i++) { // row for loop

    for (int k = 0; k < Size; k++ ) { //col for loop

      printf("%d", grid[i][k]); //prints the kth element in the ith row of grid array

    }

    printf("\n");//new line after every row 

  }

}


