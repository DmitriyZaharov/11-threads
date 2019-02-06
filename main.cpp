
//
// Created by claorisel on 2/6/19.
//

#include <iostream>
#include <thread>
#include <string>
#include <algorithm>
#include <iomanip>

template <class T> class TD;

using namespace std;

int main()
{
    auto func = [](const string &first, const string &second)
    {

//        auto days = std::chrono::system_clock::now() + std::chrono::hours(72);
//        std::this_thread::sleep_until(days);
//        std::this_thread::sleep_for(std::chrono::hours(72));

        cout << " lambda thread 0x"<< std::hex << this_thread::get_id()<< endl;
        cout << first << second << endl;
    };

    /**
     * std::thread принимает первым аргументом функцию исполнения,
     * т.е. функцию, код которой будет исполнен в отдельном потоке.
     * Остальные аргументы, - есть аргументы исполняемой функции.
     * Важно помнить, что аргументы будут использованы в другом потоке исполнения,
     * а следовательно нельзя передавать ссылки и указатели на объекты,
     * время жизни которых не больше, чем время жизни потока.
     * Это может обернуться некорректным поведением,
     * в лучшем случае, и падением, в худшем. Всегда нужно помнить об этом.
     */

    /**
     * Так же thread всегда копирует аргументы, и только потом передаёт их исполняемой функции.
     * Поэтому, даже если ваша функция принимает ссылку в качестве аргумента,
     * это будет не та ссылка, которую вы передали в конструкторе thread.
     * Это будет ссылка на копию в объекте thread!
     * Поэтому, для передачи ссылки необходимо использовать std::ref.
     */
    thread th(func, "Hello ", "threads");

    /**
     * Уникальный идентификатор потока
     */
    std::cout << "New thread id: 0x" << std::hex << th.get_id() << "\n";


    th.join();

    cout << " main thread 0x"<< std::hex << this_thread::get_id()<< endl;




    return 1;
}
