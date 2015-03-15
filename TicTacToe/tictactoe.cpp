// Russell Miller
#include <iostream>
// #include <string>
#include "tictactoe.h"
#include "board.h"
#include "tinyboard.h"
#include "bigboard.h"
using namespace std;


int main()
{
  int choice = 0;
  do
  {
    cout << "Tic-Tac-Toe Game Main Menu:" << endl
        << "0 : Quit" << endl
        << "1 : Rules - not implemented yet" << endl
        << "2 : 1 Layer game (normal game)" << endl
        << "3 : 2 Layer game" << endl
        << "4 : Choose # of Layers" << endl
        << "choice: ";
    cin >> choice;
    switch( choice )
    {
      case 1: // print rules
        break;
      case 2:
        oneLayerGame();
        break;
      case 3:
        multiLayerGame( 2 );
        break;
      case 4:
        chooseLayers();
        // multiLayerGame( 3 ); // needs to be user chosen
        break;
    } // switch
    cout << endl;
  } while( choice );
} // main()

void oneLayerGame()
{
  bool turn = false; // false = 'X', true = 'O'
  bool hasMoved; // not used in oneLayerGame()
  TinyBoard *tiny = new TinyBoard();
  tiny->print();
  while( !tiny->getIsDone() )
  {
    tiny->makeMove( turn, NULL, &hasMoved ); // 2nd turn is just extra
    tiny->print();
    turn = !turn;
  } // while
  if( tiny->getWinner() != ' ' )
    cout << "Winner is " << tiny->getWinner() << "!" << endl;
  else
    cout << "Cat's game!" << endl;

  delete tiny;
} // oneLayerGame()


void multiLayerGame( int layerNum )
{
  bool turn = false;
  bool hasMoved = false;
  int layerPos[layerNum];
  for( int i = 0; i < layerNum; i++ )
    layerPos[i] = -1;
  layerNum--;
  Board *game = new BigBoard( layerNum, layerNum );

  game->print();
  while( !game->getIsDone() )
  {
    game->makeMove( turn, layerPos, &hasMoved ); // 2nd turn is just extra
    if( layerPos[layerNum] == -1 )
      game->setCanMove( true );
    game->print();
    if( hasMoved )
      turn = !turn;
    hasMoved = false;
  } // while
  if( game->getWinner() != ' ' )
    cout << "Winner is " << game->getWinner() << "!" << endl;
  else
    cout << "Cat's game!" << endl;

  delete game;
} // multiLayerGame()


void chooseLayers()
{
  int choice = 0;
  do
  {
    cout << endl;
    cout << "0 : Return to Main Menu" << endl
        << "1 : Rules" << endl
        << "Choose number of layers to play with [>1]: ";
    cin >> choice;
    if( choice > 1 )
      multiLayerGame( choice );
    // else if( choice == 1 )
      // rules
  } while( choice > 0);

} // chooseLayers