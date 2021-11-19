#include <cmath>

#include "matrix.h"
#include "exceptions.h"

namespace prep {
double Matrix::det() const {
    if (m_rows != m_cols) {
        throw DimensionMismatch(*this);
    }

    Matrix matrix = Matrix(*this);

    if (!step_viev(matrix)) {
        return 0;
    }

    double value = 1;

    for (size_t i = 0; i < matrix.getRows(); i++) {
        value *= matrix(i, i);
    }

    return value;
}

Matrix create_minor(const Matrix& matrix, const size_t row, const size_t col) {
    Matrix minor(matrix.getRows() - 1, matrix.getCols() - 1);

    size_t minor_row = 0;
    for (size_t i = 0; i < matrix.getRows(); i++) {
        if (i == row) {
            continue;
        }

        size_t minor_col = 0;
        for (size_t j = 0; j < matrix.getCols(); j++) {
            if (j != col) {
                minor(minor_row, minor_col) = matrix(i, j);
                minor_col++;
            }
        }
        minor_row++;
    }
    return minor;
}

Matrix Matrix::adj() const {
    if (m_rows != m_cols || !m_rows) {
        throw DimensionMismatch(*this);
    }

    if (this->m_rows == 1 && this->m_cols == 1) {
        Matrix matrix_out(this->m_rows, this->m_cols);
        matrix_out(0, 0) = (*this)(0, 0);
        return matrix_out;
    }

    Matrix matrix(this->m_rows, this->m_cols);

    for (size_t i = 0; i < matrix.getRows(); i++) {
        for (size_t j = 0; j < matrix.getCols(); j++) {
            Matrix minor = create_minor(*this, i, j);
            auto value = minor.det();
            matrix(i, j) = pow(-1, (i+j)) * value;
        }
    }

    Matrix matrix_out = matrix.transp();

    return matrix_out;
}

Matrix Matrix::inv() const {
    if (m_rows != m_cols || !m_rows) {
        throw DimensionMismatch(*this);
    }

    if (m_rows == 1) {
        Matrix matrix_out(1, 1);
        if (!(*this)(0, 0)) {
            throw SingularMatrix();
        }

        matrix_out(0, 0) = 1 / (*this)(0, 0);

        return matrix_out;
    }

    auto value = det();

    auto eps = 1e-7;

    if (std::fabs(value) <= eps) {
        throw SingularMatrix();
    }

    Matrix adj_to_matrix = adj();

    Matrix matrix_out = (1.0 / value) * adj_to_matrix;

    return matrix_out;
}

}  // namespace prep

