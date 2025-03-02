#pragma once
#include "polinom.h"

#include <gtest.h>


TEST(Polinom, can_create_Polinom)
{
    ASSERT_NO_THROW(Polinom Polinom);
}

TEST(Polinom, can_create_Polinom_by_str)
{
    string polinomstr = "x+y+z";
    ASSERT_NO_THROW(Polinom p(polinomstr));
}


TEST(Polinom, can_create_copied_Polinoms)
{
    string polinomstr = "x+y+z";
    Polinom p1(polinomstr);
    ASSERT_NO_THROW(Polinom p2(p1));
}

TEST(Polinom, copied_Polinoms_are_equal)
{
    string polinomstr = "x+y+z";
    Polinom p1(polinomstr);
    Polinom p2(p1);
    EXPECT_TRUE(p2 == p1);
}


TEST(Polinom, assigned_Polinoms_are_equal)
{
    string polinomstr = "x+y+z";
    Polinom p1(polinomstr);
    Polinom p2;
    p2 = p1;
    EXPECT_TRUE(p1 == p2);
}


TEST(Polinom, can_add_Polinoms)
{
    string polinomstr = "x+y+z";
    Polinom p1(polinomstr);
    Polinom p2("x+y");
    ASSERT_NO_THROW(p1 + p2);
}



TEST(Polinom, add_Polinoms_is_correct)
{
    string polinomstr = "x+y+z";
    Polinom p1(polinomstr);
    Polinom p2("x+y");
    Polinom p3("2x+2y+z");
    EXPECT_TRUE(p3 == (p1+p2));
}


TEST(Polinom, can_substract_Polinoms)
{
    string polinomstr = "x+y+z";
    Polinom p1(polinomstr);
    Polinom p2("x+y");
    ASSERT_NO_THROW(p1 - p2);
}



TEST(Polinom, substract_Polinoms_is_correct)
{
    string polinomstr = "x+y+z";
    Polinom p1(polinomstr);
    Polinom p2("x+y");
    Polinom p3("z");
    EXPECT_TRUE(p3 == (p1 - p2));
}

TEST(Polinom, can_multiply_Polinoms)
{
    string polinomstr = "x+y";
    Polinom p1(polinomstr);
    ASSERT_NO_THROW(p1 * p1);
}


TEST(Polinom, multiply_Polinoms_is_correct)
{
    string polinomstr = "x+y";
    Polinom p1(polinomstr);
    Polinom p3("x^2+2xy+y^2");
    EXPECT_TRUE(p3 == (p1 * p1));
}



TEST(Polinom, can_add_const_to_Polinom)
{
    Polinom p1("x+y");
    double c = 11.1;
    ASSERT_NO_THROW(p1 + c);
}


TEST(Polinom, add_const_to_Polinom_is_correct)
{
    Polinom p1("1+x+y");
    double c = 11.1;
    Polinom res("12.1+x+y");
    EXPECT_TRUE((p1+c) == res);
}



TEST(Polinom, can_subctract_const_to_Polinom)
{
    Polinom p1("x+y");
    double c = 11.1;
    ASSERT_NO_THROW(p1 - c);
}


TEST(Polinom, subctract_const_to_Polinom_is_correct)
{
    Polinom p1("1+x+y");
    double c = 11.1;
    Polinom res("-10.1+x+y");
    EXPECT_TRUE((p1 - c) == res);
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
    double c = 10;
    Polinom res("10+10x+10y");
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
    double answ = p1.count(1,2,3);
    double real = 6;
    EXPECT_TRUE( answ == real);
}

TEST(Polinom, count_is_correct2)
{
    Polinom p1("-30y+10xy^2-3y^2z+xy^3z+30x-10x^2y-3xy^2+x^2y^3-3x^3+x^4y");
    double answ = p1.count(2, 5, 4);
    double real = 1316;
    EXPECT_TRUE(answ == real);
}


TEST(Polinom, count_is_correct3)
{
    Polinom p1("x+y");
    double answ = (p1*p1).count(2, 3, 4);
    double real = 4+12+9;
    EXPECT_TRUE(answ == real);
}