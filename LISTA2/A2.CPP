#include <iostream>
#include <list>
#include <string>

int main() {
    std::string input;
    while (std::getline(std::cin, input)) {
        std::list<char> result;
        auto it = result.begin();
        for (char c : input) {
            if (c == '[') {
                it = result.begin();
            } else if (c == ']') {
                it = result.end();
            } else {
                result.insert(it, c);
            }
        }
        for (char c : result) {
            std::cout << c;
        }
        std::cout << std::endl;
    }
    return 0;
}
