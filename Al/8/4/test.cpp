#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
class graph
{
private:
    vector <int> dots;
    vector <vector <int>> edge;
    int eIt=0;
public:
    graph (int n, int m)
    {
        dots.resize(n,0);
        edge.assign(m, vector<int>(2));
    }
    void push (int a, int b)
    {
        edge[eIt][0]=a;
        edge[eIt][1]=b;
        eIt++;
    }
    void get_components ()
    {
        for (int i = 1; i < edge.size(); i++)
        {
            for (int i = 0; i < edge.size()-1; i++)
            {
                
            }  
        }
        
    }
};
int main()
{
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");

    return 0;
}