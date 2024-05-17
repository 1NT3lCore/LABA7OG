#pragma once

#include <cstdlib> // Для функции rand()
#include <ctime>
#include <iostream>
struct Node {
    int data;
    Node* next;
};

struct Queue {
    Node* front;
    Node* rear;
};

Queue* createQueue();
void enqueue(Queue* q, int data);
int dequeue(Queue* q);
bool isEmpty(Queue* q);
void moveElements(int N, Queue* firstQueue, Queue* secondQueue);
void display(Queue* q);