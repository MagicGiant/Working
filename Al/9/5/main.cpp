#include <iostream>
#include <vector>
#include <fstream>
#include <stack>

#define white 0
#define gray 1

using namespace std;

ifstream fin("hamiltonian.in");
ofstream fout("hamiltonian.out");

vector <stack<int>> matrix;
vector <stack<int>> matrix_clone;
vector <char> color;

int dot_number;
int n;

void f(int date)
{
    if (color[date] == white)
        while (!matrix[date].empty())
        {
            int new_dot = matrix[date].top();
            matrix[date].pop();
            color[date] = gray;
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
        matrix = matrix_clone;
        dot_number = 1;
        f(i);
    }
}

int main()
{

    int  m;
    fin >> n >> m;

    matrix.resize(n);
    matrix_clone.resize(n);
    color.resize(n);

    for (int i = 0; i < m; i++)
    {
        int left, right;
        fin >> left >> right;
        left--;
        right--;
        matrix_clone[left].push(right);
    }

    dfs();

    fout << "NO";
    return 0;
}