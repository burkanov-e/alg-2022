#pragma once

#include <cstdlib>
#include <map>
#include <utility>
#include <vector>

int binarySearch(const std::vector<int> &v, const int &x);

std::string toStr(const std::vector<int> &v);

void insertionSort(std::vector<int> &v);

// void mergeSort(std::vector<int> &v);

void mergeSort(std::vector<int> &v, int const &beg, int const &end);
