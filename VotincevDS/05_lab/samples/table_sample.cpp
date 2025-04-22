#include <iostream>
#include "general_functions.h"
#include "polinom.h"
#include "sort_table.h"
#include "array_hash_table.h"
using namespace std;

Polinom make_op(Polinom p1, Polinom p2, char s);



template <typename Tkey, typename Tdata>
void print_tables(ScanTable<Tkey, Tdata> sct,
    SortedTable<Tkey, Tdata> sot,
    ArrayHashTable<Tkey, Tdata> ht) {

    std::cout << "ScanTable: \n";
    sct.Reset();
    while (!sct.IsTabEnded()) {
        std::cout << sct.GetCurr()->get_key() << '\n';
        sct.Next();
    }
    sct.Reset();

    sot.Reset();
    std::cout << "SortTable: \n";
    while (!sot.IsTabEnded()) {
        std::cout << sot.GetCurr()->get_key() << '\n';
        sot.Next();
    }
    sot.Reset();

    ht.Reset();
    std::cout << "HashTable: \n";
    while (!ht.IsTabEnded()) {
        std::cout << ht.GetCurr()->get_key() << '\n';
        ht.Next();
    }
    ht.Reset();

}




int main()
{
    setlocale(LC_ALL, "Russian");
    

    ScanTable<int, int> sc1(2);
    sc1.Insert(new TabRecord<int, int>(1, nullptr));
    sc1.Insert(new TabRecord<int, int>(2, nullptr));
    SortedTable<int, int> so1(2);
    so1.Insert(new TabRecord<int, int>(3, nullptr));
    so1.Insert(new TabRecord<int, int>(4, nullptr));
    ArrayHashTable<int, int> ht1(2,3);
    ht1.Insert(new TabRecord<int, int>(5, nullptr));
    ht1.Insert(new TabRecord<int, int>(6, nullptr));

    print_tables(sc1,so1,ht1);

   

    return 0;


    /*Polinom p1, p2;
    while(1) {
        cout << "Введите полином\n";
        cin >> p1;
        cout << "Введите 2й полином\n";
        cin >> p2;

        while (1) {
            cout << "Введите операцию\n";
            char oper = get_oper();

            Polinom res = make_op(p1, p2, oper);
            cout << "Результат:\n";
            cout << res;
            
            cout << "Посчитать значение при конкретных x y z?\n";
            cout << "(\t1 - да       2 -  нет)\n";
            cin >> oper;
            cin.ignore();
            if (oper == '1') {
                cout << "Введите x y z (через пробел)\nx y z\n";
                double x, y, z;
                cin >> x >> y >> z;
                cout << "Введены значения: x = "
                    << x << " y = " << y << " z = " << z << '\n';
                cout << "Результат:  " << res(x, y, z) << "\n\n";
            }

            cout << "Введите,что хотите сделать\n";
            cout << "(1 -  использовать уже введенные\n2 - ввести новые полиновмы\n3 - завершить работу\n";
            cin >> oper;
            cin.ignore();
            if (oper == '1') {
                continue;
            }
            else  if (oper == '2') {
                break;
            } else {
                return 0;
            }
        }             
    }
    */
}



Polinom make_op(Polinom p1, Polinom p2, char s) {
    switch (s)
    {
    case '+': return p1 + p2; break;
    case '-': return p1 - p2; break;
    case '*': return p1 * p2; break;
    default:
        throw "wrong operation";
        break;
    }
}