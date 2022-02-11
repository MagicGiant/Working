#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
using namespace std;
class edge
{
private:
    vector <int> path;
public:
    bool have_friend()
    {
        if (path.size() > 0)
            return true;
        return false;
    }
    void push(int data)
    {
        path.resize(path.size() + 1);
        path[path.size() - 1] = data;
    }
    int del()
    {
        int ch = path[path.size() - 1];
        path.resize(path.size() - 1);
        return ch;
    }
    int get_size()
    {
        return path.size();
    }
    int operator [] (int it)
    {
        if (it >= path.size())
            return -1;
        return path[it];
    }
};


int main()
{
    ifstream fin("components.in");
    ofstream fout("components.out");

    int n, m;
    fin >> n >> m;

    vector <edge> edg;
    vector <int> dot(n, -1);

    int it = 0;
    for (int k = 0; k < m; k++)
    {
        int left, right;
        fin >> left >> right;
        left--;
        right--;
        if (dot[left] != -1 && dot[right] != -1)
        {
            int j = edg[left].get_size();
            while (edg[dot[right]].have_friend())
                edg[dot[left]].push(edg[dot[right]].del());
            while (edg[left][j] != -1)
            {
                dot[j] = dot[left];
                j++;
            }
        }
        else if (dot[left] != -1)
        {
            edg[dot[left]].push(right);
            dot[right] = dot[left];
        }
        else if (dot[right] != -1)
        {
            edg[dot[right]].push(left);
            dot[left] = dot[right];
        }
        else
        {
            edg.resize(edg.size() + 1);
            edg[it].push(left);
            edg[it].push(right);
            dot[left] = it;
            dot[right] = it;
            it++;
        }
    }

    for (int i = 0; i < n; i++)
        if (dot[i] == -1)
        {
            edg.resize(edg.size() + 1);
            edg[it].push(i);
            dot[i] = it;
            it++;
        }

    vector <int> edgeses(n);
    int exces = 0;
    it = 0;
    for (int i = 0; i < edg.size(); i++)
    {
        int j = 0;
        if (edg[i].have_friend())
        {
            while (edg[i][j] != -1)
            {
                edgeses[edg[i][j]] = i - exces + 1;
                j++;
            }
            it++;
        }
        else
            exces++;
    }
    fout << it << endl;
    for (int i = 0; i < n; i++)
        fout << edgeses[i] << " ";

    return 0;
}