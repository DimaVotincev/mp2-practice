#pragma once
#include <iostream>

using namespace std;

template <typename T>
struct ListNode {
    /*T val;
    int degree;
    ListNode* next;
    ListNode() : val(0),degree(-1) next(nullptr) {}
    ListNode(const T& x) : val(x),degree(-1), next(nullptr) {}*/

    T val;  
    ListNode* next;
    ListNode() : val(T()), next(nullptr) {}
    ListNode(const T& x) : val(T(x)), next(nullptr) {}
    ListNode(const T& x, ListNode* _next) : val(T(x)), next(_next) {}

};


template<typename T>
class List
{
private:
   
    ListNode<T>* searchLast() const { //!! TODO: remove
        if (pFirst == nullptr) {
            return nullptr;
        }

        ListNode<T>* curr = pFirst;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        return curr;
    };
    // переместил в private , а не убрал
    // тк удобно в местах ставить навигацию: pLast = searchLast
    // без этой функции везде, где нужно искать pLast,
    // придется вставлять цикл, код будет больше



protected:
    ListNode<T>* pFirst;
    ListNode<T>* pCurr;
    ListNode<T>* pPrev;
    ListNode<T>* pLast;
    ListNode<T>* pStop;
public:

    //List() {                // ++
    //    pFirst = nullptr;
    //    pCurr = pFirst;
    //    pPrev = nullptr;
    //    pLast = nullptr;
    //    pStop = nullptr;
    //}



    //List(const T& x) {               // ++
    //    pFirst = new ListNode<T>(x);
    //    pCurr = pFirst;
    //    pPrev = nullptr;
    //    pLast = pFirst;
    //    pStop = nullptr;
    //}



    //List(const List<T>& list) : List() {     // ++
    //    // если пустой список
    //    if (list.pFirst == nullptr) {
    //        return;
    //    }

    //    pFirst = new ListNode<T>(list.pFirst->val);
    //    pCurr = pFirst;  
    //    pStop = nullptr;
    //    pPrev = pStop;
    //    // обхожу входной лист
    //    ListNode<T>* curr = list.pFirst->next;

    //    // если входной лист имел 1 элемент
    //    if (curr == pStop) {
    //        pLast = pFirst;
    //        return;
    //    }

    //    // если входной лист имеет более 1 элемента
    //    while (curr != list.pStop) {
    //        pCurr->next = new ListNode<T>(curr->val);
    //        pPrev = pCurr;
    //        pCurr = pCurr->next;
    //        curr = curr->next;
    //    }
    //    pPrev->next = pCurr;
    //    pLast = pCurr;
    //    pCurr = pFirst;
    //    pPrev = pStop;
    //}

    //List(const ListNode<T>* node) : List() {        // ++
    //    // если поступил пустой node
    //    if (node == nullptr) {
    //        return;
    //    }

    //    // если не путой node, определяю
    //    // pFirst значением корня
    //    pFirst = new ListNode<T>(node->val);
    //    pCurr = pFirst;       

    //    // обхожу поэлементно, заполняя список
    //    ListNode<T>* curr = node->next;

    //    // второе условие нужно для ringlist
    //    // (без этого условия не будет работать ringlist!!)
    //    while (curr != pStop && curr->next != node) {
    //        pCurr->next = new ListNode<T>(curr->val);
    //        pPrev = pCurr;
    //        pCurr = pCurr->next;
    //        curr = curr->next;
    //    }
    //    if (pPrev) {
    //        pPrev->next = pCurr;
    //    }
    //    
    //    pLast = pCurr;
    //    reset_pCurr();
    //}



    //~List() {       // ++
    //    if (pFirst == nullptr) {
    //        return;
    //    }
    //    
    //    pPrev = pFirst;
    //    pCurr = pPrev->next;

    //    while (pCurr != pStop) {
    //        delete pPrev;
    //        pPrev = pCurr;
    //        pCurr = pCurr->next;
    //    }
    //    delete pPrev;

    //    pFirst = nullptr;
    //    pCurr = nullptr;
    //    pPrev = nullptr;
    //    pLast = nullptr;
    //}






    //List<T>& operator=(const List <T>& list) {            // ++
    //    // присваивание самому себе
    //    if (this == &list)
    //    {
    //        return *this;
    //    }

    //    // присваивание пустому списку
    //    if (list.pFirst == nullptr)
    //    {
    //        pFirst = nullptr;
    //        return *this;
    //    }

