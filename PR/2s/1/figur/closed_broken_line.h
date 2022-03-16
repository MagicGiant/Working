#include "broken_line.h"
#include <iostream>

class closed_broken_line: public broken_line
{
protected:
    using broken_line :: set_dot;
    using broken_line :: length;
    virtual bool rule ()
    {
        if (arr_dot_.size()<4)
        {
            std::cout << "*ERROR! THIS BROKEN LINE NEED TO HAVE THREE SEGMENT\n";
            return false;
        }
        if (arr_dot_[0].get_x()!=arr_dot_[arr_dot_.size()-1].get_x() || arr_dot_[0].get_y()!=arr_dot_[arr_dot_.size()-1].get_y())
        {
            std::cout<<"*ERROR! THIS BROKEN LINE NOT CLOSED\n";
            return false;
        }
        return true;
    }
public:
    closed_broken_line ()
    {}
    closed_broken_line (std::vector <dot> &arr_dot)
    {
        arr_dot_=arr_dot;
    }
    closed_broken_line (closed_broken_line &other)
    {
        arr_dot_=other.arr_dot_;
    }
    closed_broken_line (broken_line &other)
    {
        arr_dot_=other.get_arr();
    }
    void operator = (closed_broken_line &other)
    {
        arr_dot_=other.arr_dot_;
    }
    int perimeter()
    {
        if (!rule())
            return -1;
        length();
    }
};