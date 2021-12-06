#include <include/list.hpp>

namespace task {
    template<class T>
    bool list<T>::empty() const {
        return false;
    }

    template<class T>
    size_t list<T>::size() const {
        return 0;
    }

    template<class T>
    size_t list<T>::max_size() const {
        return 0;
    }

}  // namespace task

