#pragma once
#include "table.h"
#include "binary_search_tree.h"
#include "tab_record.h"

template <typename Tkey, typename Tdata>
class BSTable : Table<Tkey,Tdata> {
private:
    BinarySearchTree<Tkey,TabRecord<Tkey,Tdata>*> bst;
public:
    BSTable(int maxsize);
    BSTable(const BSTable<Tkey, Tdata>& st);
    virtual TabRecord<Tkey, Tdata>* Find(Tkey key);
    virtual void Insert(TabRecord<Tkey, Tdata>* tr);
    virtual void Remove(Tkey key);
    virtual TabRecord<Tkey, Tdata>* GetCurr() const;
    void Next();
    bool Reset();
};

template <typename Tkey, typename Tdata>
BSTable<Tkey, Tdata>::BSTable(int msz) : Table<Tkey,Tdata>(msz) {
    
}


template <typename Tkey, typename Tdata>
BSTable<Tkey, Tdata>::BSTable(const BSTable<Tkey, Tdata>& st)
    : BSTable(st.maxsz),bst(st) {
    
}

template <typename Tkey, typename Tdata>
TabRecord<Tkey, Tdata>* BSTable<Tkey, Tdata>::Find(Tkey k) {
    return bst.Search(k)->data;
}




template <typename Tkey, typename Tdata>
void BSTable<Tkey, Tdata>::Remove(Tkey key) {
    bst.Remove(key);
    this->count--;
}


template <typename Tkey, typename Tdata>
void BSTable<Tkey, Tdata>::Insert(TabRecord<Tkey, Tdata>* tr) { 
    if (IsFull()) {
        throw "table is full";   
    }
    bst.Insert(tr);
    this->count++;
}





template <typename Tkey, typename Tdata>
TabRecord<Tkey, Tdata>* BSTable<Tkey, Tdata>::GetCurr() const {
    return bst.pCurr->data;
}




template <typename Tkey, typename Tdata>
void BSTable<Tkey, Tdata>::Next() {
    bst.SearchNext(bst.pCurr);
}


template <typename Tkey, typename Tdata>
bool BSTable<Tkey, Tdata>::Reset() {
    bst.SearchMin(bst.pRoot);
    return 0;
}

/*
*/
