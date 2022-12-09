#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <tuple>

class Item {

    private:
        int _key, _val;

    public:
        Item() {}
        Item(int key, int val) : _key(key), _val(val) {}

        friend bool operator >(const Item& i1, const Item& i2) {
            return (std::tie(i1._key, i1._val) > std::tie(i2._key, i2._val));
        }

        friend std::ostream & operator << (std::ostream &out, const Item &i) {
            return out << "(" << i._key << "," << i._val << ")"; 
        }
};

#endif