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
    List<int> l1(1);
    ASSERT_NO_THROW(List<int> list(l1));
}

TEST(LIST, copied_lists_are_equal)
{
    List<int> l1(1);
    List<int> l2(l1);
    EXPECT_TRUE(l1 == l2);
}

TEST(LIST, can_create_list_by_listnode)
{
    ListNode<int>* node = new ListNode<int>(1);
    ASSERT_NO_THROW(List<int> l(node));
}

TEST(LIST, creating_list_by_listnode_is_correct)
{
    ListNode<int>* node = new ListNode<int>(1);
    List<int> list1(node);
    List<int> list2;
    list2.pushBack(node);
    EXPECT_TRUE(list1 == list2);
}


TEST(LIST, assigned_lists_are_equal)
{ 
    List<int> l1(1);
    List<int> l2;
    l2 = l1;
    EXPECT_TRUE(l1 == l2);
}


TEST(LIST, can_search_existing_elem)
{
    List<int> list(1);
    ASSERT_NO_THROW(list.search(1));
}

TEST(LIST, cant_search_not_existing_elem)
{
    List<int> list(1);
    EXPECT_TRUE(list.search(7) == nullptr);
}

TEST(LIST, double_search_works_correctly)
{
    List<int> list(1);
    ListNode<int>* node = new ListNode<int>(2);
    list.search(2);
    EXPECT_TRUE(list.search(1) == list.get_pFirst());
}


TEST(LIST, can_pushFront_node)
{
    List<int> list;
    ListNode<int>* node = new ListNode<int>(5);
    ASSERT_NO_THROW(list.pushFront(node));
}

TEST(LIST, cant_pushFront_nullptr_in_not_empty_list)
{
    List<int> list(1);
    ASSERT_ANY_THROW(list.pushFront(nullptr));
}

TEST(LIST, pushFront_works_correctly_with_node)
{
    List<int> list(5);
    ListNode<int>* node2 = new ListNode<int>(4);
    list.pushFront(node2);   
    EXPECT_TRUE(list.get_pFirst()->val == 4);
}

TEST(LIST, can_pushFront_elem)
{
    List<int> list;
    ASSERT_NO_THROW(list.pushFront(5));
}

TEST(LIST, pushFront_works_correctly_with_elem)
{
    List<int> list(5);
    list.pushFront(4);
    EXPECT_TRUE(list.get_pFirst()->val == 4);
}



TEST(LIST, can_pushBack_node)
{
    List<int> list;
    ListNode<int>* node = new ListNode<int>(5);
    ASSERT_NO_THROW(list.pushBack(node));
}

TEST(LIST, pushBack_works_correctly_with_node)
{
    List<int> list(5);
    ListNode<int>* node2 = new ListNode<int>(4);
    list.pushBack(node2);
    EXPECT_TRUE(list.get_pFirst()->val == 5);
}

TEST(LIST, can_pushBack_elem)
{
    List<int> list;
    ASSERT_NO_THROW(list.pushBack(5));
}

TEST(LIST, pushBack_works_correctly_with_elem)
{
    List<int> list(5);
    list.pushBack(4);
    EXPECT_TRUE(list.get_pFirst()->val == 5);
}
TEST(LIST, can_InsertAfter_elem)
{
    List<int> list(5);
    ListNode<int>* add = new ListNode <int>(7);
    ASSERT_NO_THROW(list.InsertAfter(add, 5));
}

TEST(LIST, cant_InsertAfter_not_existing_elem)
{
    List<int> list(5);
    ListNode<int>* add = new ListNode <int>(7);
    ASSERT_ANY_THROW(list.InsertAfter(add, 6));
}

TEST(LIST, InsertAfter_works_correctly1)
{ 
    //  тест на вставку в конец
    List<int> list(5);
    ListNode<int>* add = new ListNode <int>(6);
    list.InsertAfter(add, 5);  
    EXPECT_EQ(list.search(5)->next->val, 6);
}

TEST(LIST, InsertAfter_works_correctly2)
{
    //  тест на вставку в середину
    List<int> list(5);
    ListNode<int>* node = new ListNode<int>(6);
    list.pushBack(node); // 5 6
    ListNode<int>* add = new ListNode <int>(7);
    list.InsertAfter(add, 5); // 5 7 6
    EXPECT_EQ(list.search(5)->next->val, 7);
}


TEST(LIST, can_InsertBefore_elem)
{
    List<int> list(5);
    ListNode<int>* add = new ListNode <int>(7);
    ASSERT_NO_THROW(list.InsertBefore(add, 5));
}

TEST(LIST, cant_InsertBefore_not_existing_elem)
{
    List<int> list(5);
    ListNode<int>* add = new ListNode <int>(7);
    ASSERT_ANY_THROW(list.InsertBefore(add, 6));
}

TEST(LIST, InsertBefore_works_correctly1)
{
    // тест на вставку в середину
    List<int> list(5);
    ListNode<int>* node = new ListNode<int>(6);
    list.pushBack(node); // 5 6

    ListNode<int>* add = new ListNode <int>(7);
    list.InsertBefore(add, 6); // 5  7  6
    
    EXPECT_EQ(list.get_pFirst()->next->val,7);
}

TEST(LIST, InsertBefore_works_correctly2)
{
    // тест на вставку в начало
    List<int> list(5);
    ListNode<int>* node = new ListNode<int>(6);
    list.pushBack(node); // 5 6

    ListNode<int>* add = new ListNode <int>(7);
    list.InsertBefore(add, 5); // 7 5 6

    EXPECT_EQ(list.get_pFirst()->val, 7);
}


TEST(LIST, can_remove_elem)
{
    List<int> list(5);
    ASSERT_NO_THROW(list.remove(5));
}

TEST(LIST, cant_remove_not_existing_elem)
{
    List<int> list(5);
    ASSERT_ANY_THROW(list.remove(6));
}

TEST(LIST, remove_works_correctly1)
{
    // тест на удаление в начале
    List<int> list(4);
    ListNode<int>* node1 = new ListNode<int>(5);
    ListNode<int>* node2 = new ListNode<int>(6);    
    list.pushBack(node1);
    list.pushBack(node2);
    list.remove(4);    
    EXPECT_EQ(list.get_pFirst()->val, 5);

}

TEST(LIST, remove_works_correctly2)
{
    // тест на удаление в середине
    List<int> list(4);
    ListNode<int>* node1 = new ListNode<int>(5);
    ListNode<int>* node2 = new ListNode<int>(6);
    list.pushBack(node1);
    list.pushBack(node2);
    list.remove(5);           // 4 6
    EXPECT_EQ(list.get_pFirst()->next->val, 6);
}

TEST(LIST, remove_works_correctly3)
{
    // тест на удаление в конце
    List<int> list(4);
    ListNode<int>* node1 = new ListNode<int>(5);
    ListNode<int>* node2 = new ListNode<int>(6);
    list.pushBack(node1);
    list.pushBack(node2);   // 4 5 6
    list.remove(6);         // 4 5
    EXPECT_EQ(list.get_pFirst()->next->next, nullptr);
}

TEST(LIST, can_RemoveFirst_elem)
{
    List<int> list(5);
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
    ListNode<int>* node1 = new ListNode<int>(5);
    ListNode<int>* node2 = new ListNode<int>(6);
    
    list.pushBack(node1);
    list.pushBack(node2);
    list.RemoveFirst();
    EXPECT_EQ(list.get_pFirst()->val, 6);
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
