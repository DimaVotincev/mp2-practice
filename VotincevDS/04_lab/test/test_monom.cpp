
#include <gtest.h>
#include "monom.h"


TEST(Monom, can_create_Monom)
{
    ASSERT_NO_THROW(Monom Monom);
}

TEST(Monom, can_create_Monom_by_parameters)
{
    ASSERT_NO_THROW(Monom Monom(1,2));
}

TEST(Monom, can_create_copied_Monoms)
{
    Monom m1(1,2);   
    ASSERT_NO_THROW(Monom Monom(m1));
}

TEST(Monom, copied_Monoms_are_equal)
{
    Monom m1(1, 2);
    Monom m2(m1);
    EXPECT_TRUE(m2 == m1);
}


TEST(Monom, assigned_Monoms_are_equal)
{
    Monom m1(1,2);
    Monom m2;
    m2 = m1;
    EXPECT_TRUE(m1 == m2);
}


TEST(Monom, can_adding_Monoms_with_same_degree)
{
    Monom m1(1,2);
    Monom m2(1, 2);
    ASSERT_NO_THROW(m1+m2);
}

TEST(Monom, cant_adding_Monoms_with_diff_degree)
{
    Monom m1(1, 3);
    Monom m2(1, 2);
    ASSERT_ANY_THROW(m1 + m2);
}

TEST(Monom, adding_Monoms_is_correct)
{
    Monom m1(1, 2);
    Monom m2(1, 2);
    Monom m3(2,2);
    ASSERT_NO_THROW(m3 == (m1+m2));
}


TEST(Monom, can_substract_Monoms_with_same_degree)
{
    Monom m1(1, 2);
    Monom m2(1, 2);
    ASSERT_NO_THROW(m1 - m2);
}

TEST(Monom, cant_substract_Monoms_with_diff_degree)
{
    Monom m1(1, 3);
    Monom m2(1, 2);
    ASSERT_ANY_THROW(m1 - m2);
}


TEST(Monom, substract_Monoms_is_correct)
{
    Monom m1(3, 2);
    Monom m2(1, 2);
    Monom m3(2, 2);
    ASSERT_NO_THROW(m3 == (m1 - m2));
}

TEST(Monom, can_multiply_Monoms)
{
    Monom m1(1, 2);
    Monom m2(1, 10);
    ASSERT_NO_THROW(m1 * m2);
}


TEST(Monom, multiply_Monoms_is_correct)
{
    Monom m1(5, 312);
    Monom m2(3, 87);
    Monom m3(15,399);
    ASSERT_NO_THROW(m3 == (m1 * m2));
}


TEST(Monom, can_add_const_to_Monom_with_deg_0)
{
    Monom m1(0,0);
    double c = 11.1;
    ASSERT_NO_THROW(m1+c);
}

TEST(Monom, cant_add_const_to_Monom_with_deg_not_0)
{
    Monom m1(0, 5);
    double c = 11.1;
    ASSERT_ANY_THROW(m1 + c);
}

TEST(Monom, add_const_to_Monom_with_deg_0_is_correct)
{
    Monom m1(0, 0);
    double c = 11.1;
    Monom m2(m1 + c);
    Monom m3(c, 0);
    EXPECT_TRUE(m2 == m3);
}



TEST(Monom, can_subctract_const_to_Monom_with_deg_0)
{
    Monom m1(0, 0);
    double c = 11.1;
    ASSERT_NO_THROW(m1 - c);
}

TEST(Monom, cant_subctract_const_to_Monom_with_deg_not_0)
{
    Monom m1(0, 5);
    double c = 11.1;
    ASSERT_ANY_THROW(m1 - c);
}

TEST(Monom, subctract_const_to_Monom_with_deg_0_is_correct)
{
    Monom m1(0, 0);
    double c = 11.1;
    Monom m2(m1 - c);
    Monom m3(-c, 0);
    EXPECT_TRUE(m2 == m3);
}


TEST(Monom, can_multiply_Monom_by_const)
{
    Monom m1(1, 3);
    double c = 11.1;
    ASSERT_NO_THROW(m1 * c);
}


TEST(Monom, multiply_Monom_by_const_is_correct)
{
    Monom m1(1, 3);
    double c = 11.1;
    Monom m2(m1*c);
    Monom m3(c, 3);
    EXPECT_TRUE(m2 == m3);
}


TEST(Monom, Monom_tostr__is_correct1)
{
    Monom m1(1, 3);
    string s = m1.Monom_tostr();
    string correct_str = "+z^3";
    EXPECT_TRUE(s == correct_str);
}


TEST(Monom, Monom_tostr__is_correct2)
{
    Monom m1(1, 33);
    string s = m1.Monom_tostr();
    string correct_str = "+y^3z^3";
    EXPECT_TRUE(s == correct_str);
}

TEST(Monom, Monom_tostr__is_correct3)
{
    Monom m1(1, 333);
    string s = m1.Monom_tostr();
    string correct_str = "+x^3y^3z^3";
    EXPECT_TRUE(s == correct_str);
}

TEST(Monom, Monom_tostr__is_correct4)
{
    Monom m1(4, 123);
    string s = m1.Monom_tostr();
    string correct_str = "+4xy^2z^3";
    EXPECT_TRUE(s == correct_str);
}

TEST(Monom, Monom_tostr__is_correct5)
{
    Monom m1(-4, 111);
    string s = m1.Monom_tostr();
    string correct_str = "-4xyz";
    EXPECT_TRUE(s == correct_str);
}



TEST(Monom, can_equalize_Monom_with_deg_0_to_const)
{
    Monom m1(10, 0);
    ASSERT_NO_THROW(m1 == 10);
}

TEST(Monom, equalize_Monom_with_deg_0_to_const_is_correct1)
{
    Monom m1(10, 0);
    EXPECT_TRUE(m1 == 10);
}

TEST(Monom, equalize_Monom_with_deg_0_to_const_is_correct2)
{
    Monom m1(10, 0);
    EXPECT_FALSE(m1 == 5);
}


TEST(Monom, operator_G_is_correct)
{
    Monom m1(1, 10);
    Monom m2(1, 1);
    EXPECT_TRUE(m1 > m2);
}

TEST(Monom, operator_GE_is_correct1)
{
    Monom m1(1, 10);
    Monom m2(1, 1);
    EXPECT_TRUE(m1 >= m2);
}

TEST(Monom, operator_GE_is_correct2)
{
    Monom m1(1, 10);
    Monom m2(1, 10);
    EXPECT_TRUE(m1 >= m2);
}


TEST(Monom, operator_L_is_correct)
{
    Monom m1(1, 11);
    Monom m2(1, 12);
    EXPECT_TRUE(m1 < m2);
}

TEST(Monom, operator_LE_is_correct1)
{
    Monom m1(1, 11);
    Monom m2(1, 12);
    EXPECT_TRUE(m1 <= m2);
}

TEST(Monom, operator_LE_is_correct2)
{
    Monom m1(1, 11);
    Monom m2(1, 11);
    EXPECT_TRUE(m1 <= m2);
}


TEST(Monom, operator_equal_is_correct)
{
    Monom Monom1(1,2);
    Monom Monom2(1,2);
    EXPECT_TRUE(Monom1 == Monom2);

}

TEST(Monom, operator_NotEqual_is_correct)
{
    Monom Monom1(1,2);
    Monom Monom2(3,4);
    EXPECT_TRUE(Monom1 != Monom2);

}
