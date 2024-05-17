#include "ahahaha.h"
#include <iostream>
#include <cstdlib> // Для функции rand()
#include <ctime> // Для инициализации генератора случайных чисел

int main() {
    srand(time(0)); // Инициализация генератора случайных чисел

    int numElements;
    std::cout << "Enter the number of elements: ";
    std::cin >> numElements;

    Node* list = createList();
    for (int i = 0; i < numElements; ++i) {
        addElement(list, rand() % 100); // Генерация случайного числа от 0 до 99
    }

    std::cout << "Original list:" << std::endl;
    Node* current = list;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    swapMinMax(list);

    std::cout << "List after swapping min and max elements:" << std::endl;
    current = list;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    return 0;
}