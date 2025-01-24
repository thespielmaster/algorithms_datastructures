#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
struct ListNode {
    T value;
    ListNode* next;

    ListNode(T val) : value(val), next(nullptr) {}
    ListNode(T val, ListNode* next) : value(val), next(next) {}
};

template <typename T>
class LinkedList {
public:
    ListNode<T>* head;

    LinkedList() : head(nullptr) {}
    LinkedList(T val) : head(new ListNode<T>(val)) {}

    T get(int index) {
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

    void addAtHead(T val) {
        if (this->head == nullptr) {
            this->head = new ListNode<T>(val);
            return;
        }

        ListNode<T>* ptr = new ListNode<T>(val, this->head);
        this->head = ptr;
    }

    void addAtTail(T val) {
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

    void remove(int index) {
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

    void print() {
        ListNode<T>* ptr = this->head;
        while (ptr != nullptr) {
            std::cout << ptr->value << " -> ";
            ptr = ptr->next;
        }
        std::cout << "END" << std::endl;
    }
};

template class LinkedList<int>;