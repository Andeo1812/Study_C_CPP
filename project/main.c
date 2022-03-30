#include <stdio.h>
#include <stdlib.h>

#include "load_database.h"

#define NEEDED_COUNT_ARG 2

#define ERR_INPUT -1
#define ERR_WRONG_TYPE_WORK -2
#define ERR_LOAD_DATA -3

#define IMPERATIVE_MODEL 1
#define MULTI_THREADED_MODEL 2

#define SUCCESS 1

int main(int argc, const char **argv) {
    if (argc < NEEDED_COUNT_ARG) {
        fprintf(stderr, "incorrect input\n");
        return ERR_INPUT;
    }

    char* end = NULL;
    long type_work = strtol(argv[1], &end, 0);
    if (*end != '\0') {
        fprintf(stdout, "incorrect input type work\n");
        return ERR_INPUT;
    }

    size_t number_records = 0;
    record_t **set_record = NULL;

    if (input(argv[2], &set_record, &number_records) < 0) {
        fprintf(stdout, "error load_data\n");
        return ERR_LOAD_DATA;
    }

    print_set_record(set_record, number_records);

    free_set_record(set_record, number_records);

    /*switch (type_work) {
        case IMPERATIVE_MODEL: {
            break;
        }
        case MULTI_THREADED_MODEL: {
            break;
        }
        default: {
            fprintf(stderr, "incorrect input type work: not such type");
            return ERR_WRONG_TYPE_WORK;
        }
    }*/

    return SUCCESS;
}
