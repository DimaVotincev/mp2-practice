#include "RingHeadList.h"

#include <gtest.h>


TEST(RingHeadList, can_create_RingHeadList)
{
    ASSERT_NO_THROW(RingHeadList<int> RingHeadList);
}

TEST(RingHeadList, can_create_RingHeadList_by_elem)
{
    ASSERT_NO_THROW(RingHeadList<int> RingHeadList(5));
}

TEST(RingHeadList, can_create_copied_RingHeadLists)
{
    RingHeadList<int> l1(1);
    ASSERT_NO_THROW(RingHeadList<int> RingHeadList(l1));
}

TEST(RingHeadList, copied_RingHeadLists_are_equal)
{
    RingHeadList<int> l1(1);
    RingHeadList<int> l2(l1);
    EXPECT_TRUE(l1 == l2);
}

TEST(RingHeadList, can_create_RingHeadList_by_ListNode)
{
    ListNode<int>* node = new ListNode<int>(1);
    ASSERT_NO_THROW(RingHeadList<int> l(node));
}

TEST(RingHeadList, creating_RingHeadList_by_ListNode_is_correct)
{
    ListNode<int>* node = new ListNode<int>(1);
    RingHeadList<int> RingHeadList1(node);
    RingHeadList<int> RingHeadList2;
    RingHeadList2.pushBack(node);
    EXPECT_TRUE(RingHeadList1 == RingHeadList2);
}


TEST(RingHeadList, assigned_RingHeadLists_are_equal)
{
    RingHeadList<int> l1(1);
    RingHeadList<int> l2;
    l2 = l1;
    EXPECT_TRUE(l1 == l2);
}


TEST(RingHeadList, can_search_existing_elem)
{
    RingHeadList<int> RingHeadList(1);
    ASSERT_NO_THROW(RingHeadList.search(1));
}


TEST(RingHeadList, double_search_works_correctly)
{
    RingHeadList<int> RingHeadList(1);
    ListNode<int>* node = new ListNode<int>(2);
    RingHeadList.search(2);
    EXPECT_TRUE(RingHeadList.search(1) == RingHeadList.get_pFirst());
}


TEST(RingHeadList, can_pushFront_node)
{
    RingHeadList<int> RingHeadList;
    ListNode<int>* node = new ListNode<int>(5);
    ASSERT_NO_THROW(RingHeadList.pushFront(node));
}

TEST(RingHeadList, cant_pushFront_nullptr_in_not_empty_RingHeadList)
{
    RingHeadList<int> RingHeadList(1);
    ASSERT_ANY_THROW(RingHeadList.pushFront(nullptr));
}

TEST(RingHeadList, pushFront_works_correctly_with_node)
{
    RingHeadList<int> RingHeadList(5);
    ListNode<int>* node2 = new ListNode<int>(4);
    RingHeadList.pushFront(node2);
    EXPECT_TRUE(RingHeadList.get_pFirst()->val == 4);
}

TEST(RingHeadList, can_pushFront_elem)
{
    RingHeadList<int> RingHeadList;
    ASSERT_NO_THROW(RingHeadList.pushFront(5));
}

TEST(RingHeadList, pushFront_works_correctly_with_elem)
{
    RingHeadList<int> RingHeadList(5);
    RingHeadList.pushFront(4);
    EXPECT_TRUE(RingHeadList.get_pFirst()->val == 4);
}



TEST(RingHeadList, can_pushBack_node)
{
    RingHeadList<int> RingHeadList;
    ListNode<int>* node = new ListNode<int>(5);
    ASSERT_NO_THROW(RingHeadList.pushBack(node));
}

TEST(RingHeadList, pushBack_works_correctly_with_node)
{
    RingHeadList<int> RingHeadList(5);
    ListNode<int>* node2 = new ListNode<int>(4);
    RingHeadList.pushBack(node2);
    EXPECT_TRUE(RingHeadList.get_pFirst()->val == 5);
}

TEST(RingHeadList, can_pushBack_elem)
{
    RingHeadList<int> RingHeadList;
    ASSERT_NO_THROW(RingHeadList.pushBack(5));
}

TEST(RingHeadList, pushBack_works_correctly_with_elem)
{

    RingHeadList<int> RingHeadList(5);
    RingHeadList.pushBack(4);
    EXPECT_TRUE(RingHeadList.get_pFirst()->val == 5);
}

TEST(RingHeadList, can_InsertAfter_elem)
{
    RingHeadList<int> RingHeadList(5);
    ListNode<int>* add = new ListNode <int>(7);
    ASSERT_NO_THROW(RingHeadList.InsertAfter(add, 5));
}

TEST(RingHeadList, cant_InsertAfter_not_existing_elem)
{
    RingHeadList<int> RingHeadList(5);
    ListNode<int>* add = new ListNode <int>(7);
    ASSERT_ANY_THROW(RingHeadList.InsertAfter(add, 6));
}

