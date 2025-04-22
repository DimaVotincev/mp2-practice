#pragma once
#include "scan_table.h"

#include <algorithm>

template <typename Tkey, typename Tdata>
class SortedTable : public ScanTable<Tkey,Tdata> {
protected:
    void sort(); //++
public:
    SortedTable(int maxsize); //++
    SortedTable(const SortedTable<Tkey,Tdata>& st); //++
    SortedTable(const ScanTable<Tkey, Tdata>& sct);  //++
    TabRecord<Tkey, Tdata>* Find(Tkey key);  //++
    void Remove(Tkey key); //++
    void Insert(TabRecord<Tkey, Tdata>* tr); //++
};

template <typename Tkey, typename Tdata>
void SortedTable<Tkey, Tdata>::sort() {
    std::sort(this->recs, this->recs + this->count, 
        [](TabRecord<Tkey, Tdata>* a, TabRecord<Tkey, Tdata>* b) {
        return a->get_key() < b->get_key();
    });
}

template <typename Tkey, typename Tdata>
SortedTable<Tkey, Tdata>::SortedTable(int maxsize) 
            : ScanTable<Tkey,Tdata>(maxsize) {
    for (int i = 0; i < maxsize; i++) {
        recs[i] = nullptr;
    }
}

template <typename Tkey, typename Tdata>
SortedTable<Tkey, Tdata>::SortedTable(const SortedTable<Tkey, Tdata>& st)
        : SortedTable(st.maxsz) {
    this->count = st.count;
    for (int i = 0; i < this->count;i++ ) {
        this->recs[i] = new TabRecord<Tkey, Tdata>(st.recs[i]->get_key(),
            st.recs[i]->get_data());
    }
}



template <typename Tkey, typename Tdata>
SortedTable<Tkey, Tdata>::SortedTable(const ScanTable<Tkey, Tdata>& sct) 
    : ScanTable<Tkey, Tdata>(sct) {
    this->sort();
}



template <typename Tkey, typename Tdata>
TabRecord<Tkey, Tdata>* SortedTable<Tkey, Tdata>::Find(Tkey key) {
    TabRecord<Tkey, Tdata>* answ = nullptr;
    int l = 0, r = this->count - 1;
    while (l <= r) {
        int c = l + (r-l)/2;
        if (this->recs[c]->get_key() == key) {
            answ = recs[c];
            currpos = c;
            return answ;
        }
        else if (recs[c]->get_key() < key) {
            l = c+1;
        }
        else {
            r = c - 1;
        }
    }
    currpos = r; // встаю до места, куда нужно вставить
    return answ;
}

template <typename Tkey, typename Tdata>
void SortedTable<Tkey, Tdata>::Remove(Tkey key) {
    TabRecord<Tkey, Tdata>* todel = Find(key);
    if (todel == nullptr) {
        throw "record with this key does not exist";
    }
    delete todel;
    for (int i = currpos; i < this->count; i++) {
        recs[i] = recs[i+1];
    }
    this->count--;
}

template <typename Tkey, typename Tdata>
void SortedTable<Tkey, Tdata>::Insert(TabRecord<Tkey, Tdata>* tr) {
    if (count == 0) {
        this->recs[0] = tr;
        this->count++;
        return;
    }
    if (IsFull()) {
        throw "table is full";
    }
    if (Find(tr->get_key()) != nullptr) {
        throw "this key already exists";
    }
    if (currpos == this->count) {
        recs[this->count] = tr;
        this->count++;
        return;
    }
    this->count++;
    // смещаю все элементы вправо, освобождая место
    // для элемента, который вставляем
    for (int i = count - 1; i > currpos+1; i--) {
        recs[i] = recs[i - 1];
    }   
    // элемент нужно вставить на currpos+1
    recs[currpos+1] = tr;  
}