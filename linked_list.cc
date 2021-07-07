#include <iostream>

using namespace std;

class ListNode
{
    friend class LinkedList;

public:
    ListNode() : prev(nullptr), next(nullptr), val(0), is_sentinal(true) {}
    ListNode(const double d) : prev(nullptr), next(nullptr), val(d), is_sentinal(false) {}
    bool sentinel() { return this->is_sentinal; }

private:
    ListNode *prev;
    ListNode *next;
    double val;
    bool is_sentinal;
};

class LinkedList
{
public:
    LinkedList() : sentinal(new ListNode())
    {
        sentinal->prev = sentinal;
        sentinal->next = sentinal;
    };

    void insertion(ListNode *ld)
    {
        ld->prev = sentinal;
        ld->next = sentinal->next;
        sentinal->next->prev = ld;
        sentinal->next = ld;
    }

    void insertion(double d)
    {
        insertion(new ListNode(d));
    }

    void deletion(ListNode *ld)
    {
        ld->prev->next = ld->next;
        ld->next->prev = ld->prev;
    }

    void deletion(double d)
    {
        auto x = searching(d);
        if (!(x->sentinel()))
            deletion(x);

        //deletion(searching(d));
    }

    ListNode *searching(double d)
    {
        auto target = this->sentinal->next;
        while (target != sentinal && (target->val) != d)
            target = target->next;
        return target;
    }

    void print_list()
    {
        auto x = sentinal->next;
        while (x != sentinal)
        {
            cout << (x->val) << " ";
            x = x->next;
        }
        cout << endl;
    }

private:
    ListNode *sentinal;
};

int main()
{
    LinkedList ll;
    for (double i = 0.1; i < 11; ++i)
        ll.insertion(new ListNode(i));

    cout << "The list is: " << endl;
    ll.print_list();

    cout << boolalpha;
    cout << "Value 1.1 is in the list? " << ll.searching(1.1)->sentinel() << endl;
    cout << "Value 2 is in the list? " << ll.searching(2)->sentinel() << endl;
    cout << noboolalpha;

    cout << "Delete the value 4.1" << endl;
    ll.deletion(4.1);
    cout << "The list now is: " << endl;
    ll.print_list();

    cout << "Delete the value 4.1 again" << endl;
    ll.deletion(4.1);
    cout << "The list now is: " << endl;
    ll.print_list();

    cout << "Insert the value 4.1" << endl;
    ll.insertion(4.1);
    cout << "The list now is: " << endl;
    ll.print_list();

    return 0;
}