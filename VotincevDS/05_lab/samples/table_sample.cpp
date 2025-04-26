#include <iostream>
#include "general_functions.h"
#include "general_functions2.h"
#include "polinom.h"
#include "sort_table.h"
#include "array_hash_table.h"

using namespace std;



int main() {
    setlocale(LC_ALL, "Russian");
    ScanTable<string, Polinom> sc(23);
    SortedTable<string, Polinom> so(23);
    ArrayHashTable<string, Polinom> ht(23, 3);

    int flag = 0;

    while (true) {
        if (flag == 0) {
            work_with_tables(sc, so, ht, flag);
            if (flag == 0) continue;
        }

        if (work_with_polinoms(sc, so, ht, flag)) {
            break;
        }
            
    }

    return 0;
}
