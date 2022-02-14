#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");
    int n, m;
    fin >> n >> m;
    vector <vector <int>> matrix (m, vector <int> (2));
    for (int i=0; i<m; i++)
            fin >> matrix[i][0] >> matrix[i][1];
    for (int i=1; i<m; i++)
        for (int j=0; j<i; j++)
        {
            
            if (matrix[i][0]==matrix[j][1] && matrix[i][1]==matrix[j][0] )
            {
                fout << "YES";
                cout <<1;
                return 0;
            }
            if (matrix[i][0]==matrix[j][0] && matrix[i][1]==matrix[j][1])
            {
                fout << "YES";
                cout << i << " " << j;
                return 0;
            }
            if (matrix[i][0]==matrix[i][1] && matrix[j][0]==matrix[j][1] && matrix[i][0]==matrix[j][0])
            {
                fout << "YES";
                cout << 3;
                return 0;
            }
        }
    fout << "NO";
    return 0;
}