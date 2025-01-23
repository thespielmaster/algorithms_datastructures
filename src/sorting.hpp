#pragma once
#include <iostream>
#include <vector>

template <typename T>

class Sorting{

private:

    std::vector<T> data;
    void verifySortable();

public:

    Sorting(const std::vector<T>& unsorted);

    std::vector<T> insertionSort();

    std::vector<T> mergeSort();
    void merge(std::vector<T>& arr, int start, int middle, int end);
    std::vector<T> recursiveMergeSort(std::vector<T>& arr, int start, int end);
};
