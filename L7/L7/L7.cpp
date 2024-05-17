#include "shtuka.h"

int main() {
    srand(time(0)); // Инициализация генератора случайных чисел

    int N, F, S;
    std::cout << "Enter the number of elements to move: ";
    std::cin >> N;
    std::cout << "Enter the number of elements in first queue: ";
    std::cin >> F;
    std::cout << "Enter the number of elements in second queue: ";
    std::cin >> S;

    Queue* firstQueue = createQueue();
    Queue* secondQueue = createQueue();

    // Заполнение первой очереди случайными элементами
    for (int i = 0; i < F; ++i) {
        int randomElement = rand() % 100; // Генерация случайного числа от 0 до 99
        enqueue(firstQueue, randomElement);
    }

    // Заполнение второй очереди случайными элементами
    for (int i = 0; i < S; ++i) {
        int randomElement = rand() % 100; // Генерация случайного числа от 0 до 99
        enqueue(secondQueue, randomElement);
    }

    std::cout << "First queue before moving elements: ";
    display(firstQueue);
    std::cout << "Second queue before moving elements: ";
    display(secondQueue);

    moveElements(N, firstQueue, secondQueue);

    std::cout << "First queue after moving elements: ";
    display(firstQueue);
    std::cout << "Second queue after moving elements: ";
    display(secondQueue);

    // Очистка памяти
    while (!isEmpty(firstQueue)) {
        dequeue(firstQueue);
    }
    while (!isEmpty(secondQueue)) {
        dequeue(secondQueue);
    }

    delete firstQueue;
    delete secondQueue;

    return 0;
}