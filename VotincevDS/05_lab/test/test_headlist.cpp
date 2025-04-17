#include "HeadList.h"

#include <gtest.h>


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
    HeadList<int> l1(1);
    ASSERT_NO_THROW(HeadList<int> HeadList(l1));
}

TEST(HeadList, copied_HeadLists_are_equal)
{
    HeadList<int> l1(1);
    HeadList<int> l2(l1);
    EXPECT_TRUE(l1 == l2);
}

TEST(HeadList, can_create_HeadList_by_ListNode)
{
    ListNode<int>* node = new ListNode<int>(1);
    ASSERT_NO_THROW(HeadList<int> l(node));
}

TEST(HeadList, creating_HeadList_by_ListNode_is_correct)
{
    ListNode<int>* node = new ListNode<int>(1);
    HeadList<int> HeadList1(node);
    HeadList<int> HeadList2;
    HeadList2.pushBack(node);
    EXPECT_TRUE(HeadList1 == HeadList2);
}


TEST(HeadList, assigned_HeadLists_are_equal)
{
    HeadList<int> l1(1);
    HeadList<int> l2;
    l2 = l1;
    EXPECT_TRUE(l1 == l2);
}


TEST(HeadList, can_search_existing_elem)
{
    HeadList<int> HeadList(1);
    ASSERT_NO_THROW(HeadList.search(1));
}

TEST(HeadList, cant_search_not_existing_elem)
{
    HeadList<int> HeadList(1);
    EXPECT_TRUE(HeadList.search(7) == nullptr);
}

TEST(HeadList, double_search_works_correctly)
{
    // по сути проверка навигации
    HeadList<int> HeadList(1);
    ListNode<int>* node = new ListNode<int>(2);
    HeadList.search(2);
    EXPECT_TRUE(HeadList.search(1) == HeadList.get_pFirst());
}


TEST(HeadList, can_pushFront_node)
{
    HeadList<int> HeadList;
    ListNode<int>* node = new ListNode<int>(5);
    ASSERT_NO_THROW(HeadList.pushFront(node));
}

TEST(HeadList, cant_pushFront_nullptr_in_not_empty_HeadList)
{
    HeadList<int> HeadList(1);
    ASSERT_ANY_THROW(HeadList.pushFront(nullptr));
}

TEST(HeadList, pushFront_works_correctly_with_node)
{
    HeadList<int> HeadList(5);
    ListNode<int>* node2 = new ListNode<int>(4);
    HeadList.pushFront(node2);
    EXPECT_TRUE(HeadList.get_pFirst()->val == 4);
}

TEST(HeadList, can_pushFront_elem)
{
    HeadList<int> HeadList;
    ASSERT_NO_THROW(HeadList.pushFront(5));
}

TEST(HeadList, pushFront_works_correctly_with_elem)
{
    HeadList<int> HeadList(5);
    HeadList.pushFront(4);
    EXPECT_TRUE(HeadList.get_pFirst()->val == 4);
}



TEST(HeadList, can_pushBack_node)
{
    HeadList<int> HeadList;
    ListNode<int>* node = new ListNode<int>(5);
    ASSERT_NO_THROW(HeadList.pushBack(node));
}

TEST(HeadList, pushBack_works_correctly_with_node)
{
    HeadList<int> HeadList(5);
    ListNode<int>* node2 = new ListNode<int>(4);
    HeadList.pushBack(node2);
    EXPECT_TRUE(HeadList.get_pFirst()->val == 5);
}

TEST(HeadList, can_pushBack_elem)
{
    HeadList<int> HeadList;
    ASSERT_NO_THROW(HeadList.pushBack(5));
}

TEST(HeadList, pushBack_works_correctly_with_elem)
{
    HeadList<int> HeadList(5);
    HeadList.pushBack(4);
    EXPECT_TRUE(HeadList.get_pFirst()->val == 5);
}
TEST(HeadList, can_InsertAfter_elem)
{
    HeadList<int> HeadList(5);
    ListNode<int>* add = new ListNode <int>(7);
    ASSERT_NO_THROW(HeadList.InsertAfter(add, 5));
}

TEST(HeadList, cant_InsertAfter_not_existing_elem)
{
    HeadList<int> HeadList(5);
    ListNode<int>* add = new ListNode <int>(7);
    ASSERT_ANY_THROW(HeadList.InsertAfter(add, 6));
}

