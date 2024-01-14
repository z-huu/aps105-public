#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


bool gameStatus(int Size, char userArray[][Size], int difficultyLevel);

void printBoard(int Size, char grid[][Size]);
bool validRowCol(int row, int col, int Size);
void updateRowCol(int* row, int* col, int dir, bool forward);
int calculateScoreInDir(int row, int col, int direction, int Size,
                        char userArray[][Size]);

void getInput(int* row, int* col, int Size);
void getLevelAndDimensions(int* size, int* difficultyLevel, const int maxDim);
int getRand(int maxChoices);

//main starts here ************************
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

  char grid[Size][Size];
  for (int row = 0; row < Size; row++) {
    for (int col = 0; col < Size; col++) {
      grid[row][col] = copy[row][col] + '0';
    }
  }
  // TODO: check if there is a valid game, if not, create one

  /* 
  take in passed array using given user dimension
  verify the gameStatus
    if invalid
      loop, taking a random column and row and adding a 1 until gameStatus returns valid
  */

 	// verify passed array
	bool isValid = gameStatus(Size, grid, difficultyLevel);
	while (!isValid) {

		int randRow = getRand(Size); 
		int randCol = getRand(Size);
		
		grid[randRow][randCol] = '1';
		isValid = gameStatus(Size, grid, difficultyLevel);
	}

  int userInputRow = 0, userInputCol = 0;

  // test gameStatus


  char userArray[Size][Size];
  for (int row = 0; row < Size; row++) {
    for (int col = 0; col < Size; col++) {
      userArray[row][col] = '-';
    }
  }
  bool gameOver = true;
  int steps = 0;


// ignore this ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`
  do {
    getInput(&userInputRow, &userInputCol, Size);
    userArray[userInputRow][userInputCol] = grid[userInputRow][userInputCol];
    printBoard(Size, userArray);

    gameOver = gameStatus(Size, userArray, difficultyLevel);
    steps++;
  } while (!gameOver && steps < Size * Size);
  if (steps == Size * Size) {
    printf("Not a valid game!");
  } else {
    printf("Game over!\n");
    printf("Your score is %d", Size * Size - steps);
  }
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  return 0;
}
//main ends here ***********************************
bool gameStatus(int Size, char userArray[][Size], int difficultyLevel) { //looks good
	// call calculateScoreinDir to check each coordinate in passed userArray. 
	//if there is a score equivalent to passed difficultyLevel, return true, otherwise, return false
	//passed userArray will have either 1s, 0s, or -s. 
	bool gameWon = false;
	int currentScore = 0;
	
	for (int i = 0; i < Size; i++){ //row for
		for (int k = 0; k < Size; k++) { //col for 
			for (int j = 0; j < 4; j++) { //direction for

				currentScore = calculateScoreInDir(i, k, j, Size, userArray);
        
        if (currentScore == difficultyLevel) {
          return true;
        }
			} //direction loop ends
				


		}// col end

	}// row end

  return gameWon; //which is false

}

