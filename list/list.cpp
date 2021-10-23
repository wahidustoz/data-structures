#include "list.h"

template <class T>
List<T>::List() : head(NULL) { }

template <class T>
void List<T>::Add(T data) { _add(data); }

template <class T>
typename List<T>::Nptr List<T>::_makeNode(T data)
{
    Nptr node = new Node();
    node->data = data;
    node->next = NULL;

    return node;
}

template <class T>
void List<T>::_add(T data) 
{
    _attach(head, _makeNode(data));
}

template <class T>
void List<T>::_attach(Nptr &Ptr, Nptr node)
{
    if(Ptr)
    {
        _attach(Ptr->next, node);
    }
    else
    {
        Ptr = node;
    }
}

template <class T>
void List<T>::Print() 
{ 
    _print(head); 
    cout << endl;
}

template <class T>
void List<T>::_print(Nptr Ptr)
{
    if(Ptr)
    {
        cout << Ptr->data << " ";
        _print(Ptr->next);
    }
}

template <class T>
void List<T>::Insert(T data, int index)
{
    if(index < 0)
    {
        throw out_of_range("List index is out of range!");
    }

    _insert(data, index);
}

template <class T>
void List<T>::_insert(T data, int index)
{
    _attach(head, _makeNode(data), index);
}

template <class T>
void List<T>::_attach(Nptr &Ptr, Nptr node, int index)
{
    if(Ptr == NULL && index > 0)
    {
        throw out_of_range("List index is out of range!");
    }

    if(index == 0 && Ptr == head)
    {
        node->next = Ptr;
        Ptr = node;
    }
    else if(index == 1)
    {
        node->next = Ptr->next;
        Ptr->next = node;
    }
    else
    {
        _attach(Ptr->next, node, --index);
    }
}

template <class T>
bool List<T>::Exists(T data) { return _exists(data); }

template <class T>
bool List<T>::_exists(Nptr Ptr, T data) 
{ 
    if(!Ptr)
    {
        return false;
    }
    else if(Ptr->data == data)
    {
        return true;
    }
    else
    {
        return _exists(Ptr->next, data);
    }
}

template <class T> 
void List<T>::Remove(T data) 
{ 
    _remove(head, data); 
}

template <class T>
void List<T>::_remove(Nptr &Ptr, T data)
{
    if(Ptr == NULL)
    {
        throw invalid_argument("Requested data doesn't exist!");
    }

    if(head->data == data)
    {
        Nptr temp = head;
        head = head->next;

        delete temp;
    }
    else if(Ptr->next && Ptr->next->data == data)
    {
        Nptr temp = Ptr->next;
        Ptr->next = temp->next;

        delete temp;
    }
    else
    {
        _remove(Ptr->next, data);
    }
}

template <class T>
void List<T>::RemoveAt(int index)
{
    _removeAt(head, index);
}

template <class T>
void List<T>::_removeAt(Nptr &Ptr, int index)
{
    if(index < 0 || !Ptr)
    {
        throw out_of_range("Index out of range!");
    }

    if(index == 0 && Ptr == head)
    {
        Nptr temp = head;
        head = head->next;

        delete temp;
    }
    else if(index == 1 && Ptr)
    {
        Nptr temp = Ptr->next;
        Ptr->next = temp->next;

        delete temp;
    }
    else
    {
        _removeAt(Ptr->next, --index);
    }
}