#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;


const int N = 1e6;


int getHash(string s)
{
    int res = 0;
    for (int i = 0; i < s.size(); i++)
        res += (char)s[i]*pow(2,i);
    return res % N;
}

class ListCollection
{
private:
    struct Node
    {
        Node *next = NULL;
        string value, key;
        Node(string key, string value)
        {
            this->key = key;
            this->value = value;
        }
    };

    Node *head = NULL;
public:
    vector<string> get(string key)
    {
        vector<string> result;
        Node *current = head;
        while (current)
        {
            if (current->key == key)
                result.push_back(current->value);
            current = current->next;
        }
        return result;
    }

    void add(string key, string value)
    {
        if (!head)
        {
            head = new Node(key, value);
            return;
        }

        Node *current = head;
        while (current->next)
            current = current->next;
        current->next = new Node(key, value);
    }

    void remove(string key)
    {
        while (head && head->key == key)
        {
            Node *forRemove = head;
            head = head->next;
            delete forRemove;
        }

        Node *current = head;
        while (current && current->next)
        {
            if (current->next->key == key)
            {
                Node *forRemove = current->next;
                current->next = current->next->next;
                delete forRemove;
            }
            current = current->next;
        }
    }

    void remove(string key, string value)
    {
        while (head && head->key == key && head->value == value)
        {
            Node *forRemove = head;
            head = head->next;
            delete forRemove;
        }

        Node *current = head;
        while (current && current->next)
        {
            if (current->next->key == key && current->next->value == value)
            {
                Node *forRemove = current->next;
                current->next = current->next->next;
                delete forRemove;
            }
            current = current->next;
        }
    }
};


class HashMap
{
private:
    ListCollection data[N];

public:
    vector<string> get(string key)
    {
        int h = getHash(key);
        return data[h].get(key);
    }

    void put(string key, string value)
    {
        int h = getHash(key);
        data[h].remove(key, value);
        data[h].add(key, value);
    }

    void remove(string key)
    {
        int h = getHash(key);
        data[h].remove(key);
    }

    void remove(string key, string value)
    {
        int h = getHash(key);
        data[h].remove(key, value);
    }
};

int main()
{
    ifstream fin ("multimap.in");
    ofstream fout ("multimap.out");
    ios_base::sync_with_stdio(false);
    HashMap h;
    while (!fin.eof())
    {
        string action, key, value;
        fin >> action;
        if (action == "put")
        {
            fin >> key >> value;
            h.put(key, value);
        }
        if (action == "delete")
        {
            fin >> key >> value;
            h.remove(key, value);
        }
        if (action == "deleteall")
        {
            fin >> key;
            h.remove(key);
        }
        if (action == "get")
        {
            fin >> key;
            vector<string> res = h.get(key);
            fout << res.size() << " ";
            for (int i = 0; i < res.size(); i++)
                fout << res[i] << " ";
            fout << "\n";
        }
    }
}