TEST(HeadList, InsertAfter_works_correctly1)
{
    //  тест на вставку в конец
    HeadList<int> HeadList(5);
    ListNode<int>* add = new ListNode <int>(6);
    HeadList.InsertAfter(add, 5);
    EXPECT_EQ(HeadList.search(5)->next->val, 6);
}

TEST(HeadList, InsertAfter_works_correctly2)
{
    //  тест на вставку в середину
    HeadList<int> HeadList(5);
    ListNode<int>* node = new ListNode<int>(6);
    HeadList.pushBack(node); // 5 6
    ListNode<int>* add = new ListNode <int>(7);
    HeadList.InsertAfter(add, 5); // 5 7 6
    EXPECT_EQ(HeadList.search(5)->next->val, 7);
}


TEST(HeadList, can_InsertBefore_elem)
{
    HeadList<int> HeadList(5);
    ListNode<int>* add = new ListNode <int>(7);
    ASSERT_NO_THROW(HeadList.InsertBefore(add, 5));
}

TEST(HeadList, cant_InsertBefore_not_existing_elem)
{
    HeadList<int> HeadList(5);
    ListNode<int>* add = new ListNode <int>(7);
    ASSERT_ANY_THROW(HeadList.InsertBefore(add, 6));
}

TEST(HeadList, InsertBefore_works_correctly1)
{
    // тест на вставку в середину
    HeadList<int> HeadList(5);
    ListNode<int>* node = new ListNode<int>(6);
    HeadList.pushBack(node); // 5 6

    ListNode<int>* add = new ListNode <int>(7);
    HeadList.InsertBefore(add, 6); // 5  7  6

    EXPECT_EQ(HeadList.get_pFirst()->next->val, 7);
}

TEST(HeadList, InsertBefore_works_correctly2)
{
    // тест на вставку в начало
    HeadList<int> HeadList(5);
    ListNode<int>* node = new ListNode<int>(6);
    HeadList.pushBack(node); // 5 6

    ListNode<int>* add = new ListNode <int>(7);
    HeadList.InsertBefore(add, 5); // 7 5 6

    EXPECT_EQ(HeadList.get_pFirst()->val, 7);
}


TEST(HeadList, can_remove_elem)
{
    HeadList<int> HeadList(5);
    ASSERT_NO_THROW(HeadList.remove(5));
}

TEST(HeadList, cant_remove_not_existing_elem)
{
    HeadList<int> HeadList(5);
    ASSERT_ANY_THROW(HeadList.remove(6));
}

TEST(HeadList, remove_works_correctly1)
{
    // тест на удаление в начале
    HeadList<int> HeadList(4);
    ListNode<int>* node1 = new ListNode<int>(5);
    ListNode<int>* node2 = new ListNode<int>(6);
    HeadList.pushBack(node1);
    HeadList.pushBack(node2);
    HeadList.remove(4);
    EXPECT_EQ(HeadList.get_pFirst()->val, 5);

}

TEST(HeadList, remove_works_correctly2)
{
    // тест на удаление в середине
    HeadList<int> HeadList(4);
    ListNode<int>* node1 = new ListNode<int>(5);
    ListNode<int>* node2 = new ListNode<int>(6);
    HeadList.pushBack(node1);
    HeadList.pushBack(node2);
    HeadList.remove(5);           // 4 6
    EXPECT_EQ(HeadList.get_pFirst()->next->val, 6);
}

TEST(HeadList, remove_works_correctly3)
{
    // тест на удаление в конце
    HeadList<int> HeadList(4);
    ListNode<int>* node1 = new ListNode<int>(5);
    ListNode<int>* node2 = new ListNode<int>(6);
    HeadList.pushBack(node1);
    HeadList.pushBack(node2);   // 4 5 6
    HeadList.remove(6);         // 4 5
    EXPECT_EQ(HeadList.get_pFirst()->next->next, nullptr);
}

TEST(HeadList, can_RemoveFirst_elem)
{
    HeadList<int> HeadList(5);
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
    ListNode<int>* node1 = new ListNode<int>(5);
    ListNode<int>* node2 = new ListNode<int>(6);

    HeadList.pushBack(node1);
    HeadList.pushBack(node2);
    HeadList.RemoveFirst();
    EXPECT_EQ(HeadList.get_pFirst()->val, 6);
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
