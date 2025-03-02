#pragma once

#include "postfix_form.h"
#include "ringheadlist.h"
#include <sstream>
#include <iomanip>

class Monom {
protected:
    double coeff;
    int degree;
public:

    /*Monom() {
        coeff = 0;
        degree = -1;
    }

    Monom(double coef, int deg) {
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
    

    Monom operator+(const Monom& p);
    Monom operator-(const Monom& p);
    Monom operator*(const Monom& p);



    const Monom& operator=(const Monom& m){
        coeff = m.coeff;
        degree = m.degree;
        return *this;
    }

    bool operator==(const Monom& m) const {
        return coeff == m.coeff && 
            degree == m.degree;
    }

    bool operator!=(const Monom& m) const {
        return !(*this == m);
    }

    bool operator>(const Monom& m) const {
        return degree > m.degree;
    }

    bool operator>=(const Monom& m) const {
        return degree >= m.degree;
    }

    bool operator<(const Monom& m) const {
        return degree < m.degree;
    }  

    bool operator<=(const Monom& m) const {
        return degree <= m.degree;
    }*/


    Monom();
    Monom(double coef, int deg);
    Monom(const Monom& m);
    ~Monom();


    Monom operator+(const Monom& p);
    Monom operator-(const Monom& p);
    Monom operator*(const Monom& p);

    Monom operator+(double p);
    Monom operator-(double p);
    Monom operator*(double p);


    const Monom& operator=(const Monom& m);


    string Monom_tostr(); 
    double count(double x, double y, double z);

    // для мономов с 0 степенью
    bool operator==(double c) const;
    bool operator!=(double c) const;


    
    bool operator>(const Monom& m) const;
    bool operator>=(const Monom& m) const;
    bool operator<(const Monom& m) const;
    bool operator<=(const Monom& m) const;
    bool operator==(const Monom& m) const;
    bool operator!=(const Monom& m) const;
};



