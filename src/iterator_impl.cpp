#include <include/list.hpp>

namespace task {
    template<class T>
    list<T>::iterator::iterator() {
        it = NULL;
    }

    template<class T>
    list<T>::iterator::iterator(const iterator&) {
        *this = iterator;
    }

    template<class T>
    typename list<T>::iterator& list<T>::iterator::operator=(const iterator&) {
        return this = iterator;
    }

    template<class T>
    typename list<T>::iterator& list<T>::iterator::operator++() {
        return it->next;
    }

    template<class T>
    typename list<T>::iterator list<T>::iterator::operator++(int) {
        it++;
        return &it;
    }

    template<class T>
    typename list<T>::iterator::reference list<T>::iterator::operator*() const {
        return *it;
    }

    template<class T>
    typename list<T>::iterator::pointer list<T>::iterator::operator->() const {
        return *this;
    }

    template<class T>
    typename list<T>::iterator& list<T>::iterator::operator--() {
        return it->prev;
    }

    template<class T>
    typename list<T>::iterator list<T>::iterator::operator--(int) {
            it--;
        return &it;
    }

    template<class T>
    bool list<T>::iterator::operator==(iterator other) const {
        return *this == other;
    }

    template<class T>
    bool list<T>::iterator::operator!=(iterator other) const {
        return !(*this == other);
    }


}  // namespace task
