// Including libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Assigning global variables
char board[3][3];
char COMPUTER = 'O', PLAYER_1 = 'X', PLAYER_2 = 'O';
int selection1;
char tempBoard[3][3];

// Declaring functions which are defined down below in the program
void printBoard();
void cleanBoard();
void welcome();
void repeatGame();
void makeTempBoard ();

int placeLetter(char position, char player);
int checkForFreeSpaces();
int selectionType();
int PlayerVsPlayer();
int checkWinner();
int computerRandom();
int smartAIalgorithm();
int playerVsmartAI();

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
        case 1: printf("\n\nPlayer 1 is X and Player 2 is O\n");
                printBoard();
                PlayerVsPlayer();
            break;
        case 2: printf("\n\nYou are X and the computer is O\n");
                printBoard();
                playerVsmartAI(); 
            break;         
        case 3: printf("\n\nYou are X and the computer is O\n");
                printBoard();
                computerRandom();
            break;
            
    
   
    }
    // Asking if user wants to paly again.
    printf("\n\nWould you like to play again? (y, n)\n");
    repeatGame();
    return 0;
    

    
   
}


// Printing welcome screen
void welcome()
{
    printf("**********************************************");
    printf("\nHi!\n");
    printf("Welcome to Tic-Tac-Toe!\n");
    printf("Please select one of these options (1, 2, 3)\n");
    printf("**********************************************\n");
    printf("1) Player vs Player\n");
    printf("2) Player vs Computer (Smart AI)\n");
    printf("3) Player vs Computer (Random Moves)\n");
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
                if (player != COMPUTER) // This 'if else' statement is there so that if the computer does an illegal move then the game does not print the error, it just returns 0 without printing
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
                if (player != COMPUTER)
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
                if (player != COMPUTER)
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
                if (player != COMPUTER)
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
                if (player != COMPUTER)
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
                if (player != COMPUTER)
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
                if (player != COMPUTER)
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
                if (player != COMPUTER)
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
                if (player != COMPUTER)
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
int smartAIalgorithm()
{
    makeTempBoard();
    char position;

    for (int x = 0; x < 3; x++) // This nested for loop, as mentioned earlier is just for going through to each position of the board, in this case the temporary board
    {   
        makeTempBoard();
        for (int y = 0; y < 3; y++)
        {
            makeTempBoard();
            if (tempBoard[x][y] != 'X' && tempBoard[x][y] != 'O')
            {
                tempBoard[x][y] = 'O';
                if(checkWinner(tempBoard) == 'O') // For checking if placing an O in position (x, y) results in the computer winning, if it does, then the folloing code assignes that position to 'position'
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
                if(checkWinner(tempBoard) == 'X') // For checking if placing an X in position (x, y) results the player winning, if it does then it blocks the move by placing an 'O' there
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

// Game mode 1 (Player vs Player)
int PlayerVsPlayer()
{
    char position;
    int draw;
    COMPUTER = 'p';
    PLAYER_2 = 'O';
    int x = (rand() % (2 - 1 + 1)) + 1; // Setting up a random variable to switch which player starts the game first

    // While loop to continuously alternate turns until a there's a winner or it's a draw
    while (checkWinner(board) != 'X' || checkWinner(board) != 'O' && checkForFreeSpaces > 0) 
    {
        // do while loop for player 1's turn
        do
        {
            if(checkForFreeSpaces() == 0)
            {
                printf("It's a draw!\n");
                draw = 1;
                break;
            }

            if(x == 1)
            {
                
                printf("\nPlayer 1's (X) turn. Please choose position by typing an alphabet\n");
                scanf(" %c", &position);
                
            }
            else
            {
                break;
            }
        } while ((placeLetter(position, PLAYER_1) != 1)); // Keeps on looping player 1's turn until he performs a legal/valid move, because then the place letter function a 1 and hence the loop exits.
        
        if (x == 1) // To prevent double printing of the board when the code is executed and the random variable x results in player 2's turn first
        {
            printBoard();
        }
        x = 2;
        if(draw == 1)
        {
            return 0;
        }
        if(checkWinner(board) == 'X')
        {
            printBoard();
            printf ("Playe X wins!\n");
            break;
        }

        // do while loop for player 2's turn
        do
        {
            if(checkForFreeSpaces() == 0)
            {   
                printf("It's a draw!\n");
                draw = 1;
                break;
            }       
            if(x == 2)
            {
                printf("\nPlayer 2's (O) turn. Please choose position by typing an alphabet\n");
                scanf(" %c", &position);     
            }
            else
            {
                break;
            }
            
        } while ((placeLetter(position, PLAYER_2) != 1));

        x = 1;
        if(draw == 1)
        {
            return 0;
        }
        printBoard();
        if(checkWinner(board) == 'O')
        {
            printBoard();
            printf ("Player O wins!\n");
            break;
        }

        
    }
    
    return 0; // To return to the main function once a match ends
}

// Game mode 2 (Player vs Computer Smart AI)
// Code inside is almost the same as the first game mode and hence hasn't been commented
int playerVsmartAI()
{
    char position;
    int draw;
    PLAYER_2 = 'p';
    COMPUTER = 'O';
    int x = (rand() % (2 - 1 + 1)) + 1;

    while (checkWinner(board) != 'X' || checkWinner(board) != 'O' && checkForFreeSpaces() > 0)
    {
        do
        {
            if(checkForFreeSpaces() == 0)
            {
                printf("It's a draw!\n");
                draw = 1;
                break;
            }
            if(x == 1)
            {
                printf("\n Your (X) turn. Please choose position by typing an alphabet\n");
                scanf(" %c", &position);
            }
            else
            {
                break;
            }
                
            
            
            
        } while ((placeLetter(position, PLAYER_1) != 1));
        if (x == 1)
        {
            printBoard();
        }
        x = 2;
        if(draw == 1)
        {
            return 0;
        }


        
        
        if(checkWinner(board) == 'X')
        {
            printBoard();
            printf ("You Win!\n");
            break;
        }

        do
        {
            if(checkForFreeSpaces() == 0)
            {   
                printf("It's a draw!\n");
                draw = 1;
                break;
            }       
            
            if(x == 2)
            {
                position = smartAIalgorithm(); // For assigning the AI's choosen move to 'position'
                printf("\nComputer's turn\n");
            }
            else
            {
                break;
            }
        } while ((placeLetter(position, COMPUTER) != 1));
        
        x = 1;
        if(draw == 1)
        {
            return 0;
        }
        printBoard();
        printf("Computer choose position %c\n\n", position);
        if(checkWinner(board) == 'O')
        {
            printBoard();
            printf ("Computer wins!\n");
            break;
        }    
    }  
    return 0;
}

// Game mode 3 (Player vs Computer random moves) 
// Code inside is almost the same as the first game mode and hence hasn't been commented
int computerRandom()
{
    char position;
    int draw;
    PLAYER_2 = 'p';
    COMPUTER = 'O';
    int x = (rand() % (2 - 1 + 1)) + 1;

    while (checkWinner(board) != 'X' || checkWinner(board) != 'O' && checkForFreeSpaces() > 0)
    {
        do
        {
            if(checkForFreeSpaces() == 0)
            {
                printf("It's a draw!\n");
                draw = 1;
                break;
            }
            if(x == 1)
            {
                printf("\n Your (X) turn. Please choose position by typing an alphabet\n");
                scanf(" %c", &position);
            }
            else
            {
                break;
            }
        } while ((placeLetter(position, PLAYER_1) != 1));
        
        if (x == 1)
        {
            printBoard();
        }
        x = 2;
        if(draw == 1)
        {
            return 0;
        }
        if(checkWinner(board) == 'X')
        {
            printBoard();
            printf ("You Win!\n");
            break;
        }

        do
        {
            if(checkForFreeSpaces() == 0)
            {   
                printf("It's a draw!\n");
                draw = 1;
                break;
            }       
            
            if(x == 2)
            {
                position = (rand() % (105 - 97 + 1)) + 97; // For generating a random letter from 'a' to 'i' which is then assignes to the variable 'position'
            }                
            
            else
            {
                break;
            }  
        } while ((placeLetter(position, COMPUTER) != 1));

        printf("\nComputer's turn\n");
        x = 1;
        if(draw == 1)
        {
            return 0;
        }
        printBoard();
        printf("Computer choose position %c\n\n", position);
        if(checkWinner(board) == 'O')
        {
            printBoard();
            printf ("Computer wins!\n");
            break;
        }
    }
    return 0;
}

/* This marks the end of the program */