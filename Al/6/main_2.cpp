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
    bool exists(string key)
    {
        Node *current = head;
        while (current && current->key != key)
            current = current->next;
        return current ? true : false;
    }

    string get(string key)
    {
        if (!exists(key))
            return "";
        Node *current = head;
        while (current->key != key)
            current = current->next;
        return current->value;
    }

    void add(string key, string value)
    {
        if (exists(key))
            return;
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
        if (!exists(key))
            return;

        if (head->key == key)
        {
            Node *forRemove = head;
            head = head->next;
            delete forRemove;
            return;
        }

        Node *current = head;
        while (current->next->key != key)
            current = current->next;

        Node *forRemove = current->next;
        current->next = current->next->next;
        delete forRemove;
    }

    void put(string key, string value)
    {
        remove(key);
        add(key, value);
    }
};


class HashMap
{
private:
    ListCollection data[N];

public:
    string get(string key)
    {
        int h = getHash(key);
        return data[h].get(key);
    }

    void put(string key, string value)
    {
        int h = getHash(key);
        data[h].put(key, value);
    }

    void remove(string key)
    {
        int h = getHash(key);
        data[h].remove(key);
    }
};

int main()
{
    ifstream fin ("map.in");
    ofstream fout ("map.out");
    // ios_base::sync_with_stdio(false);
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
            fin >> key;
            h.remove(key);
        }
        if (action == "get")
        {
            fin >> key;
            string result = h.get(key);
            if (result == "")
                fout << "none\n";
            else
                fout << result << endl;
        }
    }
}
