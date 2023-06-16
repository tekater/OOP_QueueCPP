#pragma warning(disable:4996)

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>

using namespace std;

class Stack {
    int mas[20];
    int top; // "Указатель" на вершину
public:
    Stack();
    void Push(int x);
    int Pop();
    void Clear();
    bool isEmpty();
    bool isFull();
    int getCount();

    void print();
};

Stack::Stack() {
    top = 0;
}
void Stack::Push(int x) {
    if (!isFull()) {
        mas[top++] = x;
    }
}
int Stack::Pop() {
    if (!isEmpty()) {
        return mas[--top];
    }
}
void Stack::Clear() {
    top = 0;
}
bool Stack::isEmpty() {
    return top == 0;
}
bool Stack::isFull() {
    return top == 20;
}
int Stack::getCount() {
    return top;
}

void Stack::print() {
    for (int i = 0; i < top; i++) {
        cout << mas[i] << " ";
    }
    cout << endl;
}

class Queue {
    int *mas;
    int maxsize;
    int top;
    
public:
    Queue(int size);
    ~Queue();
    void Push(int x);
    int Pop();
    void Clear();
    bool isEmpty();
    bool isFull();
    int getCount();
    void PopRing();

    void print();
};
class QueuePriority {
    int* mas;
    int maxsize;
    int top;
    int* pri;
public:
    QueuePriority(int size);
    ~QueuePriority();
    void Push(int x,int p);
    void Clear();
    bool isEmpty();
    bool isFull();
    int getCount();
    void pop();

    void print();
};

Queue::Queue(int size) {
    mas = new int[size];
    maxsize = size;
    top = 0;
}
Queue::~Queue() {
    delete[] mas;
}

void Queue::Push(int x) {
    if (!isFull()) {
        mas[top++] = x;
    }
}
int Queue::Pop() {
    if (!isEmpty()) {
        int buf = mas[0];
        for (int i = 0; i < top-1; i++) {
            mas[i] = mas[i + 1];
        }
        top--;
        mas[top] = buf;
        return mas[top];
    }
}
void Queue::PopRing() {
    if (!isEmpty()) {
        int buf = mas[0];
        for (int i = 0; i < top-1; i++) {
            mas[i] = mas[i + 1];
        }
        mas[top-1] = buf;
    }
}

void Queue::Clear() {
    top = 0;
}
bool Queue::isEmpty() {
    return top == 0;
}
bool Queue::isFull() {
    return top == maxsize;
}
int Queue::getCount() {
    return top;
}
void Queue::print() {
    for (int i = 0; i < top; i++) {
        cout << mas[i] << " ";
    }
    cout << endl;
}


QueuePriority::QueuePriority(int size) {
    mas = new int[size];
    maxsize = size;
    top = 0;
    pri = new int[size];
}
QueuePriority::~QueuePriority() {
    delete[] mas;
    delete[] pri;
}

void QueuePriority::Push(int x,int p) {
    if (!isFull()) {
        mas[top] = x;
        pri[top] = p;
        top++;
        int temp = 0;
        for (int i = 0; i < top; i++) {
            if (pri[i] > pri[i + 1]) {
                temp = mas[i];
                mas[i + 1] = mas[i];
                mas[i] = temp;

                temp = pri[i];
                pri[i + 1] = pri[i];
                pri[i] = temp;
            }
        }
    }
}

void QueuePriority::Clear() {
    top = 0;
}
bool QueuePriority::isEmpty() {
    return top == 0;
}
bool QueuePriority::isFull() {
    return top == maxsize;
}
int QueuePriority::getCount() {
    return top;
}
void QueuePriority::pop() {
    if (!isEmpty()) {
        int max=0;
        for (int i = 1; i < top; i++) {
            if (pri[i] > pri[max]) {
                max = i;
            }
        }
        for (int i = max; i < top - 1; i++) {
            mas[i] = mas[i + 1];
            pri[i] = pri[i + 1];
        }
        top--;
    }
}
void QueuePriority::print() {
    for (int i = 0; i < top; i++) {
        cout << mas[i] << " - " << pri[i] << endl;
    }
    cout << endl;
}

int main() {

    setlocale(0, "");
    srand(time(NULL));

    Stack stack;
    for (int i = 0; i < 5; i++) {
        stack.Push(rand() % 100);
    }
    stack.print();
    for (int i = 0; i < 2; i++) {
        cout << stack.Pop() << endl;
    }
    stack.print();

    stack.Clear();

    stack.print();
    while (!stack.isFull()) {
        stack.Push(rand() % 100);
    }
    stack.print(); cout << endl;
    while (!stack.isEmpty()) {
        stack.Pop();
    }
    stack.print();


    Queue q{ 10 };
    for (int i = 0; i < 5; i++) {
        q.Push(rand() % 100);
    }
    q.print();
    for (int i = 0; i < 2; i++) {
        cout << q.Pop() << endl;
    }
    q.print();

    q.Clear();

    q.print();
    while (!q.isFull()) {
        q.Push(rand() % 100);
    }
    q.print(); cout << endl;
    while (!q.isEmpty()) {
        q.Pop();
    }
    q.print();

    QueuePriority qp{ 10 };
    for (int i = 0; i < 5; i++) {
        qp.Push(rand() % 100,rand() % 100);
    }
    qp.print();
    for (int i = 0; i < 2; i++) {
        qp.pop();
    }
    qp.print();

    qp.Clear();

    qp.print();
    while (!qp.isFull()) {
        qp.Push(rand() % 100, rand() % 100);
    }
    qp.print(); cout << endl;
    while (!qp.isEmpty()) {
        qp.pop();
    }
    qp.print();
}
