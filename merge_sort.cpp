#include <iostream>
#include <vector>

void mergeSort(std::vector<int>& values, std::vector<int>& buffer,
               std::size_t begin, std::size_t end) {
    if (end - begin < 2) {
        return;
    }

    const std::size_t middle = begin + (end - begin) / 2;
    mergeSort(values, buffer, begin, middle);
    mergeSort(values, buffer, middle, end);

    std::size_t left = begin;
    std::size_t right = middle;
    std::size_t output = begin;

    while (left < middle && right < end) {
        if (values[left] <= values[right]) {
            buffer[output++] = values[left++];
        } else {
            buffer[output++] = values[right++];
        }
    }

    while (left < middle) {
        buffer[output++] = values[left++];
    }

    while (right < end) {
        buffer[output++] = values[right++];
    }

    for (std::size_t index = begin; index < end; ++index) {
        values[index] = buffer[index];
    }
}

int main() {
    std::vector<int> values{38, 27, 43, 3, 9, 82, 10};
    std::vector<int> buffer(values.size());

    std::cout << "Original values:";
    for (int value : values) {
        std::cout << ' ' << value;
    }
    std::cout << '\n';
    mergeSort(values, buffer, 0, values.size());

    std::cout << "Sorted values:";
    for (int value : values) {
        std::cout << ' ' << value;
    }
    std::cout << '\n';

    return 0;
}
