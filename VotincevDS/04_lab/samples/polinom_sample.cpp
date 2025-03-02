#include <iostream>
#include "polinom.h"
using namespace std;

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
        cout << "¬ведите полином\n";
        cin >> p1;
        cin.ignore();
        cout << "¬ведите 2й полином\n";
        cin >> p2;
        cin.ignore();


        cout << "¬ведите операцию\n";
        char oper = get_oper();
        
        Polinom res = make_op(p1, p2, oper);
        cout << res;

        cout << "ѕосчитать значение при конкретных x y z?\n";
        cout << "(\t1 - да       0 -  нет)\n";
        cin >> oper;
        cin.ignore();
        if (oper == '1') {
            cout << "¬ведите x y z (через пробел)\nx y z\n";
            double x, y, z;
            cin >> x >> y >> z;
            cout << "¬ведены значени€: x = " 
                << x << " y = " << y << " z = " << z << '\n';
            cout << "–езультат:  "  << res.count(x, y, z) << "\n\n";
        }
        
        cout << "’отите ввести новые полиномы?\n";
        cout << "(\t1 - да       0 -  нет(«ј¬≈–Ў»“№ –јЅќ“”)\n";
        cin >> oper;
        cin.ignore();
        if (oper == '0') {
            return 1;
        }
        else {
            continue;
        }
        
    }
    return 1;



}
