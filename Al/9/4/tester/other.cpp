#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

vector<int> g;
vector <int> t;

vector<int> order;
vector <bool> used;
vector <int> component;
int cnt_components = 0;

// топологическая сортировка
void dfs1(int v) 
{
    used[v] = true;
    for (int u : g[v]) 
    {
        if (!used[u]) 
            dfs1(u);
    order.push_back(v);
    }
}

// маркировка компонент сильной связности
void dfs2(int v) 
{
    component[v] = cnt_components;
    for (int u : t[v])
        if (component[u] == 0)
            dfs2(u);
}

int main()
{
    ifstream fin ("cond.in");
    ofstream fout ("condt.out");

    int n, m;

    fin >> n >> m;

    g.resize(n);
    t.resize(n);
    used.resize(n);
    component.resize(n);

    // транспонируем граф
    for (int v = 0; v < n; v++)
        for (int u : g[v])
            t[u].push_back(v);

    // запускаем топологическую сортировку
    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs1(i);

    // выделяем компоненты
    reverse(order.begin(), order.end());
    for (int v : order)
        if (component[v] == 0)
            dfs2(v);

    return 0;
}