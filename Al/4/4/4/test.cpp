#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string st ="1239";
    int j = 1;
    int ch=0;
        for (int i=st.size() - 1; i >= 0; i--)
        {
            ch += (st[i] - 48) * j;
            j *= 10;
            cout << ch << endl;
        }
    cout << ch;
    return 0;
}