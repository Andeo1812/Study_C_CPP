#include <cmath>

#include "matrix.h"
#include "exceptions.h"

namespace prep {
double Matrix::det() const {
    if (getRows() != getCols()) {
        throw DimensionMismatch(*this);
    }

    Matrix matrix = Matrix(*this);

    if (!matrix.step_view()) {
        return 0;
    }

    double value = 1;

    for (size_t i = 0; i < matrix.getRows(); i++) {
        value *= matrix(i, i);
    }

    return value;
}

Matrix Matrix::create_minor(const size_t row, const size_t col) const {
    Matrix minor(getRows() - 1, getCols() - 1);

    size_t minor_row = 0;
    for (size_t i = 0; i < getRows(); i++) {
        if (i == row) {
            continue;
        }

        size_t minor_col = 0;
        for (size_t j = 0; j < getCols(); j++) {
            if (j != col) {
                minor(minor_row, minor_col) = m_data[i][j];
                minor_col++;
            }
        }
        minor_row++;
    }
    return minor;
}

Matrix Matrix::adj() const {
    if (getRows() != getCols() || !getRows()) {
        throw DimensionMismatch(*this);
    }

    if (getRows() == 1 && getCols() == 1) {
        Matrix matrix_out(getRows(), getCols());
        matrix_out(0, 0) = m_data[0][0];
        return matrix_out;
    }

    Matrix matrix(getRows(), getCols());

    for (size_t i = 0; i < matrix.getRows(); i++) {
        for (size_t j = 0; j < matrix.getCols(); j++) {
            Matrix minor = create_minor(i, j);
            auto value = minor.det();
            matrix(i, j) = pow(-1, (i+j)) * value;
        }
    }

    Matrix matrix_out = matrix.transp();

    return matrix_out;
}

Matrix Matrix::inv() const {
    if (getRows() != getCols() || !getRows()) {
        throw DimensionMismatch(*this);
    }

    if (m_rows == 1) {
        Matrix matrix_out(1, 1);

        if (!m_data[0][0]) {
            throw SingularMatrix();
        }

        matrix_out(0, 0) = 1 / m_data[0][0];

        return matrix_out;
    }

    auto value = det();

    if (std::fabs(value) <= EPS) {
        throw SingularMatrix();
    }

    Matrix adj_to_matrix = adj();

    Matrix matrix_out = (1.0 / value) * adj_to_matrix;

    return matrix_out;
}

}  // namespace prep
