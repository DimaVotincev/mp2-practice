

#include <gtest.h>

#include "BSTable.h"
/*
// ++

TEST(BSTable, can_create_BSTable) {
	try
	{
		BSTable<int,int> st2(10);
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


TEST(BSTable, can_find) {
	BSTable<int> sc(2);
	TabRecord<int, int>* add1 = new TabRecord<int,int>(1,nullptr);
	TabRecord<int, int>* add2 = new TabRecord<int, int>(5, nullptr);;
	sc.Insert(add1);
	sc.Insert(add2);
	ASSERT_NO_THROW(sc.Find(1));
}


TEST(BSTable, can_find_existing_elem) {
	BSTable<int> sc(2);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* add2 = new TabRecord<int, int>(5, nullptr);;
	sc.Insert(add1);
	sc.Insert(add2);
	EXPECT_FALSE(sc.Find(1) == nullptr);
}

TEST(BSTable, cant_find_not_existing_elem) {
	BSTable<int> sc(2);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* add2 = new TabRecord<int, int>(5, nullptr);
	sc.Insert(add1);
	sc.Insert(add2);
	EXPECT_TRUE(sc.Find(11) == nullptr);
}


TEST(BSTable, can_insert) {
	BSTable<int> sc(2);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	ASSERT_NO_THROW(sc.Insert(add1));
}

TEST(BSTable, cant_insert_in_full_BSTable) {
	BSTable<int> sc(2);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* add2 = new TabRecord<int, int>(2, nullptr);
	TabRecord<int, int>* add3 = new TabRecord<int, int>(3, nullptr);
	sc.Insert(add1);
	sc.Insert(add2);
	ASSERT_ANY_THROW(sc.Insert(add3));
}

TEST(BSTable, can_remove_existing_key) {
	BSTable<int> sc(2);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* add2 = new TabRecord<int, int>(5, nullptr);
	sc.Insert(add1);
	sc.Insert(add2);
	ASSERT_NO_THROW(sc.Remove(1));
}


TEST(BSTable, cant_remove_not_existing_key) {
	BSTable<int> sc(2);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	sc.Insert(add1);
	ASSERT_ANY_THROW(sc.Remove(2));
}



// Additional hard-tests


TEST(BSTable, can_insert_after_removing) {
	BSTable<int> sc(2);
	TabRecord<int, int>* add1 = new TabRecord<int, int>(1, nullptr);
	TabRecord<int, int>* add2 = new TabRecord<int, int>(5, nullptr);
	TabRecord<int, int>* add3 = new TabRecord<int, int>(6, nullptr);
	sc.Insert(add1);
	sc.Insert(add2);
	sc.Remove(5);
	ASSERT_NO_THROW(sc.Insert(add3));
}

TEST(BSTable, can_remove_after_insert_when_keys_has_same_hash) {
	BSTable<int> sc(5);
	// hash:   currID = key % this->maxsz;
	// hash2: (currID + hashstep) % maxsz;

	for (int i = 0; i < 5; i++) {
		sc.Insert(new TabRecord<int, int>(1 + i*5,nullptr));
	}
	ASSERT_NO_THROW(sc.Remove(1+4*5));
}

TEST(BSTable, insertion_removing_mix_when_keys_has_same_hash) {
	BSTable<int> sc(5);
	sc.Insert(new TabRecord<int, int>(1 + 1 * 5, nullptr)); // 6
	sc.Insert(new TabRecord<int, int>(1 + 2 * 5, nullptr)); // 6 11
	sc.Remove(1+1*5);  // 11
	sc.Insert(new TabRecord<int, int>(1 + 3 * 5, nullptr)); // 11 16
	sc.Insert(new TabRecord<int, int>(1 + 4 * 5, nullptr)); // 11 16 21
	sc.Remove(1 + 3 * 5); // 11 21
	sc.Remove(1 + 2 * 5); // 21
	sc.Insert(new TabRecord<int, int>(1 + 5 * 5, nullptr)); // 21 26
	sc.Remove(1 + 5 * 5); // 21
	ASSERT_NO_THROW(sc.Remove(21));
}

TEST(BSTable, insertion_removing_mix) {
	BSTable<int> sc(5);
	sc.Insert(new TabRecord<int, int>(1, nullptr)); 
	sc.Insert(new TabRecord<int, int>(6, nullptr));
	sc.Remove(1);
	sc.Insert(new TabRecord<int, int>(11, nullptr));
	sc.Insert(new TabRecord<int, int>(7, nullptr));
	sc.Remove(6);
	sc.Remove(7);
	sc.Insert(new TabRecord<int, int>(14, nullptr));
	sc.Remove(14);
	ASSERT_NO_THROW(sc.Remove(11));
}

*/

