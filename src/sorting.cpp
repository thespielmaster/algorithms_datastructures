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
std::vector<T> Sorting<T>::insertionSort(){

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

template <typename T>
std::vector<T> Sorting<T>::mergeSort(){
    std::vector<T> unsorted = this->data;
    return recursiveMergeSort(unsorted, 0, unsorted.size() - 1);
}

template <typename T>
void Sorting<T>::merge(std::vector<T>& arr, int start, int middle, int end){

    std::vector<T> left = {arr.begin() + start, arr.begin() + middle + 1};
    std::vector<T> right = {arr.begin() + middle + 1, arr.begin() + end + 1};

    int i = 0;
    int j = 0;
    int k = start;

    while(i < left.size() && j < right.size()){
        if(left[i] <= right[j]){
            arr[k] = left[i++];
        }
        else{
            arr[k] = right[j++];
        }
        k++;
    }

    while(i < left.size()){
        arr[k++] = left[i++];
    }

    while(j < right.size()){
        arr[k++] = right[j++];
    }

}

template <typename T>
std::vector<T> Sorting<T>::recursiveMergeSort(std::vector<T>& arr, int start, int end){
    
    if(end - start + 1 <= 1){
        return arr;
    }

    int middle = (start + end) / 2;

    recursiveMergeSort(arr, start, middle);
    recursiveMergeSort(arr, middle + 1, end);

    merge(arr, start, middle, end);

    return arr;
}


template class Sorting<int>;
template class Sorting<double>;
template class Sorting<float>;
template class Sorting<long long>;
template class Sorting<std::string>;