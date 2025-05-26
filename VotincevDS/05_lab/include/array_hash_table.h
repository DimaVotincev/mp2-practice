#pragma once
#include "hash_table.h"
#include <iostream>
template <typename Tkey, typename Tdata>
class ArrayHashTable : public HashTable<Tkey,Tdata> {
private:
    TabRecord<Tkey, Tdata>** recs;
    TabRecord<Tkey, Tdata>* pMark = 
        new TabRecord<Tkey, Tdata>(Tkey(), nullptr);   // удаленна€ запись
    int hashstep; // параметр p
    int hashfunc2(int pos) { return (pos + hashstep) % maxsz; } 
public:
    ArrayHashTable(int maxsize,int hashstep); 
    ArrayHashTable(const ArrayHashTable<Tkey,Tdata>& ht);
    ~ArrayHashTable();
    TabRecord<Tkey, Tdata>* Find(Tkey key);
    TabRecord<Tkey, Tdata>*  GetCurr() const;
    void Insert(TabRecord<Tkey,Tdata>* tr);
    void Remove(Tkey key);
    void Next();
    bool IsTabEnded() const;
    bool Reset();
};

//bool Reset();
//void Next();



// ++
template <typename Tkey, typename Tdata>
ArrayHashTable<Tkey,Tdata>::ArrayHashTable(int maxsize, int _hashstep) 
    : HashTable<Tkey,Tdata>(maxsize), hashstep(_hashstep) {
    recs = new TabRecord<Tkey, Tdata>* [maxsize];
    for (int i = 0; i < maxsize; i++) {
        recs[i] = nullptr;
    }
}

// ++
template <typename Tkey, typename Tdata>
ArrayHashTable<Tkey, Tdata>::ArrayHashTable
            (const ArrayHashTable<Tkey, Tdata>& ht) 
            : ArrayHashTable(ht.maxsz,ht.hashstep) { 
    this->count = ht.count;
    for (int i = 0; i < this->maxsz; i++) {
        /*if (ht.recs[i] == nullptr) { continue; }
        Tkey k = ht.recs[i]->get_key();
        this->recs[i] = new TabRecord<Tkey, Tdata>(k,
            ht.recs[i]->get_data());*/

        if (ht.recs[i] == nullptr) { continue; }
        if (ht.recs[i] == ht.pMark) {
            this->recs[i] = this->pMark;
            continue;
        }
        Tkey k = ht.recs[i]->get_key();
        this->recs[i] = new TabRecord<Tkey, Tdata>(k,
            ht.recs[i]->get_data());

    }
}


// ++
template <typename Tkey, typename Tdata>
ArrayHashTable<Tkey, Tdata>::~ArrayHashTable() {
    /*for (int i = 0; i < this->count; i++) {
        if (recs[i] == pMark) {
            continue;
        }
        delete this->recs[i];
    }
    delete[] recs;
    delete pMark;*/

    for (int i = 0; i < this->count; i++) {
        if (recs[i] == nullptr || recs[i] == pMark) {
            continue;
        }
        delete this->recs[i];
    }
    delete[] recs;
    delete pMark;

}


template <typename Tkey, typename Tdata>
TabRecord<Tkey, Tdata>* ArrayHashTable<Tkey, Tdata>::Find(Tkey key) {
    TabRecord<Tkey, Tdata>* answ = nullptr;
    
    currpos = hashfunc(key);
    for (int i = 0; i < this->maxsz; i++) {
        if (recs[currpos] == nullptr) { // пуста€ €чейка
            break;
        }
        else if (this->recs[currpos]->get_key() == key) { // нашли ключ
            answ = recs[currpos];
            break;
        }
        else if (this->recs[currpos] == pMark) { // €чейка удалена
            currpos = hashfunc2(currpos);
            continue;
        }
        else if (recs[currpos] != nullptr) { // в €чейке другой ключ
            currpos = hashfunc2(currpos);
            continue;
        }
    }
    
    return answ;
}

template <typename Tkey, typename Tdata>
TabRecord<Tkey, Tdata>* ArrayHashTable<Tkey, Tdata>::GetCurr() const {
    return recs[currpos];
}

template <typename Tkey, typename Tdata>
void ArrayHashTable<Tkey, Tdata>::Insert(TabRecord<Tkey, Tdata>* tr) {
    if (this->IsFull()) {
        throw "hashtable is full";
    }

    if (Find(tr->get_key()) != nullptr) {
        throw "item with this key already exists";
    }
    this->count++;
    currpos = hashfunc(tr->get_key());
    //for (int i = 0; i < this->maxsz; i++) {
    //    if (recs[currpos] == nullptr) { // пуста€ €чейка
    //        recs[currpos] = tr;
    //        return;
    //    }
    //    else if (this->recs[currpos] == pMark) { // €чейка удалена
    //        this->recs[currpos] = tr;
    //        return;
    //    }
    //    else if (recs[currpos] != nullptr) { // зан€та
    //        currpos = hashfunc2(currpos);
    //        continue;
    //    }
    //}

    for (int i = 0; i < this->maxsz; i++) {
        if (recs[currpos] == nullptr || this->recs[currpos] == pMark) {
            recs[currpos] = tr;
            break;
        }
        currpos = hashfunc2(currpos);
    }
    

}

template <typename Tkey, typename Tdata>
void ArrayHashTable<Tkey, Tdata>::Remove(Tkey key) {
    TabRecord<Tkey, Tdata>* todel = Find(key);
    if (todel == nullptr) {
        throw "record with this key does not exist";
    }
    delete todel;
    this->recs[currpos] = this->pMark;
    this->count--;
}



template <typename Tkey, typename Tdata>
void ArrayHashTable<Tkey, Tdata>::Next() {
    currpos++;

    /*if (currpos == -1) {
        currpos = 0;
    }*/
    while (currpos != this->maxsz && (recs[currpos] == nullptr ||
        recs[currpos]->get_key() == this->pMark->get_key())) {
        currpos++;
    }

}


template <typename Tkey, typename Tdata>
bool ArrayHashTable<Tkey, Tdata>::Reset() {
    this->currpos = -1;
    this->Next();
    return 0;
}


template <typename Tkey, typename Tdata>
bool ArrayHashTable<Tkey, Tdata>::IsTabEnded() const {
    if (currpos == -1) {
        return 1;
    }
    return currpos == maxsz;
    // было maxsz , теперь count
    // count - логичен дл€ scan sort
    // maxsz - логичен дл€ hashtable (разрозненно хран€тс€)
    // отсюда вывод: надо переопредел€ть
    // а иначе никак
}















// не хочет линковатьс€

//friend std::ostream& operator<<(std::ostream&, ArrayHashTable<Tkey,Tdata>&);

//template <typename Tkey, typename Tdata>
//std::ostream& operator<<(std::ostream& out, ArrayHashTable<Tkey,Tdata>& ht) {
//    int i = 1;
//    while (!ht.IsTabEnded()) {
//        if (ht.GetCurr() == nullptr || ht.GetCurr() != ht.pMark) {
//            ht.Next();
//        }
//        out << i << ": " << ht.GetCurr()->get_key() << '\n';
//        i++;
//        ht.Next();
//    }
//    return out;
//}


