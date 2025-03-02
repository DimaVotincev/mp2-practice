#pragma once
#include "monom.h"
#include "general.h"
#include "algorithm"
using namespace std;


class Polinom : public Monom {
private:
    std::string name;
    RingHeadList<Monom> polinom;



public:

    Polinom();
    Polinom(const string& str);
    Polinom(const Polinom& p);


    void set_str();

    Polinom operator+(const Polinom& p);
    Polinom operator-(const Polinom& p);
    Polinom operator*(const Polinom& p);
    
    Polinom operator+(double c);
    Polinom operator-(double c);
    Polinom operator*(double c);

    
};







Polinom::Polinom() {

}


Polinom::Polinom(const string& str) {
    name = str;
    vector<string> monoms = ArithmeticExpression::ArithmeticExpression(str).convert(str);
    // счетчик считает кол-во изменений sgn
    // если counter = 2, значит ввод был неверен
    // Monom monomtoadd; это добавить в конце цикла

    vector<Monom> vpolinom;

    int sgn = 1, signs_counter = 0;
    // прохожу по токенам
    for (int i = 0; i < monoms.size(); i++) {


        if (monoms[i] == "+") {     // токен == +
            if (signs_counter == 2) {
                throw "polinom has 2 signs in a row";
            }
            sgn = 1;
            signs_counter++;
            continue;
        }
        else if (monoms[i] == "-") { // токен == -
            if (signs_counter == 2) {
                throw "polinom has 2 signs in a row";
            }
            sgn = -1;
            signs_counter++;
            continue;


        }
        else {                     // токен == моном
            signs_counter = 0;


            // моном (в виде строки)
            string strMonom = monoms[i];

            // добавл€ю мнимую часть дл€ удобства обработки
            strMonom += "y^0";

            // определ€ю коэф перед мономом
            string tmp_coeff;
            int j = 0;
            while (!is_xyz(strMonom[j]) && j < strMonom.size())
            {
                tmp_coeff += strMonom[j];
                j++;
            }

            double coeff;

            if (tmp_coeff.empty())
            {
                coeff = 1;
            }
            else
            {
                coeff = sgn * stod(tmp_coeff);
            }


            // определ€ю степень монома
            int degree = 0;
            for (j; j < strMonom.size(); j++) {

                // degree_xyz возвращает 
                // 100  если x
                //  10  если y
                //   1  если z
                //  -1  иначе
                int tmp_deg;
                tmp_deg = degree_xyz(strMonom[j]);
                if (tmp_deg == -1) {
                    throw "incorrect polinom";
                }


                if (strMonom[j + 1] == '^') {

                    if (is_digit(strMonom[j + 2])) { // переменна€ ^ цифра
                        string tmp;
                        tmp += strMonom[j + 2];

                        tmp_deg *= stoi(tmp);

                        if (is_digit(strMonom[j + 3])) { // переменна€ ^ цифра цифра
                            throw "degree must be >=0 and <= 9";
                        }

                        // обошел ещЄ 2 символа, поэтому +=2
                        j += 2;

                    }
                    else {   // переменна€ ^ не_цифра  == неверный ввод
                        throw "there must be digit after ^";
                    }
                    // добавл€ю к степени полинома степень переменной
                    degree += tmp_deg;
                    continue;
                }
                degree += tmp_deg;
            }

            Monom m(coeff, degree);          
            vpolinom.push_back(m);

        }
    }
    sort(vpolinom.begin(), vpolinom.end());
    for (Monom mn : vpolinom) {
        polinom.pushBack(mn);
    }
}



Polinom::Polinom(const Polinom& p) {
    this->name = p.name;
    this->polinom = p.polinom;
}


void Polinom::set_str() {
    string answ;
    ListNode<Monom>* tmp = polinom.get_pHead()->next;
    while (tmp != polinom.get_pHead()) {
        answ += tmp->val.Monom_tostr();
        tmp = tmp->next;
    }
    if (!answ.empty()) {
        if (answ[0] == '+') {
            answ.erase(0, 1);
        }
        
    }
    this->name = answ;
}




Polinom Polinom::operator+(const Polinom& p)
{
    Polinom answ;
    
    // answ.polinom.pushBack();
    ListNode<Monom>* iter1 = polinom.get_pHead()->next;
    ListNode<Monom>* iter2 = p.polinom.get_pHead()->next;
    while (iter1 != polinom.get_pHead() && iter2 != p.polinom.get_pHead()) {
        if (iter1->val < iter2->val)
        {
            answ.polinom.pushBack(iter1->val);
            iter1 = iter1->next;
        }
        else if (iter1->val > iter2->val ){
            answ.polinom.pushBack(iter2->val);
            iter2 = iter2->next;
        }
        else {
            // если сумма полиномов 0 
            if ((iter1->val + iter2->val) != 0) {
                iter1 = iter1->next;
                iter2 = iter2->next;
                continue;
            }
            answ.polinom.pushBack(iter1->val + iter2->val);
            iter1 = iter1->next;
            iter2 = iter2->next;
        }

    }
    while (iter1 != polinom.get_pHead())
    {
        answ.polinom.pushBack(iter1->val);
        iter1 = iter1->next;
    }

    while (iter2 != p.polinom.get_pHead())
    {
        answ.polinom.pushBack(iter2->val);
        iter2 = iter2->next;
    }

    // заполн€ю им€ полинома (строчный вариант вида полинома)
    answ.set_str();   

    return answ;
}


Polinom Polinom::operator-(const Polinom& p)
{
    Polinom tmp = p;
    tmp = tmp * (- 1.0);
    tmp.set_str();
    return Polinom::operator+(tmp);
}


Polinom Polinom::operator*(const Polinom& p)
{
    Polinom answ;
    ListNode<Monom>* iter1 = polinom.get_pHead()->next;
    ListNode<Monom>* iter2 = p.polinom.get_pHead()->next;
    while (iter1 != polinom.get_pHead() ) {
        while (iter2 != p.polinom.get_pHead()) {
            Monom add = iter1->val * iter2->val; 

            // если есть подобные
            if (answ.polinom.search(add) != answ.polinom.get_pHead()) {
                // привожу подобные
                answ.polinom.pushBack(add + answ.polinom.search(add)->val);
                answ.polinom.remove(answ.polinom.search(add)->val);               
                iter2 = iter2->next;
            }
            else {
                answ.polinom.pushBack(add);
                iter2 = iter2->next;
            }
            
            
        }
        iter2 = iter2->next;
        iter1 = iter1->next;
    }
    answ.set_str();
    
    return answ;
}

Polinom Polinom::operator+(double c)
{
    Polinom answ(*this);
    Monom tmp(1,0);

    // есть ли моном с 0 степенью?
    if (answ.polinom.get_pHead()->next->val <= tmp) {
        Monom add(answ.polinom.get_pHead()->next->val + c);
        answ.polinom.RemoveFirst();
        answ.polinom.pushFront(add);
        return answ;
    }
    answ.polinom.pushFront(Monom(c,0));
    return answ;
}


Polinom Polinom::operator-(double c) 
{
    return Polinom::operator+(-c);
}


Polinom Polinom::operator*(double c)
{
    Polinom answ;

    ListNode<Monom>* iter = polinom.get_pHead()->next;
    while (iter != polinom.get_pHead()) {
        answ.polinom.pushBack(iter->val * c);
        iter = iter->next;
    }
    return answ;
}

