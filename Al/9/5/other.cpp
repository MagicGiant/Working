#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

const int n=5;
 
int c[n] ;   // номер хода, на котором посещается вершина
int path[n]; // номера посещаемых вершин
int v0=2;    // начальная вершина
vector < vector <char>> a;
 
//подпрограмма нахождения гамильтонова цикла
int gamilton ( int k)
{
int v,q1=0;
    for(v=0; v<n && !q1; v++)
    {
      if(a[v][path[k-1]]||a[path[k-1]][v])
      {
    if (k==n &&  v==v0 ) q1=1;
    else if (c[v]==-1) 
            {
          c[v] = k ; path[k]=v; 
          q1=gamilton (k+1) ;
          if (!q1) c[v]=-1;  
        } else continue;
    } 
    }   return q1;
}
 
int main()
{
    ifstream fin("hamiltonian.in");
    ofstream fout("hamiltoniant.out");

    int n, m;
    fin >> n >> m;
    a.resize(n, vector <char> (n, 0));

    for (int i=0; i<n; i++)
    {
        int left, right;
        fin >> left >> right;
        left--;
        right--;
        a[left][right]=1;
    }

    for (int i=0; i<n; i++)
    {
      for (int j=0; j<n; j++)
      {
        cout << a[i][j];
      }
      cout << endl;
    }
      

    int j;
        for(j=0;j<n;j++) c[j]=-1;
        path[0]=v0 ;
          c[v0]=v0;
    if(gamilton (1)) 
        fout << "YES"; 
    else fout<<"NO";
	return 0;
}