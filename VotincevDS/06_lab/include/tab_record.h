#pragma once
#include <iostream>






template <typename Tkey, typename Tdata>
class TabRecord {
private:
    Tkey key;
    Tdata* data;
public:
    TabRecord(Tkey _key, Tdata* _data) : key(_key), data(_data) {};
    TabRecord(const TabRecord<Tkey,Tdata>& tr);
    Tkey get_key() { return key; }
    Tdata* get_data() { return data; }

};

template <typename Tkey, typename Tdata>
TabRecord<Tkey, Tdata>::TabRecord(const TabRecord<Tkey, Tdata>& tr) {
    key = tr.key;
    data = tr.data;
}



