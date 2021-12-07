#include <include/list.hpp>

namespace task {
    template<class T>
    list<T>::iterator::iterator() {
        node *tmp = nullptr;
        return *this;
    }

    template<class T>
    list<T>::iterator::iterator(const iterator&) {
        iterator tmp;
        return *this;
    }

    template<class T>
    typename list<T>::iterator& list<T>::iterator::operator=(const iterator&) {

    }

    template<class T>
    typename list<T>::iterator& list<T>::iterator::operator++() {
        cur = cur->next;
        return *this;
    }

    template<class T>
    typename list<T>::iterator list<T>::iterator::operator++(int) {
        iterator tmp = cur;
        ++cur;
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
        cur = cur->prev;
        return *this;
    }

    template<class T>
    typename list<T>::iterator list<T>::iterator::operator--(int) {
        iterator tmp = cur;
        --cur;
        return tmp;
    }

    template<class T>
    bool list<T>::iterator::operator==(iterator other) const {
        return (*this == other);
    }

    template<class T>
    bool list<T>::iterator::operator!=(iterator other) const {
        return *this != other;
    }

}  // namespace task
