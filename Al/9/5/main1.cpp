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
vector <vector <int>> back_matrix;
vector <char> color;

int start_dot=-1;
int dot_number=1;
int n;

void seek_starting (int date)
{
    int it=0;
    if (color[date] == white)
        while (back_matrix[date].size()!=it)
        {
            int new_dot = back_matrix[date][it];
            color[date] = gray;
            it++;
            dot_number++;
            seek_starting(new_dot);
        }
    
    if (start_dot == -1)
        start_dot = date;
}

void dfs(int date)
{
    int it=0;
    if (color[date] == white)
        while (matrix[date].size()!=it)
        {
            int new_dot = matrix[date][it];
            color[date] = gray;
            it++;
            dot_number++;
            dfs(new_dot);
        }
    
    if (dot_number == n)
    {
        fout << "YES";
        exit(0);
    }
    dot_number--;
    color[date] = white;
}

void gam()
{
    dot_number = 1;
    seek_starting(0);
    dfs(start_dot);
}

int main()
{

    int  m;
    fin >> n >> m;

    matrix.resize(n);
    back_matrix.resize(n);
    color.resize(n, white);

    for (int i = 0; i < m; i++)
    {
        int left, right;
        fin >> left >> right;
        left--;
        right--;
        matrix[left].push_back(right);
        back_matrix[right].push_back(left);
    }

    gam();

    fout << "NO";
    return 0;
}