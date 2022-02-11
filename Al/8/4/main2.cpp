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
        path.resize(path.size()+1);
        path[path.size()-1]=data;
    }
    int del()
    {
        int ch = path[path.size()-1];
        path.resize(path.size()-1);
        return ch;
    }
    int operator [] (int it)
    {
        if (it>=path.size())
            return -1;
        return path[it];
    }
};

int end_sort(vector <edge>& edg, int it, int n)
{
    vector <bool> friendly_dot(n, false);
    
    for (int i = 0; i < n; i++)
    {
        int j=0;
        while (edg[i][j]!=-1)
        {
            friendly_dot[edg[i][j]] = true;
            j++;
        }
    }
        
    for (int i = 0; i < n; i++)
        if (!friendly_dot[i])
        {
            edg[it].push(i);
            it++;
        }
    return it;
}

int main()
{
    ifstream fin("components.in");
    ofstream fout("components.out");

    int n, m;
    fin >> n >> m;

    vector <edge> edg(n);

    int it = 0;
    for (int k = 0; k < m; k++)
    {
        int left, right;
        fin >> left >> right;
        left--;
        right--;
        if (edg[left].have_friend() && edg[right].have_friend())
            while (edg[right].have_friend())
                edg[left].push(edg[right].del());
        else if (edg[left].have_friend())
            edg[left].push(right);
        else if (edg[right].have_friend())
            edg[right].push(left);
        else
        {
            edg[it].push(left);
            edg[it].push(right);
            it++;
        }
    }

    it = end_sort(edg, it, n);

    vector <int> edgeses(n);
    int exces = 0;
    for (int i = 0; i < n; i++)
    {
        if (edg[i].have_friend())
            while (edg[i].have_friend())
                edgeses[edg[i].del()] = i - exces;
        else
            exces++;
    }

    for (int i = 0; i < n; i++)
        fout << edgeses[i] << " ";

    return 0;
}