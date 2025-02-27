#include <gtest.h>

#include "headlist.h"



TEST(HeadList, can_create_HeadList)
{
    ASSERT_NO_THROW(HeadList<int> HeadList);
}

TEST(HeadList, can_create_HeadList_by_elem)
{
    ASSERT_NO_THROW(HeadList<int> HeadList(5));
}

TEST(HeadList, can_create_copied_HeadLists)
{
    HeadList<int> l1;
    ListNode<int>* node = new ListNode<int>(0);
    node->next = new ListNode<int>(1);
    node->next->next = new ListNode<int>(2);

    l1.pushBack(node);
    ASSERT_NO_THROW(HeadList<int> HeadList(l1));
}

TEST(HeadList, copied_HeadLists_are_equal)
{
    HeadList<int> l1;
    ListNode<int>* node = new ListNode<int>(0);
    node->next = new ListNode<int>(1);
    node->next->next = new ListNode<int>(2);

    l1.pushBack(node);
    HeadList<int> l2(l1);
    EXPECT_TRUE(l1 == l2);
}




TEST(HeadList, can_create_HeadList_by_ListNode)
{
    ListNode<int>* node = new ListNode<int>(0);
    node->next = new ListNode<int>(1);
    node->next->next = new ListNode<int>(2);

    ASSERT_NO_THROW(HeadList<int> l(node));
}

TEST(HeadList, creating_HeadList_by_ListNode_is_correct)
{
    ListNode<int>* node = new ListNode<int>(0);
    node->next = new ListNode<int>(1);
    node->next->next = new ListNode<int>(2);

    HeadList<int> HeadList1(node);
    HeadList<int> HeadList2;
    HeadList2.pushBack(node);

    EXPECT_TRUE(HeadList1 == HeadList2);
}


TEST(HeadList, assigned_HeadLists_are_equal)
{
    ListNode<int>* node = new ListNode<int>(0);
    node->next = new ListNode<int>(1);
    node->next->next = new ListNode<int>(2);

    HeadList<int> l1;
    l1.pushBack(node);

    HeadList<int> l2;
    l2 = l1;

    EXPECT_TRUE(l1 == l2);
}


TEST(HeadList, can_search_existing_elem)
{
    HeadList<int> HeadList;
    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);
    HeadList.pushBack(node);
    ASSERT_NO_THROW(HeadList.search(5));
}

TEST(HeadList, cant_search_not_existing_elem)
{
    HeadList<int> HeadList;
    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);
    HeadList.pushBack(node);
    ASSERT_ANY_THROW(HeadList.search(7));
}

TEST(HeadList, double_search_works_correctly)
{
    HeadList<int> HeadList;
    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);
    node->next->next = new ListNode<int>(7);

    HeadList.pushBack(node);
    HeadList.search(6);

    EXPECT_TRUE(HeadList.search(5) == HeadList.get_head());
}


TEST(HeadList, can_pushFront_elem)
{
    HeadList<int> HeadList;
    ListNode<int>* node = new ListNode<int>(5);
    ASSERT_NO_THROW(HeadList.pushFront(node));
}

TEST(HeadList, cant_pushFront_nullptr_in_not_empty_HeadList)
{
    HeadList<int> HeadList;
    ListNode<int>* node = new ListNode<int>(5);
    HeadList.pushBack(node);
    ASSERT_ANY_THROW(HeadList.pushFront(nullptr));
}

TEST(HeadList, pushFront_works_correctly)
{

    ListNode<int>* node1 = new ListNode<int>(5);
    HeadList<int> HeadList(node1);

    ListNode<int>* node2 = new ListNode<int>(4);
    HeadList.pushFront(node2);
    EXPECT_TRUE(HeadList.get_head()->val == 4);
}



TEST(HeadList, can_pushBack_elem)
{
    HeadList<int> HeadList;
    ListNode<int>* node = new ListNode<int>(5);
    ASSERT_NO_THROW(HeadList.pushBack(node));
}


TEST(HeadList, can_InsertAfter_elem)
{
    HeadList<int> HeadList;
    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);
    HeadList.pushBack(node);
    ListNode<int>* add = new ListNode <int>(7);
    ASSERT_NO_THROW(HeadList.InsertAfter(add, 6));
}

TEST(HeadList, cant_InsertAfter_not_existing_elem)
{
    HeadList<int> HeadList;
    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);
    HeadList.pushBack(node);
    ListNode<int>* add = new ListNode <int>(7);
    ASSERT_ANY_THROW(HeadList.InsertAfter(add, 7));
}

TEST(HeadList, InsertAfter_works_correctly1)
{
    //  тест на вставку в конец

    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);

    HeadList<int> HeadList;
    HeadList.pushBack(node);

    ListNode<int>* add = new ListNode <int>(7);
    HeadList.InsertAfter(add, 6);   // 5 6 7

    EXPECT_EQ(HeadList.search(6)->next->val, 7);
}