int calculateScoreInDir(int row, int col, int direction, int Size, char userArray[][Size]) {
  // Check in the forward direction how many 1s are there,
  // plus how many 1s are there in the backward direction
  // checking for CONSECUTIVE 1s including the 1 at (row, col) if there is a 1 there

  // ********** IF YOU START WITH A 0, THE LARGESTSEQUENCE WILL ALWAYS BE 0

  int oneCounter = 0;
  int largestSequence = 0;
  bool currentOne = (userArray[row][col]=='1'); //incorporate this bool in your code

  if (direction == 0) { //checking vertical line in current column

    for (int i = 0; i < Size; i++) { //going top to down in current column
      if ((userArray[i][col]) == '1') {

        oneCounter++;
        if (oneCounter > largestSequence) { //increments largestSequence only if current oneCounter is larger
          largestSequence++;
        }

      } else { //if the next element is a 0, oneCounter is set to 0

        oneCounter = 0;
      }

    }
    
    
  } else if (direction == 1) { //checking diagonal top right line
    
    if (!currentOne) {
    largestSequence = 0;
    return largestSequence;

   } else {
    int largestOne = 0, largestTwo = 0; //largestOne for iterating top right, largestTwo for iterating bottom left
    oneCounter = 1, largestSequence = 1;
    //iterate to top right and then iterate to bottom left
    for (int i = row, k = col; (i>=0 && k<Size); i--, k++) { //top right iterating
      if (userArray[i][k] == '1') {
        oneCounter++;
        if (oneCounter > largestOne) {
          largestOne++;
        }
      } else {
        oneCounter = 0;
      }

    }

    oneCounter = 1, largestSequence = 1;
    for (int i = row, k = col; (i<Size && k>=0); i++, k--) { //bottom left iterating
      if (userArray[i][k] == '1') {
        oneCounter++;
        if (oneCounter > largestTwo) {
          largestTwo++;
        }
      } else {
        oneCounter = 0;
      }
    }

      if (largestOne > largestTwo) {
        return largestOne;
      } else {
        return largestTwo;
      }
      
      return 500;
   }

  } else if (direction == 2) { //checking horizontal line in current row

    for (int k = 0; k < Size; k++) {

      if (userArray[row][k]=='1') {
        oneCounter++;
        while (oneCounter > largestSequence) {
          largestSequence++;
        }
      } else {
        oneCounter = 0;
      }

    }

  } else if (direction == 3) { //checking diagonal top left line, start from top left and iterate downwards bottom right

    if (!currentOne) {
    largestSequence = 0;
    return largestSequence;

   } else {
    int largestOne = 0, largestTwo = 0; //largestOne for iterating top left, largestTwo for iterating bottom right
    oneCounter = 1, largestSequence = 1;
   
    for (int i = row, k = col; (i>=0 && k>=0); i--, k--) { //top left iterating
      if (userArray[i][k] == '1') {
        oneCounter++;
        if (oneCounter > largestOne) {
          largestOne++;
        }
      } else {
        oneCounter = 0;
      }

    }

    oneCounter = 1, largestSequence = 1;
    for (int i = row, k = col; (i<Size && k<Size); i++, k++) { //bottom right iterating
      if (userArray[i][k] == '1') {
        oneCounter++;
        if (oneCounter > largestTwo) {
          largestTwo++;
        }
      } else {
        oneCounter = 0;
      }
    }
      if (largestOne > largestTwo) {
        return largestOne;
      } else {
        return largestTwo;
      }
      
      return 500;
   }


  }

  if (currentOne == false) {
    largestSequence = 0;
  }
  return largestSequence; 
}

void updateRowCol(int* row, int* col, int dir, bool forward) {
  // update Row and Col in forward/backward direction given direction
  // If direction is 0: row--, 1: row-- and col++, 2: col++, 3: row-- and col--
  //If forward is true, the above holds. If forward is FALSE, the above is reversed (i.e row-- becomes row++)

  if (forward == true) { //if forward is true

    if (dir == 0) {
      *row--;
    } else if (dir == 1) {
      *row--;
      *col++;
    } else if (dir == 2) {
      *col++;
    } else if (dir == 3) {
      *row--;
      *col--;
    }
    
  } else { //if forward is false

    if (dir == 0) {
      *row++;
    } else if (dir == 1) {
      *row++;
      *col--;
    } else if (dir == 2) {
      *col--;
    } else if (dir == 3) {
      *row++;
      *col++;
    }

  }

}

bool validRowCol(int row, int col, int Size) {
  // from part 1
  bool valid = true;

  if (row < 0 || row > (Size-1)) {
    valid = false;
  }

  if (col < 0 || col > (Size-1)) {
    valid = false;
  }

  return valid;
}

void printBoard(int Size, char grid[][Size]) { //adjusted to account for char array instead of int array

  //the 2d array represents a square grid; #rows = #cols
  for (int i = 0; i < Size; i++) { // row for loop

    for (int k = 0; k < Size; k++ ) { //col for loop

      printf("%c", grid[i][k]); //prints the kth element in the ith row of grid array

    }

    printf("\n");//new line after every row 

  }

}


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

int getRand(int maxChoices) { 
  return (rand() % (maxChoices)); 
}
