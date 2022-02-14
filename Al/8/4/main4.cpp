#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

#define white 0
#define black 1

using namespace std;
int main()
{
    ifstream fin("components.in");
    ofstream fout("components.out");

    int n, m;
    int it = 0;
    fin >> n >> m;
    int left, right;

    vector <queue <int>> dot(n);
    vector <bool> color(n, white);
    for (int i = 0; i < m; i++)
    {
        fin >> left >> right;
        left--;
        right--;
        dot[left].push(right);
        dot[right].push(left);
    }

    vector <int> edge(n);
    for (int i = 0; i < n; i++)
    {
        if (color[i] == black)
            continue;
        queue <int> dot_friend;
        dot_friend.push(i);
        it++;

        while (!dot_friend.empty())
        {
            int date;
            date = dot_friend.front();
            dot_friend.pop();
            color[date] = black;
            edge[date] = it;
            while (!dot[date].empty())
            {
                if (color[dot[date].front()] == white)
                {
                    dot_friend.push(dot[date].front());
                    color[dot[date].front()] = black;
                }
                dot[date].pop();
            }
        }
    }
    fout << it << endl;
    for (int i = 0; i < n; i++)
        fout << edge[i] << " ";
    return 0;
}