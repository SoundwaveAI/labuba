#include <iostream>
int ** create(size_t rows, size_t cols) {
  int ** result = new int*[rows];
  size_t i = 0;
  try {
    for (; i < rows; ++i) {
      result[i] = new int[cols];
    }
  } catch (...) {
      for (size_t j = 0; j < i; ++j) {
        delete[] result[j];
      }
      delete[] result;
      throw;
    }
    return result;
}
void remove(int ** m, size_t rows) {
  for (size_t i = 0; i < rows; ++i) {
    delete[] m[i];
  }
  delete[] m;
}
void input(int ** m, size_t rows, size_t cols) {
  for (size_t i = 0; i < rows &&(std::cin); ++i) {
    for (size_t j = 0; j < cols && (std::cin); ++j) {
      std::cin >> m[i][j];
    }
  }
}
void output(const int * const * m, size_t rows, size_t cols) {
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      if (j == (cols - 1)) {
        std::cout << m[i][j] << "\n";
      } else {
        std::cout << m[i][j] << " ";
      }
    }
  }
}
int** convert(const int* t, size_t n, const size_t* lns, size_t rows) {
  if (t == nullptr || lns == nullptr || rows == 0) {
      return nullptr;
  }
  int** result = new int*[rows];
  size_t i = 0;
  try {
    size_t current_index = 0;
    for (i = 0; i < rows; ++i) {
      result[i] = new int[lns[i]];
      for (size_t j = 0; j < lns[i]; ++j) {
        if (current_index < n) {
          result[i][j] = t[current_index++];
        } else {
          result[i][j] = 0; 
        }
      }
    }
  } catch (...) {
    for (size_t j = 0; j < i; ++j) {
      delete[] result[j];
    }
    delete[] result;
    throw;
  }
  return result;
}
int main()  {
  size_t rows = 0, cols = 0;
  std::cin >> rows >> cols;
  int ** m = nullptr;
  try {
    m = create(rows,cols);
  } catch (...) {
    return 2;
  }
  input(m, rows, cols);
  if (!std::cin) {
    remove(m, rows);
    return 1;
  }
  output(m, rows, cols);
  remove(m, rows);
  return 0;
}
