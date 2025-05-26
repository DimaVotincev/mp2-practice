
#include "binary_search_tree.h"
#include <gtest.h>





TEST(BinarySearchTree, can_create_BinarySearchTree) {
	try
	{
		BinarySearchTree<int, int> st2;
	}
	catch (const std::exception&)
	{
		ADD_FAILURE();
	}

	// просто написать 
	// ASSERT_NO_THROW(TreeNode<int, int> tr(1, data));
	// не получаетс€ 
	// (особенность gtest, там происходит не€вное
	// приведение и компил€тор может не пон€ть)
	//
}


TEST(BinarySearchTree, can_create_by_BST) {
	BinarySearchTree<int, int> bst;
	TreeNode<int, int>* add1 = new TreeNode<int, int>(5, nullptr);
	TreeNode<int, int>* add2 = new TreeNode<int, int>(3, nullptr);
	TreeNode<int, int>* add3 = new TreeNode<int, int>(4, nullptr);
	try
	{
		BinarySearchTree<int, int> bst2(bst);
	}
	catch (const std::exception&)
	{
		ADD_FAILURE();
	}
}



TEST(BinarySearchTree, can_Search) {
	BinarySearchTree<int, int> bst;
	TreeNode<int, int>* add1 = new TreeNode<int,int>(5,nullptr);
	TreeNode<int, int>* add2 = new TreeNode<int, int>(3, nullptr);
	TreeNode<int, int>* add3 = new TreeNode<int, int>(4, nullptr);

	bst.Insert(add1);
	bst.Insert(add2);
	bst.Insert(add3);
	ASSERT_NO_THROW(bst.Search(4));
}

TEST(BinarySearchTree, can_Search_existing_elem) {
	BinarySearchTree<int, int> bst;
	TreeNode<int, int>* add1 = new TreeNode<int, int>(5, nullptr);
	TreeNode<int, int>* add2 = new TreeNode<int, int>(3, nullptr);
	TreeNode<int, int>* add3 = new TreeNode<int, int>(4, nullptr);

	bst.Insert(add1);
	bst.Insert(add2);
	bst.Insert(add3);
	EXPECT_FALSE(bst.Search(4) == nullptr);
}

TEST(BinarySearchTree, cant_Search_not_existing_elem) {
	BinarySearchTree<int, int> bst;
	TreeNode<int, int>* add1 = new TreeNode<int, int>(1, nullptr);
	TreeNode<int, int>* add2 = new TreeNode<int, int>(5, nullptr);
	bst.Insert(add1);
	bst.Insert(add2);
	EXPECT_TRUE(bst.Search(11) == nullptr);
}


TEST(BinarySearchTree, can_SearchMin) {
	BinarySearchTree<int, int> bst;
	TreeNode<int, int>* add1 = new TreeNode<int, int>(5, nullptr);
	TreeNode<int, int>* add2 = new TreeNode<int, int>(3, nullptr);
	TreeNode<int, int>* add3 = new TreeNode<int, int>(4, nullptr);

	bst.Insert(add1);
	bst.Insert(add2);
	bst.Insert(add3);
	ASSERT_NO_THROW(bst.SearchMin(bst.pRoot));
}


TEST(BinarySearchTree, SearchMin_is_correct) {
	BinarySearchTree<int, int> bst;
	TreeNode<int, int>* add1 = new TreeNode<int, int>(5, nullptr);
	TreeNode<int, int>* add2 = new TreeNode<int, int>(3, nullptr);
	TreeNode<int, int>* add3 = new TreeNode<int, int>(4, nullptr);

	bst.Insert(add1);
	bst.Insert(add2);
	bst.Insert(add3);
	EXPECT_TRUE(bst.SearchMin(bst.pRoot) == add2);
}


TEST(BinarySearchTree, can_SearchMax) {
	BinarySearchTree<int, int> bst;
	TreeNode<int, int>* add1 = new TreeNode<int, int>(5, nullptr);
	TreeNode<int, int>* add2 = new TreeNode<int, int>(3, nullptr);
	TreeNode<int, int>* add3 = new TreeNode<int, int>(4, nullptr);

	bst.Insert(add1);
	bst.Insert(add2);
	bst.Insert(add3);
	ASSERT_NO_THROW(bst.SearchMax(bst.pRoot));
}


TEST(BinarySearchTree, SearchMax_is_correct) {
	BinarySearchTree<int, int> bst;
	TreeNode<int, int>* add1 = new TreeNode<int, int>(5, nullptr);
	TreeNode<int, int>* add2 = new TreeNode<int, int>(3, nullptr);
	TreeNode<int, int>* add3 = new TreeNode<int, int>(4, nullptr);

	bst.Insert(add1);
	bst.Insert(add2);
	bst.Insert(add3);
	EXPECT_TRUE(bst.SearchMax(bst.pRoot) == add1);
}

