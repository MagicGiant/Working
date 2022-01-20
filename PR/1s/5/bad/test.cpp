#include <iostream>
using namespace std;
void f(int &a)
{
    a=1;
}
int main()
{
    int *a;
    *a=10;
    f(*a);
    cout << *a;
    return 0;
}