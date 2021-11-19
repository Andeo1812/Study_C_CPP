#include "matrix.h"
#include "exceptions.h"

namespace prep {
bool check_null_row(const Matrix& source, const size_t row) {
    size_t pos = 0;

    while (source(row, pos) == 0) {
        if (pos == source.getRows() - 1) {
            return true;
        }
        pos++;
    }
    return false;
}

bool check_null_col(const Matrix& source, const size_t col) {
    size_t pos = 0;

    while (source(pos, col) == 0) {
        if (pos == source.getCols() - 1) {
            return true;
        }
        pos++;
    }
    return false;
}

void plus_col(Matrix& source, const size_t target, const size_t col) {
    for (size_t i = 0; i < source.getRows(); i++) {
        source(i, target) += source(i, col);
    }
}


bool check_null_diag_el(Matrix& source, const size_t pos) {
    if (source(pos, pos) == 0) {
        size_t not_zero_col = 1;

        while (source(pos, pos + not_zero_col) == 0) {
            not_zero_col++;
        }

        plus_col(source, pos, pos + not_zero_col);
        return true;
    }
    return false;
}

bool step_view(Matrix& source) {
    for (size_t k = 0; k < source.getRows(); k++) {
        if (check_null_row(source, k) || check_null_col(source, k)) {
            return false;
        }

        for (size_t i = 1 + k; i < source.getRows(); i++) {
            check_null_diag_el(source, k);

            double mull = source(i, k) / source(k, k);

            for (size_t j = 0; j <  source.getRows(); j++) {
                source(i, j) -= mull *  source(k, j);
            }
        }
    }
    return true;
}

}  // namespace prep
