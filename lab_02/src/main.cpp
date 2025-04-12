#include "List.hpp"

int main(void)
{
    Node<int> a {3};
    Node<int> b {5};

    a.SetParent(b);
    a.SetNext(a);

    a.Output();

    return 0;
}
