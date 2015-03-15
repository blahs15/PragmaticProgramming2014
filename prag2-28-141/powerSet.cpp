// Russell Miller
// write a method to return all subsets of a set (Power Set)
// recursive? iterative?

#include <iostream>
using namespace std;

char** getPowerSet( char* startingSet, int setSize );
char** getPowerSet2( char* startingSet, int setSize );


int main()
{
  char* set = new char[4];
  char** powerSet;
  int setSize = 4;
  for( int i = 0; i < setSize; i++ )
    set[i] = 'a' + i;
  // powerSet = getPowerSet( set, setSize );
  powerSet = getPowerSet2( set, setSize );

  int psSize = 1;
  for( int i = 0; i < setSize; i++ )
    psSize *= 2;
  for( int i = 0; i < psSize; i++ )
  {
    cout << i+1 << ": " << powerSet[i] << endl;
  } // for
} // main()

char** getPowerSet( char* startingSet, int setSize )
{ // not working currently
  int backTrackNum; // uhhhh
  int psSize = 1;
  for( int i = 0; i < setSize; i++ )
    psSize *= 2;
  char** powerSet = new char*[psSize];
  for( int subsetI = 0; subsetI < psSize; subsetI++ )
  {
    for( int curSize = 0; curSize < setSize; curSize++ )
    {
      powerSet[subsetI] = new char[curSize + 1];
      for( int i = 0; i < curSize; i++ )
      {

      } // for each element in subset
    } // for subsetSize
  } // for all subsets
  return powerSet;
} // getPowerSet()


char** getPowerSet2( char* startingSet, int setSize )
{ // uses bitmasks
  // returns PS with \0 at end of each subset
  int psSize = 1;
  for( int i = 0; i < setSize; i++ )
    psSize *= 2;
  char** powerSet = new char*[psSize];
  for( int counter = 0; counter < psSize; counter++ )
  {
    int subsetSize = 0;
    for( int i = 1; i <= counter; i *= 2 )
    { // determine subset size
      if( (i & counter) > 0 )
        subsetSize++;
    } // for each bit
    powerSet[counter] = new char[subsetSize + 1]; // creat subset

    int psIndex = 0, setIndex = 0;
    for( int i = 1; i <= counter; i *= 2 )
    { // copy elements to subset
      if( (i & counter) > 0 )
      {
        powerSet[counter][psIndex] = startingSet[setIndex];
        psIndex++;
      } // if bit is 1
      setIndex++;
      powerSet[counter][psIndex] = '\0';
    } // for each bit, add to subset
  } // for all subsets
  return powerSet;
} // getPowerSet2()