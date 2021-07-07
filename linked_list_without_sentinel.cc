#include <iostream>
using namespace std;
class Node
{
    friend class LinkedList;

public:
    Node() : prev(nullptr), next(nullptr), val(0) {}
    Node(double d) : prev(nullptr), next(nullptr), val(d) {}
    double value() { return val; }

private:
    Node *prev;
    Node *next;
    double val;
};

class LinkedList
{
public:
    LinkedList() : head(nullptr) {}
    void insert(double d)
    {
        auto curr = new Node(d);
        curr->next = head;
        if (head)
            head->prev = curr;
        head = curr;
        curr->prev = nullptr;
    }
    Node *search(double d)
    {
        auto x = head;
        while (x != nullptr && x->val != d)
            x = x->next;
        return x;
    }

    void deleting(Node *n)
    {
        if (n->prev)
            n->prev->next = n->next;
        else
            head = n->next;
        if (n->next)
            n->next->prev = n->prev;
    }

    void deleting(double d)
    {
        auto x = search(d);
        if (x)
            deleting(x);
    }

    void print_list()
    {
        auto x = head;
        while (x != nullptr)
        {
            cout << x->val << " ";
            x = x->next;
        }
        cout << endl;
    }

private:
    Node *head;
};

int main()
{
    LinkedList ll;
    ll.insert(123);
    ll.insert(1234);
    ll.insert(23123);
    ll.insert(5123);
    ll.print_list();
    ll.deleting(1234);
    ll.print_list();
    
    return 0;
}