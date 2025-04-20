#pragma once
#include "table.h"

template <typename Tkey, typename Tdata>
class HashTable : public Table<Tkey,Tdata> {
protected:
    int hashfunc(const Tkey key) { return key % this->maxsz; }
    // or unsigned int
public:
    HashTable(int maxsize);
};

template <typename Tkey, typename Tdata>
HashTable<Tkey, Tdata>::HashTable(int maxsize) : Table<Tkey,Tdata>(maxsize)  {

}
