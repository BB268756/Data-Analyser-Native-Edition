#include "Average.h"

long double averageAndPrint(const std::vector<uint8_t> data, int columns, const std::vector<int> toRead, const char* name) {
    uint64_t adder = 0;
    auto returnn = average<uint8_t,long double,uint64_t>(data, adder, columns, toRead);

    printf("%s:\n %Lf\n", name, returnn);
    return returnn;
}