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
    std::vector<T> insertion_sort();
};
