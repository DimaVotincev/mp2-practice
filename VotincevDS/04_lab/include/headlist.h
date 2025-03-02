#pragma once
#include "list.h"

template <typename T>
class HeadList : public List<T> {
protected:
    ListNode<T>* pHead;

public:

    

    /*HeadList() : List() {
        pHead = new ListNode<T>(T(), pFirst); 
        pPrev = pHead;
    }


    HeadList(const T& x) : List(x) {
        pHead = new ListNode<T>(T(), pFirst);
        pPrev = pHead;
    }


    HeadList(const List<T>& list) : List(list) {   
        pHead = new ListNode<T>(T(),pFirst);       
        pPrev = pHead;
    }

    HeadList(const HeadList<T>& list) : List(list.pFirst) {    
        pHead = new ListNode<T>(T(),pFirst);        
        pPrev = pHead;
    }

    HeadList(const ListNode<T>& node) : List(node) {
        pHead = new ListNode<T>(T(),pFirst);        
        pPrev = pHead;
    }


    ~HeadList() {
        delete pHead;
    }



    ListNode<T>* get_pHead() const { return pHead; }


    HeadList<T>& operator=(const HeadList <T>& list) {
        List<T>::operator=(list.pFirst);
        pHead = new ListNode<T>(T(),pFirst);       
        pPrev = pHead;
        return *this;
    }


    virtual void pushFront(ListNode<T>* node) {
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

    virtual void InsertAfter(ListNode<T>* node, T key) {
        List<T>::InsertAfter(node, key);
        if (pFirst == node)
        {
            pPrev = pHead;

        }
    };

    virtual void InsertBefore(ListNode<T>* node, T key) { 
        List<T>::InsertBefore(node, key);
        if (pFirst == node)
        {
            pPrev = pHead;
            
        }
    };


    virtual void remove(T key) {
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
    }*/

    

    HeadList();
    HeadList(const T& x);
    HeadList(const List<T>& list);
    HeadList(const HeadList<T>& list);
    HeadList(const ListNode<T>& node);
    ~HeadList();

    HeadList<T>& operator=(const HeadList <T>& list);

    ListNode<T>* get_pHead() const;

    virtual void pushFront(ListNode<T>* node);
    virtual void pushBack(ListNode<T>* node);
    virtual void InsertAfter(ListNode<T>* node, T key);
    virtual void InsertBefore(ListNode<T>* node, T key);
    virtual void remove(T key);
    virtual void RemoveFirst();


    size_t size() const;

    bool operator==(const HeadList<T>& s) const;
    bool operator!=(const List<T>& s) const;

};





template <typename T>
HeadList<T>::HeadList() : List() {
    pHead = new ListNode<T>(T(), pFirst);
    pPrev = pHead;
}


template <typename T>
HeadList<T>::HeadList(const T& x) : List(x) {
    pHead = new ListNode<T>(T(), pFirst);
    pPrev = pHead;
}


template <typename T>
HeadList<T>::HeadList(const List<T>& list) : List(list) {
    pHead = new ListNode<T>(T(), pFirst);
    pPrev = pHead;
}


template <typename T>
HeadList<T>::HeadList(const HeadList<T>& list) : List(list.pFirst) {
    pHead = new ListNode<T>(T(), pFirst);
    pPrev = pHead;
}


template <typename T>
HeadList<T>::HeadList(const ListNode<T>& node) : List(node) {
    pHead = new ListNode<T>(T(), pFirst);
    pPrev = pHead;
}


template <typename T>
HeadList<T>::~HeadList() {
    delete pHead;
}


template <typename T>
ListNode<T>* HeadList<T>::get_pHead() const { return pHead; }

template <typename T>
HeadList<T>& HeadList<T>::operator=(const HeadList <T>& list) {
    List<T>::operator=(list.pFirst);
    pHead = new ListNode<T>(T(), pFirst);
    pPrev = pHead;
    return *this;
}


template <typename T>
void HeadList<T>::pushFront(ListNode<T>* node) {
    List<T>::pushFront(node);
    pPrev = pHead;
    pHead->next = node;
    return;
};


template <typename T>
void HeadList<T>::pushBack(ListNode<T>* node) {
    List<T>::pushBack(node);
    if (pFirst == node)
    {
        pPrev = pHead;

    }
    return;
};


template <typename T>
void HeadList<T>::InsertAfter(ListNode<T>* node, T key) {
    List<T>::InsertAfter(node, key);
    if (pFirst == node)
    {
        pPrev = pHead;

    }
};

template <typename T>
void HeadList<T>::InsertBefore(ListNode<T>* node, T key) {
    List<T>::InsertBefore(node, key);
    if (pFirst == node)
    {
        pPrev = pHead;

    }
};


template <typename T>
void HeadList<T>::remove(T key) {
    List<T>::remove(key);
    pPrev = pHead;

};


template <typename T>
size_t HeadList<T>::size() const {
    return List<T>::size();
};


template <typename T>
void HeadList<T>::RemoveFirst() {
    List<T>::RemoveFirst();
    pPrev = pHead;

}


template <typename T>
bool HeadList<T>::operator==(const HeadList<T>& s) const {
    return List<T>::operator==(List<T>(s.pFirst));
}


template <typename T>
bool HeadList<T>::operator!=(const List<T>& s) const {
    return !(*this == s);
}