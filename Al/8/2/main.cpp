#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");
    int n;
    fin >> n;
    vector <vector <int>> matrix (n, vector <int> (n));
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            fin >> matrix[i][j];
    for (int i=0; i<n; i++)
        if (matrix[i][i]==1)
        {
            fout << "NO";
            return 0;
        }
    for (int i=0; i<n; i++)
        for (int j=1; j<n; j++)
        {   
            if (i==j)
                continue;
            if (matrix[i][j]!=matrix[j][i])
            {
                fout << "NO";
                return 0;
            }
        }
    fout << "YES";
    return 0;
}