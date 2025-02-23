#include <iostream>
#include "headlist.h"
#include "ringheadlist.h"
#include "polinom.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

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
    
    RingHeadList<int> h1;
    RingHeadList<int> h2(1);
    RingHeadList<int> h3(l);
    RingHeadList<int> h4(h3);


    List<int> l1(l);

    RingHeadList<int> h5;
    h5 = l1;
    RingHeadList<int> h6;
    h6 = h5;

    ListNode<int>* lfvalue;
    lfvalue = h6.searchLast();


    RingHeadList<int> h7(h6);
    h7.push(8);

    RingHeadList<int> h8(h6);
    ListNode<int>* nodetoadd1 = new ListNode<int>(4);
    h8.pushFront(nodetoadd1);

    RingHeadList<int> h9(h6);
    ListNode<int>* nodetoadd2 = new ListNode<int>(8);
    h9.pushBack(nodetoadd2);

    RingHeadList<int> h10(h6);
    ListNode<int>* nodetoadd3 = new ListNode<int>(10);
    h10.InsertBefore(nodetoadd3,6);


    RingHeadList<int> h11(h6);
    RingHeadList<int> h12(h6);
    cout << (h11 == h12);

    return 1;
















    //RingHeadList<int> rh(l);
    //RingHeadList<int> rh3(rh);
    //RingHeadList<int> rh12;






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
