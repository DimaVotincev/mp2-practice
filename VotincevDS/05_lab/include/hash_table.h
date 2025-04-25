#pragma once
#include "table.h"
#include <string>
#include <functional>

template <typename Tkey, typename Tdata>
class HashTable : public Table<Tkey,Tdata> {
protected:
    int hashfunc(const Tkey key);
    // or unsigned int or size_t ?
    using Table::currpos;
public:
    HashTable(int maxsize);
};

template <typename Tkey, typename Tdata>
HashTable<Tkey, Tdata>::HashTable(int maxsize) : Table<Tkey,Tdata>(maxsize)  {
       
}


template <typename Tkey, typename Tdata>
int HashTable<Tkey, Tdata>::hashfunc(const Tkey key) {
    std::hash<Tkey> hasher;
    return hasher(key) % this->maxsz;
}

