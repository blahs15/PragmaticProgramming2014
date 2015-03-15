// Russell Miller
#include <iostream>
#include "tinyboard.h"
using namespace std;

TinyBoard::TinyBoard()
{
  for( int i = 0; i < 9; i++ )
    squares[i] = ' ';
} // TinyBoard() constructor

void TinyBoard::setCanMove( bool canMove )
{
  this->canMove = canMove;
} // setCanMove()


void TinyBoard::checkForWin( char check ) // check is 'X' or 'O'
{
  bool win = false;
  for( int i = 0; i < 3; i++) 
  {
    if( squares[i*3] == check && squares[i*3 + 1] == check && squares[i*3 + 2] == check )
      win = true; // rows
    if( squares[i] == check && squares[i+3] == check && squares[i+6] == check )
      win = true; // cols
  } // for rows || cols

  // diagonals
  if( squares[0] == check && squares[4] == check && squares[8] == check )
    win = true;
  if( squares[2] == check && squares[4] == check && squares[6] == check )
    win = true;

  if( win )
  {
    winner = check;
    isDone = true;
  } // if
  else
    checkFull();
} // checkForWin()

void TinyBoard::clearLoser( char winner )
{
  for( int i = 0; i < 9; i++ )
    squares[i] = winner;
} // clearLoser()

void TinyBoard::checkFull()
{ // checks if all squares are filled
  for( int i = 0; i < 9; i++ )
    if( squares[i] == ' ' )
      return;
  isDone = true;
} // checkFull()


int TinyBoard::makeMove( bool turn, int layerPos[], bool *hasMoved )
{ // layerPos can be NULL
  int move = this->getSquare( turn );
  while( squares[move - 1] != ' ' )
  {
    cout << "invalid move, try again: ";
    move = this->getSquare( turn );
  } // while()
  squares[move - 1] = turn ? 'O' : 'X';

  checkForWin( turn ? 'O' : 'X' );
  *hasMoved = true;
  return move - 1;
} // getMove()


void TinyBoard::print()
{ // only used in 1 layer game -- special print method
  cout << "---------" << endl;
  for( int i = 0; i < 3; i++ )
  {
    cout << "  ";
    for( int k = 0; k < 3; k++ )
      if( squares[i*3 + k] == ' ' )
        cout << ". ";
      else
        cout << squares[i*3 + k] << ' ';
    cout << endl;
  } // for rows
  cout << "---------" << endl;
} // print1Layer()


void TinyBoard::getScreen( char* screen, int* charRows, 
    int* index, int rowNum )
{
  for( int i = 0; i < 9; i++ )
  {
    if( squares[i] == ' ' && canMove )
      screen[*index] = '.';
    else
      screen[*index] = squares[i];
    charRows[*index] = rowNum + (i / 3);
    (*index)++;
  } // for
} // getScreen()