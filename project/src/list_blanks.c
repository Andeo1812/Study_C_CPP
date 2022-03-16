#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "list_blanks.h"
#include "utils.h"

list_blanks_t *create_list(size_t number, char *storage, char *responsible) {
    list_blanks_t *tmp_list = calloc(1, sizeof(list_blanks_t));
    ASSERT(tmp_list, "failed get memory");

    tmp_list->storage = storage;

    tmp_list->responsible = responsible;

    node_blank_t *tmp_blank = calloc(1, sizeof(node_blank_t));
    ASSERT(tmp_blank, "failed get memory");

    tmp_blank->number = number;

    tmp_list->first = tmp_blank;
    tmp_list->last = tmp_blank;

    return tmp_list;
}

void insert(list_blanks_t *target, size_t number) {
    if (target->first->number >= number) {
        target->first = push_front(target->first, number);
        return;
    }

    if (target->last->number <= number) {
        target->last = push_back(target->last, number);
        return;
    }

    node_blank_t *iterator = target->first->next;

    while (iterator != target->last) {
        if (number <= iterator->number) {
            insert_node(iterator, number);
        }
    }
}

void print_list(list_blanks_t *list_b) {
    fprintf(stdout, "%s %s\n", list_b->storage, list_b->responsible);

    node_blank_t *end_chain = print_numbers_chain(list_b->first);

    while (end_chain->next) {
        fprintf(stdout, "%s %s\n", list_b->storage, list_b->responsible);

        end_chain = print_numbers_chain(end_chain->next);
    }
}

void free_list_blank(list_blanks_t *list_b) {
    while (list_b->first != NULL) {
        node_blank_t* tmp = list_b->first;

        list_b->first = list_b->first->next;

        free(tmp);
    }

    free(list_b->storage);
    free(list_b->responsible);

    free(list_b);
}
