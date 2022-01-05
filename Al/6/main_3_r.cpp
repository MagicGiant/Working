#include <vector>
#include <fstream>

using namespace std;
 
struct Element 
{
    string key; 
    string value; 
    Element* next; 
    Element* prev; 
    Element* next_queue;
};
 
class LinkedMap
{
private:
    Element* list;
public:
    LinkedMap() 
    {
        list = new Element();
        list->value = list->key = ""; 
        list->next_queue = NULL; 
    }
    void Insert(string& key, string& value, Element* head) 
    {
        Element* new_el = Search(key); 
        if (Search(key) == NULL)
        {
            new_el = new Element; 
            new_el->key = key; 
            new_el->value = value; 
            new_el->next_queue = list->next_queue; 
            list->next_queue = new_el;
            Element* tail = head->prev; 
            tail->next = new_el; 
            head->prev = new_el;
            new_el->next = head; 
            new_el->prev = tail; 
        }
        else 
            new_el->value = value; 
    }
    void Deleted(string key) 
    {
        Element* cur_el = list; 
 
        while (cur_el->next_queue != NULL) 
        {
            if (cur_el->next_queue->key == key) 
            {
                Element* del = cur_el->next_queue;
                cur_el->next_queue = cur_el->next_queue->next_queue;
                Element* prev_el = del->prev, * next_el = del->next;
                del->prev->next = next_el; 
                del->next->prev = prev_el; 
                delete del;
                break;
            }
            else
                cur_el = cur_el->next_queue; 
        }
    }
    Element* Search(string& key) 
    {
        Element* cur_el = list; 
        while (cur_el->next_queue != NULL) 
        {
            if (cur_el->next_queue->key == key) 
                return cur_el->next_queue;
            else
                cur_el = cur_el->next_queue; 
        }
        return NULL; 
    }
};
 
class UpgradeLinkedMap 
{
private:
    LinkedMap hash_table[100001];
    Element* head;
public:
    UpgradeLinkedMap() 
    {
        head = new Element;
        head->next = head->prev = head;
        head->value = head->key = "HEAD"; 
    }
    int func_hash(string key) 
    {
        int hash = 0; 
        int pow = 1; 

int k = 31; 
        for (int i = 0; i < key.length(); i++)
        {
            hash += (key[i] - 'A') * pow;
            pow *= k;
        }
        return abs(hash % 100001);
    }
    void put(string key, string value) 
    {
        int hash = func_hash(key);
        hash_table[hash].Insert(key, value, head);
    }
    string get(string key) 
    {
        int hash = func_hash(key);
        Element* result = hash_table[hash].Search(key); 
        if (result == NULL) 
            return "none"; 
        else
            return result->value;
    }
    void deleted(string key) 
    {
        int hash = func_hash(key);
        hash_table[hash].Deleted(key);
    }
    string next(string key)
    {
        int hash = func_hash(key);
        Element* result = hash_table[hash].Search(key); 
        if (result == NULL || result->next == head) 
            return "none"; 
        else 
            return result->next->value;
    }
    string prev(string key) 
    {
        int hash = func_hash(key);
        Element* result = hash_table[hash].Search(key); 
        if (result == NULL || result->prev == head) 
            return "none";
        else 
            return result->prev->value; 
    }
};
 
int main()
{
    ifstream fin("linkedmap.in");
    ofstream fout("linkedmap.out");
    string key;
    string value;
    string com;
    UpgradeLinkedMap map;
    while (fin >> com)
    {
        if (com == "put")
        {
            fin >> key >> value;
            map.put(key, value);
        }
        else if (com == "delete")
        {
            fin >> key;
            map.deleted(key);
        }
        else if (com == "get")
        {
            fin >> key;
            fout << map.get(key) << endl;
        }
        else if (com == "next")
        {
            fin >> key;
            fout << map.next(key) << endl;
        }
        else if (com == "prev")
        {
            fin >> key;
            fout << map.prev(key) << endl;
        }
    }
    return 0;
}