#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std;

vector <int> abjective_list [100000];
vector <char> color;
stack <int> top_sort;

void dfs (int v)
{
    if (color [v] == WHITE)
    {
        color [v] = GRAY;
        if (!abjective_list[v].empty())
        {
            for (int i: abjective_list[v])
            {
                if (color [i] == WHITE)
                {
                    dfs (i);
                }

            }

        }
    }
    else if ( color [v] == GRAY)
    {
        cout << -1 << endl;
    }
    else if (color [v] == BLACK)
    {
        return;
    }
    
    color [v] = BLACK;
    top_sort.push(v);
}
void topological_sort(int n)
{
    for(int i = 0; i < n; i++)
    {
        if (color[i] == WHITE)
            dfs(i);
    }

}

int main()
{
    ifstream fin ("topsort.in");
    ofstream fout ("topsort.out");
    int n, m, value1, value2;
    fin >> n >> m;

    color.resize(n, WHITE);

    for ( int i = 0; i < m; i++)
    {
        fin >> value1 >> value2;
        value1 --;
        value2 --;
        abjective_list[value1].push_back(value2);
    }

    topological_sort (n);
    for ( int i = 0; i < n; i++)
    {
        fout << top_sort.top() + 1 << " ";
        top_sort.pop();

    }
}