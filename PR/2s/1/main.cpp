#include <string>
#include <iostream>
#include <stdlib.h>
#include <math.h>
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
    dot ()
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
    {}
    void set_dot  (dot *ur_arr_dot)
    {
        arr_dot=ur_arr_dot;
        size_dot=sizeof(arr_dot)/sizeof(*arr_dot);
        exit(1);
    }
    double  length()
    {
        int sum_pow=0;
        for (int i=0; i<(sizeof(arr_dot)/sizeof(*arr_dot))-1; i++)
        {
            sum_pow+=sqrt(pow(arr_dot[i].get_x()-arr_dot[i+1].get_x(), 2)-pow(arr_dot[i].get_y()-arr_dot[i+1].get_y(), 2));
        }
        return sum_pow;
    }
};
class closed_broken_line: public broken_line
{
private:
    void check_closed ()
    {
        if (arr_dot[0].get_x()==arr_dot[sizeof(arr_dot)/sizeof(*arr_dot)].get_x() && arr_dot[])
    }
public:

};
int main()
{

    return 0;
}