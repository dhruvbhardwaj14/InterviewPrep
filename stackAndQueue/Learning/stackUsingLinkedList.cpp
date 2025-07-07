#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Stack class
class Stack {
private:
    Node* top;

public:
    // Constructor
    Stack() {
        top = nullptr;
    }

    // Destructor
    ~Stack() {
        while (top != nullptr) {
            pop();
        }
    }

    // Push operation
    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }

    // Pop operation
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    // Peek operation
    int peek() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return top->data;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Display stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return;
        }
        cout << "Stack (top to bottom): ";
        Node* current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// Example usage
int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();  // Output: 30 20 10

    s.pop();
    s.display();  // Output: 20 10

    cout << "Top element: " << s.peek() << endl;  // Output: 20

    return 0;
}
