#pragma once
#include "list.h"

template <typename T>
class HeadList : public List<T> {
private:
    ListNode<T>* pHead;

protected:

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
        pHead = new ListNode<T>(); // было ListNode<T>(0)
        pHead->next = get_pFirst();

    }


    HeadList(const T& x) : List(x) {
        pHead = new ListNode<T>(0);
        pHead->next = get_pFirst();
        set_pPrev(pHead);
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


    // функция "логичная" для стеков
    // для headlist и ringlist
    // может сбить с толку (но пока пусть будет)
    void push(const T& key) {
        //   добавляет элемент с заданным значением
        //   в начало списка
        ListNode<T>* tmp = new ListNode<T>(key);
        pushFront(tmp);
    }




    void pushFront(ListNode<T>* node) {   
        List<T>::pushFront(node);
        set_pPrev(pHead);
        pHead->next = node;
        return;
    };


    void pushBack(ListNode<T>* node) {  
        List<T>::pushBack(node);
        set_pPrev(pHead);
        pHead->next = get_pFirst();
        return;
    };

    void InsertAfter(ListNode<T>* node, T key) { 
        List<T>::InsertAfter(node, key);
        set_pPrev(pHead);
        pHead->next = get_pFirst();
    };

    void InsertBefore(ListNode<T>* node, T key) { 
        List<T>::InsertBefore(node, key);
        set_pPrev(pHead);
        pHead->next = get_pFirst();
    };


    void remove(T key) {     
        List<T>::remove(key);
        set_pPrev(pHead);
        pHead->next = get_pFirst();
    };

    size_t size() const {   
        return List<T>::size();
    };

    void RemoveFirst() {           
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