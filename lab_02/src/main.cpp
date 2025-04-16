#include <iostream>
#include <cstdbool>
#include <memory>
#include <string>

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
    list.push_back(456);
    list.push_back(789);
    list.push_back(101112);
    list.push_back(131415);
    std::cout << "Ожидание: 123 456 789 101112 131415. Реальность: " << list;

    list.pop_back();
    std::cout << "Ожидание: 123 456 789 101112. Реальность: " << list;

    ListIterator<int> list_iter = list.begin();
    list_iter += 3;
    list_iter = list.erase(list_iter);
    std::cout << "Ожидание: 123 456 789. Реальность: " << list;

    List<int> list_2 {};
    list_2.push_back(123);
    list_2.push_back(456);
    list_2.push_back(789);
    list_2.push_back(101112);
    list_2.push_back(131415);
    ListIterator<int> list_iter_2 = list_2.begin();
    list_iter_2 += 1;
    list_iter_2 = list_2.erase(list_iter_2); // Вызывает перенос :O
    list_iter_2 = list_2.erase(list_iter_2); // Вызывает перенос :O
    list_iter_2 = list_2.erase(list_iter_2); // Вызывает перенос :O
    std::cout << "Ожидание: 123 131415. Реальность: " << list_2;

    list_2.push_front(-95);
    std::cout << "Ожидание: -95 123 131415. Реальность: " << list_2;

    std::cout << "ТЕСТИРОВАНИЕ ЗАВЕРШЕНО" << std::endl << std::endl;




    std::cout << "ТЕСТИРОВАНИЕ: class NODE (STRING)" << std::endl;

    Node<std::string> a_s {"ewr"};
    Node<std::string> b_s {"ewr"};
    Node<std::string> c_s {"ewr"};

    std::shared_ptr<Node<std::string>> a_tmp_s = std::make_shared<Node<std::string>>(a_s);
    
    a_tmp_s->SetNext(b_s);
    std::shared_ptr<Node<std::string>> b_tmp_s = a_tmp_s->GetNext();
    
    b_tmp_s->SetNext(c_s);
    std::shared_ptr<Node<std::string>> c_tmp_s = b_tmp_s->GetNext();

    std::cout << "ТЕСТИРОВАНИЕ ЗАВЕРШЕНО" << std::endl << std::endl;



    std::cout << "ТЕСТИРОВАНИЕ: class List (STRING)" << std::endl;

    List<std::string> list_s {};
    list_s.push_back("matter");
    list_s.push_back("fixio");
    list_s.push_back("retlan");
    list_s.push_back("bitter");
    list_s.push_back("kugo");
    std::cout << "Ожидание: matter fixio retlan bitter kugo. Реальность: " << list_s;

    list_s.pop_back();
    std::cout << "Ожидание: matter fixio retlan bitter. Реальность: " << list_s;

    ListIterator<std::string> list_iter_s = list_s.begin();
    list_iter_s += 3;
    list_iter_s = list_s.erase(list_iter_s);
    std::cout << "Ожидание: matter fixio retlan. Реальность: " << list_s;

    std::cout << "ТЕСТИРОВАНИЕ ЗАВЕРШЕНО" << std::endl << std::endl;





    return 0;
}
