#include <iostream>
using namespace std;

class Stack {
private:
    int top;
    int capacity;
    int* arr;

public:
    // Constructor
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }

    // Push operation
    void push(int x) {
        if (top >= capacity - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    // Pop operation
    void pop() {
        if (top < 0) {
            cout << "Stack Underflow\n";
            return;
        }
        top--;
    }

    // Peek operation
    int peek() {
        if (top < 0) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }

    // Check if stack is empty
    bool isEmpty() {
        return top < 0;
    }

    // Print stack
    void display() {
        if (top < 0) {
            cout << "Stack is Empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// Example usage
int main() {
    Stack st(5); // Stack of size 5

    st.push(10);
    st.push(20);
    st.push(30);
    st.display();  // Output: 10 20 30

    st.pop();
    st.display();  // Output: 10 20

    cout << "Top element: " << st.peek() << endl; // Output: 20

    return 0;
}
