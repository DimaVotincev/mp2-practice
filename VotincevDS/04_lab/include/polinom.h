#pragma once

#include "postfix_form.h"
#include "ringheadlist.h"
#include "general_functions.h"
#include "monom.h"

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

    double operator()(double x, double y, double z) ;

    Polinom operator+(const Polinom& p); 
    Polinom operator-(const Polinom& p);
    Polinom operator*(const Polinom& p); 

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
