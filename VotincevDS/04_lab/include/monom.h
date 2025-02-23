#pragma once
#include "postfix_form.h"
#include "ringheadlist.h"


class Monom {
private:
    int coeff;
    int degree;
public:

    Monom() {
        coeff = 0;
        degree = -1;
    }

    Monom(int coef, int deg) {
        coeff = coef;
        if (0 <= deg && deg <= 999) {
            degree = deg;
        }
        else {
            throw "deg must be in [0,999]";
        }
    }

    Monom(const Monom& m) {
        coeff = m.coeff;
        degree = m.degree;
    }

    ~Monom() {
        
    }
    
    Monom& operator=(const Monom& m){
        coeff = m.coeff;
        degree = m.degree;
    }

    bool operator==(const Monom& m) const {
        return coeff == m.coeff && 
            degree == m.degree;
    }

    bool operator!=(const Monom& m) const {
        return !(*this == m);
    }

    bool operator>(const Monom& m) const {
        return coeff > m.coeff &&
            degree > m.degree;
    }

    bool operator>=(const Monom& m) const {
        return coeff >= m.coeff &&
            degree >= m.degree;
    }

    bool operator<(const Monom& m) const {
        return coeff < m.coeff &&
            degree < m.degree;
    }  

    bool operator<=(const Monom& m) const {
        return coeff <= m.coeff &&
            degree <= m.degree;
    }
};


