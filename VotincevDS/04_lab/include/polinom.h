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
    double count(double x, double y, double z);

    Polinom operator+(const Polinom& p);
    Polinom operator-(const Polinom& p);
    Polinom operator*(const Polinom& p);
    
    Polinom operator+(double c);
    Polinom operator-(double c);
    Polinom operator*(double c);

    bool operator==(const Polinom& p);
    bool operator!=(const Polinom& p);
    
    friend std::ostream& operator<<(std::ostream&, Polinom&);
    friend std::istream& operator>>(std::istream&, Polinom&);

};






Polinom::Polinom() {
    return;
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
                coeff = sgn;
            }
            else
            {   
                try {
                    coeff = sgn * stod(tmp_coeff);
                }
                catch (std::exception) {
                    throw "invalid polinom";
                }
                
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
        // если есть подобные
        if (polinom.search(mn) != polinom.get_pHead()) {
            polinom.pushBack(mn + polinom.search(mn)->val);
            polinom.remove(polinom.search(mn)->val);
            continue;
        }
        polinom.pushBack(mn);
    }
    this->set_str();
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
        else if (iter1->val > iter2->val) {
            answ.polinom.pushBack(iter2->val);
            iter2 = iter2->next;
        }
        else {
            // если сумма полиномов 0 
            if ((iter1->val + iter2->val) == 0) {
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
    tmp = tmp * (-1.0);
    tmp.set_str();
    return Polinom::operator+(tmp);
}


Polinom Polinom::operator*(const Polinom& p)
{
    Polinom answ;
    ListNode<Monom>* iter1 = polinom.get_pHead()->next;
    ListNode<Monom>* iter2 = p.polinom.get_pHead()->next;
    while (iter1 != polinom.get_pHead()) {
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
    Monom tmp(1, 0);

    // есть ли моном с 0 степенью?
    if (answ.polinom.get_pHead()->next->val <= tmp) {
        Monom add(answ.polinom.get_pHead()->next->val + c);
        answ.polinom.RemoveFirst();
        answ.polinom.pushFront(add);
        return answ;
    }
    answ.polinom.pushFront(Monom(c, 0));
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




bool Polinom::operator==(const Polinom& p) {
    ListNode<Monom>* iter1 = polinom.get_pHead()->next;
    ListNode<Monom>* iter2 = p.polinom.get_pHead()->next;
    while (iter1 != polinom.get_pHead() && iter2 != p.polinom.get_pHead()) {
        if (iter1->val != iter2->val) {
            return 0;
        }
        iter1 = iter1->next;
        iter2 = iter2->next;
    }
    if (iter1 != polinom.get_pHead() || iter2 != p.polinom.get_pHead()) {
        return 0;
    }
    return 1;
}

bool Polinom::operator!=(const Polinom& p) {
    return !(Polinom::operator==(p));
}





std::ostream& operator<<(std::ostream& out, Polinom& p) {
    out << p.name << "\n";
    return out;
}

std::istream& operator>>(std::istream& in, Polinom& p) {
    string strPolinom;
    in >> strPolinom;
    p = Polinom(strPolinom);
    return in;
}



double Polinom::count(double x, double y, double z) {
    double answ = 0;
    auto iter = polinom.get_pHead()->next;
    while (iter != polinom.get_pHead()) {
        answ += iter->val.count(x,y,z);
        iter = iter->next;
    }
    return answ;
}







Polinom make_op(Polinom p1, Polinom p2, char s) {
    switch (s)
    {
    case '+': return p1 + p2; break;
    case '-': return p1 - p2; break;
    case '*': return p1 * p2; break;
    default:
        break;
    }
}