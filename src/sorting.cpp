#include <iostream>
#include <vector>
#include "sorting.hpp"

template <typename T>
void Sorting<T>::verifySortable(){
    if (!std::is_arithmetic<T>::value && !std::is_same<T, std::string>::value){
        throw std::invalid_argument("The type of elements in the vector does not support ordering operations.");
    }
}

template <typename T>
Sorting<T>::Sorting(const std::vector<T>& unsorted) : data(unsorted) { 
    verifySortable(); 
}

template <typename T>
std::vector<T> Sorting<T>::insertion_sort(){

    std::vector<T> unsorted = this->data;

    for(int i = 0; i < unsorted.size(); i++){

        int j = i;
        while(j > 0 && unsorted[j] < unsorted[j-1]){
            
            T temp = unsorted[j];
            
            unsorted[j] = unsorted[j - 1];
            unsorted[j - 1] = temp;

            j--;
        }

    }
    return unsorted;
}


template class Sorting<int>;
template class Sorting<double>;
template class Sorting<std::string>;