#pragma once
#include <iostream>
#include "table.h"
#include "sort_table.h"
#include "array_hash_table.h"
#include "polinom.h"
using namespace std;

// здесь лежат функции , использующие полином
// в general_functions.h не положить
// так как его использует полином
// если засунуть - получится что полином подключает самого себя


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
bool get_polinom_from_table(Polinom*& p, ScanTable<Tkey, Tdata>& sc, SortedTable<Tkey, Tdata>& so,
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
    // а не сам полином, чтоб его выбрать

    cout << "Какой полином берем?\n";
    // убрать вектор
    // должен быть ввод полинома
    // потом он как бы берется из всех таблиц (в которых он есть)
    // и в которых он был - можно добавить результат
    // 

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
    p = polinoms[id_p - 1];
    return 0;
}




void work_with_tables(ScanTable<string, Polinom>& sc,
    SortedTable<string, Polinom>& so,
    ArrayHashTable<string, Polinom>& ht, int& flag) {
    print_tables(sc, so, ht);

    cout << "С какой таблицей работаем?\n \
            1 - Scan   Table\n \
            2 - Sorted Table\n \
            3 - Hash   Table\n \
            4 - All tables\n \
            5 - Начать работу с полиномами\n \
            6 - Завершить работу\n";

    int id_table;

    while (1) {
        cin >> id_table;
        if (1 <= id_table && id_table <= 6) {
            break;
        }      
        cout << "Введите только цифру от 1 до 6\n";
        cin.ignore();
    }
    if (id_table == 5) {
        flag = 1;
        return;
    }

    if (id_table == 6) {
        flag = 2;
        return;
    }

    cout << "Что делаем с таблицей/таблицами\n \
            1 - Вставка \n \
            2 - Удаление\n \
            3 - Поиск\n \
            4 - Начать работу с полиномами\n";

    int id_event;
    if (get_id(id_event, 4) == 1)
        flag = 1;
    else
        make_opTables(id_table, id_event, sc, so, ht);

}

bool insert_result_into_tables(Polinom& res,
    ScanTable<string, Polinom>& sc,
    SortedTable<string, Polinom>& so,
    ArrayHashTable<string, Polinom>& ht) {
    int id_event;
    cout << "\nУ вас есть результирующий полином:  ";
    cout << res;
    cout << "Его можно вставить:\n \
            1 - Вставка в scan table \n \
            2 - Вставка в sort table\n \
            3 - Вставка в hash table\n \
            4 - Вставка во все таблицы\n \
            5 - Не вставлять\n";

    if (get_id(id_event, 5) == 1) return false;

    ostringstream ss;
    ss << res;
    string polinom_name = ss.str();
    polinom_name.pop_back();
    Polinom* p = new Polinom(polinom_name);
    auto* record = new TabRecord<string, Polinom>(polinom_name, p);

    switch (id_event) {
    case 1: sc.Insert(record); break;
    case 2: so.Insert(record); break;
    case 3: ht.Insert(record); break;
    case 4:
        sc.Insert(record);
        so.Insert(record);
        ht.Insert(record);
        break;
    }
    return true;
}

int work_with_result_polinom(Polinom* p1, Polinom* p2,
    ScanTable<string, Polinom>& sc,
    SortedTable<string, Polinom>& so,
    ArrayHashTable<string, Polinom>& ht) {
    while (true) {
        cout << "Введите операцию\n";
        char oper = get_oper();

        Polinom res = make_op(*p1, *p2, oper);
        cout << "Результат:\n" << res;

        cout << "Посчитать значение при конкретных x y z?\n \
            (1 - да, 2 - нет)\n";
        cin >> oper;
        cin.ignore();
        if (oper == '1') {
            double x, y, z;
            cout << "Введите x y z (через пробел):\n";
            cin >> x >> y >> z;
            cout << "Результат:  " << res(x, y, z) << "\n\n";
        }

        insert_result_into_tables(res, sc, so, ht);

        cout << "Что делаем?\n \
            1 - работать с текущими полиномами\n \
            2 - работать с таблицами\n \
            3 - работать с новыми полиномами из таблиц\n \
            4 - завершить работу программы\n";

        int id_answ;
        get_id(id_answ, 4);

        if (id_answ == 1) continue;
        if (id_answ == 2) return 0;
        if (id_answ == 3) return 1;
        if (id_answ == 4) return -1;
    }
}

bool work_with_polinoms(ScanTable<string, Polinom>& sc,
    SortedTable<string, Polinom>& so,
    ArrayHashTable<string, Polinom>& ht, int& flag) {
    Polinom* p1, * p2;

    if (get_polinom_from_table(p1, sc, so, ht)) {
        return 1;
    }
    if (get_polinom_from_table(p2, sc, so, ht)) {
        return 0;
    }


    cout << "Ваши полиномы: \n" << *p1 << *p2;

    int result = work_with_result_polinom(p1, p2, sc, so, ht);
    if (result == 0) {
        flag = 0;
    }
    else if (result == 1) {
        flag = 1;
    }
    else {
        return 1;
    }
    return 0;
}
