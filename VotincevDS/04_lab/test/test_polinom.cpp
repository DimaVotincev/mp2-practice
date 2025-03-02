#pragma once
// #include "polinom.h"

#include <gtest.h>


//TEST(Polinom, can_create_Polinom)
//{
//    ASSERT_NO_THROW(Polinom Polinom);
//}

//TEST(Polinom, can_create_Polinom_by_str)
//{
//    string polinomstr = "x+y+z";
//    ASSERT_NO_THROW(Polinom p(polinomstr));
//}
//
//
//TEST(Polinom, can_create_copied_Polinoms)
//{
//    string polinomstr = "x+y+z";
//    Polinom p1(polinomstr);
//    ASSERT_NO_THROW(Polinom p2(p1));
//}
//
//TEST(Polinom, copied_Polinoms_are_equal)
//{
//    string polinomstr = "x+y+z";
//    Polinom p1(polinomstr);
//    Polinom p2(p1);
//    EXPECT_TRUE(p2 == p1);
//}
//
//
//TEST(Polinom, assigned_Polinoms_are_equal)
//{
//    string polinomstr = "x+y+z";
//    Polinom p1(polinomstr);
//    Polinom p2;
//    p2 = p1;
//    EXPECT_TRUE(p1 == p2);
//}
//
//
//TEST(Polinom, can_add_Polinoms)
//{
//    string polinomstr = "x+y+z";
//    Polinom p1(polinomstr);
//    Polinom p2("x+y");
//    ASSERT_NO_THROW(p1 + p2);
//}
//
//
//
//TEST(Polinom, adding_Polinoms_is_correct)
//{
//    string polinomstr = "x+y+z";
//    Polinom p1(polinomstr);
//    Polinom p2("x+y");
//    Polinom p3("2x+2y+z");
//    EXPECT_TRUE(p3==(p1+p2));
//}

