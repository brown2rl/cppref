#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <vector>

bool invertMatrix(const std::vector<std::vector<double>>& matrix,
                  std::vector<std::vector<double>>& inverse) {
    const std::size_t size = matrix.size();
    std::vector<std::vector<double>> working = matrix;
    inverse.assign(size, std::vector<double>(size, 0.0));

    double scale = 0.0;
    for (std::size_t row = 0; row < size; ++row) {
        inverse[row][row] = 1.0;
        for (double value : matrix[row]) {
            scale = std::max(scale, std::abs(value));
        }
    }

    const double tolerance =
        std::numeric_limits<double>::epsilon() * scale * size;

    for (std::size_t column = 0; column < size; ++column) {
        std::size_t pivotRow = column;
        for (std::size_t row = column + 1; row < size; ++row) {
            if (std::abs(working[row][column]) >
                std::abs(working[pivotRow][column])) {
                pivotRow = row;
            }
        }

        if (std::abs(working[pivotRow][column]) <= tolerance) {
            return false;
        }

        std::swap(working[column], working[pivotRow]);
        std::swap(inverse[column], inverse[pivotRow]);

        const double pivot = working[column][column];
        for (std::size_t entry = 0; entry < size; ++entry) {
            working[column][entry] /= pivot;
            inverse[column][entry] /= pivot;
        }

        for (std::size_t row = 0; row < size; ++row) {
            if (row == column) {
                continue;
            }

            const double factor = working[row][column];
            for (std::size_t entry = 0; entry < size; ++entry) {
                working[row][entry] -= factor * working[column][entry];
                inverse[row][entry] -= factor * inverse[column][entry];
            }
        }
    }

    return true;
}

int main() {
    int dimension = 0;
    std::cout << "Enter the dimension of the square matrix: ";
    if (!(std::cin >> dimension) || dimension <= 0) {
        std::cerr << "Please enter a positive integer dimension.\n";
        return 1;
    }

    const std::size_t size = static_cast<std::size_t>(dimension);
    std::vector<std::vector<double>> matrix(size, std::vector<double>(size));

    std::cout << "Enter the matrix elements row by row:\n";
    for (std::size_t row = 0; row < size; ++row) {
        for (std::size_t column = 0; column < size; ++column) {
            if (!(std::cin >> matrix[row][column])) {
                std::cerr << "Invalid matrix element.\n";
                return 1;
            }
        }
    }

    std::vector<std::vector<double>> inverse;
    if (!invertMatrix(matrix, inverse)) {
        std::cout << "The matrix is singular and cannot be inverted.\n";
        return 0;
    }

    std::cout << "Inverse matrix:\n" << std::fixed << std::setprecision(6);
    for (const auto& row : inverse) {
        for (std::size_t column = 0; column < size; ++column) {
            if (column > 0) {
                std::cout << ' ';
            }
            std::cout << row[column];
        }
        std::cout << '\n';
    }

    return 0;
}
