#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;
int main()
{
    ifstream fin ("postfix.in");
    ofstream fout("postfix.out");
    stack <int> arr;
    string st;
    while (fin >> st)
    {
        int ch=0;
        if(st=="+")
        {
            ch+=arr.top();
            arr.pop();
            ch+=arr.top();
            arr.pop();
            arr.push(ch);
        }
        else if(st=="-")
        {
            ch-=arr.top();
            arr.pop();
            ch+=arr.top();
            arr.pop();
            arr.push(ch);
        }
        else if(st=="*")
        {
            ch+=arr.top();
            arr.pop();
            ch*=arr.top();
            arr.pop();
            arr.push(ch);
        }
        else if(st=="/")
        {
            ch+=arr.top();
            arr.pop();
            ch=arr.top()/ch;
            arr.pop();
            arr.push(ch);
        }
        else
            {
                int j = 1;
                for (int i=st.size()-1; i >= 0; i--)
                {
                    ch += (st[i] - 48) * j;
                    j *= 10;
                }
                arr.push(ch);
            }
    }
    fout << arr.top();
    return 0;
}