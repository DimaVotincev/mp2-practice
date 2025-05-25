#pragma once

#include <iostream>
#include <queue>
using namespace std;





template<typename Tkey, typename Tdata>
struct TreeNode
{
    Tkey key;
    Tdata* data;



    TreeNode<Tkey, Tdata>* pParent;
    TreeNode<Tkey, Tdata>* pLeft;
    TreeNode<Tkey, Tdata>* pRight;
    TreeNode() : key(Tkey()), data(Tdata()),
        pParent(nullptr),
        pLeft(nullptr),
        pRight(nullptr) {
    };
    TreeNode(Tkey _key, Tdata* _data) : key(_key), data(_data),
        pParent(nullptr),
        pLeft(nullptr),
        pRight(nullptr) {
    };

    TreeNode(TreeNode<Tkey, Tdata>* t) {
        key = t->key;
        data = t->data; // ???????????
        pParent = t->pParent;
        pLeft = t->pLeft;
        pRight = t->pRight;
    }

};








template<typename Tkey, typename Tdata>
class BinarySearchTree {
public:
    TreeNode<Tkey, Tdata>* pRoot;
    TreeNode<Tkey, Tdata>* pCurr;


    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree<Tkey,Tdata>& tree);
    ~BinarySearchTree();
    TreeNode<Tkey, Tdata>* Search(Tkey key);
    TreeNode<Tkey, Tdata>* SearchMin(TreeNode<Tkey, Tdata>* tree);
    TreeNode<Tkey, Tdata>* SearchMax(TreeNode<Tkey, Tdata>* tree);
    TreeNode<Tkey, Tdata>* SearchNext(TreeNode<Tkey, Tdata>* tree);
    TreeNode<Tkey, Tdata>* SearchPrev(TreeNode<Tkey, Tdata>* tree);
    void Remove(Tkey key);
    void Insert(TreeNode<Tkey, Tdata>* node);
};


template<typename Tkey, typename Tdata>
BinarySearchTree<Tkey,Tdata>::BinarySearchTree() {
    pRoot = nullptr;
    pCurr = nullptr;
}


template<typename Tkey, typename Tdata>
TreeNode<Tkey, Tdata>* CopyNode(TreeNode<Tkey, Tdata>* node, TreeNode<Tkey, Tdata>* parent = nullptr) {
    if (!node) return nullptr;

    TreeNode<Tkey, Tdata>* newNode = new TreeNode<Tkey, Tdata>();
    newNode->key = node->key;
    newNode->data = node->data;
    newNode->pParent = parent;
    newNode->pLeft = CopyNode(node->pLeft, newNode);
    newNode->pRight = CopyNode(node->pRight, newNode);

    return newNode;
}

template<typename Tkey, typename Tdata>
BinarySearchTree<Tkey, Tdata>::
    BinarySearchTree(const BinarySearchTree<Tkey, Tdata>& tree)
    : pRoot(nullptr), pCurr(nullptr) {
    pRoot = CopyNode(tree.pRoot);

    if (tree.pCurr) {
        pCurr = Search(tree.pCurr->key);
    }
}


template<typename Tkey, typename Tdata>
BinarySearchTree<Tkey, Tdata>::~BinarySearchTree() {
    if (this->pRoot == nullptr) return;
    queue<TreeNode<Tkey,Tdata>*> q;
    q.push(this->pRoot);

    while (!q.empty()) {
        TreeNode<Tkey,Tdata>* tmp = q.front();
        
        q.pop();

        if (tmp->pLeft) {
            q.push(tmp->pLeft);
        }

        if (tmp->pRight) {
            q.push(tmp->pRight);
        }

        delete tmp;

    }
}


template<typename Tkey, typename Tdata>
TreeNode<Tkey, Tdata>* BinarySearchTree<Tkey, Tdata>::Search(Tkey key) {
    TreeNode<Tkey, Tdata>* answ = this->pRoot;
    while (answ != nullptr) {
        if (answ->key == key) {
            return answ;
        } else if (answ->key < key) { 
            answ = answ->pRight; // left?
        }
        else if (answ->key > key) {
            answ = answ->pLeft; // right?
        }
    }
    pCurr = answ;
    return answ;
}

template<typename Tkey, typename Tdata>
TreeNode<Tkey, Tdata>* BinarySearchTree<Tkey, Tdata>::
SearchMin(TreeNode<Tkey, Tdata>* tree) {
    if (!tree) {
        return nullptr;
    }
    TreeNode<Tkey, Tdata>* answ = tree;

    while (answ->pLeft != nullptr) {
        answ = answ->pLeft;
    }
    pCurr = answ;
    return answ;
}