TEST(BinarySearchTree, can_SearchNext) {
	BinarySearchTree<int, int> bst;
	TreeNode<int, int>* add1 = new TreeNode<int, int>(5, nullptr);
	TreeNode<int, int>* add2 = new TreeNode<int, int>(3, nullptr);
	TreeNode<int, int>* add3 = new TreeNode<int, int>(4, nullptr);

	bst.Insert(add1);
	bst.Insert(add2);
	bst.Insert(add3);
	ASSERT_NO_THROW(bst.SearchNext(bst.pRoot));
}


TEST(BinarySearchTree, SearchNext_is_correct) {
	BinarySearchTree<int, int> bst;
	TreeNode<int, int>* add1 = new TreeNode<int, int>(4, nullptr);
	TreeNode<int, int>* add2 = new TreeNode<int, int>(3, nullptr);
	TreeNode<int, int>* add3 = new TreeNode<int, int>(5, nullptr);

	bst.Insert(add1);
	bst.Insert(add2);
	bst.Insert(add3);
	EXPECT_TRUE(bst.SearchNext(bst.pRoot) == add3);
}

TEST(BinarySearchTree, SearchNext_is_correct2) {
	BinarySearchTree<int, int> bst;
	bst.Insert(new TreeNode<int, int>(8, nullptr));
	bst.Insert(new TreeNode<int, int>(11, nullptr));
	bst.Insert(new TreeNode<int, int>(9, nullptr));
	bst.Insert(new TreeNode<int, int>(12, nullptr));
	bst.Insert(new TreeNode<int, int>(2, nullptr));
	bst.Insert(new TreeNode<int, int>(1, nullptr));
	bst.Insert(new TreeNode<int, int>(4, nullptr));
	bst.Insert(new TreeNode<int, int>(5, nullptr));
	bst.Insert(new TreeNode<int, int>(3, nullptr));
	EXPECT_TRUE(
bst.SearchNext(bst.pRoot->pLeft->pRight->pRight)->key == 8);
}

TEST(BinarySearchTree, can_SearchPrev) {
	BinarySearchTree<int, int> bst;
	TreeNode<int, int>* add1 = new TreeNode<int, int>(5, nullptr);
	TreeNode<int, int>* add2 = new TreeNode<int, int>(3, nullptr);
	TreeNode<int, int>* add3 = new TreeNode<int, int>(4, nullptr);

	bst.Insert(add1);
	bst.Insert(add2);
	bst.Insert(add3);
	ASSERT_NO_THROW(bst.SearchPrev(bst.pRoot));
}


TEST(BinarySearchTree, SearchPrev_is_correct) {
	BinarySearchTree<int, int> bst;
	TreeNode<int, int>* add1 = new TreeNode<int, int>(4, nullptr);
	TreeNode<int, int>* add2 = new TreeNode<int, int>(3, nullptr);
	TreeNode<int, int>* add3 = new TreeNode<int, int>(5, nullptr);

	bst.Insert(add1);
	bst.Insert(add2);
	bst.Insert(add3);
	EXPECT_TRUE(bst.SearchPrev(bst.pRoot->pRight) == add1);
}


TEST(BinarySearchTree, SearchPrev_is_correct2) {
	BinarySearchTree<int, int> bst;
	bst.Insert(new TreeNode<int, int>(8, nullptr));
	bst.Insert(new TreeNode<int, int>(11, nullptr));
	bst.Insert(new TreeNode<int, int>(9, nullptr));
	bst.Insert(new TreeNode<int, int>(12, nullptr));
	bst.Insert(new TreeNode<int, int>(2, nullptr));
	bst.Insert(new TreeNode<int, int>(1, nullptr));
	bst.Insert(new TreeNode<int, int>(4, nullptr));
	bst.Insert(new TreeNode<int, int>(5, nullptr));
	bst.Insert(new TreeNode<int, int>(3, nullptr));
	EXPECT_TRUE(
bst.SearchPrev(bst.pRoot->pLeft->pRight->pRight)->key == 4);
}

TEST(BinarySearchTree, SearchPrev_is_correct3) {
	BinarySearchTree<int, int> bst;
	bst.Insert(new TreeNode<int, int>(6, nullptr));
	bst.Insert(new TreeNode<int, int>(5, nullptr));
	bst.Insert(new TreeNode<int, int>(4, nullptr));

	EXPECT_TRUE(
		bst.SearchPrev(bst.pRoot->pLeft)->key == 4);
}


TEST(BinarySearchTree, can_remove_existing_key) {
	BinarySearchTree<int, int> bst;
	TreeNode<int, int>* add1 = new TreeNode<int, int>(1, nullptr);
	TreeNode<int, int>* add2 = new TreeNode<int, int>(5, nullptr);
	bst.Insert(add1);
	bst.Insert(add2);
	ASSERT_NO_THROW(bst.Remove(1));
}




TEST(BinarySearchTree, cant_remove_not_existing_key) {
	BinarySearchTree<int, int> bst;
	TreeNode<int, int>* add1 = new TreeNode<int, int>(1, nullptr);
	bst.Insert(add1);
	ASSERT_ANY_THROW(bst.Remove(2));
}

