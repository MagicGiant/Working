#include <string>
#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;
class dot
{
protected:
    int x=0, y=0;
public:
    dot ()
    {}
    dot (int ur_x, int ur_y): x(ur_x), y(ur_y)
    {}
    void set_O (int ur_x, int ur_y)
    {
        x=ur_x;
        y=ur_y;
    }
    int get_x ()
    {
        return x;
    }
    int get_y ()
    {
        return y;
    }

};
class broken_line: public dot
{
protected:
    dot *arr_dot;
    int size_dot=0;
public:
    broken_line (dot *ur_arr_dot): arr_dot(ur_arr_dot)
    {
        size_dot=sizeof(arr_dot)/sizeof(*arr_dot);
    }
    void set_dot  (dot *ur_arr_dot)
    {
        arr_dot=ur_arr_dot;
        size_dot=sizeof(arr_dot)/sizeof(*arr_dot);
    }
    double  length()
    {
        int sum_pow=0;
        for (int i=0; i<size_dot-1; i++)
        {
            sum_pow+=sqrt(pow(arr_dot[i].get_x()-arr_dot[i+1].get_x(), 2)-pow(arr_dot[i].get_y()-arr_dot[i+1].get_y(), 2));
        }
        return sum_pow;
    }
};
class closed_broken_line: public broken_line
{
private:
    bool check ()
    {
        if (arr_dot[0].get_x()!=arr_dot[size_dot].get_x() || arr_dot[0].get_y()!=arr_dot[size_dot].get_y())
            {
                cout<<"*ERROR! THIS BROKEN LINE NOT CLOSED\n";
                return false;
            }
        if (size_dot<3)
        {
            cout<<"*ERROR! THIS BROKEN LINE NEED TO HAVE TWO SEGMENT\n";
            return false;
        }
        return true;
    }
public:

    int perimeter()
    {
        if (!check())
            return -1;
        length();
    }
    int square()
    {
        if (!check())
            return -1;
        int s=0;
        for (int i=0; i<size_dot-1; i++)
            s+=arr_dot[i].get_x()*arr_dot[i+1].get_y();
        s+=arr_dot[size_dot-1].get_x()*arr_dot[0].get_y();
        for (int i=0; i<size_dot-1; i++)
            s-=arr_dot[i+1].get_x()*arr_dot[i].get_y();
        s-=arr_dot[0].get_x()*arr_dot[size_dot-1].get_y();
        s/=2;
        return s<0 ? s*=-1 : s;
    } 

};
int main()
{
    dot arr[4];
    arr[0].set_O(2, 2);
    arr[1].set_O(2, 4);
    arr[2].set_O(4, 4);
    arr[3].set_O(4, 2);
    broken_line line(arr);
    cout << line.length();
    return 0;
}