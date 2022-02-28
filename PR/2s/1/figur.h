#include "poligon.h"
class triangle: public polygon
{
private:
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
        if (size_dot_>4)
            for (int i=2; i<size_dot_-1; i++)
            {
                for (int j=0; j<i; j++)
                {
                    if (intersection(arr_dot_[i], arr_dot_[i+1], arr_dot_[j], arr_dot_[j+1]))
                    {
                        std::cout<<"*ERROR! IT IS NOT CLOSED BROKEN LINE.\n";
                        std::cout<<"\t\tTHIS FIGUR HAVE INTERSACTION SEGMENT";
                        return false;
                    }
                }

            }
        return true;
    }
public:
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
    int square()
    {
        if (!rule())
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