TEST(BinarySearchTree, can_remove_any_key) {
	// все ситуации удалени€ с 2-м€, 1-м и 0 потомками
	BinarySearchTree<int, int> bst;
	bst.Insert(new TreeNode<int, int>(7, nullptr));
	bst.Insert(new TreeNode<int, int>(3, nullptr));
	bst.Insert(new TreeNode<int, int>(2, nullptr));
	bst.Insert(new TreeNode<int, int>(4, nullptr));
	bst.Remove(3);
	bst.Remove(4);
	bst.Remove(2);
	ASSERT_NO_THROW(bst.Remove(7));
}


TEST(BinarySearchTree, can_insert) {
	BinarySearchTree<int, int> bst;
	TreeNode<int, int>* add1 = new TreeNode<int, int>(1, nullptr);
	ASSERT_NO_THROW(bst.Insert(add1));

}



// Additional hard-tests


TEST(BinarySearchTree, can_insert_after_removing) {
	BinarySearchTree<int, int> bst;
	TreeNode<int, int>* add1 = new TreeNode<int, int>(1, nullptr);
	TreeNode<int, int>* add2 = new TreeNode<int, int>(5, nullptr);
	TreeNode<int, int>* add3 = new TreeNode<int, int>(6, nullptr);
	bst.Insert(add1);
	bst.Insert(add2);
	bst.Remove(5);
	ASSERT_NO_THROW(bst.Insert(add3));
}




TEST(BinarySearchTree, insertion_removing_mix) {
	BinarySearchTree<int, int> bst;
	bst.Insert(new TreeNode<int, int>(1, nullptr)); 
	bst.Insert(new TreeNode<int, int>(6, nullptr));
	bst.Remove(1);
	bst.Insert(new TreeNode<int, int>(11, nullptr));
	bst.Insert(new TreeNode<int, int>(7, nullptr));
	bst.Remove(6);
	bst.Remove(7);
	bst.Insert(new TreeNode<int, int>(14, nullptr));
	bst.Remove(14);
	ASSERT_NO_THROW(bst.Remove(11));
}




TEST(BinarySearchTree, insertion_removing_mix2) {
	BinarySearchTree<int, int> bst;
	bst.Insert(new TreeNode<int, int>(6, nullptr));
	bst.Insert(new TreeNode<int, int>(8, nullptr));
	bst.Insert(new TreeNode<int, int>(7, nullptr));
	bst.Insert(new TreeNode<int, int>(9, nullptr));
	bst.Insert(new TreeNode<int, int>(4, nullptr));
	bst.Insert(new TreeNode<int, int>(5, nullptr));
	bst.Insert(new TreeNode<int, int>(3, nullptr));
	bst.Insert(new TreeNode<int, int>(2, nullptr));
	bst.Insert(new TreeNode<int, int>(1, nullptr));
	bst.Remove(6);
	bst.Remove(1);
	bst.Remove(8); 
	bst.Remove(4);
	bst.Remove(9);
	bst.Remove(2);
	bst.Remove(3);
	bst.Remove(7);

	ASSERT_NO_THROW(bst.Remove(5));
}


TEST(BinarySearchTree, insertion_removing_mix3) {
	BinarySearchTree<int, int> bst;
	bst.Insert(new TreeNode<int, int>(6, nullptr));
	bst.Insert(new TreeNode<int, int>(8, nullptr));
	bst.Insert(new TreeNode<int, int>(7, nullptr));
	bst.Insert(new TreeNode<int, int>(9, nullptr));
	bst.Insert(new TreeNode<int, int>(4, nullptr));
	bst.Insert(new TreeNode<int, int>(5, nullptr));
	bst.Insert(new TreeNode<int, int>(3, nullptr));
	bst.Insert(new TreeNode<int, int>(2, nullptr));
	bst.Insert(new TreeNode<int, int>(1, nullptr));
	bst.Remove(4);
	bst.Remove(3);
	bst.Remove(5);
	bst.Remove(2);
	bst.Remove(6);
	bst.Remove(1);
	bst.Remove(9);
	bst.Remove(7);

	ASSERT_NO_THROW(bst.Remove(8));
}



TEST(BinarySearchTree, insertion_removing_mix4) {
	BinarySearchTree<int, int> bst;
	bst.Insert(new TreeNode<int, int>(6, nullptr));
	bst.Insert(new TreeNode<int, int>(8, nullptr));
	bst.Insert(new TreeNode<int, int>(7, nullptr));
	bst.Insert(new TreeNode<int, int>(9, nullptr));
	bst.Insert(new TreeNode<int, int>(4, nullptr));
	bst.Insert(new TreeNode<int, int>(5, nullptr));
	bst.Insert(new TreeNode<int, int>(3, nullptr));
	bst.Insert(new TreeNode<int, int>(2, nullptr));
	bst.Insert(new TreeNode<int, int>(1, nullptr));
	bst.Remove(6);
	bst.Remove(7);
	bst.Remove(8);
	bst.Remove(4);
	bst.Remove(5);
	bst.Remove(3);
	bst.Remove(2);
	bst.Remove(1);

	ASSERT_NO_THROW(bst.Remove(9));
}














/*
*/