TEST(HeadList, InsertAfter_works_correctly2)
{
    //  тест на вставку в середину

    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);

    HeadList<int> HeadList;
    HeadList.pushBack(node);

    ListNode<int>* add = new ListNode <int>(7);
    HeadList.InsertAfter(add, 5);  // 5 7 6

    EXPECT_EQ(HeadList.search(5)->next->val, 7);
}


TEST(HeadList, can_InsertBefore_elem)
{
    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);

    HeadList<int> HeadList;
    HeadList.pushBack(node);

    ListNode<int>* add = new ListNode <int>(7);

    ASSERT_NO_THROW(HeadList.InsertBefore(add, 6));
}

TEST(HeadList, cant_InsertBefore_not_existing_elem)
{
    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);

    HeadList<int> HeadList;
    HeadList.pushBack(node);

    ListNode<int>* add = new ListNode <int>(7);

    ASSERT_ANY_THROW(HeadList.InsertBefore(add, 7));
}

TEST(HeadList, InsertBefore_works_correctly1)
{
    // тест на вставку в середину

    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);

    HeadList<int> HeadList;
    HeadList.pushBack(node);

    ListNode<int>* add = new ListNode <int>(7);
    HeadList.InsertBefore(add, 6); // 5  7  6

    EXPECT_EQ(HeadList.get_head()->next->val, 7);
}

TEST(HeadList, InsertBefore_works_correctly2)
{
    // тест на вставку в начало

    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);

    HeadList<int> HeadList;
    HeadList.pushBack(node);

    ListNode<int>* add = new ListNode <int>(7);
    HeadList.InsertBefore(add, 5); // 7 5 6

    EXPECT_EQ(HeadList.get_head()->val, 7);
}


TEST(HeadList, can_remove_elem)
{
    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);

    HeadList<int> HeadList;
    HeadList.pushBack(node);

    ListNode<int>* add = new ListNode <int>(7);
    ASSERT_NO_THROW(HeadList.remove(6));
}

TEST(HeadList, cant_remove_not_existing_elem)
{
    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);

    HeadList<int> HeadList;
    HeadList.pushBack(node);

    ListNode<int>* add = new ListNode <int>(7);
    ASSERT_ANY_THROW(HeadList.remove(7));
}

TEST(HeadList, remove_works_correctly1)
{
    // тест на удаление в начале

    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);
    node->next->next = new ListNode<int>(7);

    HeadList<int> HeadList;
    HeadList.pushBack(node);  // 5 6 7
    HeadList.remove(5);       // 6 7
    EXPECT_EQ(HeadList.get_head()->val, 6);

}

TEST(HeadList, remove_works_correctly2)
{
    // тест на удаление в середине

    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);
    node->next->next = new ListNode<int>(7);

    HeadList<int> HeadList;
    HeadList.pushBack(node); // 5 6 7
    HeadList.remove(6); // 5 7
    EXPECT_EQ(HeadList.get_head()->next->val, 7);
}

TEST(HeadList, remove_works_correctly3)
{
    // тест на удаление в конце

    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);
    node->next->next = new ListNode<int>(7);

    HeadList<int> HeadList;
    HeadList.pushBack(node); // 5 6 7
    HeadList.remove(7); // 5 6
    EXPECT_EQ(HeadList.get_head()->next->val, 6);
}

TEST(HeadList, can_RemoveFirst_elem)
{
    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);

    HeadList<int> HeadList;
    HeadList.pushBack(node);

    ListNode<int>* add = new ListNode <int>(7);
    ASSERT_NO_THROW(HeadList.RemoveFirst());
}

TEST(HeadList, cant_RemoveFirst_in_empty_HeadList)
{
    HeadList<int> HeadList;
    ASSERT_ANY_THROW(HeadList.RemoveFirst());
}

TEST(HeadList, RemoveFirst_works_correctly1)
{
    HeadList<int> HeadList;
    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);
    HeadList.pushBack(node);
    HeadList.RemoveFirst();
    EXPECT_EQ(HeadList.get_head()->val, 6);
}


TEST(HeadList, operator_equal_is_correct)
{
    HeadList<int> HeadList1;
    HeadList<int> HeadList2;
    HeadList1.push(1);
    HeadList2.push(1);
    EXPECT_TRUE(HeadList1 == HeadList2);

}

TEST(HeadList, operator_NotEqual_is_correct)
{
    HeadList<int> HeadList1;
    HeadList<int> HeadList2;
    HeadList1.push(1);
    HeadList2.push(2);
    EXPECT_TRUE(HeadList1 != HeadList2);

}
