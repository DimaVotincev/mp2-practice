#pragma once
#include <iostream>
#include "table.h"
#include "sort_table.h"
#include "array_hash_table.h"
#include "polinom.h"

using namespace std;

bool is_digit(const char s);
bool is_xyz(const char s);
int degree_xyz(const char s);
bool is_correct_seq(const char c1, const char c2);
char get_oper();
bool get_id(int& id, int max);





