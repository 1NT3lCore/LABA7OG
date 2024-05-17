#include "ahahaha.h"

Node* createList() {
    return nullptr;
}

void addElement(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void deleteElement(Node*& head, int value) {
    Node* current = head;
    Node* previous = nullptr;
        while (current != nullptr && current->data != value) {
            previous = current;
            current = current->next;
        }

    if (current == nullptr) {
        std::cout << "Element not found in the list." << std::endl;
        return;
    }

    if (previous != nullptr) {
        previous->next = current->next;
    }
    else {
        head = current->next;
    }

    delete current;
}

void swapMinMax(Node* head) {
    if (head == nullptr) {
        std::cout << "List is empty." << std::endl;
        return;
    }

        Node* minNode = head;
    Node* maxNode = head;
    Node* current = head;

    while (current != nullptr) {
        if (current->data < minNode->data) {
            minNode = current;
        }

        if (current->data > maxNode->data) {
            maxNode = current;
        }

        current = current->next;
    }

    int temp = minNode->data;
    minNode->data = maxNode->data;
    maxNode->data = temp;
}

