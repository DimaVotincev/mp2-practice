#pragma once
#include "headlist.h"


template <typename T>
class RingHeadList : public HeadList<T> {

public:
    RingHeadList();
    RingHeadList(const T& x);
    RingHeadList(const HeadList<T>& list);
    RingHeadList(const RingHeadList<T>& list);
    RingHeadList(const ListNode<T>* node);
    ~RingHeadList();

    const RingHeadList<T>& operator=(const List<T>& list);
    const RingHeadList<T>& operator=(const RingHeadList<T>& list);

    
    void pushFront(ListNode<T>* node);
    void pushBack(ListNode<T>* node);
    void pushFront(T obj); // TODO: move to List
    void pushBack(T obj); // TODO: move to List
    void remove(T key); 
    void RemoveFirst();

    bool operator==(const RingHeadList<T>& s) const;
    bool operator!=(const HeadList<T>& s) const;
};


template <typename T>
RingHeadList<T>::RingHeadList() : HeadList() {
    
}

template <typename T>
RingHeadList<T>::RingHeadList(const T& x) : HeadList(x) {
    pFirst->next = pHead;
    pStop = pHead;
}

template <typename T>
RingHeadList<T>::RingHeadList(const HeadList<T>& list) : HeadList(list) {
    pLast->next = pHead;
    pStop = pHead;
}

template <typename T>
RingHeadList<T>::RingHeadList(const RingHeadList<T>& list) : HeadList(list.pFirst) {
    pLast->next = pHead;
    pStop = pHead;
}


template <typename T>
RingHeadList<T>::RingHeadList(const ListNode<T>* node) : HeadList(node) {
    pLast->next = pHead;
    pStop = pHead;
}

template <typename T>
RingHeadList<T>::~RingHeadList() {

}

template <typename T>
const RingHeadList<T>& RingHeadList<T>::operator=(const List<T>& list) {
    HeadList<T>::operator=(list);
    pLast->next = pHead;
    pStop = pHead;
    return *this;
}

template <typename T>
const RingHeadList<T>& RingHeadList<T>::operator=(const RingHeadList <T>& list) {
    HeadList<T>::operator=(HeadList(list.pFirst));
    pLast->next = pHead;
    pStop = pHead;
    return *this;
}

template <typename T>
void RingHeadList<T>::pushFront(T obj) {
    ListNode<T>* node = new ListNode<T>(obj);
    HeadList<T>::pushFront(obj);
    pLast->next = pHead;
    pStop = pHead;
};

template <typename T>
void RingHeadList<T>::pushBack(T obj) {
   /* ListNode<T>* node = new ListNode<T>(obj);*/
    HeadList<T>::pushBack(obj);
    pLast->next = pHead;
    pStop = pHead;
};

template <typename T>
void RingHeadList<T>::remove(T key) {
    HeadList<T>::remove(key);
    pHead->next = pFirst;
    pStop = pHead;
};



template <typename T>
void RingHeadList<T>::pushFront(ListNode<T>* node) {
    HeadList<T>::pushFront(node);
    pLast->next = pHead;
    pStop = pHead;
};



template <typename T>
void RingHeadList<T>::pushBack(ListNode<T>* node) {
    HeadList<T>::pushBack(node);
    pLast->next = pHead;
};




template <typename T>
void RingHeadList<T>::RemoveFirst() {
    HeadList<T>::RemoveFirst(); // TODO: pHead на себя, если пуст
}


template <typename T>
bool RingHeadList<T>::operator==(const RingHeadList<T>& s) const {
    return HeadList<T>::operator==(HeadList<T>(s.pHead->next));
}


template <typename T>
bool RingHeadList<T>::operator!=(const HeadList<T>& s) const {
    return !(*this == s);
}