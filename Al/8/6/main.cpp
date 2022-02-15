#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct d2
{
    int x;
    int y;
};
int main()
{
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");

    int n, m;
    fin >> n >> m;
    d2 start;

    vector <vector <char>> matrix(n, vector <char> (m));
    vector <vector <string>> min_path (n, vector <string> (m));

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
        {
            fin >> matrix[i][j];
            if (matrix[i][j]=='S')
            {
                start.y=i;
                start.x=j;
            }
        }
    queue <d2> queue_;
    queue_.push(start);
    string finish_path;

    while (!queue_.empty())
    {
        d2 O=queue_.front();
        queue_.pop();
        matrix[O.y][O.x]='#';
        if (O.x-1>=0 && matrix[O.y][O.x-1]!='#')
        {
            d2 new_O=O;
            new_O.x=O.x-1;
            min_path[new_O.y][new_O.x]=min_path[O.y][O.x]+'L';
            if (matrix[new_O.y][new_O.x]=='T')
            {
                finish_path=min_path[new_O.y][new_O.x];
                break;
            }
            matrix[new_O.y][new_O.x]='#';
            queue_.push(new_O);
        }
        if (O.y-1>=0 && matrix[O.y-1][O.x]!='#')
        {
            d2 new_O=O;
            new_O.y=O.y-1;
            min_path[new_O.y][new_O.x]=min_path[O.y][O.x]+'U';
            if (matrix[new_O.y][new_O.x]=='T')
            {
                finish_path=min_path[new_O.y][new_O.x];
                break;
            }
            matrix[new_O.y][new_O.x]='#';
            queue_.push(new_O);
        }
        if (O.x+1<m && matrix[O.y][O.x+1]!='#')
        {
            d2 new_O=O;
            new_O.x=O.x+1;
            min_path[new_O.y][new_O.x]=min_path[O.y][O.x]+'R';
            if (matrix[new_O.y][new_O.x]=='T')
            {
                finish_path=min_path[new_O.y][new_O.x];
                break;
            }
            matrix[new_O.y][new_O.x]='#';
            queue_.push(new_O);
        }
        if (O.y+1<n && matrix[O.y+1][O.x]!='#')
        {
            d2 new_O=O;
            new_O.y=O.y+1;
            min_path[new_O.y][new_O.x]=min_path[O.y][O.x]+'D';
            if (matrix[new_O.y][new_O.x]=='T')
            {
                finish_path=min_path[new_O.y][new_O.x];
                break;
            }
            matrix[new_O.y][new_O.x]='#';
            queue_.push(new_O);
        }
    }
    if (finish_path.size()==0)
        fout << -1;
    else
    {
        fout << finish_path.size() << endl;
        fout << finish_path;
    }
    return 0;
}