#pragma once // NOLINT

#include <iostream>

#include <include/list.hpp>

namespace task {
    template<class T>
    T& list<T>::front() {
        //  std::cout << first->next->value << " FRONT\n " << std::endl;
        return this->first->next->value;
    }

    template<class T>
    const T& list<T>::front() const {
        //  std::cout << first->next->value << " FRONT\n " << std::endl;
        return this->first->next->value;
    }

    template<class T>
    T& list<T>::back() {
        //  std::cout << last->prev->value << " BACK\n " << std::endl;
        return this->last->prev->value;
    }

    template<class T>
    const T& list<T>::back() const {
        //  std::cout << last->prev->value << " BACK\n " << std::endl;
        return this->last->prev->value;
    }

}  // namespace task

