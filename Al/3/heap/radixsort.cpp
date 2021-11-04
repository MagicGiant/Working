#include <iostream>
#include <vector>

using namespace std;

void radix_start() {

    vector <string> source;
    source.push_back("bbb");
    source.push_back("aba");
    source.push_back("baa");
    source.push_back("bac");
    source.push_back("cab");
    source.push_back("aaa");

    vector <int> a(source.size());
    for (int i = 0; i < source.size(); i++)
        a[i] = i;

    int str_len = 3;

    vector <vector <int> > radix(256);

    for (int index = str_len - 1; index >= 0; index--) {
        for (int i = 0; i < radix.size(); i++)
            radix[i].clear();

        for (int i = 0; i < a.size(); i++) {
            char c = source[a[i]][index];
            radix[c].push_back(i);
        }

        vector <int> buffer;
        for (int i = 0; i < radix.size(); i++)
            for (int j = 0; j < radix[i].size(); j++) {
                int target_index = radix[i][j];
                buffer.push_back(a[target_index]);
            }
        a = buffer;
    }
    for (int i = 0; i < a.size(); i++)
        cout << source[a[i]] << "\n";
}
