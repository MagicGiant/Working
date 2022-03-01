#include <iostream>
#include <vector>
#include <fstream>
#include <stack>

#define white 0
#define gray 1
#define black 2

using namespace std;
int main()
{
    ifstream fin ("topsort.in");
    ofstream fout ("topsort.out");

    int n, m;
    fin >> n >> m;
    vector <stack<char>> matrix (n);
    vector <char> color (n, white);
    int left, right;
    for (int i=0; i<m; i++)
    {
        fin >> left >> right;
        left--;
        right--;
        matrix[left].push(right);
    }

    stack <int> eque;
    stack <int> sort;
    eque.push(0);
    color[0]=gray;
    while (!eque.empty())
    {
        int date=eque.top();
        eque.pop();
        while (!matrix[date].empty())
        {
            
        }
    }

    return 0;
}