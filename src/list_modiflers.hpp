#pragma once // NOLINT

#include <iostream>

#include <include/list.hpp>

namespace task {
    template<class T>
    typename list<T>::iterator list<T>::insert(list<T>::const_iterator pos, const T& value) {
        auto buf = pos.cur;

        node* to_add = new node;

        to_add->value = value;

        to_add->next = buf;
        to_add->prev = buf->prev;

        buf->prev->next = to_add;
        buf->prev = to_add;

        size_l++;

        iterator res;

        res.cur = buf;

        //  std::cout << " INSERT\n " << std::endl;

        return res;
    }

    template<class T>
    typename list<T>::iterator list<T>::insert(list<T>::const_iterator pos, size_t count, const T& value) {
        for (size_t i = 0; i < count; i++) {
            std::cout << i + 1 << " iter\n " << std::endl;
            insert(pos, value);
            pos--;
        }

        iterator res;

        res.cur = pos.cur;

        return res;
    }

    /*template<class T>
    typename list<T>::iterator list<T>::erase(list<T>::const_iterator pos) {
        iterator tmp;
        return tmp;
    }

    template<class T>
    typename list<T>::iterator list<T>::erase(list<T>::const_iterator first, list<T>::const_iterator last) {
        iterator tmp;
        return tmp;
    }*/

}  // namespace task

