#include <iostream>
#include <vector>
#include <fstream>
#include <stack>

#define white 0
#define gray 1

using namespace std;

ifstream fin("hamiltonian.in");
ofstream fout("hamiltonian.out");

vector <vector <int>> matrix;
vector <char> IMcolor;
vector <char> color;

int dot_number;
int n;

void f(int date)
{
    int it=0;
    if (color[date] == white)
        while (matrix[date].size()!=it)
        {
            int new_dot = matrix[date][it];
            color[date] = gray;
            IMcolor[date] = gray;
            it++;
            dot_number++;
            f(new_dot);
        }
    
    if (dot_number == n)
    {
        fout << "YES";
        exit(0);
    }
    dot_number--;
    color[date] = white;
}

void dfs()
{
    for (int i = 0; i < n; i++)
    {   
        if (IMcolor[i]==gray)
            continue;
        dot_number = 1;
        f(i);
    }
}

int main()
{

    int  m;
    fin >> n >> m;

    matrix.resize(n);
    color.resize(n, white);
    IMcolor.resize(n, white);

    for (int i = 0; i < m; i++)
    {
        int left, right;
        fin >> left >> right;
        left--;
        right--;
        matrix[left].push_back(right);
    }

    dfs();

    fout << "NO";
    return 0;
}