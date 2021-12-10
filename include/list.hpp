#pragma once // NOLINT

#include <iterator>


namespace task {
template<class T>
class list {
    struct node {
        T value;
        struct node *prev, *next;
    };
public:
    class iterator {
    public:
        node *cur;

        using difference_type = ptrdiff_t;
        using value_type = T;
        using pointer = T*;
        using reference = T&;
        using iterator_category = std::bidirectional_iterator_tag;

        iterator();
        iterator(const iterator& it);
        iterator& operator=(const iterator& it);

        iterator(node* it);

        node* getPtr();

        iterator& operator++();
        iterator operator++(int);
        reference operator*() const;
        pointer operator->() const;
        iterator& operator--();
        iterator operator--(int);

        bool operator==(iterator other) const;
        bool operator!=(iterator other) const;
    };


    class const_iterator {
    public:
        node *cur;

        using difference_type = ptrdiff_t;
        using value_type = T;
        using pointer = const T*;
        using reference = const T&;
        using iterator_category = std::bidirectional_iterator_tag;

        const_iterator();
        const_iterator(const const_iterator& it);
        const_iterator& operator=(const const_iterator& it);

        const_iterator(const iterator &it);

        const_iterator& operator=(node* it);

        node* getPtr();

        const_iterator& operator++();
        const_iterator operator++(int);
        reference operator*() const;
        pointer operator->() const;
        const_iterator& operator--();
        const_iterator operator--(int);

        bool operator==(const_iterator other) const;
        bool operator!=(const_iterator other) const;
    };

    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;


    list();
    list(size_t count, const T& value);
    explicit list(size_t count);
    ~list();

    list(const list& other);
    list& operator=(const list& other);

    T& front();
    const T& front() const;

    T& back();
    const T& back() const;


    iterator begin() const;
    iterator end() const;

    const_iterator cbegin() const;
    const_iterator cend() const;

    reverse_iterator rbegin() const;
    reverse_iterator rend() const;

    const_reverse_iterator crbegin() const;
    const_reverse_iterator crend() const;


    bool empty() const;
    size_t size() const;
    size_t max_size() const;

    void clear();

    iterator insert(const_iterator pos, const T& value);
    iterator insert(const_iterator pos, size_t count, const T& value);

    iterator erase(const_iterator pos);
    iterator erase(const_iterator first, const_iterator last);


    void push_back(const T& value);
    void pop_back();

    void push_front(const T& value);
    void pop_front();

    void resize(size_t count);
    void swap(list& other);

    void merge(list& other);
    void splice(const_iterator pos, list& other);
    void remove(const T& value);
    void reverse();
    void unique();
    void sort();
private:
    size_t size_l;

    node *first;
    node *last;
};

}  // namespace task

#include <src/iterator_impl.hpp>
#include <src/const_iterator_impl.hpp>
#include <src/list_base.hpp>
#include <src/list_access.hpp>
#include <src/list_capacity.hpp>
#include <src/list_iterators.hpp>
#include <src/list_modiflers.hpp>
#include <src/list_modiflers_pop_push.hpp>
//#include <src/list_operations.hpp>*/