/*
TEST(Polinom, can_substract_Polinoms_with_same_degree)
{
    Polinom p1(polinomstr);
    Polinom p2(1, 2);
    ASSERT_NO_THROW(p1 - p2);
}



TEST(Polinom, substract_Polinoms_is_correct)
{
    Polinom p1(3, 2);
    Polinom p2(1, 2);
    Polinom m3(2, 2);
    ASSERT_NO_THROW(m3 == (p1 - p2));
}

TEST(Polinom, can_multiply_Polinoms)
{
    Polinom p1(polinomstr);
    Polinom p2(1, 10);
    ASSERT_NO_THROW(p1 * p2);
}


TEST(Polinom, multiply_Polinoms_is_correct)
{
    Polinom p1(5, 312);
    Polinom p2(3, 87);
    Polinom m3(15, 399);
    ASSERT_NO_THROW(m3 == (p1 * p2));
}


TEST(Polinom, can_add_const_to_Polinom_with_deg_0)
{
    Polinom p1(0, 0);
    double c = 11.1;
    ASSERT_NO_THROW(p1 + c);
}

TEST(Polinom, cant_add_const_to_Polinom_with_deg_not_0)
{
    Polinom p1(0, 5);
    double c = 11.1;
    ASSERT_ANY_THROW(p1 + c);
}

TEST(Polinom, add_const_to_Polinom_with_deg_0_is_correct)
{
    Polinom p1(0, 0);
    double c = 11.1;
    Polinom p2(p1 + c);
    Polinom m3(c, 0);
    EXPECT_TRUE(p2 == m3);
}



TEST(Polinom, can_subctract_const_to_Polinom_with_deg_0)
{
    Polinom p1(0, 0);
    double c = 11.1;
    ASSERT_NO_THROW(p1 - c);
}

TEST(Polinom, cant_subctract_const_to_Polinom_with_deg_not_0)
{
    Polinom p1(0, 5);
    double c = 11.1;
    ASSERT_ANY_THROW(p1 - c);
}

TEST(Polinom, subctract_const_to_Polinom_with_deg_0_is_correct)
{
    Polinom p1(0, 0);
    double c = 11.1;
    Polinom p2(p1 - c);
    Polinom m3(-c, 0);
    EXPECT_TRUE(p2 == m3);
}


TEST(Polinom, can_multiply_Polinom_by_const)
{
    Polinom p1(1, 3);
    double c = 11.1;
    ASSERT_NO_THROW(p1 * c);
}


TEST(Polinom, multiply_Polinom_by_const_is_correct)
{
    Polinom p1(1, 3);
    double c = 11.1;
    Polinom p2(p1 * c);
    Polinom m3(c, 3);
    EXPECT_TRUE(p2 == m3);
}


TEST(Polinom, Polinom_tostr__is_correct1)
{
    Polinom p1(1, 3);
    string s = p1.Polinom_tostr();
    string correct_str = "+z^3";
    EXPECT_TRUE(s == correct_str);
}


TEST(Polinom, Polinom_tostr__is_correct2)
{
    Polinom p1(1, 33);
    string s = p1.Polinom_tostr();
    string correct_str = "+y^3z^3";
    EXPECT_TRUE(s == correct_str);
}

TEST(Polinom, Polinom_tostr__is_correct3)
{
    Polinom p1(1, 333);
    string s = p1.Polinom_tostr();
    string correct_str = "+x^3y^3z^3";
    EXPECT_TRUE(s == correct_str);
}

TEST(Polinom, Polinom_tostr__is_correct4)
{
    Polinom p1(4, 123);
    string s = p1.Polinom_tostr();
    string correct_str = "+4xy^2z^3";
    EXPECT_TRUE(s == correct_str);
}

TEST(Polinom, Polinom_tostr__is_correct5)
{
    Polinom p1(-4, 111);
    string s = p1.Polinom_tostr();
    string correct_str = "-4xyz";
    EXPECT_TRUE(s == correct_str);
}



TEST(Polinom, can_equalize_Polinom_with_deg_0_to_const)
{
    Polinom p1(10, 0);
    ASSERT_NO_THROW(p1 == 10);
}

TEST(Polinom, equalize_Polinom_with_deg_0_to_const_is_correct1)
{
    Polinom p1(10, 0);
    EXPECT_TRUE(p1 == 10);
}

TEST(Polinom, equalize_Polinom_with_deg_0_to_const_is_correct2)
{
    Polinom p1(10, 0);
    EXPECT_FALSE(p1 == 5);
}


TEST(Polinom, operator_G_is_correct)
{
    Polinom p1(1, 10);
    Polinom p2(1, 1);
    EXPECT_TRUE(p1 > p2);
}

TEST(Polinom, operator_GE_is_correct1)
{
    Polinom p1(1, 10);
    Polinom p2(1, 1);
    EXPECT_TRUE(p1 >= p2);
}

TEST(Polinom, operator_GE_is_correct2)
{
    Polinom p1(1, 10);
    Polinom p2(1, 10);
    EXPECT_TRUE(p1 >= p2);
}


TEST(Polinom, operator_L_is_correct)
{
    Polinom p1(1, 11);
    Polinom p2(1, 12);
    EXPECT_TRUE(p1 < p2);
}

TEST(Polinom, operator_LE_is_correct1)
{
    Polinom p1(1, 11);
    Polinom p2(1, 12);
    EXPECT_TRUE(p1 <= p2);
}

TEST(Polinom, operator_LE_is_correct2)
{
    Polinom p1(1, 11);
    Polinom p2(1, 11);
    EXPECT_TRUE(p1 <= p2);
}


TEST(Polinom, operator_equal_is_correct)
{
    Polinom Polinop1(polinomstr);
    Polinom Polinop2(1, 2);
    EXPECT_TRUE(Polinop1 == Polinop2);

}

TEST(Polinom, operator_NotEqual_is_correct)
{
    Polinom Polinop1(polinomstr);
    Polinom Polinop2(3, 4);
    EXPECT_TRUE(Polinop1 != Polinop2);

}


*/