#include "functions.h"

bool isEven(int n) {
    if (n % 2 == 0)
        return true;
    else
        return false;
}

int sign(int n) {
    if (n < 0)
        return -1;
    if (n > 0)
        return 1;
    else
        return 0;
}

std::vector<int> difference(std::vector<int> vec) {
    std::vector<int> res;
    for (int i = 1; i < vec.size(); i++) {
        res.push_back(vec[i] - vec[i - 1]);
    }
    return res;
}

void show(const std::string &line) {
    if (line.empty())
        throw std::runtime_error("Pusty napis");
    std::cout << "Podany napis to: " << line << std::endl;
}
