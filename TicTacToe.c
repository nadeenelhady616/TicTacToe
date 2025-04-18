#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>
char board[3][3];
const char PLAYER = 'X';
const char PLAYER2 = 'O';
const char COMPUTER = 'O';

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void playertwo();
void computerMove();
char checkWinner();
void printWinner(char);
void PrintWinner2(char);

int main()
{
   char winner = ' ';
   char response = ' ';
   char Y, y;
   do
   {
      winner = ' ';
      response = ' ';
      resetBoard();
      system ("Color F0");
      int m;
      printf("Welcome to tic tac toe game!! ");
      printf("Choose playing option: \n");
      printf(" 1-ONE PLAYER\n");
      printf(" 2-TWO PLAYER \n");
      scanf("%d", &m);
      if(m == 1){
         while(winner == ' ' && checkFreeSpaces() != 0)
         {
            printBoard();
            playerMove();
            winner = checkWinner();
            if(winner != ' ' || checkFreeSpaces() == 0)
            {
               break;
            }
            computerMove();
            winner = checkWinner();
            if(winner != ' ' || checkFreeSpaces() == 0)
            {
               break;
            }
         }
      printBoard();
      printWinner(winner);
}
      else{
          while(winner == ' ' && checkFreeSpaces() != 0)
         {
            printBoard();
            playerMove();
            printBoard();
            winner = checkWinner();
            if(winner != ' ' || checkFreeSpaces() == 0)
            {
               break;
            }
            playertwo();
            winner = checkWinner();
            if(winner != ' ' || checkFreeSpaces() == 0)
            {
               break;
            }
         }
      printBoard();
      PrintWinner2(winner);
      }
      printf("\nWould you like to play again? (Y/N): \n");
      response = getch();
      response = toupper(response);
   } while (response == 'Y' || response == 'y');
   printf("Thanks for playing!\n");
   return 0;
}
void resetBoard()
{
   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         board[i][j] = ' ';
      }
   }
}
void printBoard()
{
   printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201 , 205, 205 , 205 , 203 , 205 , 205 , 205, 203 , 205 , 205, 205, 187);
   printf("%c %c %c %c %c %c %c", 186, board[0][0], 186, board[0][1],186, board[0][2],186);
   printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 204 , 205, 205 , 205 , 206 , 205 , 205 , 205, 206 , 205 , 205, 205, 185);
   printf("%c %c %c %c %c %c %c", 186, board[1][0],186, board[1][1],186, board[1][2],186);
   printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 204 , 205, 205 , 205 , 206 , 205 , 205 , 205, 206 , 205 , 205, 205, 185);
   printf("%c %c %c %c %c %c %c", 186 , board[2][0] , 186, board[2][1] , 186, board[2][2] ,186);
   printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200 , 205, 205 , 205 , 202 , 205 , 205 , 205, 202 , 205 , 205, 205, 188);
   printf("\n");
}
int checkFreeSpaces()
{
   int freeSpaces = 9;
   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         if(board[i][j] != ' ')
         {
            freeSpaces--;
         }
      }
   }
   return freeSpaces;
}
void playerMove()
{
   int x;
   int y;
   do
   {
      printf("PLAYER ONE'S TURN:\n");
      printf("Enter row #(1-3): ");
      scanf("%d", &x);
      x--;
      printf("Enter column #(1-3): ");
      scanf("%d", &y);
y--;
      if(board[x][y] != ' ')
      {
         printf("Invalid move!\n");
      }
      else
      {
         board[x][y] = PLAYER;
         break;
      }
   } while (board[x][y] != ' ');
}
void computerMove()
{
   srand(time(0));
   int x;
   int y;
   if(checkFreeSpaces() > 0)
   {
      do
      {
         x = rand() % 3;
         y = rand() % 3;
      } while (board[x][y] != ' ');
      board[x][y] = COMPUTER;
      printf("\nCOMPUTER CHOSE CELL (%d,%d)",x+1,y+1);
   }
   else
{
      printWinner(' ');
   }
}
void playertwo(){
   int x;
   int y;
   do
   {
      printf("PLAYER TWO'S TURN:\n");
      printf("Enter row from (1-3): \n");
      scanf("%d", &x);
      x--;
      printf("Enter column from (1-3): \n");
      scanf("%d", &y);
      y--;
      if(board[x][y] != ' ')
      {
         printf("Invalid move!\n");
      }
      else
      {
         board[x][y] = PLAYER2;
         break;
      }
   } while (board[x][y] != ' ');
}
char checkWinner()
{
   for(int i = 0; i < 3; i++)
   {
      if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
      {
         return board[i][0];
      }
   }
   for(int i = 0; i < 3; i++)
   {
      if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
      {
         return board[0][i];
      }
   }
   if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
   {
      return board[0][0];
   }
   if(board[0][2] == board[1][1] && board[0][2] == board[2][0])
   {
      return board[0][2];
   }
   return ' ';
}
void printWinner(char winner)
{
   if(winner == PLAYER)
   {
      system ("Color AF");
      printf("YOU WIN!\n\a");
   }
   else if(winner == COMPUTER)
   {
      system ("Color CF");
      printf("YOU LOSE! HAHAHAHAHA\n\a");
   }
   else{
   printf("IT'S A TIE!\n\a");
   }
}
void PrintWinner2(char winner)
{
   if(winner == PLAYER){
      system ("Color AF");
      printf("PLAYER ONE WINS!\n\a");
   }
   else if (winner == PLAYER2)
   {
      system ("Color AF");
      printf("PLAYER TWO WINS!\n\a");
   }
else{
      printf("IT'S A TIE\n\a");
   }
}