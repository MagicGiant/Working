#include <iostream>
#include <vector>
#include <fstream>
#include <stack>

#define white 0
#define gray 1
#define black 2

using namespace std;

ifstream fin ("topsort.in");
ofstream fout ("topsort.out");

vector <stack<int>> matrix;
vector <char> color;
stack <int> sort;

void f (int dot)
{
    if (color[dot]==white)
        while (!matrix[dot].empty())
        {
            int new_dot=matrix[dot].top();
            matrix[dot].pop();
            color[dot]=gray;
            f(new_dot);
        }
    else if (color[dot]==black)
        return;
    else if (color[dot]==gray)
    {
        fout << "-1";
        exit(0);
    }
    color[dot]=black;
    sort.push(dot+1);
}

void dfs (int n)
{
    for (int i=0; i<n; i++)
        if (color[i]==white)
            f(i);
}


int main()
{

    int n, m;
    fin >> n >> m;

    matrix.resize(n);
    color.resize(n, white);

    int left, right;
    for (int i=0; i<m; i++)
    {
        fin >> left >> right;
        left--;
        right--;
        matrix[left].push(right);
    }

    dfs(n);
    for (int i=0; i<n; i++)
    {
        fout << sort.top() << " ";
        sort.pop();
    }
    return 0;
}