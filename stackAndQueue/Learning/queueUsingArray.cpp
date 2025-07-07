#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear;
    int* arr;
    int capacity;

public:
    // Constructor
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
    }

    // Destructor
    ~Queue() {
        delete[] arr;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front > rear;
    }

    // Check if queue is full
    bool isFull() {
        return rear == capacity - 1;
    }

    // Enqueue operation
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        arr[++rear] = x;
    }

    // Dequeue operation
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        front++;
    }

    // Get front element
    int peek() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }
        return arr[front];
    }

    // Display queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// Example usage
int main() {
    Queue q(5); // Queue of size 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();  // Output: 10 20 30

    q.dequeue();
    q.display();  // Output: 20 30

    cout << "Front element: " << q.peek() << endl; // Output: 20

    return 0;
}
