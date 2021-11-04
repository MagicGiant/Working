#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
int test (string str)
{
    stack <char> steck;
    char a, b;
    int length_steck=0;
    for (int i=0; i<str.length(); i++)
    {
        if (str[i]=='(' || str[i]=='[')
            steck.push(str[i]);
        else 
            if(steck.empty())
                return 1;
            else
                if((steck.top()=='[' && str[i]==']') || (steck.top()=='(' && str[i]==')'))
                    steck.pop();
                else 
                    return 1;
    }
    if (steck.empty()) 
        return 0;
    else 
        return 1;
}
int main()
{
    ifstream fin ("brackets.in");
    ofstream fout("brackets.out");
    queue <string> arr;
    string ch;
    while (fin>>ch)
        arr.push(ch);
    while (!arr.empty())
    {
        if (!test(arr.front()))
            fout << "YES" << endl;
        else
            fout << "NO" <<endl;
        arr.pop();
    }
    return 0;
}