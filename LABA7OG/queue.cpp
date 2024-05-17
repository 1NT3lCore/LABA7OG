#include "Queue.h"
#include <iostream>

Queue::Queue() {
    front = nullptr;
    rear = nullptr;
}

Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

void Queue::enqueue(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    if (isEmpty()) {
        front = newNode;
        rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

int Queue::dequeue() {
    if (isEmpty()) {
        std::cout << "Queue is empty!" << std::endl;
        return 0;
    }
    else {
        int data = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            rear = nullptr;
        }
        return data;
    }
}

bool Queue::isEmpty() {
    return front == nullptr;
}

void Queue::moveElements(int N, Queue& secondQueue) {
    int count = 0;
    while (count < N && !isEmpty()) {
        int data = dequeue();
        secondQueue.enqueue(data);
        count++;
    }
}

void Queue::display() {
    if (isEmpty()) {
        std::cout << "NIL" << std::endl;
    }
    else {
        Node* current = front;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
}
