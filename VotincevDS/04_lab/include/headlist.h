#pragma once
#include "list.h"

template <typename T>
class HeadList : public List<T> {
protected:
    ListNode<T>* pHead;

protected:

    // !!! TODO + имеем доступ к полям
    void make_circular() {
        pStop = pHead;
        if (pLast != nullptr) {
            pLast->next = pHead;
        }       
    }

    void remove_circular() {
        pStop = nullptr
        if (pLast != nullptr) {
            pLast->next = nullptr;
        }
    }
    

public:

    

    HeadList() : List() {
        pHead = new ListNode<T>(0, pFirst);
        pPrev = pHead;
    }


    HeadList(const T& x) : List(x) {
        pHead = new ListNode<T>(0, pFirst);
        pPrev = pHead;
    }


    HeadList(const List<T>& list) : List(list) {   
        pHead = new ListNode<T>(0,pFirst);       
        pPrev = pHead;
    }

    HeadList(const HeadList<T>& list) : List(list.pFirst) {    
        pHead = new ListNode<T>(0,pFirst);        
        pPrev = pHead;
    }

    HeadList(const ListNode<T>& node) : List(node) {
        pHead = new ListNode<T>(0,pFirst);        
        pPrev = pHead;
    }


    ~HeadList() {
        delete pHead;
    }



    ListNode<T>* get_pHead() const { return pHead; }



    // вроде удобный метод, но вроде и не нужный
    // 
    //HeadList<T>& operator=(const List <T>& list) {   
    //    List<T>::operator=(list);
    //    pHead = new ListNode<T>(0,pFirst);       
    //    pPrev = pHead;
    //    
    //    return *this;
    //}
    //

    HeadList<T>& operator=(const HeadList <T>& list) {
        List<T>::operator=(list.pFirst);
        pHead = new ListNode<T>(0,pFirst);       
        pPrev = pHead;
        return *this;
    }


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
            
        }
        return;
    };


    virtual void InsertBefore(ListNode<T>* node, T key) { 
        List<T>::InsertBefore(node, key);
        if (pFirst == node)
        {
            pPrev = pHead;
            
        }
    };


    void remove(T key) {     
        List<T>::remove(key);
        pPrev = pHead;
        
    };

    size_t size() const {   
        return List<T>::size();
    };

    virtual void RemoveFirst() {           
        List<T>::RemoveFirst();
        pPrev = pHead;
        
    }


    bool operator==(const HeadList<T>& s) const {   
        return List<T>::operator==(List<T>(s.pFirst));     
    }



    bool operator!=(const List<T>& s) const { 
        return !(*this == s);
    }
};