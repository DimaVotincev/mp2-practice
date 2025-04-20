#pragma once

#include "table.h"

template <typename Tkey, typename Tdata>
class ScanTable : public Table<Tkey,Tdata> {
protected:
    TabRecord<Tkey, Tdata>** recs; 
public:
    ScanTable(int maxsize);
    ScanTable(const ScanTable<Tkey, Tdata>& st);
    ~ScanTable();
    virtual TabRecord<Tkey, Tdata>* Find(Tkey key);
    virtual void Insert(TabRecord<Tkey, Tdata>* tr);
    virtual void Remove(Tkey key);
    virtual TabRecord<Tkey, Tdata>* GetCurr() const;
};


template <typename Tkey, typename Tdata>
ScanTable<Tkey, Tdata>::ScanTable(int msz) : Table<Tkey,Tdata>(msz) {
    recs = new TabRecord<Tkey,Tdata>*[msz];
    for (int i = 0; i < msz; i++) {
        recs[i] = nullptr;
    }
}


template <typename Tkey, typename Tdata>
ScanTable<Tkey, Tdata>::ScanTable(const ScanTable<Tkey, Tdata>& st)
    : ScanTable(st.maxsz) {
    this->count = st.count;
    for (int i = 0; i < this->count; i++) {
        this->recs[i] = new TabRecord<Tkey, Tdata>(st.recs[i]->get_key(),
            st.recs[i]->get_data());
    }
}

template <typename Tkey, typename Tdata>
ScanTable<Tkey, Tdata>::~ScanTable() {
    for (int i = 0; i < this->count; i++) {
        delete this->recs[i];
    }
    delete[] recs;
}


template <typename Tkey, typename Tdata>
TabRecord<Tkey, Tdata>* ScanTable<Tkey, Tdata>::Find(Tkey k) { // ++
    TabRecord<Tkey,Tdata>* answ = nullptr;
    for (int i = 0; i < this->count; i++) {
        if (recs[i]->get_key() == k) {
            answ = recs[i];
            currpos = i;
            return answ;
        }
    }
    return answ; 
}




template <typename Tkey, typename Tdata>
void ScanTable<Tkey, Tdata>::Remove(Tkey key) { // ++
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
void ScanTable<Tkey, Tdata>::Insert(TabRecord<Tkey, Tdata>* tr) {  // ++
    if (IsFull()) {
        throw "table is full";   
    }
    if (Find(tr->get_key()) != nullptr) {
        throw "this key already exists";
    }
    recs[this->count] = tr;
    this->count++;
}





template <typename Tkey, typename Tdata>
TabRecord<Tkey, Tdata>* ScanTable<Tkey, Tdata>::GetCurr() const {
    return recs[currpos];
}



