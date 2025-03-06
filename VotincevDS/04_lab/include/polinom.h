#pragma once

#include "monom.h"
#include "general.h"
using namespace std;


class Polinom {
private:
    std::string name;
    RingHeadList<Monom> polinom;

    void set_str();
    void InsertOrder(const Monom& key);
public:
    Polinom();
    Polinom(const string& str);
    Polinom(const Polinom& p);

    const Polinom& operator=(const Polinom& p);

    double operator()(double x, double y, double z) const;

    Polinom operator+(const Polinom& p);    // делаются через соответств операции с мономом 
    Polinom operator-(const Polinom& p);    //
    Polinom operator*(const Polinom& p);    // и функцией упорядоченной вставки

    Polinom operator+(const Monom& p);
    Polinom operator-(const Monom& p); 
    Polinom operator*(const Monom& p);

    Polinom operator-(double c);
    Polinom operator+(double c);
    Polinom operator*(double c);

    bool operator==(const Polinom& p) const;
    bool operator!=(const Polinom& p) const;

    friend std::ostream& operator<<(std::ostream&, Polinom&);
    friend std::istream& operator>>(std::istream&, Polinom&);

};




void Polinom::set_str() {
    string answ;
    ListNode<Monom>* tmp = polinom.get_pFirst();
    if (tmp == nullptr) {
        this->name = "";
        return;
    }

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




void Polinom::InsertOrder(const Monom& key) {

    if (polinom.get_pFirst() == nullptr) {
        polinom.pushBack(key);
        return;
    }

    ListNode<Monom>* mn = polinom.get_pFirst();
    while (mn->val.degree != -1) {
        if (mn->val > key) {
            ListNode<Monom>* add = new ListNode<Monom>(key);
            polinom.InsertBefore(add,mn->val);
            return;
        } else if (mn->val.degree == key.degree) {
            mn->val = mn->val + key;
            if (mn->val.coeff == 0) {
                polinom.remove(mn->val);
            }
            return;
        }
        mn = mn->next;
    }
    
    polinom.pushBack(key);
}




Polinom::Polinom() {

}
                                              
Polinom::Polinom(const string& str) {
    name = str;
    vector<string> monoms = ArithmeticExpression::ArithmeticExpression(str).convert(str);
    int sgn = 1, signs_counter = 0;

    for (int i = 0; i < monoms.size(); i++) {


        if (monoms[i] == "+") {
            if (signs_counter == 2) {
                throw "polinom has 2 signs in a row";
            }
            sgn = 1;
            signs_counter++;
            continue;
        }
        else if (monoms[i] == "-") { 
            if (signs_counter == 2) {
                throw "polinom has 2 signs in a row";
            }
            sgn = -1;
            signs_counter++;
            continue;


        }
        else {
            signs_counter = 0;

            string strMonom = monoms[i];

            strMonom += "y^0";
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
            int degree = 0;
            for (j; j < strMonom.size(); j++) {
                int tmp_deg;
                tmp_deg = degree_xyz(strMonom[j]);
                if (tmp_deg == -1) {
                    throw "incorrect polinom";
                }


                if (strMonom[j + 1] == '^') {

                    if (is_digit(strMonom[j + 2])) {
                        string tmp;
                        tmp += strMonom[j + 2];

                        tmp_deg *= stoi(tmp);

                        if (is_digit(strMonom[j + 3])) {
                            throw "degree must be >=0 and <= 9";
                        }
                        j += 2;

                    }
                    else {
                        throw "there must be digit after ^";
                    }
                    degree += tmp_deg;
                    continue;
                }
                degree += tmp_deg;
            }
            Monom m(coeff, degree);
            this->InsertOrder(m);
        }
    }
}

Polinom::Polinom(const Polinom& p) {
    this->name = p.name;
    this->polinom = p.polinom;
}

const Polinom& Polinom::operator=(const Polinom& p) {
    polinom = p.polinom;
    name = p.name;
    return *this;
}


Polinom Polinom::operator+(const Monom& p) {
    if (p.coeff == 0) {
        return *this;
    }
    Polinom answ(*this);
    answ.InsertOrder(p);
    return answ;
}


Polinom Polinom::operator-(const Monom& p) {
    Monom tmp = p;
    tmp = tmp * (-1.0);
    return Polinom::operator+(tmp);
}


Polinom Polinom::operator*(const Monom& p) {
    Polinom answ;
    ListNode<Monom>* iter = polinom.get_pFirst();
    while (iter != polinom.get_pHead()) {
        answ.polinom.pushBack(iter->val * p);
        iter = iter->next;
    }
    return answ;
}


Polinom Polinom::operator+(double c) // TODO: polinom + monom 
{
    Polinom answ;
    answ = *this;
    answ.InsertOrder(Monom(c, 0));
    return answ;
}


Polinom Polinom::operator-(double c)
{
    return Polinom::operator+(-c);
}


Polinom Polinom::operator*(double c)
{
    Polinom answ;
    ListNode<Monom>* iter = polinom.get_pFirst();
    while (iter != polinom.get_pHead()) {
        answ.polinom.pushBack(iter->val * c);
        iter = iter->next;
    }
    return answ;
}



Polinom Polinom::operator+(const Polinom& p)
{
    Polinom answ;
    ListNode<Monom>* iter1 = polinom.get_pFirst();
    ListNode<Monom>* iter2 = p.polinom.get_pFirst();
    while (iter1 != polinom.get_pHead() && iter2 != p.polinom.get_pHead()) {
        answ.InsertOrder(iter1->val);
        answ.InsertOrder(iter2->val);
        iter1 = iter1->next;
        iter2 = iter2->next;
    }
    while (iter1 != polinom.get_pHead())
    {
        answ.InsertOrder(iter1->val);
        iter1 = iter1->next;
    }
    while (iter2 != p.polinom.get_pHead())
    {
        answ.InsertOrder(iter2->val);
        iter2 = iter2->next;
    }

    answ.set_str();
    return answ;
}


Polinom Polinom::operator-(const Polinom& p)
{
    if (*this == p) {
        return Polinom();
    }
    Polinom tmp = p;
    tmp = tmp * (-1.0);
    tmp.set_str();
    return Polinom::operator+(tmp);
}




Polinom Polinom::operator*(const Polinom& p)  // TODO: реализуем вставку в упорядоченный список (отдельный метод)
{
    Polinom answ;
    ListNode<Monom>* iter1 = polinom.get_pFirst();
    ListNode<Monom>* iter2 = p.polinom.get_pFirst();
    while (iter1 != polinom.get_pHead()) {
        while (iter2 != p.polinom.get_pHead()) {
            answ.InsertOrder(iter1->val * iter2->val);
            iter2 = iter2->next;
        }    
        iter1 = iter1->next;
        iter2 = iter2->next;
    }
    answ.set_str();

    return answ;
}





bool Polinom::operator==(const Polinom& p) const {  // TODO: сравнение мономов
    return this->polinom == p.polinom;
}

bool Polinom::operator!=(const Polinom& p) const {
    return !(Polinom::operator==(p));
}




std::ostream& operator<<(std::ostream& out, Polinom& p) {
    out << p.name << "\n";
    return out;
}

std::istream& operator>>(std::istream& in, Polinom& p) {
    string strPolinom;
    getline(in, strPolinom);
    p = Polinom(strPolinom);
    return in;
}



double Polinom::operator()(double x, double y, double z) const {
    double answ = 0;
    ListNode<Monom>* iter = polinom.get_pFirst();
    while (iter != polinom.get_pHead()) {
        answ += iter->val(x, y, z);
        iter = iter->next;
    }
    return answ;
}


