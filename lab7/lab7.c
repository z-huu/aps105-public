#include <stdbool.h>
#include <stdio.h>
#include <string.h>
int getDimension(void)
{
    int dim = 0;
    printf("Enter the board dimension: ");
    scanf("%d", &dim);
    return dim;
}
void initializeBoard(char board[][26], int dim) {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            board[i][j] = 'U'; //empty tiles are U
        }
    }
    //initializes starting tilezzz
    board[dim/2 - 1][dim/2 - 1] = 'W';
    board[dim/2][dim/2] = 'W';
    board[dim/2-1][dim/2] = 'B';
    board[dim/2][dim/2-1] = 'B';
}
void printBoard(char board[][26], int n) {
    //print column line
        printf("  "); //two spaces, aligned with grid print
    for (int i = 0; i < n; i++) {
        printf("%c", 97+i);
    }
        printf("\n");

    //print only the portion of board within the given dimension
        int i = 0;
        for (int row = 0; row < n; row++) {
            printf("%c ", 97+i);
            i++;
            for (int col = 0; col < n; col++) {
                printf("%c", board[row][col]);
            }
        printf("\n");
    }

}
bool positionInBounds(int n, int row, int col)
{

    if ((row > n) || (row < 0))
    {
        return false;
    }
    else if ((col > n) || (col < 0))
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool checkLegalInDirection(char board[][26], int n, int row, int col, 
                           char colour, int deltaRow, int deltaCol) {

    //obtain the color of the next immediate tile in the given direction
    char nextTile = board[row+deltaRow][col+deltaCol];
    //special out of bounds case
    if (row+deltaRow < 0 || row+deltaRow >= n || col+deltaCol < 0 || col+deltaCol >= n) {
        return false;
    }
    bool oppositeExistsBetween, isWhite, isBlack;

    isWhite = (colour == 'W');
    isBlack = !(isWhite);

    //checking color of adjacent tiles, seeing if it is opposite of player tile
    if (isWhite) {

        oppositeExistsBetween = (nextTile == 'B');

    } else if (isBlack) {

        oppositeExistsBetween = (nextTile == 'W');

    }
    
    //if there is no oppositely colored tile following the current tile, it cannot be a legal move (in that dir)
    if (!oppositeExistsBetween) {
        return false;
    } else {
        //loop ends when we encounter empty tile or end of board or same colored tile
        while ((nextTile != 'U')&&(nextTile != colour)) {

            row+=deltaRow;
            col+=deltaCol;
            
            //special out of bounds case
            if (row < 0 || row >= n || col < 0 || col >= n) {
                return false; 
            } //could replace with positionInBounds function

            nextTile = board[row][col];
            if (nextTile == colour) {
                return true;
            } else if (nextTile=='U') {
                return false;
            } else {
                continue;
            }
        }
        
    }
    
    return false;
}
void availableMoves(char board[][26], char colour, int dim, int colorMoves[][2]) {
//idea is that for each coordinate in the board (we are looping through), we test in all directions if 
// it has a legal move. if it does, we print it and move on.
    int moveCounter = 0;
    for (int row = 0; row < dim; row++) { //row for
        for (int col = 0; col < dim; col++) { //col for
            //printf("col %d\n", col);
            int movePrinted = 0; //check if this implementation works
            for (int deltaRow = -1; deltaRow <= 1 && movePrinted == 0; deltaRow++) {
                for (int deltaCol = -1; deltaCol <= 1 && movePrinted == 0; deltaCol++) {
                    if (deltaRow != 0 || deltaCol != 0) {

                        if (checkLegalInDirection(board, dim, row, col, colour, deltaRow, deltaCol)&&(board[row][col]=='U')) {
                            printf("%c%c\n", row +'a', col+'a');
                            colorMoves[moveCounter][0] = row;
                            colorMoves[moveCounter][1] = col;
                            moveCounter++;
                            movePrinted = 1;
                        }

                    }
                }
            }
            
        }
    }
    return;
}

void alterInDirection(char board[][26], char colour, int row, int col, int deltaRow, int deltaCol) {

    int rowNum = row + deltaRow; // start at the neighbor of the given tile in the given direction
    int colNum = col + deltaCol;
    
    // continue moving in the given direction until we hit a tile of the same color or an empty tile
    while ((board[rowNum][colNum] != 'U') && (board[rowNum][colNum] != colour)) {
        
        board[rowNum][colNum] = colour;// flip the color of the tile
        rowNum += deltaRow;// move to the next tile in the given direction
        colNum += deltaCol;
    }
}


int main (void) { //main start ~~~~~~~~~~~~~~~~~~~~

//GET DIMENSIONS, INITIALIZE AND PRINT BOARD ~~~~~~~~~~~~~~~~~~~~~~~~~~~

char board[26][26];
    int dim = getDimension(), userFinished = 1;
    initializeBoard(board, dim);
    printBoard(board, dim);

//BOARD CONFIGURATION START ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`
    char userInput[5];
    printf("Enter board configuration:\n"); 

        while (userFinished != 0) {

            char colour, row, col;
            scanf("%s", userInput);
            userFinished = strcmp(userInput, "!!!");

            if (userFinished == 0) {
                break;
            }

            colour = userInput[0];
            row = userInput[1];
            col = userInput[2];

            int rowNum = row - 'a';
            int colNum = col - 'a';
            board[rowNum][colNum] = colour;

        }

    printBoard(board, dim);

//AVAILABLE MOVES START ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int whiteMoves[200][2]; //arrays holding available moves for each color
int blackMoves[200][2];

printf("Available moves for W:\n");
availableMoves(board, 'W', dim, whiteMoves);

printf("Available moves for B:\n");
availableMoves(board, 'B', dim, blackMoves);

//TAKE USER INPUT, CHECK VALIDITY ~~~~~~~~~~~~~~~~~~~~~
printf("Enter a move:\n");
scanf("%s", userInput);
char colour = userInput[0];
bool isValid = false;
int rowNum = userInput[1] - 'a', colNum = userInput[2] - 'a';

if (colour == 'W') {

    for (int i = 0; i < 200; i++) {
        if (rowNum == whiteMoves[i][0] && colNum == whiteMoves[i][1]) {
            printf("Valid move.\n");
            isValid = true;
            break;
        }
    }

} else if (colour == 'B') {

    for (int i = 0; i < 200; i++) {
        if (rowNum == blackMoves[i][0] && colNum == blackMoves[i][1]) {
            printf("Valid move.\n");
            isValid = true;
            break;
        }
    }
   
}

if (!isValid) {
    printf("Invalid move.\n");
    printBoard(board, dim);
    return 0;
}

//PERFORM PLAYER'S (valid) INPUT AND CORRESPONDING BOARD MODIFICATIONS ~~~~~~~~~~~~~~~~~~~~~~~~

    board[rowNum][colNum] = colour;
    //now iterate in all directions, flipping colors as you see fit
    isValid = false;

    //find what directions have legal moves in them
    for (int deltaRow = -1; deltaRow <= 1; deltaRow++) {
        for (int deltaCol = -1; deltaCol <= 1; deltaCol++) {

            if (checkLegalInDirection(board, dim, rowNum, colNum, colour, deltaRow, deltaCol)) {
                alterInDirection(board, colour, rowNum, colNum, deltaRow, deltaCol);
            }

        }
    }

    printBoard(board, dim);
    return 0;
} //main end ~~~~~~~~~~~~~~~~~~~~~~~~``

/*
for (int deltaRow = -1; deltaRow <= -1; deltaRow++) { //row dir for
                for (int deltaCol = -1; deltaCol <= -1; deltaCol++) { //col dir for
                    printf("augh");
                    if (checkLegalInDirection(board, dim, row, col, colour, deltaRow, deltaCol)) {
                        printf("%c%c\n", row - 'a', col - 'a');
                        break;
                    }
                }
            }
*/