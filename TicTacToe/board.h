// Russell Miller
#ifndef BOARD_H
#define BOARD_H

class Board
{
private:
  virtual void checkFull() =0;
protected:
  bool isDone;
  char winner;
  bool canMove;
  int getSquare( bool turn ); // returns [1-9]
public:
  Board();
  virtual ~Board() {}
  bool getIsDone();
  char getWinner();
  virtual void setCanMove( bool canMove ) =0;

  virtual void checkForWin( char check ) =0;
  virtual void clearLoser( char winner ) =0;
  virtual int makeMove( bool turn, int layerPos[], bool *hasMoved ) =0;
  virtual void print() =0;
  virtual void getScreen( char* screen, int* charRows, 
    int* index, int rowNum ) =0;
}; // class Board

#endif