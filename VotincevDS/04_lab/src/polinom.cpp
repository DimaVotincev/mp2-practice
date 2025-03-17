#include "polinom.h"


void Polinom::set_str() {

    polinom.reset_pCurr();
    string answ = "";
    while (!polinom.IsEnded()) {
        answ += polinom.getCurr().Monom_tostr();
        polinom.Next();
    }

    if (!answ.empty()) {
        if (answ[0] == '+') {
            answ.erase(0, 1);
        }

    }
    this->name = answ;
}




void Polinom::InsertOrder(const Monom& key) {

    polinom.reset_pCurr();

    if (polinom.IsEnded()) {
        polinom.pushBack(key);
        return;
    }


    while (!polinom.IsEnded()) {
        if (polinom.getCurr() > key) {
            ListNode<Monom>* add = new ListNode<Monom>(key);
            polinom.InsertBefore(add, polinom.getCurr());
            return;
        }
        else if (polinom.getCurr().degree == key.degree) {
            Monom tmp = polinom.getCurr();
            tmp = tmp + key;
            polinom.remove(polinom.getCurr());
            if (tmp.coeff == 0) {
                return;
            }
            InsertOrder(tmp);
            return;
        }
        polinom.Next();
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
    polinom.reset_pCurr();
    Polinom answ;
    while (!polinom.IsEnded()) {
        answ.polinom.pushBack(polinom.getCurr() * p);
        polinom.Next();
    }
    return answ;
}


Polinom Polinom::operator+(double c) // TODO: polinom + monom ++
{
    return *this + Monom(c, 0);
}


Polinom Polinom::operator-(double c)
{
    return Polinom::operator+(-c);
}


Polinom Polinom::operator*(double c)
{
    polinom.reset_pCurr();
    Polinom answ;
    while (!polinom.IsEnded()) {
        answ.polinom.pushBack(polinom.getCurr() * c);
        polinom.Next();
    }
    return answ;
}



Polinom Polinom::operator+(Polinom& p)
{
    if (this == &p) {
        polinom.reset_pCurr();
        Polinom answ(*this);
        answ = answ + p;
        return answ;
    }

    polinom.reset_pCurr();
    p.polinom.reset_pCurr();
    Polinom answ;
    while (!polinom.IsEnded() && !p.polinom.IsEnded()) {
        answ.InsertOrder(polinom.getCurr());
        answ.InsertOrder(p.polinom.getCurr());
        polinom.Next();
        p.polinom.Next();
    }
    while (!polinom.IsEnded())
    {
        answ.InsertOrder(polinom.getCurr());
        polinom.Next();
    }
    while (!p.polinom.IsEnded())
    {
        answ.InsertOrder(p.polinom.getCurr());
        p.polinom.Next();
    }

    answ.set_str();
    return answ;

}


Polinom Polinom::operator-(Polinom& p)
{
    if (*this == p) {
        return Polinom();
    }
    Polinom tmp = p;
    tmp = tmp * (-1.0);
    tmp.set_str();
    return Polinom::operator+(tmp);
}




Polinom Polinom::operator*(Polinom& p)  // TODO: реализуем вставку в упорядоченный список (отдельный метод) ++
{
    // сам на себя
    if (this == &p) {
        polinom.reset_pCurr();
        Polinom answ;
        Polinom tmp(*this);
        while (!polinom.IsEnded()) {
            while (!tmp.polinom.IsEnded()) {
                answ.InsertOrder(polinom.getCurr() * tmp.polinom.getCurr());
                tmp.polinom.Next();
            }
            polinom.Next();
            tmp.polinom.Next();
        }
        answ.set_str();
        return answ;
    }


    polinom.reset_pCurr();
    p.polinom.reset_pCurr();

    Polinom answ;
    while (!polinom.IsEnded()) {
        while (!p.polinom.IsEnded()) {
            answ.InsertOrder(polinom.getCurr() * p.polinom.getCurr());
            p.polinom.Next();
        }
        polinom.Next();
        p.polinom.Next();
    }
    answ.set_str();

    return answ;
}





bool Polinom::operator==(const Polinom& p) const {  // TODO: сравнение мономов ++
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



double Polinom::operator()(double x, double y, double z)
{
    polinom.reset_pCurr();
    double answ = 0;
    while (!polinom.IsEnded()) {
        answ += polinom.getCurr()(x, y, z);
        polinom.Next();
    }
    return answ;
}


