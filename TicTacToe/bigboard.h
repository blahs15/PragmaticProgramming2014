// Russell Miller
#ifndef BIGBOARD_H
#define BIGBOARD_H
#include "board.h"

class BigBoard : public Board
{
private:
  Board **squares;
  int height;
  int maxHeight;
  void checkFull();
public:
  BigBoard( int height, int maxHeight );
  ~BigBoard();
  void setCanMove( bool canMove );

  void checkForWin( char check );
  void clearLoser( char winner );
  int makeMove( bool turn, int layerPos[], bool *hasMoved );
  void print();
  void getScreen( char* screen, int* charRows, 
    int* index, int rowNum );
}; // class BigBoard

#endif