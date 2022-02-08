#include <iostream>
#include <array>
#include <string>

#define SUCCESS 1
#define ERROR_INPUT -1

#define MAX_COUNT 9
#define MIN_COUNT 0

class ScoreBoard {
public:
    char ar_2[3] {'a', 'b', 'c'};
    char ar_3[3] {'d', 'e', 'f'};

    char ar_4[3] {'g', 'h', 'i'};
    char ar_5[3] {'j', 'k', 'l'};
    char ar_6[3] {'m', 'n', 'o'};

    char ar_7[4] {'p', 'q', 'r', 's'};
    char ar_8[3] {'t', 'u', 'v'};
    char ar_9[4] {'w', 'x', 'y', 'z'};

    void create_map();

    std::string digits;

    std::array <size_t, MAX_COUNT - MIN_COUNT> digit_int;
    int input();

    void get_digits();

    void get_res();

    ScoreBoard();
    ~ScoreBoard() = default;
};

int ScoreBoard::input() {
    std::cin >> digits;

    if (MIN_COUNT > digits.size() || digits.size() > MAX_COUNT) {
        std::cerr << "Wrong input: count must be in interval " <<
        MIN_COUNT << "-" << MAX_COUNT << std::endl;
        return ERROR_INPUT;
    }

    return SUCCESS;
}

void ScoreBoard::create_map() {
    for (size_t i =)
}

ScoreBoard::ScoreBoard() {
    input();
}

void ScoreBoard::get_digits() {
    for (size_t i = 0; i < digits.size(); i++) {
        digit_int[i] = (size_t)digits[i] - 48;

        std::cout << digit_int[i] << " ";
    }
    std::cout << std::endl;
}

void ScoreBoard::get_res() {
    get_digits();


}

int main(void) {
    ScoreBoard sb;

    sb.get_digits();

    return SUCCESS;
}

