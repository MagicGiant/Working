#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

#define white 0
#define blue 1
#define red 2

using namespace std;

int main()
{
    ifstream fin ("bipartite.in");
    ofstream fout ("bipartite.out");
    
    int n, m;
    fin >> n >> m;

    vector <char> teams (n, white);
    vector <stack <int>> matrix (n);

    for (int i=0; i<m; i++)
    {
        int left, right;
        fin >> left >> right;
        left--;
        right--;
        matrix[left].push(right);
    }

    stack <int> eque;
    eque.push(0);

    while (!eque.empty())
    {
        int date=eque.top();
        eque.pop();
        while (!matrix[date].empty())
        {
            int new_date=matrix[date].top();
            matrix[date].pop();
            if ( teams[date]==teams[new_date] && teams[date]==white)
            {
                teams[date]=red;
                teams[new_date]=blue;
                eque.push(new_date);
            }
            else if (teams[date]==red && teams[new_date]==white)
            {
                teams[new_date]=blue;
                eque.push(new_date);
            }
            else if (teams[date]==blue && teams[new_date]==white)
            {
                teams[new_date]=red;
                eque.push(new_date);
            }
            else if (teams[date]==teams[new_date])
            {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}