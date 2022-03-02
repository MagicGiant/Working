#include <iostream>
#include <vector>
#include <fstream>
#include <stack>

#define white 0
#define gray 1
#define black 2

using namespace std;

ifstream fin ("cycle.in");
ofstream fout ("cycle.out");

vector <stack<int>> matrix;
vector <char> color;
stack <int> cycle;

int found_cycle=-1;

void f (int dot)
{
    if (found_cycle!=-1)
    {
        there:
        cycle.push(dot);
        if (found_cycle==dot)
        {
            fout << "YES\n";
            while (!cycle.empty())
            {
                fout << cycle.top()+1 << " ";
                cycle.pop();
            }
            exit(0);
        }
        return;
    }
    if (color[dot]==white)
        while (!matrix[dot].empty())
        {
            int new_dot=matrix[dot].top();
            matrix[dot].pop();
            color[dot]=gray;
            f(new_dot);
            if (found_cycle!=-1)
                goto there;
        }
    else if (color[dot]==black)
        return;
    else if (color[dot]==gray)
    {
        found_cycle=dot;
        return;
    }
}

void dfs (int n)
{
    for (int i=0; i<n; i++)
        if (color[i]==white)
            f(i);
    fout << "NO";
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
    return 0;
}