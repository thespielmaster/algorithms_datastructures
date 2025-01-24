#include "LinkedList.hpp"
#include <iostream>
#include <stdexcept>

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr) {}

template <typename T>    
LinkedList<T>::LinkedList(T val) : head(new ListNode<T>(val)) {}

template <typename T>
T LinkedList<T>::get(int index) {
    if (this->head == nullptr) {
        throw std::runtime_error("Cannot get from an empty list.");
    }

    T lastEncounteredValue = this->head->value;
    ListNode<T>* ptr = this->head;
    int counter = 0;
    while (ptr != nullptr) {
        if (counter == index) {
            return ptr->value;
        }
        lastEncounteredValue = ptr->value;
        counter++;
        ptr = ptr->next;
    }

    std::cout << "End of list reached before index. Returning last list element." << std::endl;
    return lastEncounteredValue;
}

template <typename T>
void LinkedList<T>::addAtHead(T val) {
    if (this->head == nullptr) {
        this->head = new ListNode<T>(val);
        return;
    }

    ListNode<T>* ptr = new ListNode<T>(val, this->head);
    this->head = ptr;
}

template <typename T>
void LinkedList<T>::addAtTail(T val) {
    if (this->head == nullptr) {
        this->head = new ListNode<T>(val);
        return;
    }

    ListNode<T>* ptr = this->head;
    while (ptr->next != nullptr) {
        ptr = ptr->next;
    }

    ptr->next = new ListNode<T>(val);
}

template <typename T>
void LinkedList<T>::remove(int index) {
    if (this->head == nullptr) {
        std::cout << "Empty list. Nothing to remove." << std::endl;
        return;
    }

    if (index == 0) {
        ListNode<T>* temp = this->head;
        this->head = this->head->next;
        delete temp;
        return;
    }

    ListNode<T>* ptr = this->head;
    int counter = 0;

    while (ptr->next != nullptr) {
        if (++counter == index) {
            ListNode<T>* temp = ptr->next;
            ptr->next = ptr->next->next;
            delete temp;
            return;
        }
        ptr = ptr->next;
    }

    std::cout << "Index out of range. Nothing removed." << std::endl;
}

template <typename T>
void LinkedList<T>::print() {
    ListNode<T>* ptr = this->head;
    while (ptr != nullptr) {
        std::cout << ptr->value << " -> ";
        ptr = ptr->next;
    }
    std::cout << "END" << std::endl;
}