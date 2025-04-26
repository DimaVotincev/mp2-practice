#include <iostream>
#include "general_functions.h"
#include "polinom.h"
#include "sort_table.h"
#include "array_hash_table.h"
using namespace std;

Polinom make_op(Polinom p1, Polinom p2, char s);

template <typename Tkey, typename Tdata>
void print_table(Table<Tkey, Tdata>& table) {
    table.Reset();
    int i = 1;
    while (!table.IsTabEnded()) {
        std::cout << i << ": " << table.GetCurr()->get_key() << '\n';
        i++;
        table.Next();
    }
    table.Reset();
}

template <typename Tkey, typename Tdata>
void fill_vect(Table<Tkey, Tdata>& table, vector<Polinom*>& v) {
    table.Reset();
    int i = 1;
    while (!table.IsTabEnded()) {
        v.push_back(table.GetCurr()->get_data());
        i++;
        table.Next();
    }
    table.Reset();
}

template <typename Tkey, typename Tdata>
void print_tables(ScanTable<Tkey, Tdata> sct,
    SortedTable<Tkey, Tdata> sot,
    ArrayHashTable<Tkey, Tdata> ht) {

    std::cout << "ScanTable: \n";
    print_table(sct);

    std::cout << "SortTable: \n";
    print_table(sot);

    std::cout << "HashTable: \n";
    print_table(ht);
}


bool get_id(int& id,int max) {

    while (1) {
        cin >> id;
        if (1 <= id && id <= max - 1) {
            return 0;
        }
        if (id == max) {
            return 1;
        }
        cout << "Введите только цифру от 1 до " << max << '\n';
    }
    return 0;
    
}


//void get_idevent(int& id) {
//
//    while (1) {
//        cin >> id;
//        if (1 <= id && id <= 3) {
//            return;
//        }
//        cout << "Введите только цифру (1,2, или 3)\n";
//    }
//
//}






template <typename Tkey, typename Tdata>
void make_opTable(Table<Tkey, Tdata>& table, int id_event,
    TabRecord<std::string, Polinom>* rec, string polinom_name) {
    TabRecord<std::string, Polinom>* record;
    record = new TabRecord<std::string, Polinom>(*rec);
    switch (id_event)
    {
    case 1:
        table.Insert(record);
        break;
    case 2:
        table.Remove(polinom_name);
        break;
    case 3:
        if (table.Find(polinom_name)) {
            cout << " есть \n";
        }
        else {
            cout << " нет  \n";
        }
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
    case 4:
        if (id_event == 3) {
            cout << "В scan   table " << polinom_name << "  -  ";
            make_opTable(sc1, id_event, record, polinom_name);
            cout << "В sorted table " << polinom_name << "  -  ";
            make_opTable(so1, id_event, record, polinom_name);
            cout << "В hash   table " << polinom_name << "  -  ";
            make_opTable(ht1, id_event, record, polinom_name);
            break;
        }
        make_opTable(sc1, id_event, record, polinom_name);
        make_opTable(so1, id_event, record, polinom_name);
        make_opTable(ht1, id_event, record, polinom_name);
        break;
    default:
        break;
    }
        
    
}

template <typename Tkey, typename Tdata>
bool get_polinom_from_table(Polinom*& p,ScanTable<Tkey, Tdata>& sc, SortedTable<Tkey, Tdata>& so,
    ArrayHashTable<Tkey, Tdata>& ht) {
    cout << "Из какой таблицы берем полином?\n \
            1 - Scan   Table\n \
            2 - Sorted Table\n \
            3 - Hash   Table\n \
            4 - Завершить работу\n";
    int id_table;
    if (get_id(id_table, 4) == 1) {
        return 1; // то есть надо завершить программу
    }

    // выбрал таблицу
    // теперь из нее полином надо выбрать
    vector<Polinom*> polinoms;
    // это для того,чтобы полиномы вывелись списком
    // и они лежали в порядке в этом векторе
    // это чтобы пользователь вводил циферку
    //а не сам полином, чтоб его выбрать

    cout << "Какой полином берем?\n";

    switch (id_table)
    {
    case 1:
        print_table(sc);
        fill_vect(sc, polinoms);
        break;
    case 2:
        print_table(so);
        fill_vect(so, polinoms);
        break;
    case 3:
        print_table(ht);
        fill_vect(ht, polinoms);
        break;
    default:
        break;
    }

    int id_p;
    get_id(id_p, polinoms.size());
    p = polinoms[id_p  -1];
    return 0;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    

    ScanTable<std::string, Polinom> sc(5);
    SortedTable<std::string, Polinom> so(5);
    ArrayHashTable<std::string, Polinom> ht(5,3);


    
    // в таблицы можно вставлять, удалять, искать элементы

    // теперь нужно написать функцию, которая
    // спрашивает из какой таблицы берем
    // спрашивает какой полином берем
    // берет этот полином и вставляет
    // 
    // еще функцию, которая делает операции
    // с полиномами
    // 
    // сделала операцию - получила результат
    // предлагает его пихнуть в таблицу 
    // здесь опять же  - вопрос в какую 
    // (по сути тот же make_opTables , но немного переделанный)
   
    while (1) {
        print_tables(sc, so, ht);
        cout << "С какой таблицей работаем?\n \
            1 - Scan   Table\n \
            2 - Sorted Table\n \
            3 - Hash   Table\n \
            4 - All tables\n \
            5 - Начать работу с полиномами\n";

        int id_table;
        // если пользователь ввел 5 - выходим
        if (get_id(id_table,5) == 1) {
            break;
        }

        cout << "Что делаем с таблицей/таблицами\n \
            1 - Вставка \n \
            2 - Удаление\n \
            3 - Поиск\n \
            4 - Начать работу с полиномами\n";

        int id_event;
        if (get_id(id_event, 4) == 1) {
            break;
        }

        make_opTables(id_table, id_event, sc, so, ht);
    }
    
    while (1) {

        Polinom* p1, *p2;
        
        if (get_polinom_from_table(p1, sc, so, ht)) {
            break;
        }

        if (get_polinom_from_table(p2, sc, so, ht)) {
            break;
        }
        cout << *p1 << "\n" << *p2 << '\n';
        
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