TEST(RingHeadList, InsertAfter_works_correctly1)
{
    //  тест на вставку в конец
    RingHeadList<int> RingHeadList(5);
    ListNode<int>* add = new ListNode <int>(6);
    RingHeadList.InsertAfter(add, 5);
    EXPECT_EQ(RingHeadList.search(5)->next->val, 6);
}

TEST(RingHeadList, InsertAfter_works_correctly2)
{
    //  тест на вставку в середину
    RingHeadList<int> RingHeadList(5);
    ListNode<int>* node = new ListNode<int>(6);
    RingHeadList.pushBack(node); // 5 6
    ListNode<int>* add = new ListNode <int>(7);
    RingHeadList.InsertAfter(add, 5); // 5 7 6
    EXPECT_EQ(RingHeadList.search(5)->next->val, 7);
}


TEST(RingHeadList, can_InsertBefore_elem)
{
    RingHeadList<int> RingHeadList(5);
    ListNode<int>* add = new ListNode <int>(7);
    ASSERT_NO_THROW(RingHeadList.InsertBefore(add, 5));
}

TEST(RingHeadList, cant_InsertBefore_not_existing_elem)
{
    RingHeadList<int> RingHeadList(5);
    ListNode<int>* add = new ListNode <int>(7);
    ASSERT_ANY_THROW(RingHeadList.InsertBefore(add, 6));
}

TEST(RingHeadList, InsertBefore_works_correctly1)
{
    // тест на вставку в середину
    RingHeadList<int> RingHeadList(5);
    ListNode<int>* node = new ListNode<int>(6);
    RingHeadList.pushBack(node); // 5 6

    ListNode<int>* add = new ListNode <int>(7);
    RingHeadList.InsertBefore(add, 6); // 5  7  6

    EXPECT_EQ(RingHeadList.get_pFirst()->next->val, 7);
}

TEST(RingHeadList, InsertBefore_works_correctly2)
{
    // тест на вставку в начало
    RingHeadList<int> RingHeadList(5);
    ListNode<int>* node = new ListNode<int>(6);
    RingHeadList.pushBack(node); // 5 6

    ListNode<int>* add = new ListNode <int>(7);
    RingHeadList.InsertBefore(add, 5); // 7 5 6

    EXPECT_EQ(RingHeadList.get_pFirst()->val, 7);
}


TEST(RingHeadList, can_remove_elem)
{
    RingHeadList<int> RingHeadList(5);
    ASSERT_NO_THROW(RingHeadList.remove(5));
}

TEST(RingHeadList, cant_remove_not_existing_elem)
{
    RingHeadList<int> RingHeadList(5);
    ASSERT_ANY_THROW(RingHeadList.remove(6));
}

TEST(RingHeadList, remove_works_correctly1)
{
    // тест на удаление в начале
    RingHeadList<int> RingHeadList(4);
    ListNode<int>* node1 = new ListNode<int>(5);
    ListNode<int>* node2 = new ListNode<int>(6);
    RingHeadList.pushBack(node1);
    RingHeadList.pushBack(node2);
    RingHeadList.remove(4);
    EXPECT_EQ(RingHeadList.get_pFirst()->val, 5);

}

TEST(RingHeadList, remove_works_correctly2)
{
    // тест на удаление в середине
    RingHeadList<int> RingHeadList(4);
    ListNode<int>* node1 = new ListNode<int>(5);
    ListNode<int>* node2 = new ListNode<int>(6);
    RingHeadList.pushBack(node1);
    RingHeadList.pushBack(node2);
    RingHeadList.remove(5);           // 4 6
    EXPECT_EQ(RingHeadList.get_pFirst()->next->val, 6);
}


TEST(RingHeadList, can_RemoveFirst_elem)
{
    RingHeadList<int> RingHeadList(5);
    ASSERT_NO_THROW(RingHeadList.RemoveFirst());
}

TEST(RingHeadList, cant_RemoveFirst_in_empty_RingHeadList)
{
    RingHeadList<int> RingHeadList;
    ASSERT_ANY_THROW(RingHeadList.RemoveFirst());
}

TEST(RingHeadList, RemoveFirst_works_correctly1)
{
    RingHeadList<int> RingHeadList;
    ListNode<int>* node1 = new ListNode<int>(5);
    ListNode<int>* node2 = new ListNode<int>(6);

    RingHeadList.pushBack(node1);
    RingHeadList.pushBack(node2);
    RingHeadList.RemoveFirst();
    EXPECT_EQ(RingHeadList.get_pFirst()->val, 6);
}


TEST(RingHeadList, operator_equal_is_correct)
{
    RingHeadList<int> RingHeadList1;
    RingHeadList<int> RingHeadList2;
    RingHeadList1.push(1);
    RingHeadList2.push(1);
    EXPECT_TRUE(RingHeadList1 == RingHeadList2);

}

TEST(RingHeadList, operator_NotEqual_is_correct)
{
    RingHeadList<int> RingHeadList1;
    RingHeadList<int> RingHeadList2;
    RingHeadList1.push(1);
    RingHeadList2.push(2);
    EXPECT_TRUE(RingHeadList1 != RingHeadList2);

}
