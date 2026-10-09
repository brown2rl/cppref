#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <vector>

bool invertMatrix(const std::vector<std::vector<double>>& matrix,
                  std::vector<std::vector<double>>& inverse) {
    int numberOfRows = matrix.size();
    int k = 0;
    int l = 0;

    for (int i = numberOfRows - 1; i >= 0; i--) {
        // swap the columns of the matrix to get the inverse
        int columnSize = matrix[i].size();
        std::vector<double> tempColumn(columnSize);

        for (int j = columnSize - 1; j >= 0; j--) {
            tempColumn[k]=matrix[i][j];
            k++;
        }
        
        k=0;
        inverse[l] = tempColumn;
        l++;        
    }

    return true;
}

int main() {
    std::vector<std::vector<double>> matrix = {
        {4.0, 7.0},
        {2.0, 6.0},
    };

    std::vector<std::vector<double>> inverse(matrix.size());

    std::cout << "Original matrix:\n";
    int numberOfRows = matrix.size();
    for (int i = 0; i < numberOfRows; i++) {
        int columnSize = matrix[i].size();
        for (int j = 0; j < columnSize; j++) {
            std::cout << std::fixed << std::setprecision(2) << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::vector<std::vector<double>> &matrixRef = matrix;
    std::vector<std::vector<double>> &inverseRef = inverse;

    if (invertMatrix(matrixRef, inverseRef)){
        std::cout << "Matrix inversion successful.\n";

        std::cout << "Inverse matrix:\n";
        int numberOfRows = inverse.size();
        for (int i = 0; i < numberOfRows; i++) {
            int columnSize = inverse[i].size();
            for (int j = 0; j < columnSize; j++) {
                std::cout << std::fixed << std::setprecision(2) << inverse[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    return 0;
}
