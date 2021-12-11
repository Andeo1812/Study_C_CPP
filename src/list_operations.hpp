#pragma once // NOLINT

#include <algorithm>

#include <iostream>

#include <include/list.hpp>

namespace task {
    template<class T>
    void list<T>::swap_node(list<T>::const_iterator pos, list<T>::const_iterator target) {
        auto src = pos.cur;
        auto trg = target.cur;

        auto tmp = trg;

        trg->next->prev = src;
        trg->prev->next = src;

        trg->next = src->next;
        trg->prev = src->prev;

        src->next->prev = tmp;
        src->prev->next = tmp;

        src->next = tmp->next;
        src->prev = tmp->prev;
    }

    template<class T>
    void list<T>::move_node(list<T>::iterator pos, list<T>::iterator target) {
        auto src = pos.cur;
        auto trg = target.cur;

        auto tmp_s = src;

        src->next = trg;
        src->prev = trg->prev;

        trg->prev->next = src;
        trg->prev = src;

        tmp_s->prev->next = tmp_s->next;
        tmp_s->next->prev = tmp_s->prev;
    }


    template<class T>
    void list<T>::sort_interval(list<T>::iterator lft,
                                list<T>::iterator mid,
                                list<T>::iterator rht) {
        std::cout<< " THIS\n " << std::endl;
        if (lft == rht) {
            return;
        }

        iterator tmp_mid = mid++;
        iterator tmp_lft = lft;

        size_t size_interval = 0;
        while (lft != rht) {
            lft++;
            size_interval++;
        }

        lft = tmp_lft;

        while (size_interval > 0) {
            // std::cout << size_interval << " THIS\n " << std::endl;
            if (lft == mid) {
                tmp_mid = mid++;
                //  std::cout << " THIS-1\n " << std::endl;
                move_node(tmp_mid, lft);
            }

            if (*lft >= *tmp_mid) {
                //  std::cout << " THIS-2\n " << std::endl;
                move_node(tmp_mid, lft);
                tmp_mid++;
            } else {
                lft++;
            }
            size_interval--;
        }
        std::cout << " FATAL\n " << std::endl;
    }

    template<class T>
    void list<T>::merge(list& other) {
        const_iterator pos = cbegin();
        const_iterator pos_o = other.cbegin();

        size_t count_iter = other.size();

        while (count_iter) {
            if (*pos >= *pos_o) {
                insert(pos, *pos_o);

                pos_o++;
            } else {
                pos++;
            }

            if (pos == cend()) {
                push_back(*pos_o);
                pos_o++;
            }

            count_iter--;
        }
    }

    template<class T>
    void list<T>::splice(list<T>::const_iterator pos, list& other) {
        auto tmp = pos.cur;
        auto end_o = other.end().cur;
        auto begin_o = other.begin().cur;

        end_o->next = tmp;
        begin_o->prev = tmp->prev;

        tmp->prev->next = begin_o;
        tmp->prev = end_o;

        this->size_l += other.size();

        other.size_l = 0;
    }

    template<class T>
    void list<T>::remove(const T& value) {
        const_iterator iter = cbegin();
        const_iterator tmp = iter;

        while (iter != cend()) {
            if (*iter == value) {
                tmp++;
                erase(iter);
                iter = tmp;
            }
        }
    }

    template<class T>
    void list<T>::reverse() {
        //  begin() = rbegin();
        //  end() = rend();
    }

    template<class T>
    void list<T>::unique() {
        const_iterator pos = cbegin();
        const_iterator pos_next = cbegin()++;
        const_iterator tmp = pos;

        while (pos != cend()) {
            if (*pos == *pos_next) {
                tmp++;
                erase(pos);
                pos = tmp;
            }
        }
    }

    template<class T>
    void list<T>::sort() {
        iterator lft = std::next(begin(), 3);

        iterator mid = std::next(begin(), 6);

        iterator rht = std::next(begin(), 8);

        sort_interval(lft, mid, rht);
        /*for (size_t i = 1; i < size(); i *= 2) {
            for (size_t j = 0; j < size() - i; j += 2 * i) {
                iterator lft = std::next(cbegin(), j);

                iterator mid = std::next(cbegin(), j + i);

                iterator rht = std::next(cbegin(), std::min(j + 2 * i, size()));

                sort_interval(lft, mid, rht);
            }
        }*/
    }

}  // namespace task

