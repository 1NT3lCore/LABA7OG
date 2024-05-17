#include "shtuka.h"

Queue* createQueue() {
    Queue* q = new Queue;
    q->front = nullptr;
    q->rear = nullptr;
    return q;
}

void enqueue(Queue* q, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    }
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        std::cout << "Queue is empty!" << std::endl;
        return 0;
    }
    else {
        int data = q->front->data;
        Node* temp = q->front;
        q->front = q->front->next;
        delete temp;
        if (q->front == nullptr) {
            q->rear = nullptr;
        }
        return data;
    }
}

bool isEmpty(Queue* q) {
    return q->front == nullptr;
}

void moveElements(int N, Queue* firstQueue, Queue* secondQueue) {
    int count = 0;
    while (count < N && !isEmpty(firstQueue)) {
        int data = dequeue(firstQueue);
        enqueue(secondQueue, data);
        count++;
    }
}

void display(Queue* q) {
    if (isEmpty(q)) {
        std::cout << "NIL" << std::endl;
    }
    else {
        Node* current = q->front;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
}