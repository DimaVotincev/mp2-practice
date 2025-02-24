#pragma once
#include "list.h"

template <typename T>
class HeadList : public List<T> {
protected:
    ListNode<T>* pHead;

protected:

    // !!! TODO + имеем доступ к полям
    void make_circular() {
        set_pStop(pHead);
        if (get_pLast() != nullptr) {
            get_pLast()->next = pHead;
        }       
    }

    void remove_circular() {
        set_pStop(nullptr);
        if (get_pLast() != nullptr) {
            get_pLast()->next = nullptr;
        }
    }
    

public:

    

    HeadList() : List() {
        pHead = new ListNode<T>(0, pFirst);
    }


    HeadList(const T& x) : List(x) {
        pHead = new ListNode<T>(0, pFirst);
        pPrev = pHead;
    }


    HeadList(const List<T>& list) : List(list) {   
        pHead = new ListNode<T>(0);
        pHead->next = get_pFirst();
        set_pPrev(pHead);
    }

    HeadList(const HeadList<T>& list) : List(list.get_pFirst()) {    
        pHead = new ListNode<T>(0);
        pHead->next = get_pFirst();
        set_pPrev(pHead);
    }

    HeadList(const ListNode<T>& node) : List(node) {
        pHead = new ListNode<T>(0);
        pHead->next = get_pFirst();
        set_pPrev(pHead);
    }


    ~HeadList() {
        delete pHead;
    }



    ListNode<T>* get_pHead() const { return pHead; }




    HeadList<T>& operator=(const List <T>& list) {   
        List<T>::operator=(list);
        pHead = new ListNode<T>(0);
        pHead->next = get_pFirst();
        set_pPrev(pHead);
        
        return *this;
    }

    HeadList<T>& operator=(const HeadList <T>& list) {
        List<T>::operator=(list.get_pFirst());
        pHead = new ListNode<T>(0);
        pHead->next = get_pFirst();
        set_pPrev(pHead);
        return *this;
    }


    ListNode<T>* searchLast() const {  
        if (get_pFirst() == nullptr) { // было pFirst
            return nullptr;
        }

        // прохожу лист поэлементно до pStop
        // и нахожу звено ,у которого  ->next = pStop
        ListNode<T>* curr = get_pFirst(); // было pFirst
        while (curr->next !=  get_pStop()) { // было pStop
            curr = curr->next;
        }
        return curr;
    };

    void pushFront(ListNode<T>* node) {   
        List<T>::pushFront(node);
        pPrev = pHead;
        pHead->next = node;
        return;
    };


    virtual void pushBack(ListNode<T>* node) {  
        List<T>::pushBack(node);
        if (pFirst == node)
        {
            pPrev = pHead;
            pHead->next = pFirst;
        }
        return;
    };


    virtual void InsertBefore(ListNode<T>* node, T key) { 
        List<T>::InsertBefore(node, key);
        if (pFirst == node)
        {
            pPrev = pHead;
            pHead->next = pFirst;
        }
    };


    void remove(T key) {     
        List<T>::remove(key);
        set_pPrev(pHead);
        pHead->next = get_pFirst();
    };

    size_t size() const {   
        return List<T>::size();
    };

    virtual void RemoveFirst() {           
        List<T>::RemoveFirst();
        set_pPrev(pHead);
        pHead->next = get_pFirst();
    }


    bool operator==(const HeadList<T>& s) const {   
        return List<T>::operator==(List<T>(s.get_pFirst()));     
    }



    bool operator!=(const List<T>& s) const { 
        return !(*this == s);
    }
};