#include <iostream>
#include <string>
#include <array>

#define SUCCESS 1
#define ERROR_INPUT -1

#define MAX_COUNT 9
#define MIN_COUNT 0

#define FATAL_LIMIT(MIN, MAX, message) {            \
    std::cerr << "Bad input: " << message <<        \
    " must be in interval: " << MIN << "-" << MAX << std::endl;   \
    exit(ERROR_INPUT);                               \
}

char ar_2[3] {'a', 'b', 'c'};
char ar_3[3] {'d', 'e', 'f'};

char ar_4[3] {'g', 'h', 'i'};
char ar_5[3] {'j', 'k', 'l'};
char ar_6[3] {'m', 'n', 'o'};

char ar_7[4] {'p', 'q', 'r', 's'};
char ar_8[3] {'t', 'u', 'v'};
char ar_9[4] {'w', 'x', 'y', 'z'};

std::array<char*, 8> map;

int main(void) {
    std::array<char*, 8> map;

    map[0] = ar_2;
    map[1] = ar_3;
    map[2] = ar_4;
    map[3] = ar_5;
    map[4] = ar_6;
    map[5] = ar_7;
    map[6] = ar_8;
    map[7] = ar_8;



    std::string digits;

    std::cin >> digits;

    if (MIN_COUNT > digits.size() || digits.size() > MAX_COUNT) {
        FATAL_LIMIT(MIN_COUNT, MAX_COUNT, "count digit");
    }

    size_t count = digits.size();

    size_t* digit = new size_t[count];

    for (size_t i = 0; i < count; i++) {
        digit[i] = (size_t)digits[i] - 48;
    }

    for (size_t i = 0; i < count; i++) {
        for(size_t j = 0; j < sizeof(map[digit[i] - 2])/sizeof(char); j++) {

        }
    }


    delete[] digit;

    return SUCCESS;
}

