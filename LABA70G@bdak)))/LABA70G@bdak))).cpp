#include "ahahaha.h"

int main() {
    srand(time(0)); // Инициализация генератора случайных чисел

    int numElements;
    do {
        std::cout << "Enter the number of elements (a natural number > 0): ";
        std::cin >> numElements;

        if (std::cin.fail() || numElements <= 0) {
            std::cin.clear(); // Сброс состояния ошибки ввода
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка буфера ввода
            std::cout << "Invalid input. Please enter a natural number greater than 0." << std::endl;
        }
    } while (numElements <= 0);

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
