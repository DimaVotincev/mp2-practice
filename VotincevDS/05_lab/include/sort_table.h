#pragma once
#include "scan_table.h"

#include <algorithm>

template <typename Tkey, typename Tdata>
class SortedTable : public ScanTable<Tkey,Tdata> {
protected:
    void sort();
public:
    
    SortedTable(int maxsize);
    SortedTable(const SortedTable<Tkey,Tdata>& st);
    // SortedTable(const ScanTable<Tkey, Tdata>& sct); // как писать это чудо?
    TabRecord<Tkey, Tdata>* Find(Tkey key);
    void Remove(Tkey key);
    void Insert(TabRecord<Tkey, Tdata>* tr);
};

template <typename Tkey, typename Tdata>
void SortedTable<Tkey, Tdata>::sort() {
    //sort(recs[0],recs[this->maxsz-1]);
}

template <typename Tkey, typename Tdata>
SortedTable<Tkey, Tdata>::SortedTable(int maxsize) 
            : ScanTable<Tkey,Tdata>(maxsize) {          //++
    
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


// как писать это  чудо?
//template <typename Tkey, typename Tdata>
//SortedTable<Tkey, Tdata>::SortedTable(const ScanTable<Tkey, Tdata>& sct) {
//
//    sct.Next();
//}




template <typename Tkey, typename Tdata>
TabRecord<Tkey, Tdata>* SortedTable<Tkey, Tdata>::Find(Tkey key) {
    TabRecord<Tkey, Tdata>* answ = nullptr;
    int l = 0, r = this->count - 1;
    while (l <= r) {
        int c = l + (r-l)/2;
        if (this->recs[c]->get_key() == key) {
            answ = recs[c];
            break;
        }
        else if (recs[c]->get_key() < key) {
            l = c+1;
        }
        else {
            r = c - 1;
        }
    }
    currpos = r;
    return answ;
}

template <typename Tkey, typename Tdata>
void SortedTable<Tkey, Tdata>::Remove(Tkey key) {
    TabRecord<Tkey, Tdata>* todel = Find(key);
    if (todel == nullptr) {
        throw "record with this key does not exist";
    }
    delete todel;
    for (int i = currpos + 1; i < this->count; i++) {
        recs[i - 1] = recs[i];
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

    for (int i = currpos+1; i < this->count; i++) {
        recs[i+1] = recs[i];
    }
    recs[currpos+1] = tr;
    this->count++;
}