#pragma once
#include "polinom.h"

#include <gtest.h>


TEST(Polinom, can_create_Polinom)
{
    ASSERT_NO_THROW(Polinom Polinom);
}

TEST(Polinom, can_create_Polinom_by_str)
{
    
    ASSERT_NO_THROW(Polinom p("x+y+z"));
}


TEST(Polinom, can_create_copied_Polinoms)
{
    
    Polinom p1("x+y+z");
    ASSERT_NO_THROW(Polinom p2(p1));
}

TEST(Polinom, copied_Polinoms_are_equal)
{
    
    Polinom p1("x+y+z");
    Polinom p2(p1);
    EXPECT_TRUE(p2 == p1);
}


TEST(Polinom, assigned_Polinoms_are_equal)
{
    
    Polinom p1("x+y+z");
    Polinom p2;
    p2 = p1;
    EXPECT_TRUE(p1 == p2);
}



TEST(Polinom, can_add_Monoms_to_Polinoms)
{
    Polinom p("x+y");
    Monom m(1, 2);
    ASSERT_NO_THROW(p+m);
}

TEST(Polinom, add_Monoms_to_Polinoms_is_correct1)
{
    Polinom p("x+y");
    Monom m(11, 2);  
    Polinom res("x+y+11z^2");
    EXPECT_TRUE(res == (p+m));
}

TEST(Polinom, add_Monoms_to_Polinoms_is_correct2)
{
    Polinom p("x+y");
    Monom m(5, 110);
    Polinom res("x+y+5xy");
    EXPECT_TRUE(res == (p + m));
}

TEST(Polinom, add_Monoms_to_Polinoms_is_correct3)
{
    Polinom p("x+y");
    Monom m(1, 999);
    Polinom res("x+y+x^9y^9z^9");
    EXPECT_TRUE(res == (p + m));
}

TEST(Polinom, add_Monoms_to_Polinoms_is_correct4)
{
    Polinom p("x+y");
    Monom m(-1, 110);
    Polinom res("x+y-xy");
    EXPECT_TRUE(res == (p + m));
}


TEST(Polinom, can_substract_Monoms_from_Polinoms)
{
    Polinom p("x+y");
    Monom m(1, 2);
    ASSERT_NO_THROW(p - m);
}

TEST(Polinom, substract_Monoms_from_Polinoms_is_correct1)
{
    Polinom p("x+y");
    Monom m(11, 2);
    Polinom res("x+y-11z^2");
    EXPECT_TRUE(res == (p - m));
}

TEST(Polinom, substract_Monoms_from_Polinoms_is_correct2)
{
    Polinom p("x+y");
    Monom m(5, 110);
    Polinom res("x+y-5xy");
    EXPECT_TRUE(res == (p - m));
}

TEST(Polinom, substract_Monoms_from_Polinoms_is_correct3)
{
    Polinom p("x+y");
    Monom m(1, 999);
    Polinom res("x+y-x^9y^9z^9");
    EXPECT_TRUE(res == (p - m));
}

TEST(Polinom, substract_Monoms_from_Polinoms_is_correct4)
{
    Polinom p("x+y");
    Monom m(-1, 110);
    Polinom res("x+y+xy");
    EXPECT_TRUE(res == (p - m));
}

TEST(Polinom, can_multiply_Polinoms_by_Monoms)
{
    Polinom p("x+y");
    Monom m(1, 2);
    ASSERT_NO_THROW(p * m);
}

TEST(Polinom, multiply_Polinoms_by_Monoms_is_correct1)
{
    Polinom p("x+y");
    Monom m(11, 0);
    Polinom res("11x+11y");
    EXPECT_TRUE(res == (p * m));
}

TEST(Polinom, multiply_Polinoms_by_Monoms_is_correct2)
{
    Polinom p("x+y");
    Monom m(5, 110);
    Polinom res("5x^2y+5xy^2");
    EXPECT_TRUE(res == (p * m));
}

