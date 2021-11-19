#include "matrix.h"
#include "exceptions.h"

namespace prep {
Matrix Matrix::operator*(double val) const {
    if (!this->m_rows || !this->m_cols) {
        throw DimensionMismatch(*this);
    }

    Matrix matrix_out(this->m_rows, this->m_cols);

    for (size_t i = 0; i < matrix_out.getRows(); i++) {
        for (size_t j = 0; j < matrix_out.getCols(); j++) {
            matrix_out(i, j) = val * (*this)(i, j);
        }
    }

    return matrix_out;
}

    Matrix operator*(double val, const Matrix& matrix) {
        return matrix * val;
    }

Matrix Matrix::operator+(const Matrix& rhs) const {
    if (!this->m_rows || !this->m_cols || !rhs.m_rows || !rhs.m_cols) {
        throw DimensionMismatch(rhs);
    }

    if (this->m_cols != rhs.m_cols || this->m_rows != rhs.m_rows) {
        throw DimensionMismatch(*this, rhs);
    }

    Matrix matrix_out(this->m_rows, this->m_cols);

    for (size_t i = 0; i < matrix_out.getRows(); i++) {
        for (size_t j = 0; j < matrix_out.getCols(); j++) {
            matrix_out(i, j) = (*this)(i, j) + rhs(i, j);
        }
    }

    return matrix_out;
}

Matrix Matrix::operator-(const Matrix& rhs) const {
    if (!this->m_rows || !this->m_cols || !rhs.m_rows || !rhs.m_cols) {
        throw DimensionMismatch(rhs);
    }

    if (this->m_cols != rhs.m_cols || this->m_rows != rhs.m_rows) {
        throw DimensionMismatch(*this, rhs);
    }

    Matrix matrix_out(this->m_rows, this->m_cols);

    for (size_t i = 0; i < matrix_out.getRows(); i++) {
        for (size_t j = 0; j < matrix_out.getCols(); j++) {
            matrix_out(i, j) = (*this)(i, j) - rhs(i, j);
        }
    }

    return matrix_out;
}

Matrix Matrix::operator*(const Matrix& rhs) const {
    if (!this->m_rows || !this->m_cols || !rhs.m_rows || !rhs.m_cols) {
        throw DimensionMismatch(rhs);
    }

    if (this->m_cols != rhs.m_rows) {
        throw DimensionMismatch(rhs);
    }

    Matrix matrix_out(this->m_rows, rhs.m_cols);

    for (size_t i = 0; i < matrix_out.getRows(); i++) {
        for (size_t j = 0; j < matrix_out.getCols(); j++) {
            for (size_t k = 0; k < this->m_cols; k++) {
                matrix_out(i, j) += (*this)(i, k) * rhs(k, j);
            }
        }
    }

    return matrix_out;
}

Matrix Matrix::transp() const {
    Matrix matrix_out(this->m_cols, this->m_rows);

    for (size_t i = 0; i < matrix_out.getRows(); i++) {
        for (size_t j = 0; j < matrix_out.getCols(); j++) {
            matrix_out(i, j) = (*this)(j, i);
        }
    }

    return matrix_out;
}

}  // namespace prep
