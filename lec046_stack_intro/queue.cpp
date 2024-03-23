#include <iostream>
#include <string>

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (front == nullptr && rear == nullptr);
    }

    // Function to insert an element at the rear of the queue
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        std::cout << "Element enqueued: " << value << std::endl;
    }

    // Function to remove an element from the front of the queue
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue an element." << std::endl;
        } else {
            Node* temp = front;
            front = front->next;

            if (front == nullptr) {
                rear = nullptr;
            }

            std::cout << "Element dequeued: " << temp->data << std::endl;
            delete temp;
        }
    }

    // Function to get the element at the front of the queue
    int getFront() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return -1;  // Return a default value to indicate an empty queue
        } else {
            return front->data;
        }
    }

    // Function to get the element at the rear of the queue
    int getRear() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return -1;  // Return a default value to indicate an empty queue
        } else {
            return rear->data;
        }
    }
};

int main() {
    Queue queue;

    int numElements;
    std::cout << "Enter the number of elements to enqueue: ";
    std::cin >> numElements;

    for (int i = 0; i < numElements; i++) {
        int value;
        std::cout << "Enter the element to enqueue: ";
        std::cin >> value;
        queue.enqueue(value);
    }

    int numDequeue;
    std::cout << "Enter the number of elements to dequeue: ";
    std::cin >> numDequeue;

    for (int i = 0; i < numDequeue; i++) {
        queue.dequeue();
    }

    if (queue.isEmpty()) {
        std::cout << "Queue is empty." << std::endl;
    } else {
        std::cout << "Queue is not empty." << std::endl;
    }

    return 0;
}
