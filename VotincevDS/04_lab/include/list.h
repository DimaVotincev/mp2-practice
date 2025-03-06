#pragma once
#include <iostream>

using namespace std;

template <typename T>
struct ListNode {
    T val;
    ListNode* next;
    ListNode() : val(T()), next(nullptr) {}
    ListNode(const T& x) : val(T(x)), next(nullptr) {}
    ListNode(const T& x, ListNode* _next) : val(T(x)), next(_next) {}
};


template<typename T>
class List
{
protected:
    ListNode<T>* pFirst;
    ListNode<T>* pCurr;
    ListNode<T>* pPrev;
    ListNode<T>* pLast;
    ListNode<T>* pStop;
public:
    List();
    List(const T& x);
    List(const List<T>& list);
    List(const ListNode<T>* node);
    ~List();

    const List<T>& operator=(const List <T>& list);

    void reset_pCurr();
    T get_val() const;
    ListNode<T>* get_pFirst() const;
    ListNode<T>* search(T key);

    void push(const T& key);
    virtual void pushFront(ListNode<T>* node);
    virtual void pushBack(ListNode<T>* node);
    virtual void pushFront(T obj); // TODO: move to List
    virtual void pushBack(T obj); // TODO: move to List

    virtual void InsertAfter(ListNode<T>* node, T key);
    virtual void InsertBefore(ListNode<T>* node, T key);
    virtual void remove(T key);
    virtual void RemoveFirst();

    size_t size() const;

    bool operator==(const List<T>& s) const;
    bool operator!=(const List<T>& s) const;


};




template <typename T>
List<T>::List() {               
    pFirst = nullptr;
    pCurr = pFirst;
    pPrev = nullptr;
    pLast = nullptr;
    pStop = nullptr;
}



template <typename T>
List<T>::List(const T& x) {              
    pFirst = new ListNode<T>(x);
    pCurr = pFirst;
    pPrev = nullptr;
    pLast = pFirst;
    pStop = nullptr;
}



template <typename T>
List<T>::List(const List<T>& list) : List() {    
    if (list.pFirst == nullptr) {
        return;
    }
    pFirst = new ListNode<T>(list.pFirst->val);
    pCurr = pFirst;
    pStop = nullptr;
    pPrev = pStop;
    ListNode<T>* curr = list.pFirst->next;
    if (curr == pStop) {
        pLast = pFirst;
        return;
    }
    while (curr != list.pStop) {
        pCurr->next = new ListNode<T>(curr->val);
        pPrev = pCurr;
        pCurr = pCurr->next;
        curr = curr->next;
    }
    pPrev->next = pCurr;
    pLast = pCurr;
    pCurr = pFirst;
    pPrev = pStop;
}

template <typename T>
List<T>::List(const ListNode<T>* node) : List() {       
    if (node == nullptr) {
        return;
    }
    pFirst = new ListNode<T>(node->val);
    pCurr = pFirst;
    ListNode<T>* curr = node->next;
    while (curr != pStop && curr->next != node) {
        pCurr->next = new ListNode<T>(curr->val);
        pPrev = pCurr;
        pCurr = pCurr->next;
        curr = curr->next;
    }
    if (pPrev) {
        pPrev->next = pCurr;
    }

    pLast = pCurr;
    reset_pCurr();
}



template <typename T>
List<T>::~List() {      
    if (pFirst == nullptr) {
        return;
    }

    pPrev = pFirst;
    pCurr = pPrev->next;

    while (pCurr != pStop) {
        delete pPrev;
        pPrev = pCurr;
        pCurr = pCurr->next;
    }
    delete pPrev;

    pFirst = nullptr;
    pCurr = nullptr;
    pPrev = nullptr;
    pLast = nullptr;
}





template <typename T>
const List<T>& List<T>::operator=(const List <T>& list) {           
    if (this == &list)
    {
        return *this;
    }
    if (list.pFirst == nullptr)
    {
        pFirst = nullptr;
        return *this;
    }

    pFirst = new ListNode<T>(list.pFirst->val);
    pCurr = pFirst;

    ListNode<T>* curr = list.pFirst->next;
    while (curr != nullptr)
    {
        pCurr->next = new ListNode<T>(curr->val);
        pCurr = pCurr->next;
        curr = curr->next;
    }
    pLast = pCurr;
    reset_pCurr();

    return *this;
}


template <typename T>
void List<T>::reset_pCurr() {           
    pCurr = pFirst;
    pPrev = pStop;
}


template <typename T>
T List<T>::get_val() const {               
    return pFirst->val;
}


