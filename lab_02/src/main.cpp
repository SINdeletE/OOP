#include <iostream>
#include <memory>

#include "ListIterator.hpp"
#include "List.hpp"

int main(void)
{
    std::cout << "ТЕСТИРОВАНИЕ: class NODE";

    Node<int> a {3};
    Node<int> b {5};
    Node<int> c {9};

    std::shared_ptr<Node<int>> a_tmp = std::make_shared<Node<int>>(a);
    
    a_tmp->SetNext(b);
    std::shared_ptr<Node<int>> b_tmp = a_tmp->GetNext();
    b_tmp->SetParent(a_tmp);
    
    b_tmp->SetNext(c);
    std::shared_ptr<Node<int>> c_tmp = b_tmp->GetNext();
    c_tmp->SetParent(b_tmp);

    std::cout << "ТЕСТИРОВАНИЕ ЗАВЕРШЕНО" << std::endl << std::endl;


    std::cout << "ТЕСТИРОВАНИЕ: class ListIterator" << std::endl;

    std::shared_ptr<Node<int>> pseudo_list = b_tmp->GetParent();
    ListIterator<int> iter {pseudo_list};
    
    std::cout << "Ожидание: 3. Реальность: " << iter.Current() << std::endl;
    iter++;
    std::cout << "Ожидание: 5. Реальность: " << iter.Current() << std::endl;
    iter++;
    std::cout << "Ожидание: 9. Реальность: " << iter.Current() << std::endl;
    iter--;
    std::cout << "Ожидание: 5. Реальность: " << iter.Current() << std::endl;
    iter--;
    std::cout << "Ожидание: 3. Реальность: " << iter.Current() << std::endl;

    std::cout << "ТЕСТИРОВАНИЕ ЗАВЕРШЕНО" << std::endl << std::endl;

    return 0;
}
