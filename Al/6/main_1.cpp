#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

const int N = 1e4;


class ListCollection
{
private:
    struct Node
    {
        Node *next = NULL;
        int value;
        Node(int value)
        {
            this->value = value;
        }
    };

    Node *head = NULL;
public:
    bool exists(int value)
    {
        Node *current = head;
        while (current && current->value != value)
            current = current->next;
        return current ? true : false;
    }

    void add(int value)
    {
        if (exists(value))
            return;
        if (!head)
        {
            head = new Node(value);
            return;
        }

        Node *current = head;
        while (current->next)
            current = current->next;
        current->next = new Node(value);
    }

    void remove(int value)
    {
        if (!exists(value))
            return;

        if (head->value == value)
        {
            Node *forRemove = head;
            head = head->next;
            delete forRemove;
            return;
        }

        Node *current = head;
        while (current->next->value != value)
            current = current->next;

        Node *forRemove = current->next;
        current->next = current->next->next;
        delete forRemove;
    }
};




int getHash(int source)
{
    return abs(source) % N;
}


class HashMap
{
private:
    ListCollection data[N];

public:
    bool exists(int value)
    {
        int h = getHash(value);
        return data[h].exists(value);
    }

    void add(int value)
    {
        int h = getHash(value);
        data[h].add(value);
    }

    void remove(int value)
    {
        int h = getHash(value);
        data[h].remove(value);
    }
};

int main()
{
    ifstream fin ("set.in");
    ofstream fout ("set.out");
    HashMap h;
    while (!fin.eof())
    {
        string action;
        int value;
        fin >> action >> value;
        if (action == "exists")
            if (h.exists(value))
                fout << "true\n";
            else
                fout << "false\n";
        if (action == "insert")
            h.add(value);
        if (action == "delete")
            h.remove(value);
    }
}
