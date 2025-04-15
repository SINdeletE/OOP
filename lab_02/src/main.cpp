#include <iostream>
#include <cstdbool>
#include <memory>

#include "ListIterator.hpp"
#include "List.hpp"
#include "Output.hpp"

int main(void)
{
    std::cout << "ТЕСТИРОВАНИЕ: class NODE" << std::endl;

    Node<int> a {3};
    Node<int> b {5};
    Node<int> c {9};

    std::shared_ptr<Node<int>> a_tmp = std::make_shared<Node<int>>(a);
    
    a_tmp->SetNext(b);
    std::shared_ptr<Node<int>> b_tmp = a_tmp->GetNext();
    
    b_tmp->SetNext(c);
    std::shared_ptr<Node<int>> c_tmp = b_tmp->GetNext();

    std::cout << "ТЕСТИРОВАНИЕ ЗАВЕРШЕНО" << std::endl << std::endl;





    std::cout << "ТЕСТИРОВАНИЕ: class ListIterator" << std::endl;

    std::shared_ptr<Node<int>> pseudo_list = a_tmp;
    ListIterator<int> iter {pseudo_list, 0};

    ListIterator<int> iter_1 {pseudo_list, 0};

    std::cout << "Ожидание: 1. Реальность: " << (iter == iter_1) << std::endl;
    std::cout << "Ожидание: 0. Реальность: " << (iter != iter_1) << std::endl;
    
    std::cout << "Ожидание: 3. Реальность: " << iter.Current() << std::endl;
    iter++;
    std::cout << "Ожидание: 5. Реальность: " << iter.Current() << std::endl;
    iter++;
    std::cout << "Ожидание: 9. Реальность: " << iter.Current() << std::endl;

    std::cout << "Ожидание: 9. Реальность: " << c_tmp << std::endl;

    std::cout << "ТЕСТИРОВАНИЕ ЗАВЕРШЕНО" << std::endl << std::endl;





    std::cout << "ТЕСТИРОВАНИЕ: class List" << std::endl;

    List<int> list {};
    list.push_back(123);
    list.push_back(123);
    list.push_back(123);
    list.push_back(123);
    list.push_back(123);

    std::cout << "Ожидание: 123 123 123 123 123. Реальность: " << list;

    std::cout << "ТЕСТИРОВАНИЕ ЗАВЕРШЕНО" << std::endl << std::endl;

    return 0;
}
