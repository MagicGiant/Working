#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
long long inv = 0;
vector <int> merge(vector <int>& a, vector <int>& b)
{
    int k = 0, i = 0, j = 0;
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
            inv += a.size()-i;
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
        vector <int> temp1(arr.size() / 2);
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
    setlocale(LC_ALL, "ru");
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    int n;
    fin >> n;
    vector <int> c(n);
    for (int i = 0; i < n; i++)
        fin >> c[i];
    c = MergeSort(c);
    fout << inv;
    return 0;
}