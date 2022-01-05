#include <fstream>
#include <vector>
 
using namespace std;
 
int multi_map_size = 10001;
int set_size = 101;
 
struct Set
{
    string key;
    vector < vector <string>> values;
    Set()
    {
        values.resize(set_size);
    }
};
struct MultiMap
{
    vector< vector<Set> > set;
    MultiMap()
    {
        set.resize(multi_map_size);
    }
};
 
MultiMap multimap;
 
 
int func_hash(string key, int vector_size)
{
    const int k = 31;
    int hash_code = 0;
    for (int i = 0; i < key.length(); i++)
    {
        hash_code = hash_code * k % vector_size;
        hash_code += (key[i] - 'A' + 1);
        hash_code %= vector_size;
    }
    return hash_code;
}
 
void put(const string& key, const string& value)
{
    int hash_key = func_hash(key, multi_map_size);
    for (auto& i : multimap.set[hash_key])
    {
        if (i.key == key)
        {
            int hash_value = func_hash(value, set_size);
            for (const auto& j : i.values[hash_value])
                if (j == value)
                    return;
            i.values[hash_value].push_back(value);
            return;
        }
    }
 
    Set* new_set = new Set;
    new_set->key = key;
    new_set->values[func_hash(value, set_size)].push_back(value);
    multimap.set[hash_key].push_back(*new_set);
    delete new_set;
}
 
void deleted(const string& key, const string& value)
{
    int hash_key = func_hash(key, multi_map_size);
    for (auto& i : multimap.set[hash_key])
    {
        if (i.key == key)
        {
            int hash_value = func_hash(value, set_size);
            for (int j = 0; j < i.values[hash_value].size(); j++)
            {
                if (i.values[hash_value][j] == value)
                {
                    i.values[hash_value].erase(i.values[hash_value].begin() + j);
                    return;
                }
            }
        }
    }
}
 
void deleteAll(const string& key)
{
    int hash_key = func_hash(key, multi_map_size);
    for (auto& i : multimap.set[hash_key])
    {
        if (i.key == key)
        {
            for (auto& j : i.values)
            {
                while (!j.empty())
                    j.pop_back();
            }
            return;
        }
    }
}
 
vector<string> get(const string& key)
{
    vector<string> answer;
    int hash_key = func_hash(key, multi_map_size);
    for (auto& i : multimap.set[hash_key])
    {
        if (i.key == key)
        {
            for (auto& j : i.values)
                for (const auto& k : j)
                    answer.push_back(k);
            return answer;
        }
    }
    return answer;
}
 
int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("multimap.in");
    fout.open("multimap.out");
    while (!fin.eof())
    {
        string com;
        fin >> com;
        if (com == "put")
        {
            string key, value;
            fin >> key >> value;
            put(key, value);
        }
        else if (com == "delete")
        {
            string key, value;
            fin >> key >> value;
            deleted(key, value);
        }
        else if (com == "deleteall")
        {
            string key;
            fin >> key;
            deleteAll(key);
        }
        else if (com == "get")
        {
            string key;
            fin >> key;
            vector<string> anw = get(key);
            fout << anw.size() << ' ';
            for (const string& i : anw)
                fout << i << ' ';
            fout << "\n";
        }
    }
    fin.close();
    fout.close();
    return 0;
}