#include <iostream>
#include <vector>
#include <fstream>
#include <stack>

using namespace std;

vector <stack<int>> matrix;
vector <char> color;

int main()
{
    ifstream fin ("cond.in");
    ofstream fout ("cond.out");

    int n, m;
    fin >> n >> m;

    matrix.resize(n);
    color.resize(n);

    for (int i=0; i<m; i++)
    {
        int left, right;
        fin >> left >> right;
        left--;
        right--;
        matrix[left].push(right);
    }

    return 0;
}