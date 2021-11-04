#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
 int main()
{
    ifstream fin ("stack.in");
    ofstream fout ("stack.out");
    int n, j=0;
    fin >> n;
    vector <int> arr (n);
    char sing;
    for (int i=0; i<n; i++)
    {
        fin >> sing;
        if(sing == '+')
        {
            fin >> arr[j];
            j++;
        }
        else
        {
            j--;
            fout << arr[j] << endl;
        }
    }
    return 0;
}