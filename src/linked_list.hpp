#pragma once

template <typename T>
struct ListNode{
    T value;
    ListNode* next;

    ListNode(T val);
    ListNode(T val, ListNode* next);
};

template <typename T>
class LinkedList{
public:
    ListNode<T>* head;

    LinkedList();
    LinkedList(T val);

    T get(int index);
    void addAtHead(T val);
    void addAtTail(T val);
    void remove(int index);
    void print();
};