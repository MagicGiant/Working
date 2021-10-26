#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
    string f;
    stack <int> integer;
    stack <char> znak;
    cin >> f;
    int i = 0;
    while (i != f.size())
    {
        int ch = 0;
        if (f[i] == '+' || f[i] == '-' || f[i] == '*' || f[i] == '/')
            znak.push(f[i]);
        else if (f[i] == ')')
        {
            if (znak.top() == '+')
            {
                ch += integer.top();
                integer.pop();
                ch += integer.top();
                integer.pop();
                integer.push(ch);
                cout << znak.top() << endl;
            }
            else if (znak.top() == '-')
            {
                ch -= integer.top();
                integer.pop();
                ch += integer.top();
                integer.pop();
                integer.push(ch);
                cout << znak.top() << endl;
            }
            else if (znak.top() == '*')
            {
                ch += integer.top();
                integer.pop();
                ch *= integer.top();
                integer.pop();
                integer.push(ch);
                cout << znak.top() << endl;
            }
            else if (znak.top() == '/')
            {
                ch += integer.top();
                integer.pop();
                ch = integer.top() / ch;
                integer.pop();
                integer.push(ch);
                cout << znak.top() << endl;
            }
            znak.pop();
        }
        else if (f[i]!='(')
            integer.push(f[i]-48);
        i++;
    }
    cout << integer.top();
    cin >> f;
    return 0;
}