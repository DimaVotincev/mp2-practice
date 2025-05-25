#include "tab_record.h"

#include <gtest.h>

// ++

TEST(TABRECORD, can_create_tabrecord) {
    int* data = new int[5];
	try
	{
		TabRecord<int, int> tr(1, data);
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


TEST(TABRECORD, can_get_key) {
	int* data = new int[5];
	TabRecord<int, int> tr(1, data);
	ASSERT_NO_THROW(tr.get_key());
}

TEST(TABRECORD, get_key_is_correct) {
	int* data = new int[5];
	int key = 262;
	TabRecord<int, int> tr(key, data);
	EXPECT_TRUE(tr.get_key() == key);
}

TEST(TABRECORD, can_get_data) {
	int* data = new int[5];
	TabRecord<int, int> tr(1, data);
	ASSERT_NO_THROW(tr.get_data());
}

TEST(TABRECORD, get_data_is_correct) {
	int* data = new int[5];
	TabRecord<int, int> tr(1, data);
	EXPECT_TRUE(tr.get_data() == data);
}