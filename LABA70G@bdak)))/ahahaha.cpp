#include "ahahaha.h"

Node* createList() {
    return nullptr;
}

// Этот метод добавляет новый элемент со значением value в начало списка
void addElement(Node*& head, int value) {
    Node* newNode = new Node; // Создание нового узла
    newNode->data = value; // Присвоение узлу значения
    newNode->next = head; // Установка следующего указателя на текущий head
    head = newNode; // head теперь указывает на новый узел
}

// Этот метод удаляет элемент со значением value из списка
void deleteElement(Node*& head, int value) {
    Node* current = head; // Текущий указатель на начало списка
    Node* previous = nullptr; // Предыдущий указатель, инициализирован как nullptr

        // Поиск элемента со значением value в списке
        while (current != nullptr && current->data != value) {
            previous = current;
            current = current->next;
        }

    // Если элемент не найден
    if (current == nullptr) {
        std::cout << "Element not found in the list." << std::endl;
        return;
    }

    // Удаление найденного элемента
    if (previous != nullptr) {
        previous->next = current->next;
    }
    else {
        head = current->next;
    }

    delete current; // Освобождение памяти
}

// Этот метод меняет местами минимальный и максимальный элементы списка
void swapMinMax(Node* head) {
    if (head == nullptr) {
        std::cout << "List is empty." << std::endl;
        return;
    }
        Node* minNode = head; // Узел с минимальным значением, инициализирован как первый элемент
    Node* maxNode = head; // Узел с максимальным значением, инициализирован как первый элемент
    Node* current = head; // Текущий элемент, инициализирован как первый элемент

    // Поиск минимального и максимального элементов в списке
    while (current != nullptr) {
        if (current->data < minNode->data) {
            minNode = current;
        }

        if (current->data > maxNode->data) {
            maxNode = current;
        }

        current = current->next;
    }

    // Обмен значениями минимального и максимального элементов
    int temp = minNode->data;
    minNode->data = maxNode->data;
    maxNode->data = temp;
}

