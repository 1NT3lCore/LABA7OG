#include "shtuka.h"

Queue* createQueue() {
    Queue* q = new Queue; // Выделяем память под новую очередь
    q->front = nullptr; // Инициализируем указатель на начало очереди как nullptr
    q->rear = nullptr; // Инициализируем указатель на конец очереди как nullptr
    return q; // Возвращаем созданную очередь
}

// Функция для добавления элемента в очередь
void enqueue(Queue* q, int data) {
    Node* newNode = new Node; // Выделяем память под новый узел
    newNode->data = data; // Устанавливаем значение элемента в новом узле
    newNode->next = nullptr; // Устанавливаем указатель на следующий узел как nullptr
    if (isEmpty(q)) { // Если очередь пуста
        q->front = newNode; // Устанавливаем начало очереди на новый узел
        q->rear = newNode; // Устанавливаем конец очереди на новый узел
    }
    else {
        q->rear->next = newNode; // Устанавливаем указатель на следующий элемент текущего последнего элемента на новый узел
        q->rear = newNode; // Устанавливаем конец очереди на новый узел
    }
}

// Функция для извлечения элемента из очереди
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        std::cout << "Queue is empty!" << std::endl;
        return 0;
    }
    else {
        int data = q->front->data; // Получаем данные из первого элемента в очереди
        Node* temp = q->front; // Сохраняем указатель на первый элемент
        q->front = q->front->next; // Сдвигаем указатель начала очереди на следующий элемент
        delete temp; // Удаляем первый элемент из памяти
        if (q->front == nullptr) { // Если начало очереди указывает на nullptr
            q->rear = nullptr; // Обнуляем указатель на конец очереди
        }
        return data; // Возвращаем данные удаленного элемента
    }
}

// Функция для проверки пуста ли очередь
bool isEmpty(Queue* q) {
    return q->front == nullptr; // Возвращаем true, если начало очереди указывает на nullptr
}

// Функция для перемещения N элементов из одной очереди в другую
void moveElements(int N, Queue* firstQueue, Queue* secondQueue) {
    int count = 0; // Переменная для подсчета перемещенных элементов
    while (count < N && !isEmpty(firstQueue)) { // Пока не переместили N элементов и очередь не пуста
        int data = dequeue(firstQueue); // Извлекаем элемент из первой очереди
        enqueue(secondQueue, data); // Добавляем элемент во вторую очередь
        count++; // Увеличиваем счетчик перемещенных элементов
    }
}

// Функция для вывода содержимого очереди
void display(Queue* q) {
    if (isEmpty(q)) { // Если очередь пуста
        std::cout << "NIL" << std::endl; // Выводим NIL
    }
    else {
        Node* current = q->front; // Устанавливаем указатель на начало очереди
        while (current != nullptr) { // Пока не достигнут конец очереди
            std::cout << current->data << " "; // Выводим данные текущего узла
            current = current->next; // Переходим к следующему узлу
        }
        std::cout << std::endl; // Переходим на новую строку
    }
}
