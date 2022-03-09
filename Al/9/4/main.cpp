#include <iostream>
#include <vector>
#include <fstream>
#include <stack>

#define white 0
#define gray 1
#define black 2

using namespace std;

vector <stack<int>> matrix;
vector <stack<int>> back_matrix;
vector <char> color;

vector <int> clases;
stack <int> sort_dot;

int it = 0;
int max_it = 0;

void f_1(int date)
{
    if (color[date] == white)
        while (!back_matrix[date].empty())
        {
            int new_date = back_matrix[date].top();
            back_matrix[date].pop();
            color[date] = gray;
            f_1(new_date);
        }
    else if (color[date] == gray || color[date] == black)
        return;

    color[date] = black;
    sort_dot.push(date);
}

void f_2(int date)
{
    if (color[date] == white)
        while (!matrix[date].empty())
        {
            int new_date = matrix[date].top();
            matrix[date].pop();
            color[date] = gray;
            f_2(new_date);
        }
    else if (color[date] == gray || color[date] == black)
        return;

    color[date] = black;
    clases[date] = it;
}

void dfs(int n)
{
    for (int i = 0; i < n; i++)
        if (color[i] == white)
        {
            it++;
            f_1(i);
        }

    max_it = it;

    for (int i = 0; i < n; i++)
        color[i] = white;

    for (int i = 0; i < n; i++)
    {
        int date = sort_dot.top();
        sort_dot.pop();
        if (color[date] == white)
        {
            f_2(date);
            it--;
        }
    }
}
int main()
{
    ifstream fin("cond.in");
    ofstream fout("cond.out");

    int n, m;
    fin >> n >> m;

    matrix.resize(n);
    color.resize(n);
    back_matrix.resize(n);
    clases.resize(n, -1);

    for (int i = 0; i < m; i++)
    {
        int left, right;
        fin >> left >> right;
        left--;
        right--;
        matrix[left].push(right);
        back_matrix[right].push(left);
    }

    dfs(n);

    fout << max_it << endl;
    for (int i = 0; i < n; i++)
        fout << clases[i] << " ";

    return 0;
}