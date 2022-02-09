#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin ("components.in");
    ofstream fout ("components.out");
    int m, n, component=1;
    fin >> n >> m;
    vector <int> dot (n, -1);
    for (int i=0; i<m; i++)
    {
        int dot_1, dot_2;
        fin >> dot_1 >> dot_2;
        dot_1--;
        dot_2--;
        if (dot[dot_1] != -1)
            dot[dot_2] = dot[dot_1];
        else if (dot[dot_2] != -1)
            dot[dot_1] = dot[dot_2];
        else
        {
            dot[dot_1]=component;
            dot[dot_2]=component;
            component++;
        }
    }
    for (int i=0; i<n; i++)
        if (dot[i]==-1)
        {
            dot[i]=component;
            component++;
        }
    fout << component-1 << endl;
    for (int i=0; i<n; i++)
    {
        
        fout << dot[i] << " ";
    }
    return 0;
}