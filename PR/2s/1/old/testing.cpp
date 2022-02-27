#include <iostream>
#include <string>
#include <locale.h>
using namespace std;
class test
{
public:
int i=0;
int k=2;
};
int main()
{
    test arr[21];
    int size=sizeof(arr)/sizeof(*arr);
    cout<< size;
    return 0;
}