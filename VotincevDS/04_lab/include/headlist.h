#pragma once
#include "list.h"

template <typename T>
class HeadList : public List<T> {
protected:
    ListNode<T>* pHead;

public:
    HeadList();
    HeadList(const T& x);
    HeadList(const List<T>& list);
    HeadList(const HeadList<T>& list);
    HeadList(const ListNode<T>& node);
    ~HeadList();

    const HeadList<T>& operator=(const HeadList <T>& list);

    virtual void pushFront(ListNode<T>* node);
    virtual void pushBack(ListNode<T>* node);


    using List::pushFront; // вместо pushFront(T obj)
    using List::pushBack;  // убрать pushFront(ListNode<T>* node) нельзя (специфика headlist)

    //virtual void pushFront(T obj); // TODO: move to List  ++
    //virtual void pushBack(T obj); // TODO: move to List   ++

    virtual void InsertBefore(ListNode<T>* node, T key);
    virtual void RemoveFirst();

    bool operator==(const HeadList<T>& s) const;
    bool operator!=(const List<T>& s) const;

};

template <typename T>
HeadList<T>::HeadList() : List() {
    pHead = new ListNode<T>(T(), pFirst);
}

template <typename T>
HeadList<T>::HeadList(const T& x) : List(x) {
    pHead = new ListNode<T>(T(), pFirst); 
}

template <typename T>
HeadList<T>::HeadList(const List<T>& list) : List(list) {
    pHead = new ListNode<T>(T(), pFirst);   
}

template <typename T>
HeadList<T>::HeadList(const HeadList<T>& list) : List(list.pFirst) {
    pHead = new ListNode<T>(T(), pFirst);   
}

template <typename T>
HeadList<T>::HeadList(const ListNode<T>& node) : List(node) {
    pHead = new ListNode<T>(T(), pFirst);    
}

template <typename T>
HeadList<T>::~HeadList() {
    delete pHead;
}

template <typename T>
const HeadList<T>& HeadList<T>::operator=(const HeadList <T>& list) {
    List<T>::operator=(list.pFirst);
    pHead = new ListNode<T>(T(), pFirst);    
    return *this;
}

template <typename T>
void HeadList<T>::pushFront(ListNode<T>* node) {
    List<T>::pushFront(node);   
    pHead->next = node;
};

template <typename T>
void HeadList<T>::pushBack(ListNode<T>* node) {
    List<T>::pushBack(node);
    if (pFirst == node)
    {
        pHead->next = node;       
    }
};

template <typename T>
void HeadList<T>::InsertBefore(ListNode<T>* node, T key) {
    List<T>::InsertBefore(node, key);
    if (pFirst == node)
    {
        pHead->next = pFirst;       
    }
};

template <typename T>
void HeadList<T>::RemoveFirst() {
    List<T>::RemoveFirst();
    pHead->next = pFirst;  
}

template <typename T>
bool HeadList<T>::operator==(const HeadList<T>& s) const {
    return List<T>::operator==(List<T>(s.pFirst));
}

template <typename T>
bool HeadList<T>::operator!=(const List<T>& s) const {
    return !(*this == s);
}
