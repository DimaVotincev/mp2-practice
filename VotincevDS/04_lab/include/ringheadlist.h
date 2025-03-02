#pragma once
#include "headlist.h"


template <typename T>
class RingHeadList : public HeadList<T> {

public:

    /*RingHeadList() : HeadList() {     
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

    void pushBack(T obj) {
        ListNode<T>* node = new ListNode<T>(obj);
        RingHeadList<T>::pushBack(node);
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
    }*/

    // !!! TODO + имеем доступ к полям
    void make_circular() {
        pStop = pHead;
        if (pLast != nullptr) {
            pLast->next = pHead;
        }
        if (pHead->next == nullptr) {
            pHead->next = pHead;
        }
    }

    void remove_circular() {
        pStop = nullptr
            if (pLast != nullptr) {
                pLast->next = nullptr;
            }
    }


    RingHeadList();
    RingHeadList(const T& x);
    RingHeadList(const HeadList<T>& list);
    RingHeadList(const RingHeadList<T>& list);
    RingHeadList(const ListNode<T>* node);
    ~RingHeadList();

    RingHeadList<T>& operator=(const List <T>& list);
    RingHeadList<T>& operator=(const RingHeadList <T>& list);

    void pushFront(T obj);
    void pushFront(ListNode<T>* node); 
    void pushBack(T obj);
    void pushBack(ListNode<T>* node);
    void InsertAfter(ListNode<T>* node, T key);
    void InsertBefore(ListNode<T>* node, T key);
    void remove(T key);
    void RemoveFirst();

    size_t size() const;

    bool operator==(const RingHeadList<T>& s) const;
    bool operator!=(const HeadList<T>& s) const;
};



template <typename T>
RingHeadList<T>::RingHeadList() : HeadList() {
    make_circular();
}

template <typename T>
RingHeadList<T>::RingHeadList(const T& x) : HeadList(x) {
    make_circular();
}

template <typename T>
RingHeadList<T>::RingHeadList(const HeadList<T>& list) : HeadList(list) {
    make_circular();
}

template <typename T>
RingHeadList<T>::RingHeadList(const RingHeadList<T>& list) : HeadList(list.get_pHead()->next) {
    make_circular();
}


template <typename T>
RingHeadList<T>::RingHeadList(const ListNode<T>* node) : HeadList(node) {
    make_circular();
}

template <typename T>
RingHeadList<T>::~RingHeadList() {

}

template <typename T>
RingHeadList<T>& RingHeadList<T>::operator=(const List <T>& list) {
    HeadList<T>::operator=(list);
    make_circular();
    return *this;
}

template <typename T>
RingHeadList<T>& RingHeadList<T>::operator=(const RingHeadList <T>& list) {
    HeadList<T>::operator=(HeadList(list.get_pHead()->next));
    make_circular();
    return *this;
}

template <typename T>
void RingHeadList<T>::pushFront(T obj) {
    ListNode<T>* node = new ListNode<T>(obj);
    HeadList<T>::pushFront(node);
    make_circular();
};

template <typename T>
void RingHeadList<T>::pushFront(ListNode<T>* node) {
    HeadList<T>::pushFront(node);
    make_circular();
};

template <typename T>
void RingHeadList<T>::pushBack(T obj) {
    ListNode<T>* node = new ListNode<T>(obj);
    RingHeadList<T>::pushBack(node);
    make_circular();
};

template <typename T>
void RingHeadList<T>::pushBack(ListNode<T>* node) {
    HeadList<T>::pushBack(node);
    make_circular();
};

template <typename T>
void RingHeadList<T>::InsertAfter(ListNode<T>* node, T key) {
    HeadList<T>::InsertAfter(node, key);
    make_circular();
};



template <typename T>
void RingHeadList<T>::InsertBefore(ListNode<T>* node, T key) {
    HeadList<T>::InsertBefore(node, key);
    make_circular();
};

template <typename T>
void RingHeadList<T>::remove(T key) {
    HeadList<T>::remove(key);
    pLast->next = pHead;
    pHead->next = pFirst;
};

template <typename T>
size_t RingHeadList<T>::size() const {
    return HeadList<T>::size();
};

template <typename T>
void RingHeadList<T>::RemoveFirst() {
    HeadList<T>::RemoveFirst();
    pHead->next = get_pHead();
}


template <typename T>
bool RingHeadList<T>::operator==(const RingHeadList<T>& s) const {
    return HeadList<T>::operator==(HeadList<T>(s.get_pHead()->next));
}


template <typename T>
bool RingHeadList<T>::operator!=(const HeadList<T>& s) const {
    return !(*this == s);
}