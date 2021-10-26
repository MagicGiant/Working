#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
vector <int> arr;
int sort_revers(int left, int right)
{
    cout << right-left;
    if (right>left)
    {
        for (int i=left; i<right; i++)
            swap(arr[i],arr[i/2]);
        sort_revers(left, right/2);
        sort_revers(right, right-right/2);
    }
    else
        return 0;
}
 int main()
{
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    int n;
    fin >> n;
    vector <int> arr (n);
    arr.resize(n);
    for (int i=0; i<n; i++)
        arr[i]=i+1;
    sort_revers(0, n);
    for (int i=0; i<n; i++)
        fout << arr[i] << " ";
    return 0;
}