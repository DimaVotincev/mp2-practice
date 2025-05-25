#include "sort_table.h"

#include <gtest.h>

// ++

TEST(SortedTable, can_create_SortedTable) {
	try
	{
		SortedTable<int, int> st2(10);
		return;
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



TEST(SortedTable, can_create_by_ScanTable) {
	ScanTable<int, int> sc(3);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(8, nullptr);
	TabRecord<int, int>* add2 = new TabRecord<int, int>(5, nullptr);
	TabRecord<int, int>* add3 = new TabRecord<int, int>(1, nullptr);
	sc.Insert(add1);
	sc.Insert(add2);
	sc.Insert(add3);
	try
	{
		SortedTable<int, int> st(sc);
		return;
	}
	catch (const std::exception&)
	{
		ADD_FAILURE();
	}
}

TEST(SortedTable, can_create_by_SortTable) {
	SortedTable<int, int> sc(2);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* add2 = new TabRecord<int, int>(5, nullptr);
	sc.Insert(add1);
	sc.Insert(add2);
	SortedTable<int, int> st(sc);
	ASSERT_NO_THROW(sc.Find(1));
}

TEST(SortedTable, can_find) {
	SortedTable<int, int> sc(2);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* add2 = new TabRecord<int, int>(5, nullptr);
	sc.Insert(add1);
	sc.Insert(add2);
	ASSERT_NO_THROW(sc.Find(1));
}

TEST(SortedTable, can_find_existing_elem) {
	SortedTable<int, int> sc(2);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* add2 = new TabRecord<int, int>(5, nullptr);
	sc.Insert(add1);
	sc.Insert(add2);
	EXPECT_FALSE(sc.Find(1) == nullptr);
}

TEST(SortedTable, cant_find_not_existing_elem) {
	SortedTable<int, int> sc(2);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* add2 = new TabRecord<int, int>(5, nullptr);
	sc.Insert(add1);
	sc.Insert(add2);
	EXPECT_TRUE(sc.Find(11) == nullptr);
}

TEST(SortedTable, can_insert) {
	SortedTable<int, int> sc(2);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	ASSERT_NO_THROW(sc.Insert(add1));
}

TEST(SortedTable, cant_insert_in_full_SortedTable) {
	SortedTable<int, int> sc(2);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* add2 = new TabRecord<int, int>(2, nullptr);
	TabRecord<int, int>* add3 = new TabRecord<int, int>(3, nullptr);
	sc.Insert(add1);
	sc.Insert(add2);
	ASSERT_ANY_THROW(sc.Insert(add3));
}

TEST(SortedTable, can_remove_existing_key) {
	SortedTable<int, int> sc(2);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	sc.Insert(add1);
	ASSERT_NO_THROW(sc.Remove(1));
}


TEST(SortedTable, cant_remove_not_existing_key) {
	SortedTable<int, int> sc(2);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	sc.Insert(add1);
	ASSERT_ANY_THROW(sc.Remove(2));
}

// Additional hard-tests

//TEST(SortedTable, sort_stays_after_removing_inserting_mix) {
//	SortedTable<int, int> sc(5);
//	sc.Insert(new TabRecord<int, int>(5, nullptr)); // 5
//	sc.Insert(new TabRecord<int, int>(1, nullptr)); // 1 5
//	sc.Remove(1); // 5
//	sc.Insert(new TabRecord<int, int>(3, nullptr)); // 3 5
//	sc.Insert(new TabRecord<int, int>(2, nullptr)); // 2 3 5
//	sc.Remove(5); // 2 3
//	sc.Insert(new TabRecord<int, int>(10, nullptr)); // 2 3 10
//	sc.Remove(3); // 2 10
//	sc.Insert(new TabRecord<int, int>(3, nullptr)); // 2 3 10
//	sc.Insert(new TabRecord<int, int>(11, nullptr)); // 2 3 10 11
//	sc.Insert(new TabRecord<int, int>(1, nullptr)); // 1 2 3 10 11
//}
