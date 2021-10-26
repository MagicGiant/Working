#include <iostream>
#include <fstream>
using namespace std;
struct struct_node
{
    int data;
    struct_node *next;
    struct_node *prev;

    struct_node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};
class queue
{
private:
    struct_node *head;
    struct_node *teil;
public:
    queue ()
    {
        head=NULL;
        teil=NULL;
    }
    void push (int chislo)
    {
        struct_node *ch = new struct_node(chislo);
        if (head==NULL && teil==NULL)
        {
            head = ch;
            teil = ch;
            teil -> prev = head;
            head -> next = teil;

            // ch->prev=head;
            // ch->next=teil;
            // ch->data=chislo;
            // head=ch;
        }
        else
        {
            struct_node *currency = teil;
            if (teil == head)
            {
                head -> next = currency;
            }
            teil = ch;
            teil -> prev = currency;
            currency -> next = teil;

            // ch->next=teil;
            // ch->data=chislo;
            // new teil=ch;
        }
    }
    int pop ()
    {
        int forReturn = head -> data;

        if (head == teil)
        {
            head = NULL;
            teil = NULL;
            return forReturn;
        }
        struct_node *currency = head -> next;
        head = currency;
        delete head -> prev;

        return forReturn;
    }
};
int main()
{
    queue queue;
    ifstream fin ("queue.in");
    ofstream fout("queue.out");
    int n, chisl;
    fin >> n;
    char znak;
    for (int i=0; i<n; i++)
    {
        fin >> znak;
        if (znak=='+')
        {
            fin >> chisl;
            queue.push(chisl);
        }
        else fout << queue.pop() << endl;
    }
}