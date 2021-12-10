#pragma once // NOLINT

#include <include/list.hpp>

namespace task {
    template<class T>
    list<T>::const_iterator::const_iterator() = default;

    template<class T>
    list<T>::const_iterator::const_iterator(const const_iterator& it) = default;

    template<class T>
    typename list<T>::const_iterator& list<T>::const_iterator::operator=(const const_iterator& it) {
        cur = it.cur;
        return *this;
    }

    template<class T>
    list<T>::const_iterator::const_iterator(const iterator &it): cur(it.cur) {}

    template<class T>
    typename list<T>::node* list<T>::const_iterator::getPtr() {
        return cur;
    }

    template<class T>
    typename list<T>::const_iterator& list<T>::const_iterator::operator=(node* it) {
        cur = it;
        return *this;
    }


    template<class T>
    typename list<T>::const_iterator& list<T>::const_iterator::operator++() {  //  справа
        this->cur = cur->next;
        return *this;
    }

    template<class T>
    typename list<T>::const_iterator list<T>::const_iterator::operator++(int) {  //  слева
        const_iterator tmp = *this;
        this->cur++;
        return tmp;
    }

    template<class T>
    typename list<T>::const_iterator::reference list<T>::const_iterator::operator*() const {
        return cur->value;
    }

    template<class T>
    typename list<T>::const_iterator::pointer list<T>::const_iterator::operator->() const {
        return &cur->value;
    }

    template<class T>
    typename list<T>::const_iterator& list<T>::const_iterator::operator--() {
        this->cur = cur->prev;
        return *this;
    }

    template<class T>
    typename list<T>::const_iterator list<T>::const_iterator::operator--(int) {
        const_iterator tmp = *this;
        this->cur--;
        return tmp;
    }

    template<class T>
    bool list<T>::const_iterator::operator==(const_iterator other) const {
        return *this == other;
    }

    template<class T>
    bool list<T>::const_iterator::operator!=(const_iterator other) const {
        return *this != other;
    }

}  // namespace task