template<typename Tkey, typename Tdata>
TreeNode<Tkey, Tdata>* BinarySearchTree<Tkey, Tdata>::
    SearchMax(TreeNode<Tkey, Tdata>* tree) {
    if (!tree) {
        return nullptr;
    }
    TreeNode<Tkey, Tdata>* answ = tree;

    while (answ->pRight != nullptr) {
        answ = answ->pRight;
    }
    pCurr = answ;
    return answ;
}

template<typename Tkey, typename Tdata>
TreeNode<Tkey, Tdata>* BinarySearchTree<Tkey, Tdata>::
SearchNext(TreeNode<Tkey, Tdata>* tree) {
    if (tree->pRight != nullptr) {
        return SearchMin(tree->pRight);
    }
    TreeNode<Tkey, Tdata>* answ = tree->pParent;
    if (SearchMax(pRoot) == answ) // мб не надо
    {
        return answ;
    }
    while (answ != nullptr && answ->pRight == tree) {
        tree = answ;
        answ = tree->pParent;
    }
    pCurr = answ;
    return answ;
}

template<typename Tkey, typename Tdata>
TreeNode<Tkey, Tdata>* BinarySearchTree<Tkey, Tdata>::
SearchPrev(TreeNode<Tkey, Tdata>* tree) {
    if (tree->pLeft != nullptr) {
        return SearchMax(tree->pLeft);
    }
    TreeNode<Tkey, Tdata>* answ = tree->pParent;
    if (SearchMin(pRoot) == answ) // мб не надо
    {
        return answ;
    }
    while (answ != nullptr && answ->pLeft == tree) {
        tree = answ;
        answ = tree->pParent;
    }
    pCurr = answ;
    return answ;
}

template<typename Tkey, typename Tdata>
void BinarySearchTree<Tkey, Tdata>::Remove(Tkey key) {
    TreeNode<Tkey, Tdata>* node = Search(key);
    if (node == nullptr)
    {
        throw "this key doent exist";
    }
    if (node->pLeft == nullptr && node->pRight == nullptr) // лист
    {
        if (node == pRoot)
        {
            delete node;
            pRoot = nullptr;
            return;
        }
        if (node->pParent->pLeft == node)
        {
            node->pParent->pLeft = nullptr;
            delete node;
            return;
        }
        else 
        {
            node->pParent->pRight = nullptr;
            delete node;
            return;
        }
    }
    if (node->pLeft == nullptr || node->pRight == nullptr)// 1 потомок
    {

        if (node == pRoot)
        {
            if (pRoot->pLeft) {
                pRoot = pRoot->pLeft;
            }
            else {
                pRoot = pRoot->pRight;
            }
            pRoot->pParent = nullptr;
            delete node;
            return;
        }

        if (node->pParent->pLeft == node)
        {
            if (node->pLeft != nullptr) // есть левый
            {
                node->pParent->pLeft = node->pLeft;
                node->pLeft->pParent = node->pParent;
            }
            else // есть правый
            {
                node->pParent->pLeft = node->pRight;
                node->pRight->pParent = node->pParent;
            }
            delete node;
            return;
        }
        if (node->pParent->pRight == node)
        {
            if (node->pLeft != nullptr) //есть левый
            {
                node->pParent->pRight = node->pLeft;
                node->pLeft->pParent = node->pParent;
            }
            else // есть правый
            {
                node->pParent->pRight = node->pRight;
                node->pRight->pParent = node->pParent;
            }
            delete node;
            return;
        }
    }

    TreeNode<Tkey, Tdata>* tmp = SearchMin(node->pRight);
    TreeNode<Tkey, Tdata>* add = new TreeNode<Tkey,Tdata>(tmp);
    
    Remove(tmp->key);
    node->key = add->key;
    node->data = add->data;
    /*node->pParent = add->pParent;
    node->pLeft = add->pLeft;
    node->pRight = add->pRight;*/
    
    return;
    
    /*TreeNode<Tkey, Tdata>* successor = SearchMin(node->pRight);
    node->key = successor->key;
    node->data = successor->data;
    Remove(successor->key);
    return;*/

}

template<typename Tkey, typename Tdata>
void BinarySearchTree<Tkey, Tdata>::
Insert(TreeNode<Tkey, Tdata>* node) {
    if (pRoot == nullptr) {
        pRoot = node;
        return;
    }
    if (Search(node->key) != nullptr) {
        throw "this item already exists";
    }

    TreeNode<Tkey, Tdata>* x = pRoot, * y = nullptr;
    while (x) {
        y = x;
        if (x->key < node->key) {
            x = x->pRight;
        }
        else {
            x = x->pLeft;
        }
    }
    node->pParent = y;
    if (y->key < node->key) {
        y->pRight = node;
    }
    else {
        y->pLeft = node;
    }
}








