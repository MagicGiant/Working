#include <iostream>
#include <vector>
#include <fstream>
#include <stack>
#include <queue>

#define white 0
#define gray 1
#define black 2

using namespace std;

vector <stack<int>> matrix;
vector <stack<int>> back_matrix;
vector <char> color;

vector <int> clases;
stack <int> sort_dot;
queue <int> end_sort;

int it = 0;
int max_it = 0;

void sort_matrix(int date)
{
    if (color[date] == white)
        while (!back_matrix[date].empty())
        {
            int new_date = back_matrix[date].top();
            back_matrix[date].pop();
            color[date] = gray;
            sort_matrix(new_date);
        }
    else if (color[date] == gray || color[date] == black)
        return;

    color[date] = black;
    sort_dot.push(date);
}

void classed(int date)
{
    if (color[date] == white)
        while (!back_matrix[date].empty())
        {
            int new_date = back_matrix[date].top();
            back_matrix[date].pop();
            color[date] = gray;
            classed(new_date);
        }
    else if (color[date] == gray || color[date] == black)
        return;

    color[date] = black;
    clases[date] = it;
}

void top_sort(int date)
{
    if (color[date]==white)
        while (!matrix[date].empty())
        {
            int new_dot=matrix[date].top();
            matrix[date].pop();
            color[date]=gray;
            top_sort(new_dot);
        }
    else if (color[date]==black || color[date]==gray)
        return;
        
    color[date]=black;
    end_sort.push(date+1);
}
void dfs(int n)
{
    for (int i = 0; i < n; i++)
        if (color[i] == white)
            sort_matrix(i);

    for (int i = 0; i < n; i++)
        color[i] = white;

    back_matrix=matrix;

    for (int i = 0; i < n; i++)
    {
        int date = sort_dot.top();
        sort_dot.pop();
        if (color[date] == white)
        {
            classed(date);
            it++;
        }
    }

    for (int i = 0; i < n; i++)
        color[i] = white;

    for (int i=0; i<n; i++)
        if (color[i]==white)
            top_sort(i);

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

    fout << it << endl;
    for (int i = 0; i < n; i++)
    {
        int date;
        date=end_sort.front();
        end_sort.pop();
        fout << clases[date-1] + 1 << " ";
    }

    return 0;
}