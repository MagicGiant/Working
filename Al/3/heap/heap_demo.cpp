#include <time.h>
#include <vector>
#include <cstdlib>
#include <iostream>
#include "radixsort.hpp"

using namespace std;

struct EasyHeap {
    vector <int> data;
    const int EMPTY = 1e9;

    int siftUp(int index) {
        if (index == 0)
            return index;

        int parent_index = (index - 1) / 2;
        if (data[index] < data[parent_index]) {
            swap(data[index], data[parent_index]);
            return siftUp(parent_index);
        }

        return index;
    }

    bool exists(int index) {
        return index < data.size();
    }

    void siftDown(int index) {
        int child1 = index * 2 + 1, child2 = index * 2 + 2;

        if (!exists(child1))
            return;

        if (!exists(child2)) {
            if (data[child1] < data[index]) {
                swap(data[index], data[child1]);
                siftDown(child1);
            }
            return;
        }

        int target_child = data[child1] < data[child2] ? child1 : child2;
        if (data[target_child] < data[index]) {
            swap(data[target_child], data[index]);
            siftDown(target_child);
        }
    }

    int add(int value) {
        data.push_back(value);
        return siftUp(data.size() - 1);
    }

    int extrctMin() {
        if (data.empty()) {
            return EMPTY;
        }

        int last = data.size() - 1;
        int result = data[0];
        swap(data[0], data[last]);
        data.pop_back();
        if (!data.empty())
            siftDown(0);

        return result;
    }

    void change(int index, int value) {
        int last = data.size() - 1;
        swap(data[index], data[last]);
        data.pop_back();
        siftDown(index);
        add(value);
    }
};

void heap_start() {
    srand(time(0));
    int source[] = {2, 1, 6, 3, 4, 8, 9};
    vector <int> values(source, source + sizeof(source) / 4);

    vector <int> additions;
    EasyHeap h;

    for (int i = 0; i < values.size(); i++)
        additions.push_back(h.add(values[i]));

    h.change(additions[2], 15);

    while(!h.data.empty())
        cout << h.extrctMin() << " ";
}