template <typename T>
ListNode<T>* List<T>::get_pFirst() const {
    return pFirst;
}


template <typename T>
ListNode<T>* List<T>::search(T key) {  
    pCurr = pFirst;
    pPrev = pStop;

    while (pCurr != pStop && pCurr != nullptr) {
        if (pCurr->val == key) {
            return pCurr;
        }
        pPrev = pCurr;
        pCurr = pCurr->next;
    }

    if (pCurr == pStop || pCurr == nullptr) {
        return pStop;
    }

    return pCurr;
};


template <typename T>
void List<T>::push(const T& key) {   
    ListNode<T>* tmp = new ListNode<T>(key);
    pushFront(tmp);
}


template <typename T>
void List<T>::pushFront(ListNode<T>* node) {  
    if (node == nullptr) {
        throw "cant push null node in front";
    }
    if (node->next != nullptr) {
        throw "InsertAfter can push only 1 node";
    }
    if (pFirst == nullptr) {
        pFirst = node;
        pCurr = pFirst;
        pPrev = pStop;
        pLast = pFirst;
        return;
    }

    node->next = pFirst;
    pFirst = node;
    pCurr = pFirst;
    pPrev = pStop;
};



template <typename T>
void List<T>::pushBack(ListNode<T>* node) { 
    if (node == nullptr) {
        return;
    }
    if (node->next != nullptr) {
        throw "InsertAfter can push only 1 node";
    }
    if (pFirst == nullptr) {
        this->pushFront(node);
        return;
    }

    pLast->next = node;
    pLast = pLast->next;
};


template <typename T>
void List<T>::InsertAfter(ListNode<T>* node, T key) {            
    search(key);
    if (node->next != nullptr) {
        throw "InsertAfter can push only 1 node";
    }
    if (pCurr == pStop) {
        throw "cant InsertAfter not existing elem";
    }
    node->next = pCurr->next;
    if (pCurr->next == pStop) {
        pLast = node;
    }

    pCurr->next = node;
};

template <typename T>
void List<T>::InsertBefore(ListNode<T>* node, T key) {      
    search(key);            // !! TODO: search!!!!!!!!!!!!!
    if (pCurr == pStop) {
        throw "this key does not exist";
    }
    if (node->next != nullptr) {
        throw "InsertBefore can push only 1 node";
    }
    if (pCurr == pFirst) {
        pushFront(node);
        return;
    }
    node->next = pCurr;
    pPrev->next = node;
};


template <typename T>
void List<T>::remove(T key) {                
    search(key);        // !! TODO: search!!!!!!!!!!!!!
    if (pCurr == pStop) {
        throw "this key doesnt exist";
    }
    if (pPrev == pStop) { // !! TODO: RemoveFirst!!!!!!!!!!!!!
        RemoveFirst();
        return;
    }
    if (pCurr->next == pStop) {
        pLast = pPrev;
    }
    pPrev->next = pCurr->next;
    delete pCurr;
    reset_pCurr();
};



template <typename T>
void List<T>::pushFront(T obj) {
    ListNode<T>* add = new ListNode<T>(obj);
    pushFront(add);

}
template <typename T>
void List<T>::pushBack(T obj) {
    ListNode<T>* add = new ListNode<T>(obj);
    pushBack(add);
}

template <typename T>
size_t List<T>::size() const {       
    ListNode<T>* curr = pFirst;
    size_t size = 0;
    while (curr != pStop) {
        size++;
        curr = curr->next;
    }
    return size;
};


template <typename T>
void List<T>::RemoveFirst() {          
    if (pFirst == nullptr) {
        throw "removing element from empty list";
    }

    ListNode<T>* tmp = pFirst;
    if (pFirst->next == pStop) {
        delete tmp;
        pFirst = nullptr;
        pCurr = nullptr;
        pLast = nullptr;
        return;
    }

    if (pCurr == pFirst) {
        pFirst = pFirst->next;
        pCurr = pFirst;
    }
    else {
        pFirst = pFirst->next;
    }
    delete tmp;
}


template <typename T>
bool List<T>::operator==(const List<T>& s) const {     
    ListNode<T>* curr1 = pFirst, * curr2 = s.pFirst;
    while (curr1 != pStop && curr2 != s.pStop) {
        if (curr1->val != curr2->val) {
            return 0;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    if (curr1 == pStop && curr2 == s.pStop) {
        return 1;
    }
    return 0;
}


template <typename T>
bool List<T>::operator!=(const List<T>& s) const {    
    return !(*this == s);
}
