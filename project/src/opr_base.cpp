#include <cmath>

#include "matrix.h"
#include "exceptions.h"

namespace prep {
size_t Matrix::getRows() const {
    return m_rows;
}

size_t Matrix::getCols() const {
    return m_cols;
}

double Matrix::operator()(size_t i, size_t j) const {
    if (i >= m_rows || j >= m_cols) {
        throw OutOfRange(i, j, *this);
    }

    return m_data[i][j];
}

double& Matrix::operator()(size_t i, size_t j) {
    if (i >= m_rows || j >= m_cols) {
        throw OutOfRange(i, j, *this);
    }

    return m_data[i][j];
}

bool Matrix::operator==(const Matrix& rhs) const {
    if (this->m_rows != rhs.m_rows || this->m_cols != rhs.m_cols) {
        return false;
    }

    auto eps = 1e-07;

    for (size_t i = 0; i < rhs.getRows(); i++) {
        for (size_t j = 0; j < rhs.getCols(); j++) {
            if (std::fabs(rhs(i, j) - (*this)(i, j)) > eps) {
                return false;
            }
        }
    }

    return true;
}

bool Matrix::operator!=(const Matrix& rhs) const {
    return !(*this == rhs);
}

}  // namespace prep
