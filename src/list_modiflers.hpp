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

        this->size_l++;

        iterator res;

        res = buf;

        //  std::cout << " INSERT\n " << std::endl;

        return res;
    }

    template<class T>
    typename list<T>::iterator list<T>::insert(list<T>::const_iterator pos, size_t count, const T& value) {
        for (size_t i = 0; i < count; i++) {
            //  std::cout << i + 1 << " iter\n " << std::endl;
            insert(pos, value);
            pos--;
        }

        iterator res;

        res = pos.cur;

        return res;
    }

    template<class T>
    typename list<T>::iterator list<T>::erase(list<T>::const_iterator pos) {

        node* to_del = pos.cur;

        //  std::cout << to_del->value << " to_del\n " << std::endl;
        //  std::cout << to_del->prev->value << " to_del-prev\n " << std::endl;
        //  std::cout << to_del->next->value << " to_del-next\n " << std::endl;

        to_del->next->prev = to_del->prev;
        to_del->prev->next = to_del->next;

        delete to_del;

        this->size_l--;

        iterator res;
        pos++;
        res = pos.cur;

        return res;

    }

    template<class T>
    typename list<T>::iterator list<T>::erase(list<T>::const_iterator first, list<T>::const_iterator last) {
        const_iterator iter = first;
        const_iterator tmp = iter;

        while (iter != last) {
            tmp++;
            erase(iter);
            iter = tmp;
        }

        iterator res;
        res = last.cur;

        return res;
    }

}  // namespace task

