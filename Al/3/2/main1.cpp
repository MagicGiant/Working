#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector <int> arr;
void swaps (int i, int n)
{
    if (i*2+1<=n-1 && i*2+2<=n-1 && arr[i]<max(arr[i*2+1],arr[i*2+2]))
    {
        if (arr[i*2+1]>arr[i*2+2])
        {
            swap(arr[i], arr[i*2+1]);
            swaps(i*2+1, n);
        }
        else
        {
            swap(arr[i], arr[i*2+2]);
            swaps(i*2+2, n);
        }
    }
    else if (i*2+1<=n-1 && arr[i]<arr[i*2+1])
        swap(arr[i],arr[i*2+1]);
}
void creat_pyramid()
{
    int i=arr.size();
    i=i-1-i/2;
    while (i>=0)
    {
        swaps(i, arr.size());       
        // for (int i=0; i<arr.size(); i++)
        //     cout << arr[i] << " ";
        // cout<<endl;
        i--;
    }
}
void sort_pyramid ()
{
    creat_pyramid();
    //cout<<"________________________"<<endl;
    int n=arr.size();
    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        swaps(0, i);
        // for (int i=0; i<arr.size(); i++)
        //         cout << arr[i] << " ";
        // cout<<endl;
    }
}
int main()
{
    ifstream fin ("sort.in");
    ofstream fout("sort.out");
    int n;
    fin >> n;
    arr.resize(n);
    for (int i=0; i<n; i++)
        fin >> arr[i];
    sort_pyramid ();
    for (int i=0; i<n; i++)
        fout << arr[i] << " ";
    return 0;
}