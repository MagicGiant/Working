#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
    ifstream fin ("isheap.in");
    ofstream fout ("isheap.out");
    int n;
    fin >> n;
    vector <int> a(n);
    for (int i=0; i<n; i++)
        fin >> a[i];
    for (int i=0; i<n; i++)
        if ((2*(i+1)<=n && a[i]>a[2*(i + 1) - 1]) || (2*(i+1)+1<=n && a[i]>a[2*(i+1)]))
        {
            fout << "NO";
            return 0;
        }
    fout << "YES";
    return 0;
}