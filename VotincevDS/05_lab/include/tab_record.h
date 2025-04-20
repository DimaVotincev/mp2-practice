#pragma once
#include <iostream>

template <typename Tkey, typename Tdata>
class TabRecord {
private:
    Tkey key;
    Tdata* data;
public:
    TabRecord(Tkey _key, Tdata* _data) : key(_key), data(_data) {};
    Tkey get_key() { return key; }
    Tdata* get_data() { return data; }
};
