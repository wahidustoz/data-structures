#include "list.cpp"

int main()
{
    List<int> list = List<int>();
    for(int i = 0; i < 10; i++)
    {
        list.Add(i);
    }

    list.Insert(5, 2);
    list.RemoveAt(9);

    list.Print();

    return 0;
}