#include <include/list.hpp>

namespace task {
    template<class T>
    list<T>::iterator::iterator() {
        cur->next = NULL;
        cur->prev = NULL;
    }

    template<class T>
    list<T>::iterator::iterator(const iterator&) {
        cur->next = this.cur->next;
        cur->prev = this.cur->prev;
        cur->value = this.cur->value;
    }

    template<class T>
    typename list<T>::iterator& list<T>::iterator::operator=(const iterator&) {
        cur->next = this.cur->next;
        cur->prev = this.cur->prev;
        cur->value = this.cur->value;
        return *this;
    }

    template<class T>
    typename list<T>::iterator& list<T>::iterator::operator++() {
        cur = cur->next;
        return &this;
    }

    template<class T>
    typename list<T>::iterator list<T>::iterator::operator++(int) {
        cur++;
        return *this;
    }

    template<class T>
    typename list<T>::iterator::reference list<T>::iterator::operator*() const {
        return &(cur->value);
    }

    template<class T>
    typename list<T>::iterator::pointer list<T>::iterator::operator->() const {
        return *(cur->value);
    }

    template<class T>
    typename list<T>::iterator& list<T>::iterator::operator--() {
        cur = cur->prev;
        return &this;
    }

    template<class T>
    typename list<T>::iterator list<T>::iterator::operator--(int) {
        cur--;
        return *this;
    }

    template<class T>
    bool list<T>::iterator::operator==(iterator other) const {
        return (*this == other);
    }

    template<class T>
    bool list<T>::iterator::operator!=(iterator other) const {
        return !(*this == other);
    }


}  // namespace task
