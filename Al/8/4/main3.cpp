#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

#define white 0
#define black 1

using namespace std;

int cl=1;
vector <int> dot_class (1);

void seek_friend (int it, vector <bool> &dot, vector <vector<bool>> &matrix)
{
    queue <int> edge;
    edge.push(it);
    while (!edge.empty())
    {
        int it = edge.front();
        edge.pop();
        dot[it] = black;
        if (it>=dot_class.size()-1)
            dot_class.resize(it+1);
        dot_class[it]=cl;
        for (int i=0; i<dot.size(); i++)
        {
            if (matrix[it][i]==1 && dot[i]==white)
            {
                dot[i]=black;
                edge.push(i);
            }
        }
    }
    cl++;
}
int main()
{
    ifstream fin ("components.in");
    ofstream fout ("components.out");
    int n, m;
    fin >> n >> m;

    vector <vector <bool>> matrix (n, vector <bool> (n, 0));
    vector <bool> dot (n, white);

    for (int i=0; i<m; i++)
    {
        int left, right;
        fin >> left >> right;
        matrix[left-1][right-1]=1;
        matrix[right-1][left-1]=1;
    }

    int i=0;
    while (i<n)
    {
        if(dot[i]!=white)
        {
            i++;
            continue;
        }
        seek_friend(i, dot, matrix);
    }

    fout << cl-1 << endl;
    for (int i=0; i<dot_class.size(); i++)
        fout << dot_class[i] << " ";
    
    return 0;
}