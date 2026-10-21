#pragma once
#include <map>
#include <vector>
#include <algorithm>

template<typename T>
struct Comparison {
    std::vector<std::vector<T>> uniqueVals;
    std::map<std::vector<T>, int> index;
    double purity;
};

template<typename T>
Comparison<T> compare(std::vector<T> data, int columns, std::vector<int> columnsToRead) {
    std::vector<std::vector<T>> toCompare;
    int rows = data.size() / columns;
    int replies = 0, unpure = 0;
    for (int i = 0; i < rows; i++) {
        int index = i * columns;
        std::vector<T> dataToCompare;
        for (int j = 0; j < columns; j++) {
            if (std::find(columnsToRead.begin(), columnsToRead.end(), j) != columnsToRead.end()) {
                dataToCompare.push_back(data[index + j]);
            }
        }
        replies++;
        if (std::all_of(dataToCompare.begin(), dataToCompare.end(),[&] (const auto value) {return value == dataToCompare[0];})) {
            unpure++;
        }

        toCompare.push_back(dataToCompare);
    }

    std::map<std::vector<T>, int> comparison;
    for (std::vector<T> data : toCompare) {
        if (comparison.find(data) == comparison.end()) {
            comparison[data] = 1;
        } else {
            ++comparison[data];
        }
    }

  //  std::map<std::vector<T>, int>* comparisonMap = malloc(sizeof(comparison));
//
  //  comparisonMap->copy(comparison);
//
    Comparison<T> result;
    result.index = comparison;

    std::vector<std::vector<T>> uniqueKeys;
    for (const auto& pair : comparison) {
        uniqueKeys.push_back(pair.first);
    }
    result.uniqueVals = uniqueKeys;

    result.purity = static_cast<double>(replies - unpure) / replies * 100;

    return result;
}

Comparison<uint8_t> compairAndPrint(std::vector<uint8_t> vecData, int columns, std::vector<int> columnsToRead, const char* title);