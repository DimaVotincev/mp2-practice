#pragma once
#include "monom.h"



class Polinom : public Monom {
private:
    RingHeadList<Monom> polinom;
public:
    
    Polinom() {
        
    }

    Polinom(std::string str) {
        ArithmeticExpression expr(str);
        // vector<std::string> monoms = expr.convert();
    }
};




