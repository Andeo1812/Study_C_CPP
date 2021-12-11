#pragma once // NOLINT

#include <iterator>

#include <include/list.hpp>

namespace task {
    template<class T>
    typename list<T>::iterator list<T>::begin() const {
        iterator res;
        res = first->next;
        return res;
    }

    template<class T>
    typename list<T>::iterator list<T>::end() const {
        iterator res;
        res = last;
        return res;
    }

    template<class T>
    typename list<T>::const_iterator list<T>::cbegin() const {
        const_iterator res;
        res = first->next;
        return res;
    }

    template<class T>
    typename list<T>::const_iterator list<T>::cend() const {
        const_iterator res;
        res = last;
        return res;
    }

    template<class T>
    typename list<T>::reverse_iterator list<T>::rbegin() const {
        return reverse_iterator(end());
    }

    template<class T>
    typename list<T>::reverse_iterator list<T>::rend() const {
        return reverse_iterator(begin());
    }

    template<class T>
    typename list<T>::const_reverse_iterator list<T>::crbegin() const {
        return const_reverse_iterator(cend());
    }

    template<class T>
    typename list<T>::const_reverse_iterator list<T>::crend() const {
        return const_reverse_iterator(cbegin());
    }

}  // namespace task
