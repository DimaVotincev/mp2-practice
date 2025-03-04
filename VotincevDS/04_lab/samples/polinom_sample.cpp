#include <iostream>
#include "polinom.h"
using namespace std;




Polinom make_op(Polinom p1, Polinom p2, char s);






int main()
{
    setlocale(LC_ALL, "Russian");
    /*
    "-123x^3y^2z^6+x^5yz^3-y^2z^3-z^2x^3"
    "xyz + x + y + z"
    "x+y"
    "2,2x+y"
    */

    Polinom p1, p2;
    while(1) {
        cout << "Введите полином\n";
        cin >> p1;
        cin.ignore();
        cout << "Введите 2й полином\n";
        cin >> p2;
        cin.ignore();

        while (1) {
            cout << "Введите операцию\n";
            char oper = get_oper();

            Polinom res = make_op(p1, p2, oper);
            cout << res;

            cout << "Посчитать значение при конкретных x y z?\n";
            cout << "(\t1 - да       0 -  нет)\n";
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
            cout << "(2 -  использовать уже введенные\n1 - ввести новые полиновмы\n0 - завершить работу\n";
            cin >> oper;
            cin.ignore();
            if (oper == '2') {
                continue;
            }
            else  if (oper == '1') {
                break;
            } else {
                return 1;
            }
        }             
    }
    return 1;
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