#include <iostream>
#include <vector>
using namespace std;

class dot
{
private:
    int x=0, y=0;
public:
    dot (int x, int y)
    {
        this->x=x;
        this->y=y;
    }
    dot (int &dot)
    {
        this->x=dot->x;

    }
    void set_O (int x, int y)
    {
        this->x=x;
        this->y=y;
    }

}
int main()
{
    
    return 0;
}