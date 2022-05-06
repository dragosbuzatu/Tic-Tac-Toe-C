#include <stdio.h>

void printTurn(int turn)
{
  if(turn == 1) //prints whos turn it is
  {
    printf("Player %d turn 'X'\n", turn);
  }
  else if(turn == 2)
  {
    printf("Player %d turn 'O'\n", turn);
  }
}

void printboard(int turn, char board[3][3]) //prints current board
{
  for(int r = 0; r < 3; r++) //prints board
  {
    for(int c = 0; c < 3; c++)
    {
      printf("%c", board[r][c]);
      if(c != 2)
      {
        printf("|");
      }
    }
    printf("\n");
    if(r != 2)
    {
      for(int c = 0; c < 5; c++)
      {
        printf("-");
      }
      printf("\n");
    }
  }
}

char playerMove(int row, int col, int turn, char board[3][3])
{
  do
  {
    printf("Which row would you like?\n"); //input from player
    scanf("%d", &row);
    printf("Which column would you like?\n");
    scanf("%d", &col);

    if(board[row][col] != ' ') //if space not empty
    {
      printf("Illegal Move\n");
    }
  } while(board[row][col] != ' '); //while board has empty spaces

  if(turn == 1) //fill in with right character
  {
    board[row][col] = 'X';
  }
  else if(turn == 2)
  {
    board[row][col] = 'O';
  }
}


int winGame(char board[3][3]) //checks for wins or cats game
{
  for(int r = 0; r < 3; r++)
  {
    if(board[r][0] != ' ' && board[r][0] == board[r][1] && board[r][0] == board[r][2]) //row win
    {
      return 1;
    }
  }

  for(int c = 0; c < 3; c++)
  {
    if(board[0][c] != ' ' && board[0][c] == board[1][c] && board[0][c] == board[2][c]) //col win
    {
      return 1;
    }
  }

  if(board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2]) //diagonal win
  {
    return 1;
  }

  if(board[0][2] != ' ' && board[0][2] == board[1][1] && board[0][2] == board[2][0]) // got the reverse diagonal
  {
    return 1;
  }

  return 0;
}

int nextTurn(int turn) //gives turn to next player
{
  if(turn == 1)
  {
    turn = 2;
  }
  else if(turn == 2)
  {
    turn = 1;
  }
  return turn;
}

int main()
{
  int turn = 1; //sets tp player one
  int numOfMoves = 0;
  int row, col;
  char board[3][3] = {{' ', ' ', ' '},{' ', ' ', ' '}, {' ', ' ', ' '}}; //make empty board

  printf("Welcome to Tic-Tac-Toe\n");
  printf("======================\n");
  printTurn(turn);
  printboard(turn, board);

  while(winGame(board) != 1)
  {
    playerMove(row, col, turn, board);
    numOfMoves++;
    winGame(board);
    if(numOfMoves == 9) //checks for cats game
    {
      printf("Cat's Game!\n");
      printboard(turn, board);
      break;
    }
    turn = nextTurn(turn);
    printTurn(turn);
    printboard(turn, board);
  }

  if(winGame(board) == 1) //if win
  {
    turn = nextTurn(turn);
    if(turn == 1)
    {
      printf("X Player Wins!\n");
      printboard(turn, board);
    }
    else if(turn == 2)
    {
      printf("O Player Wins!\n");
      printboard(turn, board);
    }
  }
  else if(winGame(board) == 0) //if other
  {
    return 0;
  }

  return 0;
}