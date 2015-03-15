// Russell Miller
#ifndef TINYBOARD_H
#define TINYBOARD_H
#include "board.h"

class TinyBoard : public Board
{
private:
  char squares[9];
  void checkFull();
public:
  TinyBoard();
  void setCanMove( bool canMove );

  void checkForWin( char check );
  void clearLoser( char winner );
  int makeMove( bool turn, int layerPos[], bool *hasMoved );
  void print();
  void getScreen( char* screen, int* charRows, 
    int* index, int rowNum );
}; // class TinyBoard

#endif