#include "Comparer.h"

Comparison<uint8_t> compairAndPrint(std::vector<uint8_t> vecData, int columns, std::vector<int> columnsToRead, const char* title) {
    Comparison<uint8_t> comparison = compare<uint8_t>(vecData, columns, columnsToRead);

    printf("Comparison of %s Reveals:\n", title);
    printf("Unique Answers of:\n");
    for (auto val : comparison.uniqueVals) {
        for (auto val : val) {
            printf("%u,", val);
        }
        printf("\n");
    }

    printf("Total Repeats of:\n");

    for (auto [key, val] : comparison.index) {
        if (val == 1)
            continue;

        for (auto val : key) {
            printf("%u,", val);
        }
        printf(": %u\n", val);
    }

    printf("\n");

    printf("Purity: %f\n", comparison.purity);

    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    return comparison;
}