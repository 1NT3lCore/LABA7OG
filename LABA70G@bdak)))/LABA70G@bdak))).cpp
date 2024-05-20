#include "ahahaha.h"

// Основная функция программы
int main() {
    srand(time(0)); // Инициализация генератора случайных чисел
    std::regex naturalNumberRegex("^[1-9]\\d*$");

    int numElements;
    do {
        std::cout << "Enter the number of elements to move (a natural number): ";
        std::string input;
        while (true) {
            std::cin >> input;
            if (std::regex_match(input, naturalNumberRegex)) {
                numElements = std::stoi(input);
                break;
            }
            else {
                std::cout << "Invalid input. Please enter a natural number: ";
            }
        }
    } while (numElements <= 0);


    Node* list = createList(); // Создание пустого списка
    // Добавление случайных элементов в список
    for (int i = 0; i < numElements; ++i) {
        addElement(list, rand() % 100); // Генерация случайного числа от 0 до 99 и добавление его в список
    }

    std::cout << "Original list:" << std::endl; // Вывод сообщения оригинального списка
    Node* current = list; // Установка указателя на начало списка
    // Вывод элементов списка
    while (current != nullptr) {
        std::cout << current->data << " "; // Вывод элемента списка
        current = current->next; // Переход к следующему элементу
    }
    std::cout << std::endl; // Переход на новую строку

    swapMinMax(list); // Вызов функции для обмена минимального и максимального элементов списка

    std::cout << "List after swapping min and max elements:" << std::endl; // Вывод сообщения списка после обмена
    current = list; // Установка указателя на начало списка
    // Вывод элементов списка
    while (current != nullptr) {
        std::cout << current->data << " "; // Вывод элемента списка
        current = current->next; // Переход к следующему элементу
    }
    std::cout << std::endl; // Переход на новую строку

    return 0; // Возврат 0, как признак успешного завершения программы
}
