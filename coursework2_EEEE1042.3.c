// Including libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Assigning global variables
char board[3][3];
char COMPUTER_Random1 = 'O', COMPUTER_Random2 = 'X', COMPUTER_Smart1 = 'O', COMPUTER_Smart2 = 'X';
int selection1;
char tempBoard[3][3];
int drawsCounter, winsCounterCompX, winsCounterCompO;

// Declaring functions which are defined down below in the program
void printBoard();
void cleanBoard();
void welcome();
void repeatGame();
void makeTempBoard ();

int placeLetter(char position, char player);
int checkForFreeSpaces();
int selectionType();
int checkWinner();
int smartAIalgorithm(char player);
int smartVSsmart();
int smartVSrandom();
int randomVSrandom();

// Main function
int main()
{
    // Calling some functions
    welcome();
    cleanBoard();
    // Setting up random seed  based on curren time
    srand(clock());

    // Switch statement for taking user input to select game mode
    switch (selectionType())
    {
        case 1: drawsCounter = 0, winsCounterCompO = 0, winsCounterCompX = 0; // Reset counters
                for (int i = 0; i < 1000; i++) // Loop the game 1000 times, change number if you want to change the number of time to repeat the game
                {
                    cleanBoard();
                    smartVSsmart();
                    printf("\n\nCount: %d games\n", i+1);
                }     
                printf("\nWins Smart AI 1 (O) =   %d    | Draws =   %d    | Wins Smart AI 2 (X) =   %d  \n", winsCounterCompO, drawsCounter, winsCounterCompX);         
            break;
        case 2: drawsCounter = 0, winsCounterCompO = 0, winsCounterCompX = 0;
                for (int i = 0; i < 1000; i++)
                {
                    cleanBoard();
                    smartVSrandom();
                    printf("\n\nCount: %d games\n", i+1);
                }     
                printf("\nWins Smart AI (O) =   %d    | Draws =   %d    | Wins Random AI (X) =   %d  \n", winsCounterCompO, drawsCounter, winsCounterCompX);         
            break;        
        case 3: drawsCounter = 0, winsCounterCompO = 0, winsCounterCompX = 0;
                for (int i = 0; i < 1000; i++)
                {
                    cleanBoard();
                    smartVSsmart();
                    printf("\n\nCount: %d games\n", i+1);
                }     
                printf("\nWins Random AI 1 (O) =   %d    | Draws =   %d    | Wins Random AI 2 (X) =   %d  \n", winsCounterCompO, drawsCounter, winsCounterCompX);         
            break;
            
    
   
    }
    // Asking if user wants to paly again.
    printf("\n\nWould you like to restart (y, n)\n");
    repeatGame();
    return 0;
    

    
   
}


// Printing welcome screen
void welcome()
{
    printf("******************************************************");
    printf("\nHi!\n");
    printf("Welcome to automated Tic-Tac-Toe (For gathering data) \n");
    printf("Please select one of these options (1, 2, 3)\n");
    printf("******************************************************\n");								
    printf("1) Smart AI vs Smart AI\n");
    printf("2) Smart AI vs Random AI\n");
    printf("3) Random AI vs Random AI\n");
}

// Function for taking input from user for which game mode to select.
int selectionType()
{
    
    while (scanf("%d", &selection1) != 1 )
    {
        printf("Invalid entry, please try again\n");
        scanf("%*s");
    }

    if (selection1 == 1 || selection1 == 2 || selection1 == 3)
    {
        printf("You've selected option %d\n", selection1);
       
    }
    else
    {
        printf("Invalid entry, please try again\n"); 
        selectionType();
    }
    return selection1;
}

