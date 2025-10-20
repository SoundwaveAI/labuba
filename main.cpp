#include <iostream>
int main() {
  size_t rows = 0, cols = 0;
  std::cin >> rows >> cols;
  if (!std::cin) {
    return 1;
  }
  std::cout << rows << " " << cols;
  std::cout << "\n";
}