    //    // если не путой список, определяю
    //    // pFirst значением корня 
    //    pFirst = new ListNode<T>(list.pFirst->val);
    //    pCurr = pFirst;

    //    // обхожу все элементы входного списка
    //    // и заполняю наш список его значениями
    //    ListNode<T>* curr = list.pFirst->next;        
    //    while (curr != nullptr)
    //    {
    //        pCurr->next = new ListNode<T>(curr->val);
    //        pCurr = pCurr->next;
    //        curr = curr->next;
    //    }
    //    pLast = pCurr;
    //    reset_pCurr();

    //    return *this;
    //}


    //// !! TODO (я не понял это туду но наверное этот метод не нужен)
    //void reset_pCurr() {            // ++
    //    // сбрасывает pCurr по умолчанию
    //    // (соответственно и pPrev)
    //    pCurr = pFirst;
    //    pPrev = pStop;
    //}



    //T get_val() const {                // ++
    //    // возвращает значение корня
    //    return pFirst->val;
    //}


    //
    //// используется в лист стеке
    //ListNode<T>* get_head() const {       
    //    return pFirst;
    //}


    //
    //






    //// --------------------------------------------------------
    ////      если метод search будет const  тогда:
    //// вызовем для списка  1 2 3 4 5 и найдем элемент 3
    //// pCurr будет на 3
    //// а теперь вызовем ещё раз и попробуем найти 1
    //// но pCurr теперь находится на 3 ,он не может быть сброшен
    ////      если метод search оставить const  тогда:
    //// нельзя использовать pCurr    
    //// --------------------------------------------------------
    //ListNode<T>* search(T key)  {   //  ++
    //    // обхожу исходный список поэлементно
    //    // и сравниваю ключи с входным ключом

    //    pCurr = pFirst;
    //    pPrev = pStop;
    //    
    //    while (pCurr != pStop) {
    //        if (pCurr->val == key) {
    //            return pCurr;
    //        }
    //        pPrev = pCurr;
    //        pCurr = pCurr->next;
    //    }

    //    // не нашелся ключ
    //    if (pCurr == pStop) {
    //        throw "this element does not exist";
    //    }
    //    return pCurr;
    //};

    //

    //void push(const T& key) {    // ++
    //    //   добавляет элемент с заданным значением
    //    //   в начало списка
    //    ListNode<T>* tmp = new ListNode<T>(key);
    //    pushFront(tmp);
    //}


    //// лучше сделать так, чтобы он добавлял
    //// не только 1 звено,а как в pushBack
    //virtual void pushFront(ListNode<T>* node) {   // ++

    //    if(node == nullptr) {
    //        throw "cant push null node in front";
    //    }


    //    if (pFirst == nullptr) {
    //        pFirst = node;
    //        pCurr = pFirst;
    //        pPrev = pStop;
    //        pLast = searchLast(); // !! TODO: remove searchlast
    //        return;
    //    }
    //    
    //    node->next = pFirst;
    //    pFirst = node;
    //    pCurr = pFirst;
    //    pPrev = pStop;
    //};

   
    //
    //
    //virtual void pushBack(ListNode<T>* node) {  // ++

    //    // добавление пустого в конец не меняет список
    //    if (node == nullptr) {
    //        return;
    //    }
    //    
    //    // если изначально лист пустой
    //    if (pFirst == nullptr) {        // !! TODO: pushFront
    //        this->pushFront(node);
    //        return;
    //    }

    //    pLast->next = node;
    //    pLast = pLast->next;
    //};



    //virtual void InsertAfter(ListNode<T>* node, T key) {             // ++
    //    // ищу ключ с заданным значением 
    //    ListNode<T>* pCurr = search(key); // !! pCurr
    //    // если ключа нет,то search бросает исключение

    //    if (node->next != nullptr) {
    //        throw "InsertAfter can push only 1 node";
    //    }

    //    // вставляю node после звена с ключом key
    //    node->next = pCurr->next;

    //    // изменяю значение pLast, если происходит pushBack
    //    if (pCurr->next == pStop) {
    //        pLast = node;
    //    }

    //    pCurr->next = node;

    //   
    //};

    //virtual void InsertBefore(ListNode<T>* node, T key) {       // ++

