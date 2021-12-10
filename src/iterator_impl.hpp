#pragma once // NOLINT

#include <include/list.hpp>

namespace task {
    template<class T>
    list<T>::iterator::iterator() : cur{} {}

    template<class T>
    list<T>::iterator::iterator(const list<T>::iterator& it) {
        cur = it.cur;
    }

    template<class T>
    typename list<T>::node* list<T>::iterator::getPtr() {
        return cur;
    }

    template<class T>
    typename list<T>::iterator& list<T>::iterator::operator=(node* it) {
        cur = it;
        cur->value = it->value;
        cur->next = it->next;
        cur->prev = it->prev;
        return *this;
    }

    template<class T>
    typename list<T>::iterator& list<T>::iterator::operator=(const list<T>::iterator& it) {
        cur = it.cur;
        return *this;
    }

    template<class T>
    typename list<T>::iterator& list<T>::iterator::operator++() {  //  справа
        if ((this->cur != NULL) && (this->cur->next != 0))
            cur = cur->next;
        return *this;
    }

    template<class T>
    typename list<T>::iterator list<T>::iterator::operator++(int) {  //  слева
        iterator tmp = *this;
        if ((this->cur != NULL) && (this->cur->next != 0))
            cur = cur->next;
        return tmp;
    }

    template<class T>
    typename list<T>::iterator::reference list<T>::iterator::operator*() const {
        return cur->value;
    }

    template<class T>
    typename list<T>::iterator::pointer list<T>::iterator::operator->() const {
        return &cur->value;
    }

    template<class T>
    typename list<T>::iterator& list<T>::iterator::operator--() {
        if ((this->cur != NULL) && (this->cur->prev != 0))
            cur = cur->prev;
        return *this;
    }

    template<class T>
    typename list<T>::iterator list<T>::iterator::operator--(int) {
        iterator tmp = *this;
        if ((this->cur != NULL) && (this->cur->prev != 0))
            cur = cur->prev;
        return tmp;
    }

    template<class T>
    bool list<T>::iterator::operator==(list<T>::iterator other) const {
        return (this->cur == other.cur);
    }

    template<class T>
    bool list<T>::iterator::operator!=(list<T>::iterator other) const {
        return !(this->cur == other.cur);
    }

}  // namespace task
