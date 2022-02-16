#include <string>
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>

using namespace std;
class dot
{
protected:
    int x_=0, y_=0;
public:
    dot ()
    {}
    dot (int x, int y)
    : x_(x)
    , y_(y)
    {}
    dot (const dot &other)
    : x_(other.x_)
    , y_(other.y_)
    {}
    void operator = (const dot &other)
    {
        x_=other.x_;
        y_=other.y_;
    }
    void set_O (int x, int y)
    {
        x_=x;
        y_=y;
    }
    int get_x ()
    {
        return x_;
    }
    int get_y ()
    {
        return y_;
    }

};
class broken_line: public dot
{
protected:
    using dot :: get_x;
    using dot :: get_y;
    using dot :: set_O;

    vector <dot> arr_dot_;
public:
    int size_dot_=0;
    broken_line()
    {}
    broken_line (vector <dot> &arr_dot)
    : arr_dot_(arr_dot)
    , size_dot_(arr_dot.size())
    {}
    broken_line (const broken_line &other)
    : arr_dot_(other.arr_dot_)
    , size_dot_(other.size_dot_)
    {}
    void operator = (const broken_line &other)
    {
        arr_dot_=other.arr_dot_;
        size_dot_=other.size_dot_;
    }
    void set_dot  (vector <dot> &arr_dot)
    {
        arr_dot_=arr_dot;
        size_dot_=arr_dot_.size();
    }
    double  length()
    {
        double sum_pow=0;
        for (int i=0; i<size_dot_-1; i++)
        {
            sum_pow+=sqrt(abs(pow(arr_dot_[i].get_x()-arr_dot_[i+1].get_x(), 2)-pow(arr_dot_[i].get_y()-arr_dot_[i+1].get_y(), 2)));
        }
        return sum_pow;
    }
    vector <dot> &get_arr ()
    {
        return arr_dot_;
    }
};
class closed_broken_line: public broken_line
{
protected:
    using broken_line :: set_dot;
    using broken_line :: length;
    bool check ()
    {
        if (arr_dot_[0].get_x()!=arr_dot_[size_dot_-1].get_x() || arr_dot_[0].get_y()!=arr_dot_[size_dot_-1].get_y())
            {
                cout<<"*ERROR! THIS BROKEN LINE NOT CLOSED\n";
                return false;
            }
        if (size_dot_<3)
        {
            cout<<"*ERROR! THIS BROKEN LINE NEED TO HAVE TWO SEGMENT\n";
            return false;
        }
        return true;
    }
public:
    closed_broken_line ()
    {}
    closed_broken_line (vector <dot> &arr_dot)
    {
        arr_dot_=arr_dot;
        size_dot_=arr_dot.size();
    }
    closed_broken_line (closed_broken_line &other)
    {
        arr_dot_=other.arr_dot_;
        size_dot_=other.size_dot_;
    }
    closed_broken_line (broken_line &other)
    {
        arr_dot_=other.get_arr();
        size_dot_=other.size_dot_;
    }
    void operator = (closed_broken_line &other)
    {
        arr_dot_=other.arr_dot_;
        size_dot_=other.size_dot_;
    }
    int perimeter()
    {
        if (!check())
            return -1;
        length();
    }
};
class polygon :public closed_broken_line
{
public:
    polygon (vector <dot> &arr_dot)
    {
        arr_dot_=arr_dot;
        size_dot_=arr_dot.size();
    }
    polygon (closed_broken_line &other)
    {
        arr_dot_=other.get_arr();
        size_dot_=other.size_dot_;
    }
    polygon (broken_line &other)
    {
        arr_dot_=other.get_arr();
        size_dot_=other.size_dot_;
    }
    polygon (polygon &other)
    {
        arr_dot_=other.arr_dot_;
        size_dot_=other.size_dot_;
    }
    void operator = (closed_broken_line &other)
    {
        arr_dot_=other.get_arr();
        size_dot_=other.size_dot_;
    }
    int square()
    {
        if (!check())
            return -1;
        int s=0;
        for (int i=0; i<size_dot_-1; i++)
            s+=arr_dot_[i].get_x()*arr_dot_[i+1].get_y();
        s+=arr_dot_[size_dot_-1].get_x()*arr_dot_[0].get_y();
        for (int i=0; i<size_dot_-1; i++)
            s-=arr_dot_[i+1].get_x()*arr_dot_[i].get_y();
        s-=arr_dot_[0].get_x()*arr_dot_[size_dot_-1].get_y();
        s/=2;
        return s<0 ? s*=-1 : s;
    } 
};
class triangle: public polygon
{
private:
    
}
int main()
{
    vector <dot> arr(5);
    arr[0].set_O(2, 2);
    arr[1].set_O(2, 4);
    arr[2].set_O(4, 4);
    arr[3].set_O(4, 2);
    arr[4].set_O(2, 2);
    broken_line line (arr);
    closed_broken_line cline(line);
    cout << cline.perimeter();
    return 0;
}