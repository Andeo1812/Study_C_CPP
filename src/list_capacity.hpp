#pragma once // NOLINT

#include <limits>
#include <iostream>

#include <include/list.hpp>

namespace task {
    template<class T>
    bool list<T>::empty() const {
        if (!size()) {
            return true;
        }
        return false;
    }

    template<class T>
    size_t list<T>::size() const {
        return size_l;
    }

    template<class T>
    size_t list<T>::max_size() const {
        return std::numeric_limits<size_t>::max();
    }

    template<class T>
    void list<T>::clear() {
        node* tmp = first->next;

        while (first->next != last) {
            first = tmp->next;
            delete tmp;
        }

        size_l = 0;
    }

    template<class T>
    void list<T>::resize(size_t count) {
        if (count > size()) {
            for (size_t i = 0; i < (count - size()); i++) {
                push_back(T{});
                i--;
            }
        } else if (count < size()) {
            for (size_t i = 0; i < (size() - count); i++) {
                pop_back();
                i--;
            }
        }
    }

}  // namespace task
