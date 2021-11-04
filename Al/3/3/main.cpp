#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int n, m, k;
bool ch=true;
ifstream fin ("radixsirt.in.txt");
ofstream fout("radixsort.in.txt");
struct struct_arr
{
    vector <char> data;
    struct_arr *prev;
    struct_arr *next;
};
void f()
{
    for (int i=0; i<n; i++)
    {
        struct_arr *arr = new struct_arr();
        fin >> arr.data[i];
        if (ch)
        {
        }
    }
}
int main()
{
    
    fin >> n;
    return 0;
}