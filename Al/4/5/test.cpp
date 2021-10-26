#include <iostream>
#include <fstream>
#include <string>
#include <stack>
using namespace std;
int main()
{
    ifstream fin ("binsearch.in.txt");
    ofstream fout("binsearch.out.txt");
    string f;
    stack <int> integer;
    stack <char> znak;
    fin >> f;
    int i=0;
    while (i!=f.size())
    {
        int ch=0;
        if (f[i]=='+' || f[i]=='-' || f[i]=='*' || f[i]=='/')
            znak.push(f[i]);
        if (f[i]==')')
        {
            if(znak.top()=='+')
            {
                ch+=integer.top();
                integer.pop();
                ch+=integer.top();
                integer.pop();
                integer.push(ch);
            }
            else if(znak.top()=='-')
            {
                ch-=integer.top();
                integer.pop();
                ch+=integer.top();
                integer.pop();
                integer.push(ch);
            }
            else if(znak.top()=='*')
            {
                ch+=integer.top();
                integer.pop();
                ch*=integer.top();
                integer.pop();
                integer.push(ch);
            }
            else if(znak.top()=='/')
            {
                ch+=integer.top();
                integer.pop();
                ch=integer.top()/ch;
                integer.pop();
                integer.push(ch);
            }
            znak.pop();
        }
        i++;
    }
    return 0;
}