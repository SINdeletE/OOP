#include <iostream>
#include <cstdbool>
#include <memory>
#include <string>

#include "ListIterator.hpp"
#include "List.hpp"
#include "Set.hpp"
#include <vector>
// #include "Hash.hpp"

int main(void)
{
    std::cout << "ТЕСТИРОВАНИЕ: class NODE" << std::endl;

    Node<int> wq {};
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


    list_iter_s = list_s.begin();
    list_iter_s = list_s.insert(list_iter_s, "reworder");
    std::cout << "Ожидание: reworder matter fixio retlan. Реальность: " << list_s;
    list_iter_s = list_s.insert(list_iter_s, "IO");
    std::cout << "Ожидание: IO reworder matter fixio retlan. Реальность: " << list_s;
    list_iter_s++;
    list_iter_s = list_s.insert(list_iter_s, "MIXTURA");

    std::cout << "Ожидание: IO MIXTURA reworder matter fixio retlan. Реальность: " << list_s;

    std::cout << "ТЕСТИРОВАНИЕ ЗАВЕРШЕНО" << std::endl << std::endl;





    
    std::cout << "ТЕСТИРОВАНИЕ: class Set" << std::endl;

    Set<int> set {};
    SetIterator<int> my_iter {};

    set.append(1);
    set.append(3);
    set.append(3);
    set.append(0);
    set.append(2);

    std::cout << "Ожидание: 0 1 2 3. Реальность: " << set;

    Set<std::string> set_s {};
    set_s.append("aata");
    set_s.append("bata");
    set_s.append("bata");
    set_s.append("cata");
    set_s.append("data");
    std::cout << "Ожидание: aata bata cata data. Реальность: " << set_s;

    Set<std::string> set_s_2 {};
    set_s_2.append("aata");
    set_s_2.append("bata");
    set_s_2.append("rata");

    set_s | set_s_2;
    set_s | "wqewqeqw";
    set_s |= set_s_2;
    set_s |= "zata";
    set_s + set_s_2;
    set_s + "wqewqeqw";
    set_s += set_s_2;
    set_s += "zata";
    set_s += set_s;
    set_s.erase("aata");
    set_s.erase("cata");
    set_s.erase("zata");
    std::cout << "Ожидание: bata data rata. Реальность: " << set_s << std::endl;

    Set<std::string> set_s_2_copy {set_s_2};
    set_s_2 -= set_s_2_copy;
    std::cout << "Ожидание: (Пусто). Реальность: " << set_s_2;

    set_s_2 -= set_s_2;
    std::cout << "Ожидание: (Пусто). Реальность: " << set_s_2 << std::endl;



    Set<int> set_and {};
    set_and.append(1);
    set_and.append(2);
    set_and.append(8);
    set_and.append(4);
    set_and.append(5);

    Set<int> set_and_2 {};
    set_and_2.append(1);
    set_and_2.append(2);
    set_and_2.append(4);
    set_and_2.append(5);

    std::cout << "Ожидание: 1. Реальность: " << (set_and.find(9) == set_and.cend()) << std::endl;
    std::cout << "Ожидание: 1. Реальность: " << (set_and.find(8) != set_and.cend()) << std::endl;

    set_and &= set_and_2;
    std::cout << "Ожидание: 1 2 4 5. Реальность: " << set_and;

    std::cout << "Ожидание: 1. Реальность: " << (set_and == set_and) << std::endl;
    std::cout << "Ожидание: 0. Реальность: " << (set_and != set_and_2) << std::endl;
    std::cout << "Ожидание: 1. Реальность: " << (set_and == set_and_2) << std::endl;

    set_and_2 |= 144;
    set_and_2 &= {144};
    set_and_2 & set_and;
    set_and_2 & 128;
    std::cout << "Ожидание: 144. Реальность: " << set_and_2;

    std::cout << "ТЕСТИРОВАНИЕ ЗАВЕРШЕНО" << std::endl << std::endl;



    

    Set<int> set_xor {};
    set_xor.append(1);
    set_xor.append(2);
    set_xor.append(8);
    set_xor.append(4);
    set_xor.append(5);

    Set<int> set_xor_2 {26, 15, 4, 5};

    set_xor ^= set_xor_2;
    std::cout << "Ожидание: 1 2 8 15 26. Реальность: " << set_xor;

    set_xor ^= 99;
    std::cout << "Ожидание: 99. Реальность: " << set_xor;

    set_xor ^= 99;
    set_xor ^ set_xor_2;
    set_xor ^ 1;
    std::cout << "Ожидание: (Пусто). Реальность: " << set_xor;
    std::cout << "ТЕСТИРОВАНИЕ ЗАВЕРШЕНО" << std::endl << std::endl;




    std::cout << "ТЕСТИРОВАНИЕ: Конструкторы Set" << std::endl;

    Set<int> t1 {4, 2, 3, 1, 5, 7, 6};
    std::cout << "Ожидание: 1 2 3 4 5 6 7. Реальность: " << t1;

    Set<int> t2 {4.1, 2.2, 3.3, 1.1, 5.213, 7.123, 6.14};
    std::cout << "Ожидание: 1 2 3 4 5 6 7. Реальность: " << t2;

    int array[7] {1, 2, 3, 4, 5, 6, 7};
    Set<int> t3 {7, array};
    std::cout << "Ожидание: 1 2 3 4 5 6 7. Реальность: " << t3;

    double array_2[7] {1.1, 2, 3.352, 4.5, 5.9, 6, 7};
    Set<int> t4 {7, array_2};
    std::cout << "Ожидание: 1 2 3 4 5 6 7. Реальность: " << t4;

    std::vector<int> vec = {1, 2, 5, 6, 7, 4, 3};
    Set<int> t5 {vec.begin(), vec.end()};
    std::cout << "Ожидание: 1 2 3 4 5 6 7. Реальность: " << t5;

    std::vector<double> vec2 = {1.1, 2.999, 5.24, 6.4, 7.1, 4.2, 3.1};
    Set<int> t6 {vec2.begin(), vec2.end()};
    std::cout << "vector<int> init. Ожидание: 1 2 3 4 5 6 7. Реальность: " << t6;

    t6.And({1, 2, 5, 6, 3, 4, 7});
    std::cout << "AND Ожидание: 1 2 3 4 5 6 7. Реальность: " << t6;

    t6.Or({1, 2, 5, 6, 3, 4, 7, 8, 9, 11});
    std::cout << "Or Ожидание: 1 2 3 4 5 6 7 8 9 11. Реальность: " << t6;

    t6.Xor({9.1, 8.1, 11.1});
    std::cout << "Xor Ожидание: 1 2 3 4 5 6 7. Реальность: " << t6;

    t6.Diff({7, 6, 5, 4, 3, 2 ,1});
    std::cout << "Diff Ожидание: (Пусто). Реальность: " << t6;

    t6 = {1, 5, 2, 6, 7, 8};
    std::cout << "Присваивание Ожидание: 1 2 5 6 7 8. Реальность: " << t6;

    t6 = {1.1, 5.3, 2.99999995, 6.912, 7.1239, 8.0123};
    std::cout << "Присваивание (double) Ожидание: 1 2 5 6 7 8. Реальность: " << t6;

    Set<int> set_tmp {10, 9};
    t6 ^= set_tmp;
    std::cout << "Xor (int) Ожидание: 1 2 5 6 7 8 9 10. Реальность: " << t6;

    t5 = std::move(t4);

    Set<int> t7 {};
    std::cout << "Set (int) Ожидание: (Пусто). Реальность: " << t7;
    std::cout << "Размер (int) Ожидание: 0. Реальность: " << t7.size() << std::endl << std::endl;

    t7 |= {1, 2, 3, 4, 5, 7, 6, 0};
    std::cout << "Присваивание |= (int) Ожидание: 0 1 2 3 4 5 6 7. Реальность: " << t7;
    Set<int> t_tmp {};
    t7 &= t_tmp;
    std::cout << "Присваивание &= (int) Ожидание: (Пусто). Реальность: " << t7;
    t7 ^= {1, 2, 3, 4, 5, 7, 6, 0};
    std::cout << "Присваивание ^= (int) Ожидание: 0 1 2 3 4 5 6 7. Реальность: " << t7;
    t7 -= {11, 16, 5, 6, 12};
    std::cout << "Присваивание -= (int) Ожидание: 0 1 2 3 4 7. Реальность: " << t7;

    std::cout << "ТЕСТИРОВАНИЕ ЗАВЕРШЕНО" << std::endl << std::endl;


    std::cout << "ТЕСТИРОВАНИЕ: Правки 23 апреля 2025" << std::endl << std::endl;

    Set<int> range_set {std::ranges::iota_view(1, 6)};
    std::cout << "Ожидание: 1 2 3 4 5. Реальность: " << range_set;
    Set<int> range_set_2 {std::ranges::iota_view(1, 6), 3};
    std::cout << "Ожидание: 1 3 5. Реальность: " << range_set_2;

    Set<int> range_set_3 {std::ranges::iota_view(1, 1), 3};
    std::cout << "Ожидание: (Пусто). Реальность: " << range_set_3;

    try
    {
        Set<int> range_set_err {std::ranges::iota_view(1, 99), 1};
    }
    catch (ErrorSet_BadSize &error)
    {
        std::cout << "Исключение отловлено" << std::endl;
    }

    std::vector<double> vector_test = {1.1, 24, 8.1, 99.9};
    Set<int> set_container_eq {};
    set_container_eq = vector_test;

    std::cout << "Ожидание: 1 8 24 99. Реальность: " << set_container_eq;

    Set<int> set_range_eq {};
    set_range_eq = std::ranges::iota_view(1, 6);

    std::cout << "Ожидание: 1 2 3 4 5. Реальность: " << set_range_eq;

    std::cout << "ТЕСТИРОВАНИЕ ЗАВЕРШЕНО" << std::endl << std::endl;

    return 0;
}
