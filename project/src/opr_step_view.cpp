#include "matrix.h"
#include "exceptions.h"

namespace prep {
bool Matrix::check_null_row(const size_t row) const {
    size_t pos = 0;

    while (m_data[row][pos] == 0) {
        if (pos == getRows() - 1) {
            return true;
        }
        pos++;
    }

    return false;
}

bool Matrix::check_null_col(const size_t col) const {
    size_t pos = 0;

    while (m_data[pos][col] == 0) {
        if (pos == getCols() - 1) {
            return true;
        }
        pos++;
    }

    return false;
}

void Matrix::plus_col(const size_t target, const size_t col) {
    for (size_t i = 0; i < getRows(); i++) {
        m_data[i][target] += m_data[i][col];
    }
}


bool Matrix::check_null_diag_el(const size_t pos) {
    if (m_data[pos][pos] == 0) {
        auto not_zero_col = 1;

        while (m_data[pos][pos + not_zero_col] == 0) {
            not_zero_col++;
        }

        plus_col(pos, pos + not_zero_col);

        return true;
    }

    return false;
}

bool Matrix::step_view() {
    for (size_t k = 0; k < getRows(); k++) {
        if (check_null_row(k) || check_null_col(k)) {
            return false;
        }

        for (size_t i = 1 + k; i < getRows(); i++) {
            check_null_diag_el(k);

            auto mull = m_data[i][k] / m_data[k][k];

            for (size_t j = 0; j < getRows(); j++) {
                m_data[i][j] -= mull *  m_data[k][j];
            }
        }
    }

    return true;
}

}  // namespace prep
