#include "polygon.h"
class triangle: public polygon
{
private:
    virtual bool rule ()
    {
        if (size_dot_!=4)
        {
            std::cout << "*ERROR! THIS BROKEN LINE NEED TO HAVE ONLY THREE SEGMENT\n";
            return false;
        }
        if (arr_dot_[0].get_x()!=arr_dot_[size_dot_-1].get_x() || arr_dot_[0].get_y()!=arr_dot_[size_dot_-1].get_y())
        {
            std::cout<<"*ERROR! THIS BROKEN LINE NOT CLOSED\n";
            return false;
        }
        return true;
    }
public:
    triangle()
    {}
    triangle (std::vector <dot> &arr_dot)
    {
        arr_dot_=arr_dot;
        size_dot_=arr_dot.size();
    }
    triangle (closed_broken_line &other)
    {
        arr_dot_=other.get_arr();
        size_dot_=other.size_dot_;
    }
    triangle (broken_line &other)
    {
        arr_dot_=other.get_arr();
        size_dot_=other.size_dot_;
    }
    triangle (polygon &other)
    {
        arr_dot_=other.get_arr();
        size_dot_=other.size_dot_;
    }
    triangle (triangle &other)
    {
        arr_dot_=other.get_arr();
        size_dot_=other.size_dot_;
    }
    void operator = (triangle &other)
    {
        arr_dot_=other.get_arr();
        size_dot_=other.size_dot_;
    }
};
class trapezoid: public polygon
{
private:
    bool parallel (dot &a1, dot &a2, dot &b1, dot &b2)
    {
        double k1 = (a2.get_y()-a1.get_y())/(a2.get_x()-a1.get_x());
        double k2 = (b2.get_y()-b1.get_y())/(b2.get_x()-b1.get_x());
        if (k1==k2)
            return true;
        return false; 
    }
    virtual bool rule ()
    {
        if (size_dot_<4)
        {
            std::cout << "*ERROR! THIS BROKEN LINE NEED TO HAVE THREE SEGMENT\n";
            return false;
        }
        if (arr_dot_[0].get_x()!=arr_dot_[size_dot_-1].get_x() || arr_dot_[0].get_y()!=arr_dot_[size_dot_-1].get_y())
        {
            std::cout<<"*ERROR! THIS BROKEN LINE NOT CLOSED\n";
            return false;
        }

        bool par1, par2;
        par1=parallel(arr_dot_[0], arr_dot_[1], arr_dot_[2], arr_dot_[3]);
        par2=parallel(arr_dot_[0], arr_dot_[3], arr_dot_[1], arr_dot_[2]);
        if (par1 && par2 || !par1 && !par2)
        {
            std::cout<<"*ERROR! TRAPESOID NEED TO HAVE TWO PARALLEL SEGMENT\n";
            return false;
        }

        return true;
    }
public:
    trapezoid()
    {}
    trapezoid (std::vector <dot> &arr_dot)
    {
        std::cout << "!!!!!";
        arr_dot_=arr_dot;
        size_dot_=arr_dot.size();
    }
    trapezoid (closed_broken_line &other)
    {
        arr_dot_=other.get_arr();
        size_dot_=other.size_dot_;
    }
    trapezoid (broken_line &other)
    {
        arr_dot_=other.get_arr();
        size_dot_=other.size_dot_;
    }
    trapezoid (polygon &other)
    {
        arr_dot_=other.get_arr();
        size_dot_=other.size_dot_;
    }
    trapezoid (trapezoid &other)
    {
        arr_dot_=other.get_arr();
        size_dot_=other.size_dot_;
    }
    void operator = (trapezoid &other)
    {
        arr_dot_=other.get_arr();
        size_dot_=other.size_dot_;
    }
};