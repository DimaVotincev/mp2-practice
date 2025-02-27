#include "list.h"

#include <gtest.h>


TEST(LIST, can_create_list)
{
    ASSERT_NO_THROW(List<int> list);
}

TEST(LIST, can_create_list_by_elem)
{
    ASSERT_NO_THROW(List<int> list(5));
}

TEST(LIST, can_create_copied_lists)
{
    List<int> l1;
    ListNode<int>* node = new ListNode<int>(0);
    node->next = new ListNode<int>(1);
    node->next->next = new ListNode<int>(2);

    l1.pushBack(node);
    ASSERT_NO_THROW(List<int> list(l1));
}

TEST(LIST, copied_lists_are_equal)
{
    List<int> l1;
    ListNode<int>* node = new ListNode<int>(0);
    node->next = new ListNode<int>(1);
    node->next->next = new ListNode<int>(2);

    l1.pushBack(node);
    List<int> l2(l1);
    EXPECT_TRUE(l1 == l2);
}




TEST(LIST, can_create_list_by_listnode)
{
    ListNode<int>* node = new ListNode<int>(0);
    node->next = new ListNode<int>(1);
    node->next->next = new ListNode<int>(2);

    ASSERT_NO_THROW(List<int> l(node));
}

TEST(LIST, creating_list_by_listnode_is_correct)
{
    ListNode<int>* node = new ListNode<int>(0);
    node->next = new ListNode<int>(1);
    node->next->next = new ListNode<int>(2);

    List<int> list1(node);
    List<int> list2;
    list2.pushBack(node);

    EXPECT_TRUE(list1 == list2);
}


TEST(LIST, assigned_lists_are_equal)
{ 
    ListNode<int>* node = new ListNode<int>(0);
    node->next = new ListNode<int>(1);
    node->next->next = new ListNode<int>(2);

    List<int> l1;
    l1.pushBack(node);

    List<int> l2;
    l2 = l1;

    EXPECT_TRUE(l1 == l2);
}


TEST(LIST, can_search_existing_elem)
{
    List<int> list;
    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);
    list.pushBack(node);
    ASSERT_NO_THROW(list.search(5));
}

TEST(LIST, cant_search_not_existing_elem)
{
    List<int> list;
    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);
    list.pushBack(node);
    ASSERT_ANY_THROW(list.search(7));
}

TEST(LIST, double_search_works_correctly)
{
    List<int> list;
    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);
    node->next->next = new ListNode<int>(7);

    list.pushBack(node);
    list.search(6);

    EXPECT_TRUE(list.search(5) == list.get_head());
}


TEST(LIST, can_pushFront_elem)
{
    List<int> list;
    ListNode<int>* node = new ListNode<int>(5);
    ASSERT_NO_THROW(list.pushFront(node));
}

TEST(LIST, cant_pushFront_nullptr_in_not_empty_list)
{
    List<int> list;
    ListNode<int>* node = new ListNode<int>(5);
    list.pushBack(node);
    ASSERT_ANY_THROW(list.pushFront(nullptr));
}

TEST(LIST, pushFront_works_correctly)
{
    
    ListNode<int>* node1 = new ListNode<int>(5);
    List<int> list(node1);

    ListNode<int>* node2 = new ListNode<int>(4);
    list.pushFront(node2);   
    EXPECT_TRUE(list.get_head()->val == 4);
}



TEST(LIST, can_pushBack_elem)
{
    List<int> list;
    ListNode<int>* node = new ListNode<int>(5);
    ASSERT_NO_THROW(list.pushBack(node));
}


TEST(LIST, can_InsertAfter_elem)
{
    List<int> list;
    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);
    list.pushBack(node);
    ListNode<int>* add = new ListNode <int>(7);
    ASSERT_NO_THROW(list.InsertAfter(add, 6));
}

TEST(LIST, cant_InsertAfter_not_existing_elem)
{
    List<int> list;
    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);
    list.pushBack(node);
    ListNode<int>* add = new ListNode <int>(7);
    ASSERT_ANY_THROW(list.InsertAfter(add, 7));
}

