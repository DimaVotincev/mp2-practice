#pragma once
#include "tab_record.h"
template <typename Tkey, typename Tdata>
class Table {
protected:
    int maxsz; // макс кол-во записей
    int count; // текущее кол-во записей
    int currpos; // индекс текущей позиции в таблице
public:
    Table(int maxsize) : maxsz(maxsize), count(0), currpos(-1) {}
    virtual TabRecord<Tkey, Tdata>* Find(Tkey key) = 0;
    virtual void Insert(TabRecord<Tkey, Tdata>* tr) = 0;
    virtual void Remove(Tkey key) = 0;
    bool Reset();
    void Next();
    virtual TabRecord<Tkey, Tdata>* GetCurr() const = 0;
    bool IsTabEnded() { return currpos == maxsz-1; }
    bool IsEmpty() const { return count == 0; }
    bool IsFull() const { return count == maxsz; }
};

template <typename Tkey, typename Tdata>
bool Table<Tkey, Tdata>::Reset() {
    if (currpos == -1) {
        return 1;
    }
    currpos = 0;
    return 0;
}

template <typename Tkey, typename Tdata>
void Table<Tkey, Tdata>::Next() {
    if (IsFull()) {
        throw "end reached";
    }
    currpos++;
}