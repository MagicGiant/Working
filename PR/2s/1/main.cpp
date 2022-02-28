#include <iostream>
#include "figur.h"
int main()
{
    std::vector <dot> arr(5);
    arr[0].set_O(0, 0);
    arr[1].set_O(0, 3); 
    arr[2].set_O(2, 3);
    arr[3].set_O(2, 0);
    arr[4].set_O(0, 0);
    trapezoid line (arr);
    std::cout << line.square();
    return 0;
}