TEST(LIST, InsertAfter_works_correctly1)
{ 
    //  тест на вставку в конец

    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);

    List<int> list;
    list.pushBack(node);

    ListNode<int>* add = new ListNode <int>(7);
    list.InsertAfter(add, 6);   // 5 6 7

    EXPECT_EQ(list.search(6)->next->val, 7);
}

TEST(LIST, InsertAfter_works_correctly2)
{
    //  тест на вставку в середину

    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);

    List<int> list;
    list.pushBack(node);

    ListNode<int>* add = new ListNode <int>(7);
    list.InsertAfter(add, 5);  // 5 7 6

    EXPECT_EQ(list.search(5)->next->val, 7);
}


TEST(LIST, can_InsertBefore_elem)
{
    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);

    List<int> list;
    list.pushBack(node);

    ListNode<int>* add = new ListNode <int>(7);

    ASSERT_NO_THROW(list.InsertBefore(add, 6));
}

TEST(LIST, cant_InsertBefore_not_existing_elem)
{
    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);

    List<int> list;
    list.pushBack(node);

    ListNode<int>* add = new ListNode <int>(7);

    ASSERT_ANY_THROW(list.InsertBefore(add, 7));
}

TEST(LIST, InsertBefore_works_correctly1)
{
    // тест на вставку в середину

    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);

    List<int> list;
    list.pushBack(node);

    ListNode<int>* add = new ListNode <int>(7);
    list.InsertBefore(add, 6); // 5  7  6
    
    EXPECT_EQ(list.get_head()->next->val,7);
}

TEST(LIST, InsertBefore_works_correctly2)
{
    // тест на вставку в начало

    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);

    List<int> list;
    list.pushBack(node);

    ListNode<int>* add = new ListNode <int>(7);
    list.InsertBefore(add, 5); // 7 5 6

    EXPECT_EQ(list.get_head()->val, 7);
}


TEST(LIST, can_remove_elem)
{
    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);

    List<int> list;
    list.pushBack(node);

    ListNode<int>* add = new ListNode <int>(7);
    ASSERT_NO_THROW(list.remove(6));
}

TEST(LIST, cant_remove_not_existing_elem)
{
    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);

    List<int> list;
    list.pushBack(node);

    ListNode<int>* add = new ListNode <int>(7);
    ASSERT_ANY_THROW(list.remove(7));
}

TEST(LIST, remove_works_correctly1)
{
    // тест на удаление в начале

    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);
    node->next->next = new ListNode<int>(7);

    List<int> list;
    list.pushBack(node);  // 5 6 7
    list.remove(5);       // 6 7
    EXPECT_EQ(list.get_head()->val, 6);

}

TEST(LIST, remove_works_correctly2)
{
    // тест на удаление в середине

    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);
    node->next->next = new ListNode<int>(7);

    List<int> list;
    list.pushBack(node); // 5 6 7
    list.remove(6); // 5 7
    EXPECT_EQ(list.get_head()->next->val, 7);
}

TEST(LIST, remove_works_correctly3)
{
    // тест на удаление в конце

    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);
    node->next->next = new ListNode<int>(7);

    List<int> list;
    list.pushBack(node); // 5 6 7
    list.remove(7); // 5 6
    EXPECT_EQ(list.get_head()->next->val, 6);
}

TEST(LIST, can_RemoveFirst_elem)
{
    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);

    List<int> list;
    list.pushBack(node);

    ListNode<int>* add = new ListNode <int>(7);
    ASSERT_NO_THROW(list.RemoveFirst());
}

TEST(LIST, cant_RemoveFirst_in_empty_list)
{
    List<int> list;
    ASSERT_ANY_THROW(list.RemoveFirst());
}

TEST(LIST, RemoveFirst_works_correctly1)
{
    List<int> list;
    ListNode<int>* node = new ListNode<int>(5);
    node->next = new ListNode<int>(6);
    list.pushBack(node);
    list.RemoveFirst();
    EXPECT_EQ(list.get_head()->val, 6);
}


TEST(LIST, operator_equal_is_correct)
{
    List<int> list1;
    List<int> list2;
    list1.push(1);
    list2.push(1);
    EXPECT_TRUE(list1 == list2);

}

TEST(LIST, operator_NotEqual_is_correct)
{
    List<int> list1;
    List<int> list2;
    list1.push(1);
    list2.push(2);
    EXPECT_TRUE(list1 != list2);

}
