#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main()
{
    int n, m;
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin >> n >> m;
    vector <vector <bool>> matrix (n, vector <bool> (n, 0)); 
    for (int i=0; i<m; i++)
    {
        int tDot, sDot;
        fin >> tDot >> sDot;
        matrix[tDot-1][sDot-1]=1;
    }
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            fout << matrix[i][j] << " ";
        fout <<endl;
    }
    return 0;
}