    //    // ищу элемент с заданным ключом и элемент перед ним
    //    ListNode<T>* prev = pStop,*curr = pFirst; // !! TODO: search
    //    while (curr != pStop && curr->val != key) {
    //        prev = curr;
    //        curr = curr->next;
    //    }

    //    // проверяю существование ключа
    //    if (curr == pStop) {
    //        throw "this key does not exist";
    //    }

    //    if (node->next != nullptr) {
    //        throw "InsertBefore can push only 1 node";
    //    }

    //    // если первый элемент оказался нужного ключа
    //    // то вызывается pushFront
    //    if (curr == pFirst) {
    //        pushFront(node);
    //        return;
    //    }

    //    // вставляю node до звена curr, имеющего ключ key
    //    // и соединяю prev с этим node
    //    node->next = curr;
    //    prev->next = node;
    //};



    //virtual void remove(T key) {                 // ++
    //    // нахожу звено со значением key
    //    // и предыдущее звено
    //    ListNode<T>* prev = pStop, * curr = pFirst;
    //    while (curr != pStop && curr->val != key) { // !! TODO: search
    //        prev = curr;
    //        curr = curr->next;
    //    }

    //    // не нашелся элемент с ключом key
    //    if (curr == pStop) {
    //        throw "this key doesnt exist";
    //    }

    //    // звено с ключом key первое
    //    if (prev == pStop) { // !! RemoveFirst
    //        ListNode<T>* tmp = pFirst;
    //        pFirst = pFirst->next;
    //        pCurr = pFirst;
    //        delete tmp;          
    //        return;
    //    }

    //    // звено с ключом key последнее
    //    if (curr->next == pStop) {
    //        pLast = prev;
    //    }

    //    prev->next = curr->next;
    //    delete curr;      
    //};



    //size_t size() const {        // ++
    //    ListNode<T>* curr = pFirst;
    //    size_t size = 0;
    //    while (curr != pStop) {
    //        size++;
    //        curr = curr->next;
    //    }
    //    return size;
    //};


    //
    //virtual void RemoveFirst() {           // ++
    //    
    //    if (pFirst == nullptr) {
    //        throw "removing element from empty list";
    //    }

    //    ListNode<T>* tmp = pFirst;

    //    if (pCurr == pFirst) {        
    //        pFirst = pFirst->next;
    //        pCurr = pFirst;
    //    }
    //    else {
    //        pFirst = pFirst->next;
    //    }
    //    
    //    delete tmp;
    //}



    //bool operator==(const List<T>& s) const {      // ++

    //    ListNode<T>* curr1 = pFirst, *curr2 = s.pFirst;
    //    while (curr1 != pStop && curr2 != s.pStop) {
    //        if (curr1->val != curr2->val) {
    //            return 0;
    //        }
    //        curr1 = curr1->next;
    //        curr2 = curr2->next;
    //    }
    //    if (curr1 == pStop && curr2 == s.pStop) {
    //        return 1;
    //    }
    //    return 0;
    //}



    //bool operator!=(const List<T>& s) const {     // ++
    //    return !(*this == s);
    //}

    List();
    List(const T& x);
    List(const List<T>& list);
    List(const ListNode<T>* node);
    ~List();

    List<T>& operator=(const List <T>& list);

    void reset_pCurr();
    T get_val() const;
    ListNode<T>* get_head() const;
    ListNode<T>* search(T key);

    void push(const T& key);
    virtual void pushFront(ListNode<T>* node);
    virtual void pushBack(ListNode<T>* node);
    virtual void InsertAfter(ListNode<T>* node, T key);
    virtual void InsertBefore(ListNode<T>* node, T key);
    virtual void remove(T key);
    virtual void RemoveFirst();

    size_t size() const;

    bool operator==(const List<T>& s) const;
    bool operator!=(const List<T>& s) const;


};




template <typename T>
List<T>::List() {                // ++
    pFirst = nullptr;
    pCurr = pFirst;
    pPrev = nullptr;
    pLast = nullptr;
    pStop = nullptr;
}



template <typename T>
List<T>::List(const T& x) {               // ++
    pFirst = new ListNode<T>(x);
    pCurr = pFirst;
    pPrev = nullptr;
    pLast = pFirst;
    pStop = nullptr;
}



