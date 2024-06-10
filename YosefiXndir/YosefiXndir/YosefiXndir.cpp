#include<string>
#include "stack"
#include<vector>
#include<iostream>

template <typename T>
struct Node
{
    T info;
    Node<T>* next;
};

template <typename T>
class List
{
    Node<T>* first;
    int size;

public:
    List();
    List(const List& ob);
    ~List();
    bool IsEmpty() const;
    int GetLength() const;
    Node<T>* GetFirst() const;
    void InsertAfter(Node<T>* p, T item);
    void InsertAt(int n, T item);
    void DeleteAt(int n);
    void DeleteAfter(Node<T>* p);
    T& GetData(Node<T>* p);
};

template <typename T>
List<T>::List() : size(0), first(nullptr) { std::cout << "const"; }
template <typename T>

List<T>::List(const List& ob)
{
    Node <T>* p = new Node<T>;
    Node <T>* temp = ob.GetFirst();

    p->info = ob.GetData(temp);
    first = p;

    for (int i = 1; i < ob.GetLength(); i++)
    {
        temp = temp->next;

        InsertAfter(p, ob.GetData(temp));
        p = p->next;


    }
    size = ob.GetLength();
    delete temp;
}

template <typename T>
List<T>::~List()
{

    if (GetLength())
    {
        while (first->next)
            DeleteAfter(first);
        delete first;
        first = nullptr;
    }
    size = 0;
    std::cout << "dest";
}

template <typename T>
bool List<T>::IsEmpty() const
{
    return size == 0;
}

template <typename T>
int List<T>::GetLength() const
{
    return size;
}

template <typename T>
Node<T>* List<T>::GetFirst() const
{
    return first;
}

template <typename T>
void List<T>::InsertAfter(Node<T>* p, T item)
{
    Node<T>* q = new Node<T>;
    q->info = item;
    q->next = p->next;

    p->next = q;
    size++;
}

template <typename T>
void List<T>::InsertAt(int n, T item)
{
    if (n<0 || n>GetLength())
    {
        throw "out of range";
    }
    if (n == 0)
    {
        Node<T>* temp = new Node<T>;
        temp->info = item;
        temp->next = first;
        first = temp;
        size++;

        return;
    }
    Node  <T>* p = first;
    for (int i = 0; i < n - 1; i++)
    {
        p = p->next;
    }
    InsertAt(p, item);
}
template <typename T>

void List<T>::DeleteAfter(Node<T>* p)
{
    if (IsEmpty())
    {
        throw "is empty";
    }
    if (p->next == nullptr)
    {
        throw "no element";

    }
    Node <T>* q = p->next;
    p->next = q->next;
    delete q;


}
template <typename T>
void List<T>::DeleteAt(int n)
{
    if (n < 0 || n >= GetLength())
    {
        throw "out of range";

    }
    if (n == 0 && GetLength != 0)
    {
        Node <T>* p = first;

        first = first->next;
        size--;
        delete p;
    }
    Node <T>* p = first;
    for (int i = 0; i < n - 1; i++)
    {
        p = p->next;
    }
    DeleteAfter(p);
}
template <typename T>
T& List<T>::GetData(Node<T>* p)
{
    return p->info;
}
int main()
{
    try {

        List<int> myList;
        const int n = 3;
        int item;
        for (int i = 0; i < n; i++)
        {
            std::cin >> item;
            myList.InsertAt(i, item);

        }
        myList.InsertAt(1, 8);
        Node <int >* p;
        int i;
        for (i = 0, p = myList.GetFirst(); i < myList.GetLength(); i++, p = p->next)
        {
            std::cout << myList.GetData(p) << std::endl;
        }
    }
    catch (char* a)
    {
        std::cout << a;
    }
    return 0;
}
