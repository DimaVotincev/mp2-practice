#include "monom.h"


Monom::Monom() {
    coeff = 0;
    degree = -1;
}

Monom::Monom(double coef, int deg) {
    coeff = coef;
    if (0 <= deg && deg <= 999) {
        degree = deg;
    }
    else {
        throw "deg must be in [0,999]";
    }
}

Monom::Monom(const Monom& m) {
    coeff = m.coeff;
    degree = m.degree;
}

Monom Monom::operator+(const Monom& p)
{
    if (degree == p.degree) {
        return Monom(coeff + p.coeff, degree);
    }
    else {
        throw "monoms has diff degree";
    }
}

Monom Monom::operator-(const Monom& p)
{
    if (degree == p.degree) {
        return Monom(coeff - p.coeff, degree);
    }
    else {
        throw "monoms has diff degree";
    }
}

Monom Monom::operator*(const Monom& p)
{
    int x, px;
    x = degree / 100;
    px = p.degree / 100;

    if ((x + px) > 9) {
        throw "degree x is greater than 9";
    }

    int y, py;
    y = ((degree - 100 * (degree / 100)) / 10);
    py = ((p.degree - 100 * (p.degree / 100)) / 10);
    if ((y + py) > 9) {
        throw "degree y is greater than 9";
    }

    int z, pz;
    z = degree % 10;
    pz = p.degree % 10;
    if ((z + pz) > 9) {
        throw "degree z is greater than 9";
    }


    return Monom(coeff * p.coeff, degree + p.degree);
}

Monom Monom::operator*(double p)
{
    return Monom(coeff * p, degree);
}

string Monom::Monom_tostr() const {
    string answ;
    if (coeff > 0) {
        answ += "+";

        if (coeff != 1) {
            std::stringstream ss;
            ss << std::defaultfloat << coeff;
            answ += ss.str();
        }
        else if (degree == 0) {
            std::stringstream ss;
            ss << std::defaultfloat << coeff;
            answ += ss.str();
        }

    }
    else if (coeff < 0) {
        if (coeff != -1) {
            std::stringstream ss;
            ss << std::defaultfloat << coeff;
            answ += ss.str();
        }
        else if (degree == 0) {
            std::stringstream ss;
            ss << std::defaultfloat << coeff;
            answ += ss.str();
        }
        else {
            answ += "-";
        }
    }
    else {
        return "";
    }
    int tmp = degree;


    if (tmp / 100) {

        if ((tmp / 100) == 1) {
            answ += "x";
        }
        else {
            string xd = "x^";
            xd += '0' + tmp / 100;
            answ += xd;
        }
    }

    if ((tmp - 100 * (tmp / 100)) / 10) {

        if (((tmp - 100 * (tmp / 100)) / 10) == 1) {
            answ += "y";
        }
        else {
            string yd = "y^";
            yd += '0' + ((tmp - 100 * (tmp / 100)) / 10);
            answ += yd;
        }
    }

    if (tmp % 10) {
        if ((tmp % 10) == 1) {
            answ += "z";
        }
        else {
            string zd = "z^";
            zd += '0' + tmp % 10;
            answ += zd;
        }

    }

    return answ;
}

const Monom& Monom::operator=(const Monom& m) {
    if (this == &m)
    {
        return *this;
    }
    coeff = m.coeff;
    degree = m.degree;
    return *this;
}

bool Monom::operator==(const Monom& m) const {
    return degree == m.degree && fabs(coeff - m.coeff) <= EPS;
}

bool Monom::operator!=(const Monom& m) const {
    return !(*this == m);
}

bool Monom::operator>(const Monom& m) const {
    return degree > m.degree;
}

bool Monom::operator>=(const Monom& m) const {
    return degree >= m.degree;
}

bool Monom::operator<(const Monom& m) const {
    return degree < m.degree;
}

bool Monom::operator<=(const Monom& m) const {
    return degree <= m.degree;
}

double Monom::operator()(double x, double y, double z) const {
    int tmp = degree;
    double answ = coeff;
    // x
    if (tmp / 100) {
        answ *= pow(x, tmp / 100);
    }

    // y
    if ((tmp - 100 * (tmp / 100)) / 10) {
        answ *= pow(y, ((tmp - 100 * (tmp / 100)) / 10));
    }

    // z
    if (tmp % 10) {
        answ *= pow(z, tmp % 10);

    }
    return answ;
}