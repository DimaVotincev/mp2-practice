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
    int i;
    std::cout << "ScanTable: \n";
    sct.Reset();
    i = 1;
    while (!sct.IsTabEnded()) {
        std::cout << i << ": " << sct.GetCurr()->get_key() << '\n';
        i++;
        sct.Next();
    }
    sct.Reset();

    sot.Reset();
    std::cout << "SortTable: \n";
    i = 1;
    while (!sot.IsTabEnded()) {
        std::cout << i << ": " << sot.GetCurr()->get_key() << '\n';
        i++;
        sot.Next();
    }
    sot.Reset();

    ht.Reset();
    std::cout << "HashTable: \n";
    
    //std::cout << ht; // не хочет линковаться
    i = 1;
    while (!ht.IsTabEnded()) {
        std::cout << i << ": " << ht.GetCurr()->get_key() << '\n';
        i++;
        ht.Next();
    }
    //ht.Reset();

}


void get_idtable(int& id) {

    while (1) {
        cin >> id;
        if (1 <= id && id <= 4) {
            return;
        }
        cout << "Введите только цифру (1,2,3 или 4)\n";
    }
    
}


void get_idevent(int& id) {

    while (1) {
        cin >> id;
        if (1 <= id && id <= 3) {
            return;
        }
        cout << "Введите только цифру (1,2, или 3)\n";
    }

}






template <typename Tkey, typename Tdata>
void make_opTable(Table<Tkey, Tdata>& table, int id_event,
    TabRecord<std::string, Polinom>* record, string polinom_name) {
    switch (id_event)
    {
    case 1:
        table.Insert(record);
        break;
    case 2:
        table.Remove(polinom_name);
        break;
    case 3:
        table.Find(polinom_name);
        break;
    default:
        break;
    }
}




template <typename Tkey, typename Tdata>
void make_opTables(int id_table, int id_event, 
    ScanTable<Tkey, Tdata>& sc1, SortedTable<Tkey, Tdata>& so1,
    ArrayHashTable<Tkey, Tdata>& ht1) {

    switch (id_event)
    {
    case 1:
        cout << "Какой полином вставляем?\n";
        break;
    case 2:
        cout << "Какой полином удаляем?\n";
        break;
    case 3:
        cout << "Какой полином ищем?\n";
        break;
    default:
        break;
    }
    cin.ignore();
    string polinom_name;
    getline(cin, polinom_name);
    Polinom* p = new Polinom(polinom_name);

    TabRecord<std::string, Polinom>* record = new TabRecord<std::string, Polinom>(polinom_name, p);
    switch (id_table)
    {
    case 1:
        make_opTable(sc1, id_event, record, polinom_name);
        break;
    case 2:
        make_opTable(so1, id_event, record, polinom_name);
        break;
    case 3:
        make_opTable(ht1, id_event, record, polinom_name);
        break;
    default:
        break;
    }
        
    
}



int main()
{
    setlocale(LC_ALL, "Russian");
    

    ScanTable<std::string, Polinom> sc(2);
    /*sc1.Insert(new TabRecord<int, int>(1, nullptr));
    sc1.Insert(new TabRecord<int, int>(2, nullptr));*/
    SortedTable<std::string, Polinom> so(2);
    /*so1.Insert(new TabRecord<int, int>(3, nullptr));
    so1.Insert(new TabRecord<int, int>(4, nullptr));*/
    ArrayHashTable<std::string, Polinom> ht(2,3);
    /*ht1.Insert(new TabRecord<int, int>(5, nullptr));
    ht1.Insert(new TabRecord<int, int>(6, nullptr));*/

   
    while (1) {
        print_tables(sc, so, ht);
        cout << "С какой таблицей работаем?\n \\
            1 - Scan   Table\n \\
            2 - Sorted Table\n \\
            3 - Hash   Table\n \\
            4 - All tables\n";
            int id_table;
        get_idtable(id_table);
        cout << "Что делаем с таблицей/таблицами\n \\
            1 - Вставка \n \\
            2 - Удаление\n \\
            3 - Поиск\n";
            int id_event;
        get_idevent(id_event);
        make_opTables(id_table, id_event, sc, so, ht);
    }
    

    
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