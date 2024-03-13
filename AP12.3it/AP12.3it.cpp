#include <iostream>

using namespace std;

typedef int Info;
struct Elem
{
    Elem* next,
        * prev;
    Info info;
};

void LAdd(Elem*& first, Elem*& last, Info value)
{
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->next = NULL;
    if (last != NULL)
        last->next = tmp;
    tmp->prev = last;
    last = tmp;
    if (first == NULL)
        first = tmp;
}

bool LisSubset(Elem* first1, Elem* first2)
{
    while (first2 != NULL)
    {
        bool found = false;
        Elem* tmp = first1;
        while (tmp != NULL && found == false)
        {
            if (tmp->info == first2->info)
                found = true;
            tmp = tmp->next;
        }
        if (found == false)
            return false;
        first2 = first2->next;
    }
    return true;
}

void LPrint(Elem* first)
{
    while (first != NULL)
    {
        cout << first->info << "  ";
        first = first->next;
    }
    cout << endl;
}

void DeleteList(Elem*& first)
{
    while (first != NULL)
    {
        Elem* tmp = first->next;
        delete first;
        first = tmp;
    }
}

int main()
{
    Elem* L1 = NULL, * last1 = NULL, * L2 = NULL, * last2 = NULL;

    int n1;
    cout << "Enter the number of elements for list L1: ";
    cin >> n1;
    cout << "Enter the elements for list L1: ";
    for (int i = 0; i < n1; ++i) {
        Info value;
        cin >> value;
        LAdd(L1, last1, value);
    }

    int n2;
    cout << "Enter the number of elements for list L2: ";
    cin >> n2;
    cout << "Enter the elements for list L2: ";
    for (int i = 0; i < n2; ++i) {
        Info value;
        cin >> value;
        LAdd(L2, last2, value);
    }

    LPrint(L1);
    LPrint(L2);

    if (LisSubset(L2, L1))
        cout << " yes " << endl;
    else
        cout << " no " << endl;

    
    DeleteList(L1);
    DeleteList(L2);

    return 0;
}
