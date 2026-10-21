#pragma once
#include <vector>

template <typename T, typename R, typename A>
R average(std::vector<T> data, A adder, int columns, std::vector<int> toRead) {
    int rows = data.size() / columns;
    int invalid = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < toRead.size(); j++) {
            int toReadValue = i * columns + toRead[j];
            if (0 == data[toReadValue]) {
                invalid++;
                continue;
            }
            adder += data[toReadValue];
        }
    };
    return static_cast<R>(adder) / (toRead.size() * rows - invalid);
}

long double averageAndPrint(const std::vector<uint8_t> data, int columns, const std::vector<int> toRead, const char*  name);