#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
struct stack_node{ 
    int data;
    stack_node* next;
};
class Stack 
{
private:
    stack_node* top; 
public:
    Stack() 
    {
        top = NULL;
    }
    void push (int new_node)
    {
        stack_node *node = new stack_node; 
        node->next = top;
        node->data = new_node;
        top = node;
    }
    int pop() {
        int result = top->data; 	
        stack_node *del = top;
        top = top->next; 
        delete del; 
        return result;
    }
};
 int main()
{
    Stack stack;
    ifstream fin ("stack.in.txt");
    ofstream fout ("stack.out.txt");
    int n, j=0;
    fin >> n;
    char sing;
    for (int i=0; i<n; i++)
    {
        fin >> sing;
        if(sing == '+')
        {
            fin >> j;
            stack.push(j);
        }
        else
        {
            fout << stack.pop() << endl;
        }
    }
    return 0;
}