#include <iostream>

int atoi(std::string str) {
    int res = 0;
    bool negative = false;

    bool whitespaces = true;
    for (char &c : str) {
        if ((c == ' ' || c == '\t') && whitespaces) {
            continue;
        }

        whitespaces = false;
        if (c == '+') continue;
        else if (c == '-') negative = true;
        else if (c > '0' && c < '9') {
            res = (10 * res) + (c - '0');
        } else break;
    }

    if (negative) res = -res;

    return res;
}

int main() {
    std::string str = "   1234";
    std::cout << atoi(str) << std::endl;
}
