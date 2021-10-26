#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
    ifstream fin ("binsearch.in");
    ofstream fout ("binsearch.out");
    int n, N;
    fin >> n;
    vector <int> arr (n);
    for (int i=0; i<n; i++)
        fin >> arr[i];
    fin >> N;
    vector <int> ARR (N);
    for (int i=0; i<N; i++)
        fin >> ARR[i];
    for (int i=0; i<N; i++)
    {
        int l=0; int r=n-1;
        int mid;
        bool flag = false;
        while ((l <= r) && (flag != true)) 
        {
            mid = (l + r) / 2;
            if (arr[mid] == ARR[i]) flag = true;
            if (arr[mid] > ARR[i]) r = mid - 1;
            else l = mid + 1;
        }
        if (flag)
        {
            int j=mid;
            while (j>0 && arr[j-1]==arr[mid])
                j--;
            fout << j+1;
            j=mid;
            while (j<n && arr[j+1]==arr[mid])
                j++;
            fout << " " << j+1 << endl;
        }
        else
            fout << "-1 -1" << endl;
    }
    return 0;
}