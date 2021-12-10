#pragma once // NOLINT

#include <iostream>

#include <include/list.hpp>


namespace task {
    template<class T>
    void list<T>::push_back(const T& value) {
        node* to_add = new node;

        to_add->value = value;

        to_add->next = last;
        to_add->prev = last->prev;

        last->prev->next = to_add;
        last->prev = to_add;

        size_l++;

        //  std::cout << last->prev->value << " PUSH_BACK\n " << std::endl;
    }

    template<class T>
    void list<T>::pop_back() {
        if (size_l == 0) {
            return;
        }

        node* to_del = last->prev;

        last->prev = to_del->prev;
        to_del->prev->next = last;

        delete to_del;

        size_l--;

        //std::cout << last->prev->value << " POP_BACK\n " << std::endl;
    }

    template<class T>
    void list<T>::push_front(const T& value) {
        node* to_add = new node;

        to_add->value = value;

        to_add->next = first->next;
        to_add->prev = first;

        first->next->prev = to_add;
        first->next = to_add;

        size_l++;

        //std::cout << first->next->value << " PUSH_FRONT\n " << std::endl;
    }

    template<class T>
    void list<T>::pop_front() {
        if (size_l == 0) {
            return;
        }

        node* to_del = first->next;

        first->next = to_del->next;
        to_del->next->prev = first;

        delete to_del;

        size_l--;

        //std::cout << first->next->value << " POP_FRONT\n " << std::endl;
    }

    template<class T>
    void list<T>::swap(list& other) {

    }

}  // namespace task
