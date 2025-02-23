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
    ListNode(const T& x) : val(x), next(nullptr) {}

};


template<typename T>
class List
{
private:
    ListNode<T>* pFirst;
    ListNode<T>* pCurr;
    ListNode<T>* pPrev;
    ListNode<T>* pLast;
    ListNode<T>* pStop;
public:

    List() {                // ++
        pFirst = nullptr;
        pCurr = pFirst;
        pPrev = nullptr;
        pLast = nullptr;
        pStop = nullptr;
    }



    List(const T& x) {               // ++
        pFirst = new ListNode<T>(x);
        pCurr = pFirst;
        pPrev = nullptr;
        pLast = pFirst;
        pStop = nullptr;
    }



    List(const List<T>& list) : List() {     // ++
        // если пустой список
        if (list.pFirst == nullptr) {
            return;
        }

        // определяю значение pFirst как 1й элемент списка
        // и назначаю pCurr по умолчанию (на pFirst)
        pFirst = new ListNode<T>(list.pFirst->val);
        pCurr = pFirst;  

        // обхожу входной лист
        ListNode<T>* curr = list.pFirst->next;

        // если входной лист имел 1 элемент
        if (curr == nullptr) {
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

        // сбрасывается pCurr 
        // pCurr = pFirst;
        // pPrev = pStop; 
        reset_pCurr();


        //     это можно сделать здесь
        //     (тк до конструктора не мб изменен
        //     pCurr и pPrev , они оба nullptr)
        //  
        // 
        //    например, в методе search нельзя тк
        //    если раннее был изменен pCurr ,то он
        //    снова сбросится на начальный момент             
    }


    // & ??? 
    List(const ListNode<T>* node) : List() {        // ++
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
        pPrev->next = pCurr;
        pLast = pCurr;
        reset_pCurr();
    }



    ~List() {       // ++
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



    // ----------- пока не знаю



    ListNode<T>* get_pFirst() const { return pFirst; }
    void set_pFirst(ListNode<T>* node) { 
        pFirst = node; 
    }

    ListNode<T>* get_pCurr()  const  { return pCurr; }
    void set_pCurr(ListNode<T>* node) { 
        pCurr = node; 
    }

    ListNode<T>* get_pPrev() const { return pPrev; }
    void set_pPrev(ListNode<T>* node) { 
        pPrev = node; 
    }

    ListNode<T>* get_pLast() const { return pLast; }
    void set_pLast(ListNode<T>* node) { pLast = node; }

    ListNode<T>* get_pStop() const { return pStop; }
    void set_pStop(ListNode<T>* node) { pStop = node; }



    // ----------- пока не знаю




    List<T>& operator=(const List <T>& list) {            // ++
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



    void reset_pCurr() {            // ++
        // сбрасывает pCurr по умолчанию
        // (соответственно и pPrev)
        pCurr = pFirst;
        pPrev = pStop;
    }



    T get_val() const {                // ++
        // возвращает значение корня
        return pFirst->val;
    }


    
    // (он используется в листстеке,
    // просто нужно поменять в нем функцию и все)
    ListNode<T>* get_head() const {       //  ???????? уже есть get_pFirst()
        return pFirst;
    }


    // должен использовать pCurr , pPrev ?
    // если использует,то меняет значения
    // и если будет код с направленным изменением pCurr
    // то search изменит pCurr  
    // (возможно, изменение pCurr на прямую нужно запретить
    //  и тогда изменить search)
    ListNode<T>* search(T key) const {   //  ++
        // обхожу исходный список поэлементно
        // и сравниваю ключи с входным ключом
        ListNode<T>* curr = pFirst;
        while (curr != pStop) {
            if (curr->val == key) {
                return curr;
            }
            curr = curr->next;
        }

        // не нашелся ключ
        if (curr == pStop) {
            throw "this element does not exist";
        }
        return curr;
    };



    ListNode<T>* searchLast() const {   //++
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


    // лучше сделать так, чтобы он добавлял
    // не только 1 звено,а как в pushBack
    void pushFront(ListNode<T>* node) {   // ++

        if(node == nullptr) {
            throw "cant push null node in front";
        }


        if (pFirst == nullptr) {
            pFirst = node;
            pCurr = pFirst;
            pPrev = pStop;
            pLast = searchLast();
            return;
        }
        
        node->next = pFirst;
        pFirst = node;
        pCurr = pFirst;
        pPrev = pStop;
    };



    void pushBack(ListNode<T>* node) {  // ++

        // добавление пустого в конец не меняет список
        if (node == nullptr) {
            return;
        }
        
        if (pFirst == nullptr) {
            pFirst = node;
            pCurr = pFirst;
            pPrev = pStop;
            pLast = searchLast();
            return;
        }
        
        pLast->next = node;
        pLast = pLast->next;
        // pLast =  searchLast();   // возможно нужно это оставить

    };



    void InsertAfter(ListNode<T>* node, T key) {             // ++
        // ищу ключ с заданным значением 
        ListNode<T>* curr = search(key);
        // если ключа нет,то search бросает исключение

        if (node->next != nullptr) {
            throw "InsertAfter can push only 1 node";
        }

        // вставляю node после звена с ключом key
        node->next = curr->next;

        // изменяю значение pLast, если происходит pushBack
        if (curr->next == pStop) {
            pLast = node;
        }

        curr->next = node;

       
    };

    void InsertBefore(ListNode<T>* node, T key) {       // ++

        // ищу элемент с заданным ключом и элемент перед ним
        ListNode<T>* prev = pStop,*curr = pFirst;
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



    void remove(T key) {                 // ++
        // нахожу звено со значением key
        // и предыдущее звено
        ListNode<T>* prev = pStop, * curr = pFirst;
        while (curr != pStop && curr->val != key) {
            prev = curr;
            curr = curr->next;
        }

        // не нашелся элемент с ключом key
        if (curr == pStop) {
            throw "this key doesnt exist";
        }

        // звено с ключом key первое
        if (prev == pStop) {
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



    size_t size() const {        // ++
        ListNode<T>* curr = pFirst;
        size_t size = 0;
        while (curr != pStop) {
            size++;
            curr = curr->next;
        }
        return size;
    };



    void RemoveFirst() {           // ++
        
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



    bool operator==(const List<T>& s) const {      // ++

        ListNode<T>* curr1 = pFirst, *curr2 = s.pFirst;
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



    bool operator!=(const List<T>& s) const {     // ++
        return !(*this == s);
    }

};