// For resetting the board to initial values
void cleanBoard()
{
    char position[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    int v = 0;
   
       for(int x = 0; x < 3; x++)  // These nested for loops are for going to each position in the 2D array of the 'board'
       {
           for (int y = 0; y < 3; y++)
           {
                board[x][y] = position[v]; // To assign the position (x, y) of the board the values from the 'position' array
                v++; // To increment v so that during the next run of the loop the next character from 'position' array gets assigned to the correspondoing spot of 'board'
           }
           
       }
      
}

// For printing the board
void printBoard()
{
    printf("___________________\n");
    printf("|     |     |     |\n");
    printf("|  %c  |  %c  |  %c  |\n", board[0][0], board[0][1], board[0][2]);
    printf("|_____|_____|_____|\n");
    printf("|     |     |     |\n");
    printf("|  %c  |  %c  |  %c  |\n", board[1][0], board[1][1], board[1][2]);
    printf("|_____|_____|_____|\n");
    printf("|     |     |     |\n");
    printf("|  %c  |  %c  |  %c  |\n", board[2][0], board[2][1], board[2][2]);
    printf("|_____|_____|_____|\n\n");
}

// For checking the number of free spaces left on the board and returning that value
int checkForFreeSpaces()
{
    int freeSpaces = 9;
       
    for(int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            if (board[x][y] == 'O' || board[x][y] == 'X')
            {
                freeSpaces--;
            }
                
          }
           
    }
    return freeSpaces;
}

// For assigning 'X' or 'O' to a certain postion of the board, takes slected position by Player 1 or Player 2 or the computer as the 2 inputs.
int placeLetter(char position, char player)
{
    switch (position)
    {
    case 'a': 
            if (board[0][0] != 'a')
            {
                if (player == 'm') // This 'if else' statement is there so that if the computer does an illegal move then the game does not print the error, it just returns 0 without printing
                {
                    printf("\nPosition occupied, try a diffrent position\n\n");
                    return 0;
                }
                else
                {
                    return 0;
                }   
            }
            else
            {
                board[0][0] = player;
                return (1);
            }
          break;  
    case 'b': 
            if (board[0][1] != 'b')
            {
                if (player == 'm')
                    {
                        printf("\nPosition occupied, try a diffrent position\n\n");
                        return 0;
                    }
                    else
                    {
                        return 0;
                    }
            }
            else
            {
                board[0][1] = player;
                return (1);
            }
          break;  
    case 'c': 
            if (board[0][2] != 'c')
            {
                if (player == 'm')
                    {
                        printf("\nPosition occupied, try a diffrent position\n\n");
                        return 0;
                    }
                    else
                    {
                        return 0;
                    }
            }
            else
            {
                board[0][2] = player;
                return (1);
            }
          break;  
    case 'd': 
            if (board[1][0] != 'd')
            {
                if (player == 'm')
                    {
                        printf("\nPosition occupied, try a diffrent position\n\n");
                        return 0;
                    }
                    else
                    {
                        return 0;
                    }
            }
            else
            {
                board[1][0] = player;
                return (1);
            }
          break;  
    case 'e': 
            if (board[1][1] != 'e')
            {
                if (player == 'm')
                    {
                        printf("\nPosition occupied, try a diffrent position\n\n");
                        return 0;
                    }
                    else
                    {
                        return 0;
                    }
            }
            else
            {
                board[1][1] = player;
                return (1);
            }
          break;
    case 'f': 
            if (board[1][2] != 'f')
            {
                if (player == 'm')
                    {
                        printf("\nPosition occupied, try a diffrent position\n\n");
                        return 0;
                    }
                    else
                    {
                        return 0;
                    }
            }
            else
            {
                board[1][2] = player;
                return (1);
            }
          break;
    case 'g': 
            if (board[2][0] != 'g')
            {
                if (player == 'm')
                    {
                        printf("\nPosition occupied, try a diffrent position\n\n");
                        return 0;
                    }
                    else
                    {
                        return 0;
                    }
            }
            else
            {
                board[2][0] = player;
                return (1);
            }
          break;
    case 'h': 
            if (board[2][1] != 'h')
            {
                if (player == 'm')
                    {
                        printf("\nPosition occupied, try a diffrent position\n\n");
                        return 0;
                    }
                    else
                    {
                        return 0;
                    }
            }
            else
            {
                board[2][1] = player;
                return (1);
            }
          break;
    case 'i': 
            if (board[2][2] != 'i')
            {
                if (player == 'm')
                    {
                        printf("\nPosition occupied, try a diffrent position\n\n");
                        return 0;
                    }
                    else
                    {
                        return 0;
                    }
            }
            else
            {
                board[2][2] = player;
                return (1);
            }
          break;    
    default:
            printf("Invalid entry, please try again.\n\n");
            return 0;

    }
    checkForFreeSpaces();
    return 0;
}

