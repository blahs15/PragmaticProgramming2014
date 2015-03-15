// Russell Miller
#include <iostream>
#include "bigboard.h"
#include "tinyboard.h"
using namespace std;


BigBoard::BigBoard( int height, int maxHeight )
{
  this->height = height;
  this->maxHeight = maxHeight;
  squares = new Board*[9];
  if( height > 1 )
    for( int i = 0; i < 9; i++ )
      squares[i] = new BigBoard( height - 1, maxHeight );
  else
    for( int i = 0; i < 9; i++ )
      squares[i] = new TinyBoard();
} // BigBoard() constructor
BigBoard::~BigBoard()
{
  for( int i = 0; i < 9; i++ )
    delete squares[i];
  delete [] squares;
} // ~BigBoard() deconstructor


void BigBoard::setCanMove( bool canMove )
{
  for( int i = 0; i < 9; i++ )
    squares[i]->setCanMove( canMove );
} // setCanMove()


void BigBoard::checkForWin( char check )
{
  for( int i = 0; i < 9; i++ )
    squares[i]->checkForWin( check );

  bool win = false;
  for( int i = 0; i < 3; i++) 
  {
    if( squares[i*3]->getWinner() == check && squares[i*3 + 1]->getWinner() == check && squares[i*3 + 2]->getWinner() == check )
      win = true; // rows
    if( squares[i]->getWinner() == check && squares[i+3]->getWinner() == check && squares[i+6]->getWinner() == check )
      win = true; // cols
  } // for rows || cols

  // diagonals
  if( squares[0]->getWinner() == check && squares[4]->getWinner() == check && squares[8]->getWinner() == check )
    win = true;
  if( squares[2]->getWinner() == check && squares[4]->getWinner() == check && squares[6]->getWinner() == check )
    win = true;

  if( win )
  {
    winner = check;
    isDone = true;
  } // if
  else
    checkFull();
} // checkForWin()

void BigBoard::clearLoser( char winner )
{
  for( int i = 0; i < 9; i++ )
    squares[i]->clearLoser( winner );
} // clearLoser()

void BigBoard::checkFull()
{
  for( int i = 0; i < 9; i++ )
    if( !squares[i]->getIsDone() )
      return;
  isDone = true;
} // checkFull()


int BigBoard::makeMove( bool turn, int layerPos[], bool *hasMoved )
{
  if( layerPos[height] < 0 )
  { // choose square
    int move = this->getSquare( turn );
    while( squares[move - 1]->getIsDone() )
    {
      cout << "invalid move, try again: " << endl;
      move = this->getSquare( turn );
    } // while()
    for( int i = 0; i < 9; i++ )
      squares[i]->setCanMove( false );
    squares[move - 1]->setCanMove( true );
    layerPos[height] = move - 1;

    setCanMove( false );
    for( int i = 0; i < 9; i++ )
      if( i == layerPos[height] )
        squares[i]->setCanMove( true );
  } // if square not decided
  else 
  { // square already chosen
    int temp = squares[ layerPos[height] ]->
      makeMove( turn, layerPos, hasMoved );
    if( squares[ layerPos[height] ]->getWinner() != ' ' )
      squares[ layerPos[height] ]->clearLoser(
        squares[ layerPos[height] ]->getWinner() );
    layerPos[height] = temp;
    if( squares[ layerPos[height] ]->getIsDone() )
      layerPos[height] = -1;

    setCanMove( false );
    // bug: will return and canMove will be set from top Layer only
    // maybe check if prev moveSpot == new moveSpot??
    for( int i = 0; i < 9; i++ )
      if( i == layerPos[height] || layerPos[height] == -1 )
        squares[i]->setCanMove( true );
  } // else

  checkForWin( turn ? 'O' : 'X' );
  if( getIsDone() )
    return layerPos[height];
  else if( height != maxHeight )
    return layerPos[height + 1];
  return -1; // it is the topBoard, and this number isn't used
} // makeMove()


void BigBoard::print()
{
  int maxCount = 9; // total number of chars
  for( int i = 0; i < maxHeight; i++ )
    maxCount *= 9;
  char* screen = new char[maxCount]; // all the chars
  int* charRows = new int[maxCount]; // what row each char is in
  int count = 0; // index variable for screen
  getScreen( screen, charRows, &count, 1 );

  int totalRows = 1; // number of rows to be printed
  for( int i = 0; i < maxHeight + 1; i++ )
    totalRows *= 3;

  for( int i = 0; i < totalRows; i++ )
  {

    // prints all "--------" dividing rows
    int modRow = 1;
    for( int k = 0; k < maxHeight; k++ )
    {
      modRow *= 3;
      if( i % modRow == 0 && i != 0)
      {
        for( int j = 0; j < totalRows; j++ )
        {
          int modCol = 1;
          for( int l = 0; l < maxHeight; l++ )
          {
            modCol *= 3;
            if( j % modCol == 0 && j != 0 )
            {
              cout << '|';
            } // if
          } // for printing each '|' char
          cout << '~';
        } // for print each '-' char
        cout << endl;
      } // if print "---" line
    } // for divider lines

    // prints characters with '|' dividers
    int printedCount = 0;
    for( count = 0; count < maxCount; count++ )
      if( charRows[count] == i + 1 )
      {
        int mod = 1;
        for( int k = 0; k < maxHeight; k++ )
        {
          mod *= 3;
          if( printedCount % mod == 0 && printedCount != 0)
            cout << '|';
        } // for divider lines
        cout << screen[count];
        printedCount++;
      } // if
    cout << endl;

  } // for each line

} // print()


void BigBoard::getScreen( char* screen, int* charRows, 
  int* index, int rowNum )
{
  int multiplier = 1;
  for( int i = 0; i < height; i++ )
    multiplier *= 3;
  for( int i = 0; i < 9; i++ )
    squares[i]->getScreen( screen, charRows, index,
        (i/3)*multiplier + rowNum );
} // getScreen()