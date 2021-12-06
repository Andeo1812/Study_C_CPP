#include <include/list.hpp>

namespace task {
    template<class T>
    void list<T>::clear() {

    }

    template<class T>
    typename list<T>::iterator list<T>::insert(const_iterator pos, const T& value) {
        return NULL;
    }

    template<class T>
    typename list<T>::iterator list<T>::insert(const_iterator pos, size_t count, const T& value) {
        return NULL;
    }

    template<class T>
    typename list<T>::iterator list<T>::erase(const_iterator pos) {
        return 0;
    }

    template<class T>
    typename list<T>::iterator list<T>::erase(const_iterator first, const_iterator last) {
        return 0;
    }

}  // namespace task

