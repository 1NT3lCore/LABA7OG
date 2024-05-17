#include "Queue.h"
#include <iostream>
#include <cstdlib> // Для функции rand()
#include <ctime> // Для инициализации генератора случайных чисел

int main() {
    srand(time(0)); // Инициализация генератора случайных чисел

    int N;
    int F;
    int S;
    std::cout << "Enter the number of elements to move: ";
    std::cin >> N;
    std::cout << "Enter the number of elements in first queue: ";
    std::cin >> F;
    std::cout << "Enter the number of elements in second queue: ";
    std::cin >> S;

    Queue firstQueue;
    Queue secondQueue;

    // Заполнение первой очереди случайными элементами
    for (int i = 0; i < F; ++i) {
        int randomElement = rand() % 100; // Генерация случайного числа от 0 до 99
        firstQueue.enqueue(randomElement);
    }

    // Заполнение второй очереди случайными элементами
    for (int i = 0; i < S; ++i) {
        int randomElement = rand() % 100; // Генерация случайного числа от 0 до 99
        secondQueue.enqueue(randomElement);
    }

    std::cout << "First queue before moving elements: ";
    firstQueue.display();
    std::cout << "Second queue before moving elements: ";
    secondQueue.display();

    firstQueue.moveElements(N, secondQueue);

    std::cout << "First queue after moving elements: ";
    firstQueue.display();
    std::cout << "Second queue after moving elements: ";
    secondQueue.display();

    return 0;
}
