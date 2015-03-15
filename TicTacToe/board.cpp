// Russell Miller
#include <iostream>
#include "board.h"
using namespace std;

Board::Board()
{
  winner = ' ';
  isDone = false;
  canMove = true;
} // Board constructor

bool Board::getIsDone()
{ return isDone; }
char Board::getWinner()
{ return winner; }

// void Board::setCanMove( bool canMove )
// {
//   this->canMove = canMove;
// } // setCanMove()

int Board::getSquare( bool turn ) // returns [1-9]
{
  int move;
  for( int i = 0; i < 30; i++ )
    cout << (turn ? 'O' : 'X');
  cout << endl;
  cout << "Player " << (turn ? 'O' : 'X') << ", pick a square [1-9]: ";
  cin >> move;
  while( move < 1 || move > 9 )
  {
    cout << "invalid move, try again: ";
    cin >> move;
  } // while()
  return move;
} // getSquare()

