// Russell Miller
// #15 from projecteuler.net
#include <iostream>

using namespace std;

void move( int *count, int maxRow, int maxCol, int row, int col );


int main()
{
  int num1, num2, count = 0;
  cout << "input 2 numbers" << endl
    << "first number: ";
  cin >> num1;
  cout << "second number: ";
  cin >> num2;

  move( &count, num1, num2, 0, 0 );

  cout << "There are " << count << " possible routes." << endl;
  //cout << num1 << "x" << num2 << " board" << endl;
} // main()


void move( int *count, int maxRow, int maxCol, int row, int col )
{
  if( row < maxRow ) // go down
    move( count, maxRow, maxCol, row + 1, col );
  if( col < maxCol ) // go right
    move( count, maxRow, maxCol, row, col + 1 );
  if( col == maxCol && row == maxRow )
    (*count)++;
  return;
} // move()