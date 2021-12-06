#include <include/list.hpp>

namespace task {
    template<class T>
    list<T>::iterator::iterator() {

    }

    template<class T>
    list<T>::iterator::iterator(const iterator&) {

    }

    template<class T>
    iterator& list<T>::iterator::operator=(const iterator&){

    }

    template<class T>
    iterator& list<T>::iterator::operator++() {

    }

    template<class T>
    iterator list<T>::iterator::operator++(int) {

    }

    template<class T>
    reference list<T>::iterator::operator*() const {

    }

    template<class T>
    pointer list<T>::iterator::operator->() const {

    }

    template<class T>
    iterator& list<T>::iterator::operator--() {

    }

    template<class T>
    iterator list<T>::iterator::operator--(int) {

    }

    template<class T>
    bool list<T>::iterator::operator==(iterator other) const {
        return false;
    }

    template<class T>
    bool list<T>::iterator::operator!=(iterator other) const {
        return false;
    }


}  // namespace task
