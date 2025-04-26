#pragma once
#include <iostream>
#include "table.h"
#include "sort_table.h"
#include "array_hash_table.h"
#include "polinom.h"

using namespace std;

bool is_digit(const char s);
bool is_xyz(const char s);
int degree_xyz(const char s);
bool is_correct_seq(const char c1, const char c2);
char get_oper();
bool get_id(int& id, int max);




//int fffff(Polinom p) {
//    return 1;
//}










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