// Function to check for wins and return the winning character 'X'/'O', takes board as input.
int checkWinner(char chkboard[3][3])
{
    //Checks rows for wins
    for(int x = 0; x <3; x++)
    {
        if(chkboard [x][0] == chkboard [x][1] && chkboard [x][1] == chkboard [x][2] )
        {
            return chkboard [x][1];
        }
    }
    //Checks columns for wins
    for(int y = 0; y < 3; y++)
    {
        if(chkboard [0][y] == chkboard [1][y] && chkboard [1][y] == chkboard [2][y] )
        {
            return chkboard [1][y];
        }
    }
    //Checks one of the diagonals for wins
    if (chkboard[0][0] == chkboard[1][1] && chkboard[1][1] == chkboard[2][2])
    {
        return chkboard[1][1];
    }
    //Checks the other diagonal for wins
    if (chkboard[0][2] == chkboard[1][1] && chkboard[1][1] == chkboard[2][0])
    {
        return chkboard[1][1];
    }
    return 0; // Return 0 if there is no winner.
}

// Function for taking input from user on whether he wants to repeat the game.
void repeatGame()
{
    char repeat;
    while (scanf(" %c", &repeat) != 1 )
    {
        printf("Invalid entry, please try again\n");
        scanf("%*s");
    }

    if (repeat == 'y')
    {
        main();
       
    }
    else if (repeat == 'n')
    {
        printf("\n\nThanks for playing!!\n\n");
    }
    else
    {
        printf("Invalid entry, please try again\n"); 
        repeatGame();
    }
}

// Algorithm for Smart AI
int smartAIalgorithm(char player)
{
    makeTempBoard();
    char position;
    if (player == 'O')
    {
        for (int x = 0; x < 3; x++) // This nested for loop, as mentioned earlier is just for going through to each position of the board, in this case the temporary board
        {   
        makeTempBoard();
        for (int y = 0; y < 3; y++)
        {
            makeTempBoard();
            if (tempBoard[x][y] != 'X' && tempBoard[x][y] != 'O')
            {
                tempBoard[x][y] = 'O';
                if(checkWinner(tempBoard) == 'O') // For checking if placing an O in position (x, y) results in O winning, if it does, then the folloing code assignes that position to 'position'
                {
                    position = 'a' + (x * 3) + y; // Formula for assigning the correct position based on x and y (in terms of ASCII)
                    return position; // Returning the assigned position 
                }
                
            }
        }
        
        }

        for (int x = 0; x < 3; x++)
    {   
        makeTempBoard();
        for (int y = 0; y < 3; y++)
        {
            makeTempBoard();
            if (tempBoard[x][y] != 'X' && tempBoard[x][y] != 'O')
            {
                tempBoard[x][y] = 'X';
                if(checkWinner(tempBoard) == 'X') // For checking if placing an X in position (x, y) results in X winning, if it does then it blocks the move by placing an 'O' there
                {
                    tempBoard[x][y] = 'O';
                    position = 'a' + (x * 3) + y;
                    return position;
                }
                
            }
        }
        
    }
    if (checkWinner(tempBoard) == 0) // If none of the above cases happen then it just falls back to a random move.
    {
        position = (rand() % (105 - 97 + 1)) + 97;
        return position;
    }
    } 

    if (player == 'X')
    {
        for (int x = 0; x < 3; x++) // This nested for loop, as mentioned earlier is just for going through to each position of the board, in this case the temporary board
        {   
        makeTempBoard();
        for (int y = 0; y < 3; y++)
        {
            makeTempBoard();
            if (tempBoard[x][y] != 'X' && tempBoard[x][y] != 'O')
            {
                tempBoard[x][y] = 'X';
                if(checkWinner(tempBoard) == 'X') // For checking if placing an O in position (x, y) results in X winning, if it does, then the folloing code assignes that position to 'position'
                {
                    position = 'a' + (x * 3) + y; // Formula for assigning the correct position based on x and y (in terms of ASCII)
                    return position; // Returning the assigned position 
                }
                
            }
        }
        
        }

        for (int x = 0; x < 3; x++)
    {   
        makeTempBoard();
        for (int y = 0; y < 3; y++)
        {
            makeTempBoard();
            if (tempBoard[x][y] != 'X' && tempBoard[x][y] != 'O')
            {
                tempBoard[x][y] = 'O';
                if(checkWinner(tempBoard) == 'O') // For checking if placing an O in position (x, y) results in O winning, if it does then it blocks the move by placing an 'X' there
                {
                    tempBoard[x][y] = 'X';
                    position = 'a' + (x * 3) + y;
                    return position;
                }
                
            }
        }
        
    }
        if (checkWinner(tempBoard) == 0) // If none of the above cases happen then it just falls back to a random move.
        {
            position = (rand() % (105 - 97 + 1)) + 97;
            return position;
        }
    } 
    return 0;
}

