#include "array_hash_table.h"

#include <gtest.h>

// ++

TEST(ArrayHashTable, can_create_ArrayHashTable) {
	try
	{
		ArrayHashTable<int, int> st2(10,2);
	}
	catch (const std::exception&)
	{
		ADD_FAILURE();
	}

	// просто написать 
	// ASSERT_NO_THROW(TabRecord<int, int> tr(1, data));
	// не получается 
	// (особенность gtest, там происходит неявное
	// приведение и компилятор может не понять)
	//
}


/*

TEST(ArrayHashTable, can_find) {
	ArrayHashTable<int, int> sc(2);
	TabRecord<int, int>* add1 = new TabRecord<int,int>(1,nullptr);
	TabRecord<int, int>* add2 = new TabRecord<int, int>(5, nullptr);;
	sc.Insert(add1);
	sc.Insert(add2);
	ASSERT_NO_THROW(sc.Find(1));
}

TEST(ArrayHashTable, can_find_existing_elem) {
	ArrayHashTable<int, int> sc(2);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* add2 = new TabRecord<int, int>(5, nullptr);;
	sc.Insert(add1);
	sc.Insert(add2);
	EXPECT_FALSE(sc.Find(1) == nullptr);
}

TEST(ArrayHashTable, cant_find_not_existing_elem) {
	ArrayHashTable<int, int> sc(2);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* add2 = new TabRecord<int, int>(5, nullptr);
	sc.Insert(add1);
	sc.Insert(add2);
	EXPECT_TRUE(sc.Find(11) == nullptr);
}


TEST(ArrayHashTable, can_insert) {
	ArrayHashTable<int, int> sc(2);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	ASSERT_NO_THROW(sc.Insert(add1));
}

TEST(ArrayHashTable, cant_insert_in_full_ArrayHashTable) {
	ArrayHashTable<int, int> sc(2);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* add2 = new TabRecord<int, int>(2, nullptr);
	TabRecord<int, int>* add3 = new TabRecord<int, int>(3, nullptr);
	sc.Insert(add1);
	sc.Insert(add2);
	ASSERT_ANY_THROW(sc.Insert(add3));
}

TEST(ArrayHashTable, can_remove_existing_key) {
	ArrayHashTable<int, int> sc(2);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* add2 = new TabRecord<int, int>(5, nullptr);
	sc.Insert(add1);
	sc.Insert(add2);
	ASSERT_NO_THROW(sc.Remove(1));
}


TEST(ArrayHashTable, cant_remove_not_existing_key) {
	ArrayHashTable<int, int> sc(2);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	sc.Insert(add1);
	ASSERT_ANY_THROW(sc.Remove(2));
}

*/