#pragma once // NOLINT

#include <include/list.hpp>

namespace task {
    template<class T>
    typename list<T>::iterator list<T>::begin() const {
        iterator res
        res(first->next);
        return res;
    }

    template<class T>
    typename list<T>::iterator list<T>::end() const {
        iterator res;
        res(last->prev);
        return res;
    }

    template<class T>
    typename list<T>::const_iterator list<T>::cbegin() const {
        return nullptr;
    }

    template<class T>
    typename list<T>::const_iterator list<T>::cend() const {
        return nullptr;
    }

    template<class T>
    typename list<T>::reverse_iterator list<T>::rbegin() const {
        return nullptr;
    }

    template<class T>
    typename list<T>::reverse_iterator list<T>::rend() const {
        return nullptr;
    }

    template<class T>
    typename list<T>::const_reverse_iterator list<T>::crbegin() const {
        return nullptr;
    }

    template<class T>
    typename list<T>::const_reverse_iterator list<T>::crend() const {
        return nullptr;
    }

}  // namespace task
