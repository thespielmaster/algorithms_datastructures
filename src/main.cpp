#include <iostream>
#include "sorting.hpp"

int main(){

    std::vector<int> arr = {3, 2, 4, 1, 6};

    for(auto it = arr.begin(); it != arr.end(); it++){
        std::cout << *it << std::endl;
    }


    Sorting<int> sort(arr);
    std::vector<int> sorted = sort.insertion_sort();

    for(auto it = sorted.begin(); it != sorted.end(); it++){
        std::cout << *it << std::endl;
    }
    
    return 0;
}