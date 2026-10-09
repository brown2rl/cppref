#include <iostream>
#include <string>

int main() {
    std::cout << "Enter a line: " << std::flush;

    std::string input;
    if (!std::getline(std::cin, input)) {
        std::cerr << "Failed to read input.\n";
        return 1;
    }

    std::cout << "You entered: " << input << '\n';
    return 0;
}
