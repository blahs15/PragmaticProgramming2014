// Russell Miller
#include <iostream>
#include <string>

int main()
{
  std::string s, s2;
  char prev, current;
  int charcount = 1;
  std::cin >> s;
  prev = s[0];
  s2 = s[0];
  for( int i = 1; i < s.length(); i++ )
  {
    current = s[i];
    if( prev == current )
    {
      charcount++;
    } // if
    else
    {
      s2 += std::to_string(charcount);
      s2 += s[i];
    } // else
    prev = current;
  } // for

  s2 += std::to_string(charcount);

  std::cout << s2 << std::endl;
} // main()