#include <iostream>
#include "general_functions.h"

using namespace std;

bool is_digit(const char s) {
    return '0' <= s && s <= '9';
}
bool is_xyz(const char s) {
    return s == 'x' || s == 'y' || s == 'z';
}

int degree_xyz(const char s) {
    if (s == 'x') { return 100; }
    if (s == 'y') { return 10; }
    if (s == 'z') { return 1; }
    return -1;
}

bool is_correct_seq(const char c1, const char c2) {
    if (is_digit(c1) && is_digit(c2) ||
        is_xyz(c1) && is_xyz(c2) ||
        is_xyz(c1) && c2 == '^' ||
        c1 == '^' && is_digit(c2) ||
        is_digit(c1) && is_xyz(c2))
    {
        return 1;
    }
    return 0;

}


char get_oper() {
    char oper;
    cin >> oper;
    cin.ignore();
    while (oper != '+' && oper != '-' && oper != '*') {
        cout << "\tВозможны только операции - + *. Введите другую\n";
        cin >> oper;
        cin.ignore();
    }
    return oper;
}
