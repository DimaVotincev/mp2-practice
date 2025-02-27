#pragma once
#include "headlist.h"


template <typename T>
class RingHeadList : public HeadList<T> {

public:
    RingHeadList() : HeadList() {     
        make_circular();
    }

    
    RingHeadList(const T& x) : HeadList(x) {
        make_circular();
    }

    
    RingHeadList(const HeadList<T>& list) : HeadList(list) {
        make_circular();
    }

    
    RingHeadList(const RingHeadList<T>& list) : HeadList(list.get_pHead()->next)  {
        make_circular();
    }



    RingHeadList(const ListNode<T>* node) : HeadList(node) {
        make_circular();
    }

    
    ~RingHeadList() {
    
    }
    
    
    RingHeadList<T>& operator=(const List <T>& list) {
        HeadList<T>::operator=(list);       
        make_circular();
        return *this;
    }
    
    RingHeadList<T>& operator=(const RingHeadList <T>& list) {
        HeadList<T>::operator=(HeadList(list.get_pHead()->next));
        make_circular();
        return *this;
    }
    
    
    void pushFront(ListNode<T>* node) {
        HeadList<T>::pushFront(node);
        make_circular();
    };

    
    void pushBack(ListNode<T>* node) {
        HeadList<T>::pushBack(node);
        make_circular();
    };
    
    void InsertAfter(ListNode<T>* node, T key) {
        HeadList<T>::InsertAfter(node, key);
        make_circular();
    };



    
    void InsertBefore(ListNode<T>* node, T key) {
        HeadList<T>::InsertBefore(node, key);
        make_circular();
    };


    void remove(T key) {
        HeadList<T>::remove(key);
        pHead->next = get_pHead();
    };

    size_t size() const {
        return HeadList<T>::size();
    };

    void RemoveFirst() {
        HeadList<T>::RemoveFirst();    
        pHead->next = get_pHead();
    }


    bool operator==(const RingHeadList<T>& s) const {
        return HeadList<T>::operator==(HeadList<T>(s.get_pHead()->next));
    }



    bool operator!=(const HeadList<T>& s) const {
        return !(*this == s);
    }

    
};
