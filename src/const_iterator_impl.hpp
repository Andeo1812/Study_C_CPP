#pragma once // NOLINT

#include <include/list.hpp>

namespace task {
    template<class T>
    list<T>::const_iterator::const_iterator() : cur{} {}

    template<class T>
    list<T>::const_iterator::const_iterator(const list<T>::const_iterator& it) {
        cur = it.cur;
    }

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
    typename list<T>::const_iterator& list<T>::const_iterator::operator=(const list<T>::const_iterator& it) {
        cur = it.cur;
        return *this;
    }

    template<class T>
    typename list<T>::const_iterator& list<T>::const_iterator::operator++() {  //  справа
        if ((this->cur != NULL) && (this->cur->next != 0))
            cur = cur->next;
        return *this;
    }

    template<class T>
    typename list<T>::const_iterator list<T>::const_iterator::operator++(int) {  //  слева
        const_iterator tmp = *this;
        if ((this->cur != NULL) && (this->cur->next != 0))
            cur = cur->next;
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
        if ((this->cur != NULL) && (this->cur->prev != 0))
            cur = cur->prev;
        return *this;
    }

    template<class T>
    typename list<T>::const_iterator list<T>::const_iterator::operator--(int) {
        const_iterator tmp = *this;
        if ((this->cur != NULL) && (this->cur->prev != 0))
            cur = cur->prev;
        return tmp;
    }

    template<class T>
    bool list<T>::const_iterator::operator==(list<T>::const_iterator other) const {
        return (this->cur == other.cur);
    }

    template<class T>
    bool list<T>::const_iterator::operator!=(list<T>::const_iterator other) const {
        return !(this->cur == other.cur);
    }

    template<class T>
    list<T>::const_iterator::const_iterator(const iterator &it) {
        cur = it.cur;
    }

}  // namespace task

