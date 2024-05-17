#pragma once

struct Node {
    int data;
    Node* next;
};

struct Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue();
    ~Queue();
    void enqueue(int data);
    int dequeue();
    bool isEmpty();
    void moveElements(int N, Queue& secondQueue);
    void display();
};