#include "scan_table.h"

#include <gtest.h>

// ++

TEST(ScanTable, can_create_ScanTable) {
	try
	{
		ScanTable<int, int> st2(10);
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





TEST(ScanTable, can_find) {
	ScanTable<int, int> sc(2);
	TabRecord<int, int>* add1 = new TabRecord<int,int>(1,nullptr);
	TabRecord<int, int>* add2 = new TabRecord<int, int>(5, nullptr);;
	sc.Insert(add1);
	sc.Insert(add2);
	ASSERT_NO_THROW(sc.Find(1));
}

TEST(ScanTable, can_find_existing_elem) {
	ScanTable<int, int> sc(2);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* add2 = new TabRecord<int, int>(5, nullptr);;
	sc.Insert(add1);
	sc.Insert(add2);
	EXPECT_FALSE(sc.Find(1) == nullptr);
}

TEST(ScanTable, cant_find_not_existing_elem) {
	ScanTable<int, int> sc(2);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* add2 = new TabRecord<int, int>(5, nullptr);
	sc.Insert(add1);
	sc.Insert(add2);
	EXPECT_TRUE(sc.Find(11) == nullptr);
}


TEST(ScanTable, can_insert) {
	ScanTable<int, int> sc(2);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	ASSERT_NO_THROW(sc.Insert(add1));
}

TEST(ScanTable, cant_insert_in_full_ScanTable) {
	ScanTable<int, int> sc(2);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* add2 = new TabRecord<int, int>(2, nullptr);
	TabRecord<int, int>* add3 = new TabRecord<int, int>(3, nullptr);
	sc.Insert(add1);
	sc.Insert(add2);
	ASSERT_ANY_THROW(sc.Insert(add3));
}

TEST(ScanTable, can_remove_existing_key) {
	ScanTable<int, int> sc(2);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* add2 = new TabRecord<int, int>(5, nullptr);
	sc.Insert(add1);
	sc.Insert(add2);
	ASSERT_NO_THROW(sc.Remove(1));
}


TEST(ScanTable, cant_remove_not_existing_key) {
	ScanTable<int, int> sc(2);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	sc.Insert(add1);
	ASSERT_ANY_THROW(sc.Remove(2));
}

// Additional hard-tests

//TEST(ScanTable, sort_stays_after_removing_inserting_mix) {
//	ScanTable<int, int> st(3);
//
//	st.Insert(new TabRecord<int, int>(5, nullptr)); // 5
//	st.Insert(new TabRecord<int, int>(1, nullptr)); // 5 1
//	st.Insert(new TabRecord<int, int>(3, nullptr)); // 5 1 3
//	st.Remove(1); // 5 3
//	st.Insert(new TabRecord<int, int>(4, nullptr)); // 5 3 4
//	st.Remove(5); // 3 4
//	st.Insert(new TabRecord<int, int>(5, nullptr)); // 3 4 5
//	st.Remove(3); // 4 5
//	st.Insert(new TabRecord<int, int>(10, nullptr)); // 4 5 10
//	st.Remove(5); // 4 10
//	st.Insert(new TabRecord<int, int>(2, nullptr)); // 4 10 2
//	st.Find(2);
//
//}
