#include <iomanip>
#include <limits>


#include "matrix.h"
#include "exceptions.h"

namespace prep {
std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    auto max_prec = std::numeric_limits<double>::max_digits10;

    os << matrix.m_rows << " " << matrix.m_cols << std::endl;

    for (size_t i = 0; i < matrix.getRows(); i++) {
        for (size_t j = 0; j < matrix.getCols(); j++) {
            os << std::setprecision(max_prec) << matrix(i, j) << " ";
        }
        os << std::endl;
    }

    return os;
}

Matrix::Matrix(size_t rows, size_t cols)
    : m_rows(rows), m_cols(cols),
    m_data(rows, std::vector<double> (cols)) {
}

Matrix::Matrix(std::istream& is) {
    is >> m_rows >> m_cols;

    if (!is) {
        throw InvalidMatrixStream();
    }

    m_data.resize(m_rows);
    for (auto& row : m_data) {
        row.resize(m_cols);

        for (auto& el : row) {
            is >> el;

            if (!is) {
                throw InvalidMatrixStream();
            }
        }
    }
}

}  // namespace prep
