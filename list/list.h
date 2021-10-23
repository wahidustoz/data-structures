#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

template <class T>
class List 
{
    typedef struct Node
    {
        T data;
        struct Node* next;
    }*Nptr;

    Nptr head;

    void _add(T);
    Nptr _makeNode(T);
    void _attach(Nptr &, Nptr);
    void _print(Nptr);
    void _insert(T, int);
    void _attach(Nptr &, Nptr, int);
    bool _exists(Nptr, T);
    void _remove(Nptr &, T);
    void _removeAt(Nptr &, int);

public:
    List();
    void Add(T);
    void Print();
    void Insert(T, int);
    bool Exists(T);
    void Remove(T);
    void RemoveAt(int);
};