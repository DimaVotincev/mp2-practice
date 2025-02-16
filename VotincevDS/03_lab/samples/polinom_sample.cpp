#include <iostream>
#include "headlist.h"
#include "ringheadlist.h"
using namespace std;

int main()
{
    //ListNode<int>* l;
    //l = new ListNode<int>(5);
    //l->next = new ListNode<int>(6);
    //l->next->next = new ListNode<int>(7);
    //HeadList<int> h1(l);
    //ListNode<int>* lt;
    //lt = new ListNode<int>(3);
    //// lt->next = new ListNode<int>(4);
    //HeadList<int> h2(l);  // 5 6 7
    //HeadList<int> h3(l);  // 5 6 7
    //h2.push(8);
    //h2.pushBack(nullptr);


    ListNode<int>* l;
    l = new ListNode<int>(5);
    l->next = new ListNode<int>(6);
    l->next->next = new ListNode<int>(7);
    HeadList<int> h1(l);
    RingHeadList<int> rh(1);

    RingHeadList<int> rh3(rh);


    RingHeadList<int> rh12;






    /*ListNode<int>* lv = h2.search(6);
    std::cout << lv->val;*/




    /*setlocale(LC_ALL, "Russian");

    cout << "¬ведите, какой стек тестируем\n" <<
        "0 - ArrayStack   1 - ListStack\n";
    char stack_type;
    cin >> stack_type;
    cin.ignore();
    while (stack_type != '0' && stack_type != '1') {
        cout << "¬ведите правильный тип\n";
        cin >> stack_type;
        cin.ignore();
    }


    string s;
    cout << "\n¬ведите выражение:\n";
    getline(cin, s);

    STACK_IMPL stack_impl;
    switch (stack_type)
    {
    case '0': stack_impl = ARRAY_STACK; break;
    case '1': stack_impl = LIST_STACK; break;
    }
    ArithmeticExpression expr(s, stack_impl);

    double res = expr.compute({});
    cout << "\nRes = " << res;

    return 0;*/
}
