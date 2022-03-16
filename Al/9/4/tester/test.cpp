#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int key;

int my_rand (int left, int right)
{
    left;
    right;
    key = (key * 73129 + 95121) % 100000;
    return abs(key%(right-left))+left;
}

int main()
{

    key = 3;

    int n=my_rand(5, 10);
    int m=my_rand(n, n+5);

    for (int i=0; i<30; i++)
    {
        ifstream Itest ("condt.out");
        ifstream MItest ("cond.out");
        ofstream Otest ("cond.in");

        Otest << n << " " << m << endl;

        for (int j=0; j<m; j++)
            Otest << my_rand(1, n) << " " << my_rand (1, n) << endl;
        
        system("main.exe");
        system("other.exe");

        while (!MItest.eof())
        {
            if(Itest.eof())
            {
                cout << "error";
                return 0;
            }

            string date1;
            string date2;

            Itest >> date1;
            MItest >> date2;

            if (date1!=date2)
            {
                cout << "error";
                return 0;
            }
        }
        MItest.close();
        Itest.close();
        Otest.close();
    }
    return 0;
}