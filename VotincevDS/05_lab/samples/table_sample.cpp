#include <iostream>
#include "general_functions.h"
#include "polinom.h"
#include "sort_table.h"
#include "array_hash_table.h"
using namespace std;

Polinom make_op(Polinom p1, Polinom p2, char s);

template <typename Tkey, typename Tdata>
void fill_vect(Table<Tkey, Tdata>& table, vector<Polinom*>& v);

template <typename Tkey, typename Tdata>
void make_opTable(Table<Tkey, Tdata>& table, int id_event,
    TabRecord<std::string, Polinom>* rec, string polinom_name);

template <typename Tkey, typename Tdata>
bool get_polinom_from_table(Polinom*& p, ScanTable<Tkey, Tdata>& sc,
    SortedTable<Tkey, Tdata>& so, ArrayHashTable<Tkey, Tdata>& ht);


int main()
{
    setlocale(LC_ALL, "Russian");
    ScanTable<std::string, Polinom> sc(23);
    SortedTable<std::string, Polinom> so(23);
    ArrayHashTable<std::string, Polinom> ht(23,3);

    int flag = 0;
    while (1) {

        // работа с таблицами
        if (flag == 0) {


            print_tables(sc, so, ht);
            cout << "С какой таблицей работаем?\n \
            1 - Scan   Table\n \
            2 - Sorted Table\n \
            3 - Hash   Table\n \
            4 - All tables\n \
            5 - Начать работу с полиномами\n";

            int id_table;
            // если пользователь не ввел 5 - выходим
            if (get_id(id_table, 5) != 1) {
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
                continue;
            }


        }
        

        

        Polinom* p1, *p2;
        
        if (get_polinom_from_table(p1, sc, so, ht)) {
            break;
        }

        if (get_polinom_from_table(p2, sc, so, ht)) {
            break;
        }

        cout << "Ваши полиномы: \n";
        cout << *p1 <<  *p2;
        



        while (1) {
            cout << "Введите операцию\n";
            char oper = get_oper();

            Polinom res = make_op(*p1, *p2, oper);
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


            int id_event;
            cout << "\nУ вас есть результирующий полином:  " << res;
            cout << "Его можно вставить:\n \
            1 - Вставка в scan table \n \
            2 - Вставка в sort table\n \
            3 - Вставка в hash table\n \
            4 - Вставка во все таблицы\n \
            5 - Не вставлять\n";


            if (get_id(id_event, 5) != 1) {

                std::ostringstream ss;
                ss << res;
                std::string polinom_name = ss.str();
                polinom_name.pop_back();
                Polinom* p = new Polinom(polinom_name);
                TabRecord<std::string, Polinom>* record = new TabRecord<std::string, Polinom>(polinom_name, p);

                switch (id_event)
                {
                case 1:
                    sc.Insert(record);
                    break;
                case 2:
                    so.Insert(record);
                    break;
                case 3:
                    ht.Insert(record);
                    break;
                case 4:
                    sc.Insert(record);
                    so.Insert(record);
                    ht.Insert(record);
                    break;
                default:
                    break;
                }        
            }
            cout << "Что делаем?\n \
            1 - работать с текущими полиномами \n \
            2 - работать с таблицами\n \
            3 - работать с новыми полиномами из таблиц\n \
            4 - завершить работу программы\n";
            int id_answ;
            get_id(id_answ, 4);

            if (id_answ == 1) {
                continue;
            }
            else if (id_answ == 2) {
                flag = 0;
                break;
            }
            else if (id_answ == 3) {
                flag = 1;
                break;
            }
            else if (id_answ == 4) {
                return 0;
            }
        }
    }
    return 0;

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
