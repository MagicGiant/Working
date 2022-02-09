#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin ("components.in");
    ofstream fout ("components.out");
    int m, n, component=2;
    fin >> n >> m;
    vector <vector <int>> dots (n, vector <int> (2,1));
    vector <vector <int>> edge(m, vector <int> (2));
    for (int i = 0; i < n; i++)
        dots[i][1]=-1;
    
    for (int i=0; i<m; i++)
    {
        fin >> edge[i][0] >> edge [i][1];
        edge [i][0]--;
        edge [i][1]--;
    }
    dots[edge[0][0]][1]=0;
    dots[edge[0][1]][1]=0;
    for (int i = 1; i < m; i++)
    {
        bool flag=false;
        for (int j=0; j<i; j++)
        {
            if(edge[i][0]==edge[j][0] || edge[i][0]==edge[j][1])
                flag=true;
            if(edge[i][1]==edge[j][0] || edge[i][1]==edge[j][1])
                flag=true;
            if (flag)
            {
                dots[edge[i][0]][0]=dots[edge[j][0]][0];
                dots[edge[i][1]][0]=dots[edge[j][0]][0];
                dots[edge[i][0]][1]=0;
                dots[edge[i][1]][1]=0;
                break;
            }
        }
        if (!flag)
        {
            dots[edge[i][0]][0]=component;
            dots[edge[i][1]][0]=component;
            dots[edge[i][0]][1]=0;
            dots[edge[i][1]][1]=0;
            component++;
        }
    }
    for (int i=0; i<n; i++)
        if (dots[i][1]==-1)
        {
            dots[i][0]=component;
            component++;
        }
    
    fout << component-1 << endl;
    for (int i=0; i<n; i++)
        fout << dots[i][0] << " ";
    //fout <<endl;
    // for (int i=0; i<n; i++)
    //     fout << dots[i][1] << " ";
    
    return 0;
}