#pragma once // NOLINT

#include <vector>
#include <istream>

namespace prep {
class Matrix {
 public:
  explicit Matrix(size_t rows = 0, size_t cols = 0);
  explicit Matrix(std::istream& is);
  Matrix(const Matrix& rhs) = default;
  Matrix& operator=(const Matrix& rhs) = default;
  ~Matrix() = default;

  size_t getRows() const;
  size_t getCols() const;

  double operator()(size_t i, size_t j) const;
  double& operator()(size_t i, size_t j);

  bool operator==(const Matrix& rhs) const;
  bool operator!=(const Matrix& rhs) const;

  Matrix operator+(const Matrix& rhs) const;
  Matrix operator-(const Matrix& rhs) const;
  Matrix operator*(const Matrix& rhs) const;

  Matrix operator*(double val) const;

  friend Matrix operator*(double val, const Matrix& matrix);
  friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

  bool check_null_row(const Matrix& source, const size_t row) const;
  bool check_null_col(const Matrix& source, const size_t col) const;
  void plus_col(Matrix& source, const size_t target, const size_t col) const;
  bool check_null_diag_el(Matrix& source, size_t pos) const;
  bool step_view(Matrix& source) const;

  Matrix transp() const;
  double det() const;
  Matrix adj() const;
  Matrix inv() const;

 private:
  size_t m_rows{};
  size_t m_cols{};
  std::vector<std::vector<double>> m_data{};
};

Matrix operator*(double val, const Matrix& matrix);
std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

}  // namespace prep