TEST(Polinom, multiply_Polinoms_by_Monoms_is_correct3)
{
    Polinom p("x+y");
    Monom m(1, 1);
    Polinom res("xz+yz");
    EXPECT_TRUE(res == (p * m));
}

TEST(Polinom, multiply_Polinoms_by_Monoms_is_correct4)
{
    Polinom p("x-y");
    Monom m(-1, 55);
    Polinom res("-xy^5z^5+y^6z^5");
    EXPECT_TRUE(res == (p * m));
}


TEST(Polinom, can_add_coeff_to_Polinoms)
{
    Polinom p("x+y");
    ASSERT_NO_THROW(p + 3615.2461);
}



TEST(Polinom, add_coeff_to_Polinoms_is_correct1)
{
    Polinom p("x+y");
    Polinom res("3615.2461+x+y");
    EXPECT_TRUE(res == (p + 3615.2461));
}

TEST(Polinom, add_coeff_to_Polinoms_is_correct2)
{
    Polinom p("x+y");
    Polinom res("-214421.1246+x+y");
    EXPECT_TRUE(res == (p + (-214421.1246)));
}
TEST(Polinom, can_substract_coeff_from_Polinoms)
{
    Polinom p("x+y");
    ASSERT_NO_THROW(p -12345.6789);
}

TEST(Polinom, substract_coeff_from_Polinom_is_correct)
{
    Polinom p("x+y");
    Polinom res("-987.654321+x+y");
    EXPECT_TRUE(res == (p - 987.654321));
}


TEST(Polinom, can_multiply_Polinoms_by_coeff)
{
    Polinom p("x+y");
    ASSERT_NO_THROW(p * -12345.6789);
}

TEST(Polinom, multiply_Polinoms_by_coeff_is_correct)
{
    Polinom p("x+y");
    Polinom res("-12345.6789x-12345.6789y");
    EXPECT_TRUE(res == (p * -12345.6789));
}


TEST(Polinom, can_add_Polinoms)
{
    
    Polinom p1("x+y+z");
    Polinom p2("x+y");
    ASSERT_NO_THROW(p1 + p2);
}



TEST(Polinom, add_Polinoms_is_correct1)
{
    
    Polinom p1("x+y+z");
    Polinom p2("x+y");
    Polinom p3("2x+2y+z");
    EXPECT_TRUE(p3 == (p1+p2));
}

TEST(Polinom, add_Polinoms_is_correct2)
{

    Polinom p1("1+x");
    Polinom p2("xyz");
    Polinom p3("1+x+xyz");
    EXPECT_TRUE(p3 == (p1 + p2));
}

TEST(Polinom, add_Polinoms_is_correct3)
{

    Polinom p1("x^3yz+xy^3z+xyz^3");
    Polinom p2("x^3y^3z^3");
    Polinom p3("x^3yz+xy^3z+xyz^3+x^3y^3z^3");
    EXPECT_TRUE(p3 == (p1 + p2));
}

TEST(Polinom, add_Polinoms_is_correct4)
{

    Polinom p1("x-yz");
    Polinom p2("x+zy");
    Polinom p3("2x");
    EXPECT_TRUE(p3 == (p1 + p2));
}

TEST(Polinom, add_Polinoms_is_correct5)
{
    Polinom p1("x+y");
    Polinom p3("2x+2y");
    EXPECT_TRUE(p3 == (p1 + p1));
}


TEST(Polinom, can_substract_Polinoms)
{
    
    Polinom p1("x+y+z");
    Polinom p2("x+y");
    ASSERT_NO_THROW(p1 - p2);
}



TEST(Polinom, substract_Polinoms_is_correct1)
{
    
    Polinom p1("x+y+z");
    Polinom p2("x+y");
    Polinom p3("z");
    EXPECT_TRUE(p3 == (p1 - p2));
}

