#include <iostream>
#include <vector>
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

        head=head->next;
        delete head->prev;
        cout << head-> next-> data <<endl;
        return forReturn;
    }
};
 int main()
{
    queue queue;
    queue.push(5);
    queue.push(1);
    queue.push(3);
    queue.push(4);
    queue.push(8);
    cout << queue.pop() << " " << queue.pop() << " " << queue.pop() << " " << queue.pop();
    // ifstream fin ("queue.in.txt");
    // ofstream fout("queue.out.txt");
    // int n, chisl;
    // fin >> n;
    // char znak;
    // for (int i=0; i<n; i++)
    // {
    //     fin >> znak;
    //     if (znak=='+')
    //     {
    //         fin >> chisl;
    //         queue.push(chisl);
    //     }
    //     else fout << queue.pop() << endl;
    // }
}