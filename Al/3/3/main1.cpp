#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector <vector <char>> arr;
void swaps (int i, int n, int m)
{
    if (i*2+1<=n-1 && i*2+2<=n-1 && arr[i][m]<max(arr[i*2+1][m],arr[i*2+2][m]))
    {
        if (arr[i*2+1][m]>arr[i*2+2][m])
        {
            swap(arr[i], arr[i*2+1]);
            swaps(i*2+1, n, m);
        }
        else
        {
            swap(arr[i], arr[i*2+2]);
            swaps(i*2+2, n, m);
        }
    }
    else if (i*2+1<=n-1 && arr[i][m]<arr[i*2+1][m])
        swap(arr[i],arr[i*2+1]);
}
void creat_pyramid(int m)
{
    int i=arr.size();
    i=i-1-i/2;
    while (i>=0)
    {
        swaps(i, arr.size(), m);       
        // for (int i=0; i<arr.size(); i++)
        //     cout << arr[i] << " ";
        // cout<<endl;
        i--;
    }
}
void sort_pyramid (int m)
{
    creat_pyramid(m);
    //cout<<"________________________"<<endl;
    int n=arr.size();
    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        swaps(0, i, m);
        // for (int i=0; i<arr.size(); i++)
        //         cout << arr[i] << " ";
        // cout<<endl;
    }
}
int main()
{
    int n, m, k;
    ifstream fin ("radixsort.in.txt");
    ofstream fout("radixsort.out.txt");
    fin >> n >> m >> k;
    //cout << n << " " << m << " " << k << endl;
    arr.assign(n, vector <char> (m));
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            fin >> arr[i][j];
            //cout << arr[i][j] << " ";
        }
        //cout << endl;
    }
    for (int i=k-1; i>0; i--)
        sort_pyramid(i);
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    return 0;
}