// For making a 'temporary board' for Smart AI, it just copies the actual 'board'
void makeTempBoard ()
{
    for (int x = 0; x < 3; x++)
    {   
        for (int y = 0; y < 3; y++)
        {
            tempBoard[x][y] = board[x][y];
        }
        
    }
}

// Function for Smart AI vs Samrt AI mode
int smartVSsmart()
{
    char position;
    
    COMPUTER_Random1 = 'p';
    COMPUTER_Random2 = 'q';
    COMPUTER_Smart1 = 'O';
    COMPUTER_Smart2 = 'X';
    cleanBoard();
    int x = (rand() % (2 - 1 + 1)) + 1; // Setting up a random variable to switch which player starts the game first

    // While loop to continuously alternate turns until a there's a winner or it's a draw
    while(checkWinner(board) != 'X' || checkWinner(board) != 'O')
    {
        if (checkForFreeSpaces() == 0) // To check for draw and increment draw counter.
        {
            drawsCounter++;
            printBoard();
            printf("*********** It's a draw *************\n");
            return 0;
            break;
        }
        if (checkWinner(board) =='O') // To check for wins and increment win counter of the corresponding player.
        {
            winsCounterCompO++;
            printBoard();
            printf("*********** O wins *************\n");
            return 0;
        }
        do
        {
            if (x == 1)
            {
                position = smartAIalgorithm('O');
            }
            else
            {
                break;
            }
        } while (placeLetter(position, COMPUTER_Smart1) != 1); // Keeps on looping player 1's turn until he performs a legal/valid move, because then the place letter function a 1 and hence the loop exits.
        
        if(x == 1) // To prevent double printing of the board when the code is executed and the random variable x results in player 2's turn first 
        {
            printBoard();
        }
        x = 2;
        if (checkWinner(board) == 'O')
        {
            winsCounterCompO++;
            printBoard();
            printf("*********** O wins *************\n");
            return 0;
        }


        if (checkForFreeSpaces() == 0)
        {
            drawsCounter++;
            printBoard();
            printf("*********** It's a draw *************\n");
            return 0;
            break;
        }
        if (checkWinner(board) == 'X')
        {
            winsCounterCompX++;
            printBoard();
            printf("*********** X wins *************\n");
            return 0;
        }
        do
        {
            if (x == 2)
            {
                position = smartAIalgorithm('X');
            }
            else
            {
                break;
            }
        } while (placeLetter(position, COMPUTER_Smart2) != 1);
        if(x == 2)
        {
            printBoard();
        }
        x = 1;
        if (checkWinner(board) == 'X')
        {
            winsCounterCompX++;
            printBoard();
            printf("*********** X wins *************\n");
            return 0;
        }
        
        
    }
    return 0; // To return to the main function once a match ends.
}

