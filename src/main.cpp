#include <iostream>
#include "sorting.hpp"
#include "linked_list.hpp"

int main(){

    std::vector<int> arr = {3, 2, 4, 1, 6};

    LinkedList<int> myList;
    myList.addAtHead(1);

    for(auto it = arr.begin(); it != arr.end(); it++){
        std::cout << *it << std::endl;
        myList.addAtTail(*it);
    }

    myList.print();
    
    return 0;
}