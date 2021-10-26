#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
vector <vector <string>> merge(vector <vector <string>>& a, vector <vector <string>>& b)
{
    int k = 0;
    int i = 0;
    int j = 0;
    vector <vector <string>> res(a.size() + b.size(), vector <string> (2));
     
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
vector <vector <string>> MergeSort(vector <vector <string>>& arr)
{
    if (arr.size() > 1)
    {
        vector <vector <string>> temp1(arr.size()/2, vector <string> (2));
        vector <vector <string>> temp2(arr.size() - (arr.size() / 2), vector <string> (2));
        for (int i = 0; i < arr.size() / 2; i++)
            temp1[i] = arr[i];
        for (int i = arr.size() / 2; i < arr.size(); i++)
            temp2[i - arr.size() / 2] = arr[i];
        temp1 = MergeSort(temp1);
        temp2 = MergeSort(temp2);
        return merge(temp1, temp2);
         
    }
    else
    {
        return arr;
    }
}
int main()
{
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    int n;
    fin >> n;
    vector <vector<string>> c(n, vector <string> (2));
    vector <vector<string>> f(n, vector <string> (2));
    for (int i = 0; i < n; i++)
        fin >> c[i][0] >> c[i][1];
    f = MergeSort(c);
    int i=0;
    string country;
    while (i!=n)
    {
        country = f[i][0];
        fout <<"=== "<<country<<" ==="<<endl;
        while (i!=n && f[i][0]==country)
        {
            fout<<f[i][1]<<endl;
            i++;
        }
    }
    return 0;
}