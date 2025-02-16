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

    
    // доделать это и все что ниже
    /*RingHeadList(const RingHeadList<T>& list) { 
        RingHeadList<T> tmp = li
        make_circular();
    }*/

    /*
    RingHeadList(const ListNode<T>& node) : HeadList(node) {
        make_circular();
    }


    ~RingHeadList() {
    
    }

    
    RingHeadList<T>& operator=(const List <T>& list) {
        HeadList<T>::operator=(list);
        pHead = new ListNode<T>(0);
        pHead->next = get_pFirst();
        set_pPrev(pHead);
        return *this;
    }

    RingHeadList<T>& operator=(const RingHeadList <T>& list) {
        HeadList<T>::operator=(list.get_pFirst());
        pHead = new ListNode<T>(0);
        pHead->next = get_pFirst();
        set_pPrev(pHead);
        return *this;
    }


    ListNode<T>* search(T key) const {
        // обхожу исходный список поэлементно
        // и сравниваю ключи с входным ключом
        ListNode<T>* curr = this->get_pFirst();
        while (curr != this->get_pStop()) {
            if (curr->val == key) {
                return curr;
            }
            curr = curr->next;
        }

        // не нашелся ключ
        if (curr == this->get_pStop()) {
            throw "this element does not exist";
        }
        return curr;
    };

    ListNode<T>* searchLast() const {
        if (pFirst == nullptr) {
            return nullptr;
        }

        // прохожу лист поэлементно до pStop
        // и нахожу звено ,у которого  ->next = pStop
        ListNode<T>* curr = pFirst;
        while (curr->next != pStop) {
            curr = curr->next;
        }
        return curr;
    };

    void push(const T& key) {
        //   добавляет элемент с заданным значением
        //   в начало списка
        ListNode<T>* tmp = new ListNode<T>(key);
        pushFront(tmp);
    }

    void pushFront(ListNode<T>* node) {
        HeadList<T>::pushFront(node);
        set_pPrev(pHead);
        pHead->next = node;
        return;
    };


    void pushBack(ListNode<T>* node) {
        HeadList<T>::pushBack(node);
        set_pPrev(pHead);
        pHead->next = get_pFirst();
        return;
    };

    void InsertAfter(ListNode<T>* node, T key) {
        HeadList<T>::InsertAfter(node, key);
        set_pPrev(pHead);
        pHead->next = get_pFirst();
    };

    void InsertBefore(ListNode<T>* node, T key) {
        HeadList<T>::InsertBefore(node, key);
        set_pPrev(pHead);
        pHead->next = get_pFirst();
    };


    void remove(T key) {
        HeadList<T>::remove(key);
        set_pPrev(pHead);
        pHead->next = get_pFirst();
    };

    size_t size() const {
        return HeadList<T>::size();
    };

    void RemoveFirst() {
        HeadList<T>::RemoveFirst();
        set_pPrev(pHead);
        pHead->next = get_pFirst();
    }


    bool operator==(const RingHeadList<T>& s) const {
        return HeadList<T>::operator==(HeadList<T>(s.get_pFirst()));
    }



    bool operator!=(const HeadList<T>& s) const {
        return !(*this == s);
    }

    */
};
