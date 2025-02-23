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
        HeadList<T>::operator=(list.get_pFirst());
        make_circular();
        return *this;
    }
    

    ListNode<T>* search(T key) const {
        return HeadList<T>::search(key);
    };
    
    ListNode<T>* searchLast() const {
        return HeadList<T>::searchLast();
    };
    



    // функция "логичная" для стеков
    // для headlist и ringlist
    // может сбить с толку (но пока пусть будет)
    void push(const T& key) {
        HeadList<T>::push(key);
        ////   добавляет элемент с заданным значением
        ////   в начало списка
        //ListNode<T>* tmp = new ListNode<T>(key);
        //pushFront(tmp);
    }


    
    void pushFront(ListNode<T>* node) {
        HeadList<T>::pushFront(node);
    };

    
    void pushBack(ListNode<T>* node) {
        HeadList<T>::pushBack(node);
        make_circular();
    };
    
    void InsertAfter(ListNode<T>* node, T key) {
        HeadList<T>::InsertAfter(node, key);
        make_circular();
    };






    //------------------------------
    // кажется, писать реализацию 
    // след метод нет необходимости
    // тк и так вызываются методы
    // класса предка


    /*
    void InsertBefore(ListNode<T>* node, T key) {
        HeadList<T>::InsertBefore(node, key);
        make_circular();
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
