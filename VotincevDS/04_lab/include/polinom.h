#pragma once
#include "monom.h"



class Polinom : public Monom {
private:
    std::string name;
    RingHeadList<Monom> polinom;
public:
    
    Polinom() {
        
    }

    Polinom(const std::string& str) {
        name = str;
        ArithmeticExpression expr(str);
        // vector<std::string> monoms = expr.convert();
    }
};




