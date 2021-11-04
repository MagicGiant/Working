#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
 int main()
{
    ifstream fin ("queue.in");
    ofstream fout ("queue.out");
    int n, j=0, i=0;
    fin >> n;
    vector <int> arr (n);
    char sing;
    for (int k=0; k<n; k++)
    {
        fin >> sing;
        if(sing == '+')
        {
            fin >> arr[i];
            i++;
        }
        else
        {
            fout << arr[j] << endl;
            j++;
        }
    }
    return 0;
}