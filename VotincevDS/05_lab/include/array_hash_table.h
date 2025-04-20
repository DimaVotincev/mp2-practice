#pragma once
#include "hash_table.h"

template <typename Tkey, typename Tdata>
class ArrayHashTable : public HashTable<Tkey,Tdata> {
private:
    TabRecord<Tkey, Tdata>** recs;
    TabRecord<Tkey, Tdata>* pMark = new TabRecord<Tkey, Tdata>(-1,nullptr);
    int freepos; // зачем это нужно???????????????????????????????
    int hashstep; // параметр p
    int get_next_pos(int pos) { return (pos + hashstep) % maxsz; }

public:
    ArrayHashTable(int maxsize,int hashstep); 
    ArrayHashTable(const ArrayHashTable<Tkey,Tdata>& ht);
    ~ArrayHashTable();
    TabRecord<Tkey, Tdata>* Find(Tkey key);
    TabRecord<Tkey, Tdata>*  GetCurr() const;
    void Insert(TabRecord<Tkey,Tdata>* tr);
    void Remove(Tkey key);

};

//bool Reset();
//void Next();

template <typename Tkey, typename Tdata>
ArrayHashTable<Tkey,Tdata>::ArrayHashTable(int maxsize, int _hashstep) 
    : HashTable<Tkey,Tdata>(maxsize) {
    recs = new TabRecord<Tkey, Tdata>* [maxsize];
    for (int i = 0; i < maxsize; i++) {
        recs[i] = nullptr;
    }
}

template <typename Tkey, typename Tdata>
ArrayHashTable<Tkey, Tdata>::ArrayHashTable(const ArrayHashTable<Tkey, Tdata>& ht) 
    : ArrayHashTable(ht.maxsz) {
    this->count = ht.count;
    for (int i = 0; i < this->count; i++) {
        this->recs[i] = new TabRecord<Tkey, Tdata>(ht.recs[i]->get_key(),
            ht.recs[i]->get_data());
    }
}

template <typename Tkey, typename Tdata>
ArrayHashTable<Tkey, Tdata>::~ArrayHashTable() {
    for (int i = 0; i < this->count; i++) {
        delete this->recs[i];
    }
    delete[] recs;
    delete pMark;
}




//в тетради про эту функцию какой-то бред
// мне надоело
template <typename Tkey, typename Tdata>
TabRecord<Tkey, Tdata>* ArrayHashTable<Tkey, Tdata>::Find(Tkey key) {
    TabRecord<Tkey, Tdata>* answ = nullptr;
    
    int currpos = hashfunc(key);
    if (recs[currpos] == nullptr) {
        return answ;
    } else if (this->recs[currpos]->get_key() == key) {
        answ = recs[currpos];
    }
    else if (this->recs[currpos] == pMark) {

    }


    return answ;
}

template <typename Tkey, typename Tdata>
TabRecord<Tkey, Tdata>* ArrayHashTable<Tkey, Tdata>::GetCurr() const {
    return recs[currpos];
}

template <typename Tkey, typename Tdata>
void ArrayHashTable<Tkey, Tdata>::Insert(TabRecord<Tkey, Tdata>* tr) {
    return;
}

template <typename Tkey, typename Tdata>
void ArrayHashTable<Tkey, Tdata>::Remove(Tkey key) {
    return;
}