// Function for Smart AI vs Random AI mode
// Code inside is almost the same as the first mode and hence hasn't been commented
int smartVSrandom()
{
    char position;
    
    COMPUTER_Random1 = 'X';
    COMPUTER_Random2 = 'p';
    COMPUTER_Smart1 = 'O';
    COMPUTER_Smart2 = 'q';
    cleanBoard();
    int x = (rand() % (2 - 1 + 1)) + 1;

    while(checkWinner(board) != 'X' || checkWinner(board) != 'O')
    {
        if (checkForFreeSpaces() == 0)
        {
            drawsCounter++;
            printBoard();
            printf("*********** It's a draw *************\n");
            return 0;
            break;
        }
        if (checkWinner(board) =='O')
        {
            winsCounterCompO++;
            printBoard();
            printf("*********** O wins *************\n");
            return 0;
        }
        do
        {
            if (x == 1)
            {
                position = smartAIalgorithm('O');
            }
            else
            {
                break;
            }
        } while (placeLetter(position, COMPUTER_Smart1) != 1);
        if(x == 1)
        {
            printBoard();
        }
        x = 2;
        if (checkWinner(board) == 'O')
        {
            winsCounterCompO++;
            printBoard();
            printf("*********** O wins *************\n");
            return 0;
        }


        if (checkForFreeSpaces() == 0)
        {
            drawsCounter++;
            printBoard();
            printf("*********** It's a draw *************\n");
            return 0;
            break;
        }
        if (checkWinner(board) == 'X')
        {
            winsCounterCompX++;
            printBoard();
            printf("*********** X wins *************\n");
            return 0;
        }
        do
        {
            if (x == 2)
            {
                position = (rand() % (105 - 97 + 1)) + 97; // For generating a random letter from 'a' to 'i' which is then assignes to the variable 'position'
            }
            else
            {
                break;
            }
        } while (placeLetter(position, COMPUTER_Random1) != 1);
        if(x == 2)
        {
            printBoard();
        }
        x = 1;
        if (checkWinner(board) == 'X')
        {
            winsCounterCompX++;
            printBoard();
            printf("*********** X wins *************\n");
            return 0;
        }
        
        
    }
    return 0;
}

// Function for Random AI vs Random AI
// Code inside is almost the same as the first mode and hence hasn't been commented
int randomVSrandom()
{
    char position;
    
    COMPUTER_Random1 = 'O';
    COMPUTER_Random2 = 'X';
    COMPUTER_Smart1 = 'p';
    COMPUTER_Smart2 = 'q';
    cleanBoard();
    int x = (rand() % (2 - 1 + 1)) + 1;

    while(checkWinner(board) != 'X' || checkWinner(board) != 'O')
    {
        if (checkForFreeSpaces() == 0)
        {
            drawsCounter++;
            printBoard();
            printf("*********** It's a draw *************\n");
            return 0;
            break;
        }
        if (checkWinner(board) =='O')
        {
            winsCounterCompO++;
            printBoard();
            printf("*********** O wins *************\n");
            return 0;
        }
        do
        {
            if (x == 1)
            {
                position = (rand() % (105 - 97 + 1)) + 97;
            }
            else
            {
                break;
            }
        } while (placeLetter(position, COMPUTER_Random1) != 1);
        if(x == 1)
        {
            printBoard();
        }
        x = 2;
        if (checkWinner(board) == 'O')
        {
            winsCounterCompO++;
            printBoard();
            printf("*********** O wins *************\n");
            return 0;
        }


      if (checkForFreeSpaces() == 0)
        {
            drawsCounter++;
            printBoard();
            printf("*********** It's a draw *************\n");
            return 0;
            break;
        }
        if (checkWinner(board) == 'X')
        {
            winsCounterCompX++;
            printBoard();
            printf("*********** X wins *************\n");
            return 0;
        }
        do
        {
            if (x == 2)
            {
                position = (rand() % (105 - 97 + 1)) + 97;
            }
            else
            {
                break;
            }
        } while (placeLetter(position, COMPUTER_Random2) != 1);
        if(x == 2)
        {
            printBoard();
        }
        x = 1;
        if (checkWinner(board) == 'X')
        {
            winsCounterCompX++;
            printBoard();
            printf("*********** X wins *************\n");
            return 0;
        }
        
        
    }
    return 0;
}


/* This marks the end of the program */
