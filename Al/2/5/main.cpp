#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> merge(vector <int>& a, vector <int>& b)
{
    int k = 0;
    int i = 0;
    int j = 0;
    vector <int> res(a.size() + b.size());
     
    while (i < a.size() && j < b.size())
    {
        if (a[i] <= b[j])
        {
            res[k] = a[i];
            k++;
            i++;
        }
        else
        {
            res[k] = b[j];
            k++;
            j++;
        }
    }
     
    while (i < a.size())
    {
        res[k] = a[i];
        k++;
        i++;
    }
    while (j < b.size())
    {
         
        res[k] = b[j];
        k++;
        j++;
    } 
     
     
    return res;
}
vector <int> MergeSort(vector <int>& arr)
{
    if (arr.size() > 1)
    {
        vector <int> temp1(arr.size()/2);
        vector <int> temp2(arr.size() - (arr.size() / 2));
        for (int i = 0; i < arr.size() / 2; i++)
            temp1[i] = arr[i];
        for (int i = arr.size() / 2; i < arr.size(); i++)
            temp2[i - arr.size() / 2] = arr[i];
 
 
        vector <int> A(MergeSort(temp1));
        vector <int> B(MergeSort(temp2));
        return merge(A, B);
         
    }
    else
    {
        return arr;
    }
}
int main()
{
    ifstream fin ("kth.in.txt");
    ofstream fout("kth.out.txt");
    int n, k, A, B, C;
    fin >> n >> k >> A >> B >> C;
    
    vector <int> a(n);
    vector <int> a_sort(n);
    fin >> a[0] >> a[1];
    for (int i=2; i<n; i++)
        a[i]=A*a[i-2]+B*a[i-1]+C;
    a_sort=MergeSort(a);
    cout << a_sort[k-1];
    return 0;
}