TEST(Polinom, substract_Polinoms_is_correct2)
{

    Polinom p1("x");
    Polinom p2("y+z");
    Polinom p3("x-y-z");
    EXPECT_TRUE(p3 == (p1 - p2));
}

TEST(Polinom, substract_Polinoms_is_correct3)
{

    Polinom p1("-x");
    Polinom p2("-yz");
    Polinom p3("-x+yz");
    EXPECT_TRUE(p3 == (p1 - p2));
}

TEST(Polinom, substract_Polinoms_is_correct4)
{

    Polinom p1("-1");
    Polinom p2("-y");
    Polinom p3("y-1");
    EXPECT_TRUE(p3 == (p1 - p2));
}

TEST(Polinom, substract_Polinoms_is_correct5)
{
    Polinom p1("x+y");
    Polinom p3("");
    EXPECT_TRUE(p3 == (p1 - p1));
}


TEST(Polinom, can_multiply_Polinoms)
{
    Polinom p1("x+y+z");
    ASSERT_NO_THROW(p1 * p1);
}

TEST(Polinom, multiply_Polinoms_is_correct1)
{
    Polinom p1("x+y");
    Polinom p2("x+y");
    Polinom p3("x^2+2xy+y^2");
    EXPECT_TRUE(p3 == (p1 * p2));
}

TEST(Polinom, multiply_Polinoms_is_correct2)
{
    Polinom p1("x-y");
    Polinom p2("x+y");
    Polinom p3("x^2-y^2");
    EXPECT_TRUE(p3 == (p1 * p2));
}

TEST(Polinom, multiply_Polinoms_is_correct3)
{
    Polinom p1("1");
    Polinom p2("xy");
    Polinom p3("xy");
    EXPECT_TRUE(p3 == (p1 * p2));
}

TEST(Polinom, multiply_Polinoms_is_correct4)
{
    Polinom p1("-1");
    Polinom p2("xy-zx+y");
    Polinom p3("-xy+zx-y");
    EXPECT_TRUE(p3 == (p1 * p2));
}

TEST(Polinom, can_multiply_Polinom_by_const)
{
    Polinom p1("x+y");
    double c = 11.1;
    ASSERT_NO_THROW(p1 * c);
}


TEST(Polinom, multiply_Polinom_by_const_is_correct)
{
    Polinom p1("1+x+y");
    double c = 11.1;
    Polinom res("11.1+11.1x+11.1y");
    EXPECT_TRUE((p1 * c) == res);
}


TEST(Polinom, operator_equal_is_correct)
{
    Polinom p1("x");
    Polinom p2("y");
    Polinom p3 = p1 + p2;
    Polinom p4("x+y");
    EXPECT_TRUE(p3 == p4);

}

TEST(Polinom, operator_NotEqual_is_correct)
{
    Polinom p1("x");
    Polinom p2("z");
    Polinom p3 = p1 + p2;
    Polinom p4("x+y");
    EXPECT_TRUE(p3 != p4);
}


TEST(Polinom, count_is_correct1)
{
    Polinom p1("x+y+z");
    double answ = p1(1,2,3);
    double real = 6;
    EXPECT_TRUE( answ == real);
}

TEST(Polinom, count_is_correct2)
{
    Polinom p1("-30y+10xy^2-3y^2z+xy^3z+30x-10x^2y-3xy^2+x^2y^3-3x^3+x^4y");
    double answ = p1(2, 5, 4);
    double real = 1316;
    EXPECT_TRUE(answ == real);
}


TEST(Polinom, count_is_correct3)
{
    Polinom p1("x+y");
    double answ = (p1*p1)(2, 3, 4);
    double real = 25;
    EXPECT_TRUE(answ == real);
}


TEST(Polinom, count_is_correct4)
{
    Polinom p1("x^2y^5+x^2y^6z");
    double answ = p1(2,2,2);
    double real = 640;
    EXPECT_TRUE(answ == real);
}
