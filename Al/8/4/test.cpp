#include <iostream>
#include <vector>

using namespace std;
int main()
{
    vector < vector<int>> arr (10);
    arr[1].resize(arr[1].size()+2);
    cout << arr[1].size();
    return 0;
}