template <typename T>
List<T>::List(const List<T>& list) : List() {     // ++
    // если пустой список
    if (list.pFirst == nullptr) {
        return;
    }

    pFirst = new ListNode<T>(list.pFirst->val);
    pCurr = pFirst;
    pStop = nullptr;
    pPrev = pStop;
    // обхожу входной лист
    ListNode<T>* curr = list.pFirst->next;

    // если входной лист имел 1 элемент
    if (curr == pStop) {
        pLast = pFirst;
        return;
    }

    // если входной лист имеет более 1 элемента
    while (curr != list.pStop) {
        pCurr->next = new ListNode<T>(curr->val);
        pPrev = pCurr;
        pCurr = pCurr->next;
        curr = curr->next;
    }
    pPrev->next = pCurr;
    pLast = pCurr;
    pCurr = pFirst;
    pPrev = pStop;
}

template <typename T>
List<T>::List(const ListNode<T>* node) : List() {        // ++
    // если поступил пустой node
    if (node == nullptr) {
        return;
    }

    // если не путой node, определяю
    // pFirst значением корня
    pFirst = new ListNode<T>(node->val);
    pCurr = pFirst;

    // обхожу поэлементно, заполняя список
    ListNode<T>* curr = node->next;

    // второе условие нужно для ringlist
    // (без этого условия не будет работать ringlist!!)
    while (curr != pStop && curr->next != node) {
        pCurr->next = new ListNode<T>(curr->val);
        pPrev = pCurr;
        pCurr = pCurr->next;
        curr = curr->next;
    }
    if (pPrev) {
        pPrev->next = pCurr;
    }

    pLast = pCurr;
    reset_pCurr();
}



template <typename T>
List<T>::~List() {       // ++
    if (pFirst == nullptr) {
        return;
    }

    pPrev = pFirst;
    pCurr = pPrev->next;

    while (pCurr != pStop) {
        delete pPrev;
        pPrev = pCurr;
        pCurr = pCurr->next;
    }
    delete pPrev;

    pFirst = nullptr;
    pCurr = nullptr;
    pPrev = nullptr;
    pLast = nullptr;
}





template <typename T>
List<T>& List<T>::operator=(const List <T>&list) {            // ++
    // присваивание самому себе
    if (this == &list)
    {
        return *this;
    }

    // присваивание пустому списку
    if (list.pFirst == nullptr)
    {
        pFirst = nullptr;
        return *this;
    }

    // если не путой список, определяю
    // pFirst значением корня 
    pFirst = new ListNode<T>(list.pFirst->val);
    pCurr = pFirst;

    // обхожу все элементы входного списка
    // и заполняю наш список его значениями
    ListNode<T>* curr = list.pFirst->next;
    while (curr != nullptr)
    {
        pCurr->next = new ListNode<T>(curr->val);
        pCurr = pCurr->next;
        curr = curr->next;
    }
    pLast = pCurr;
    reset_pCurr();

    return *this;
}


// !! TODO (я не понял это туду но наверное этот метод не нужен)
template <typename T>
void List<T>::reset_pCurr() {            // ++
    // сбрасывает pCurr по умолчанию
    // (соответственно и pPrev)
    pCurr = pFirst;
    pPrev = pStop;
}


template <typename T>
T List<T>::get_val() const {                // ++
    // возвращает значение корня
    return pFirst->val;
}



// используется в лист стеке
template <typename T>
ListNode<T>* List<T>::get_head() const {
    return pFirst;
}










// --------------------------------------------------------
//      если метод search будет const  тогда:
// вызовем для списка  1 2 3 4 5 и найдем элемент 3
// pCurr будет на 3
// а теперь вызовем ещё раз и попробуем найти 1
// но pCurr теперь находится на 3 ,он не может быть сброшен
//      если метод search оставить const  тогда:
// нельзя использовать pCurr    
// --------------------------------------------------------

template <typename T>
ListNode<T>* List<T>::search(T key) {   //  ++
    // обхожу исходный список поэлементно
    // и сравниваю ключи с входным ключом

    pCurr = pFirst;
    pPrev = pStop;

    while (pCurr != pStop && pCurr != nullptr ) {
        if (pCurr->val == key) {
            return pCurr;
        }
        pPrev = pCurr;
        pCurr = pCurr->next;
    }

    // не нашелся ключ
    if (pCurr == pStop || pCurr == nullptr) {
        return pStop;
        //throw "this element does not exist";
    }

    return pCurr;
};


