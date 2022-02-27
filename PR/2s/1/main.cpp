#include <iostream>
#include "closed_broken_line.h"
int main()
{
    std::vector <dot> arr(4);
    arr[0].set_O(0, 0);
    arr[1].set_O(1, 0);
    arr[2].set_O(1, 1);
    arr[3].set_O(0, 1);
    broken_line line (arr);
    std::cout << line.length();
    return 0;
}