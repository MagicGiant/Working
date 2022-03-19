#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;


vector<vector<int>> arr;

int n, new_n=0;

    ifstream fin ("hamiltonian.in");
    ofstream fout ("hamiltonian.out");
void dfs(int i)
{
    int it=0;
    new_n++;
    int k = arr[i].size();

    while (k!=it)
    {
        int new_i = arr[i][it];
        it++;
        dfs(new_i);
    }

    if (n==new_n)
    {
        fout << "YES";
        exit(0);
    }

    new_n--;
}


int main()
{
    ios::sync_with_stdio(false);
    int m;
    fin >> n >> m;
    arr.resize(n);
    vector<vector<int>> par(n);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        fin >> a >> b;
        arr[a - 1].push_back(b - 1);
        par[b - 1].push_back(a - 1);
    }
    int g = 0;
    while(g < n && par[g].size() > 0)
    {
        g = par[g][0];
    }
    
    dfs(g);

    fout << "NO";
    return 0;
}