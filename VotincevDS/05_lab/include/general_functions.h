#pragma once
//#include "sort_table.h"
//#include "array_hash_table.h"
bool is_digit(const char s);
bool is_xyz(const char s);
int degree_xyz(const char s);
bool is_correct_seq(const char c1, const char c2);
char get_oper();

//template <typename Tkey, typename Tdata>
//void print_tables(ScanTable<Tkey,Tdata> sct, 
//    SortedTable<Tkey, Tdata> sot, 
//    ArrayHashTable<Tkey, Tdata> ht);