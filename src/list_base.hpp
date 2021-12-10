#pragma once // NOLINT

#include <iostream>

#include <include/list.hpp>

namespace task {
    template<class T>
    list<T>::list() {
        first = new node;
        last = new node;
        node* cap = new node;

        first->next = last;
        first->prev = NULL;

        last->next = cap;
        last->prev = first;

        cap->next = NULL;
        cap->prev = last;

        size_l = 0;
    }

    template<class T>
    list<T>::list(size_t count, const T& value) : list() {
        //  std::cout << size() << std::endl;
        for (size_t i = 0; i < count; i++) {
            push_back(value);
            //  std::cout << " +\n " << std::endl;
        }
        //  std::cout << size() << " \n " << std::endl;
    }

    template<class T>
    list<T>::list(size_t count) : list() {
        for (size_t i = 0; i < count; i++) {
            push_back(T{});
        }
    }

    template<class T>
    list<T>::~list() {
        node* tmp;
        this->size_l = 0;
        while (first != NULL) {
            tmp = first;
            first = first->next;
            delete tmp;
        }
    }

    template<class T>
    list<T>::list(const list &other) {
       this->first = other.first;
       this->last = other.last;
       this->size_l = other.size_l;
    }

    template<class T>
    typename list<T>::list& list<T>::operator=(const list& other) {
        this->first = other.first;
        this->last = other.last;
        this->size_l = other.size_l;
        return *this;
    }

}  // namespace task

