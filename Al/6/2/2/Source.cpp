#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;


ifstream fin("map.in");
ofstream fout("map.out");

const int n = 520;

int translate(string s)
{
	int key=0;
	for (int i = 0; i < s.size(); i++)
		key += s[i]-'a';
	return key;
}

struct element
{
	string data;
	element* next;
};
class cash
{
private:
	element arr[n];
public:

	cash()
	{
		for (int i = 0; i < n; i++)
		{
			arr[i].data = "@";
			arr[i].next = nullptr;
		}
	}

	void insert (string s, string key)
	{
		key += s;
		int i = translate(s);
		if (arr[i].data != "@" && arr[i].data != key)
		{
			element* new_node = new element();
			new_node->data = key;
			new_node->next = nullptr;
			element* currentNode = &arr[i];
			while (currentNode->next)
			{
				currentNode = currentNode->next;
				if (currentNode->data == key)
					return;
			}
			currentNode->next = new_node;
		}
		else
			arr[i].data = key;
	}
	void del(string s, string key)
	{
		key += s;
		int i = translate(s);
		if (arr[i].data == key)
			arr[i].data = "@";
		else
		{
			element* currentNode = &arr[i];
			while (currentNode->next)
			{
				if (currentNode->next->data == key)
				{
					element* forRemove = currentNode->next;
					currentNode->next = currentNode->next->next;
					delete forRemove;
					return;
				}
				currentNode = currentNode->next;
			}
		}
	}
	void exists(string s, string key)
	{
		key += s;
		int i = translate(s);
		element* currentNode = &arr[i];
		while (currentNode)
		{
			if (currentNode->data == key)
			{
				fout << "true" << endl;
				return;
			}
			currentNode = currentNode->next;
		}
		fout << "false" << endl;
	}
	void vivod(int i)
	{
		element* currentNode = &arr[i];
		while (currentNode)
		{
			if (currentNode->data != "@")
				fout << currentNode->data << endl;
			currentNode = currentNode->next;
		}
	}
};

void main()
{
	cash cash;

	string command, code, key;

	while (fin >> command && fin >> code && fin >> key)
		if (command == "insert")
			cash.insert(key);
		else if (command == "exists")
			cash.exists(key);
		else if (command == "delete")
			cash.del(key);
		else if (command == "v")
			cash.vivod(key);
}