// Russell Miller
#include <iostream>

int main()
{
  int num1, num2, temp1, count;
  std::cout << "input num1: ";
  std::cin >> num1;
  std::cout << "input num2: ";
  std::cin >> num2;

  temp1 = num1 ^ num2;
  for( int i = 0; i < sizeof(int) * 8; i++ )
  {
    int temp2 = temp1 % 2;
    count += temp2;
    temp1 >>= 1;
  } // for

  std::cout << "count: " << count << std::endl;
} // main()