template <typename T>
void List<T>::push(const T& key) {    // ++
    //   добавляет элемент с заданным значением
    //   в начало списка
    ListNode<T>* tmp = new ListNode<T>(key);
    pushFront(tmp);
}


template <typename T>
void List<T>::pushFront(ListNode<T>* node) {   // ++

    if (node == nullptr) {
        throw "cant push null node in front";
    }


    if (pFirst == nullptr) {
        pFirst = node;
        pCurr = pFirst;
        pPrev = pStop;
        pLast = searchLast(); // !! TODO: remove searchlast
        return;
    }

    node->next = pFirst;
    pFirst = node;
    pCurr = pFirst;
    pPrev = pStop;
};



template <typename T>
void List<T>::pushBack(ListNode<T>* node) {  // ++

    // добавление пустого в конец не меняет список
    if (node == nullptr) {
        return;
    }

    // если изначально лист пустой
    if (pFirst == nullptr) {        // !! TODO: pushFront
        this->pushFront(node);
        return;
    }

    pLast->next = node;
    pLast = pLast->next;
};


template <typename T>
void List<T>::InsertAfter(ListNode<T>* node, T key) {             // ++
    // ищу ключ с заданным значением 
    search(key); // !! pCurr
    // если ключа нет,то search бросает исключение

    if (node->next != nullptr) {
        throw "InsertAfter can push only 1 node";
    }

    if (pCurr == pStop) {
        throw "cant push not existing elem";
    }

    // вставляю node после звена с ключом key
    node->next = pCurr->next;

    // изменяю значение pLast, если происходит pushBack
    if (pCurr->next == pStop) {
        pLast = node;
    }

    pCurr->next = node;


};

template <typename T>
void List<T>::InsertBefore(ListNode<T>* node, T key) {       // ++

    // ищу элемент с заданным ключом и элемент перед ним
    ListNode<T>* prev = pStop, * curr = pFirst; // !! TODO: search
    while (curr != pStop && curr->val != key) {
        prev = curr;
        curr = curr->next;
    }

    // проверяю существование ключа
    if (curr == pStop) {
        throw "this key does not exist";
    }

    if (node->next != nullptr) {
        throw "InsertBefore can push only 1 node";
    }

    // если первый элемент оказался нужного ключа
    // то вызывается pushFront
    if (curr == pFirst) {
        pushFront(node);
        return;
    }

    // вставляю node до звена curr, имеющего ключ key
    // и соединяю prev с этим node
    node->next = curr;
    prev->next = node;
};


template <typename T>
void List<T>::remove(T key) {                 // ++
    // нахожу звено со значением key
    // и предыдущее звено
    ListNode<T>* prev = pStop, * curr = pFirst;
    while (curr != pStop && curr->val != key) { // !! TODO: search
        prev = curr;
        curr = curr->next;
    }

    // не нашелся элемент с ключом key
    if (curr == pStop) {
        throw "this key doesnt exist";
    }

    // звено с ключом key первое
    if (prev == pStop) { // !! RemoveFirst
        ListNode<T>* tmp = pFirst;
        pFirst = pFirst->next;
        pCurr = pFirst;
        delete tmp;
        return;
    }

    // звено с ключом key последнее
    if (curr->next == pStop) {
        pLast = prev;
    }

    prev->next = curr->next;
    delete curr;
};


template <typename T>
size_t List<T>::size() const {        // ++
    ListNode<T>* curr = pFirst;
    size_t size = 0;
    while (curr != pStop) {
        size++;
        curr = curr->next;
    }
    return size;
};


template <typename T>
void List<T>::RemoveFirst() {           // ++

    if (pFirst == nullptr) {
        throw "removing element from empty list";
    }

    ListNode<T>* tmp = pFirst;

    if (pCurr == pFirst) {
        pFirst = pFirst->next;
        pCurr = pFirst;
    }
    else {
        pFirst = pFirst->next;
    }

    delete tmp;
}


template <typename T>
bool List<T>::operator==(const List<T>& s) const {      // ++

    ListNode<T>* curr1 = pFirst, * curr2 = s.pFirst;
    while (curr1 != pStop && curr2 != s.pStop) {
        if (curr1->val != curr2->val) {
            return 0;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    if (curr1 == pStop && curr2 == s.pStop) {
        return 1;
    }
    return 0;
}


template <typename T>
bool List<T>::operator!=(const List<T>& s) const {     // ++
    return !(*this == s);
}