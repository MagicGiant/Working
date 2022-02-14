#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

#define white 0
#define black 1

using namespace std;
int main ()
{
    ifstream fin ("pathbge1.in");
    ofstream fout ("pathbge1.out");
    int n, m;
    fin >> n >> m;
    
    vector <queue<int>> dot (n);
    vector <bool> color(n, white);
    vector <int> min_path(n, 0);

    int left, right;
    for (int i=0; i<n; i++)
    {
        fin >> left >> right;
        left--;
        right--;
        dot[left].push(right);
    }

    queue <int> dot_friend;
    dot_friend.push(0);
    while (!dot_friend.empty())
    {
        int date=dot_friend.front();
        dot_friend.pop();
        color[date]=black;
        while(!dot[date].empty())
        {
            if (color[dot[date].front()]==white)
            {
                int new_date = dot[date].front();
                dot[date].pop();
                min_path[new_date]=min_path[date]+1;
                dot_friend.push(new_date);
                color[new_date]=black;
            }
            dot[date].pop();
        }
    }
    for (int i=0; i<n; i++)
        fout << min_path[i];
}