#include "matrix.h"
#include "exceptions.h"

namespace prep {
Matrix Matrix::operator*(double val) const {
    if (!getRows() || !getCols()) {
        throw DimensionMismatch(*this);
    }

    Matrix matrix_out(getRows(), getCols());

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
    if (!getRows() || !getCols() || !rhs.getRows() || !rhs.getCols()) {
        throw DimensionMismatch(rhs);
    }

    if (getRows() != rhs.getRows() || getCols()  != rhs.getCols()) {
        throw DimensionMismatch(*this, rhs);
    }

    Matrix matrix_out(getRows(), getCols());

    for (size_t i = 0; i < matrix_out.getRows(); i++) {
        for (size_t j = 0; j < matrix_out.getCols(); j++) {
            matrix_out(i, j) = (*this)(i, j) + rhs(i, j);
        }
    }

    return matrix_out;
}

Matrix Matrix::operator-(const Matrix& rhs) const {
    if (!getRows() || !getCols() || !rhs.getRows() || !rhs.getCols()) {
        throw DimensionMismatch(rhs);
    }

    if (getRows() != rhs.getRows() || getCols()  != rhs.getCols()) {
        throw DimensionMismatch(*this, rhs);
    }

    Matrix matrix_out(getRows(), getCols());

    for (size_t i = 0; i < matrix_out.getRows(); i++) {
        for (size_t j = 0; j < matrix_out.getCols(); j++) {
            matrix_out(i, j) = (*this)(i, j) - rhs(i, j);
        }
    }

    return matrix_out;
}

Matrix Matrix::operator*(const Matrix& rhs) const {
    if (!getRows() || !getCols() || !rhs.getRows() || !rhs.getCols()) {
        throw DimensionMismatch(rhs);
    }

    if (getCols() != rhs.getRows()) {
        throw DimensionMismatch(rhs);
    }

    Matrix matrix_out(getRows(), rhs.getCols());

    for (size_t i = 0; i < matrix_out.getRows(); i++) {
        for (size_t j = 0; j < matrix_out.getCols(); j++) {
            for (size_t k = 0; k < getCols(); k++) {
                matrix_out(i, j) += (*this)(i, k) * rhs(k, j);
            }
        }
    }

    return matrix_out;
}

Matrix Matrix::transp() const {
    Matrix matrix_out(getCols(), getRows());

    for (size_t i = 0; i < matrix_out.getRows(); i++) {
        for (size_t j = 0; j < matrix_out.getCols(); j++) {
            matrix_out(i, j) = (*this)(j, i);
        }
    }

    return matrix_out;
}

}  // namespace prep
