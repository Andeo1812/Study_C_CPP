#include <include/list.hpp>

namespace task {
    template<class T>
    list<T>::iterator::iterator() = default;

    template<class T>
    list<T>::iterator::iterator(const iterator& other) {
        this->cur = other.cur;
    }

    template<class T>
    typename list<T>::iterator& list<T>::iterator::operator=(const iterator& other) {
        this->cur = other.cur;
        return *this;
    }

    template<class T>
    typename list<T>::iterator& list<T>::iterator::operator++() {  //  справа
        this->cur = cur->next;
        return *this;
    }

    template<class T>
    typename list<T>::iterator list<T>::iterator::operator++(int) {  //  слева
        iterator tmp = cur;
        this->cur++;
        return tmp;
    }

    template<class T>
    typename list<T>::iterator::reference list<T>::iterator::operator*() {
        return cur->value;
    }

    template<class T>
    typename list<T>::iterator::pointer list<T>::iterator::operator->() {
        return &cur->value;
    }

    template<class T>
    typename list<T>::iterator& list<T>::iterator::operator--() {
        this->cur = cur->prev;
        return *this;
    }

    template<class T>
    typename list<T>::iterator list<T>::iterator::operator--(int) {
        iterator tmp = cur;
        this->cur--;
        return tmp;
    }

    template<class T>
    bool list<T>::iterator::operator==(iterator other) const {
        return *this == other;
    }

    template<class T>
    bool list<T>::iterator::operator!=(iterator other) const {
        return *this != other;
    }

}  // namespace task
