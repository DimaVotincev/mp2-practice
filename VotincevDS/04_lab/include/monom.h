#pragma once

#include "postfix_form.h"
#include "ringheadlist.h"
#include <sstream>
#include <iomanip>


#define EPS 0.000001

struct Monom { // TODO struct?
    double coeff;
    int degree;

    Monom();
    Monom(double coef, int deg);
    Monom(const Monom& m);

    Monom operator+(const Monom& p);
    Monom operator-(const Monom& p);
    Monom operator*(const Monom& p);

    Monom operator*(double p);

    const Monom& operator=(const Monom& m);

    string Monom_tostr() const;
    
    double operator()(double x, double y, double z) const;

    bool operator>(const Monom& m) const;
    bool operator>=(const Monom& m) const;
    bool operator<(const Monom& m) const;
    bool operator<=(const Monom& m) const;

    bool operator==(const Monom& m) const;
    bool operator!=(const Monom& m) const;
};