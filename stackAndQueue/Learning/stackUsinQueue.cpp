// Push operation is costly (O(n)).
// Pop and top are O(1).
#include <iostream>
#include <queue>
using namespace std;

class Stack {
private:
    queue<int> q;

public:
    // Push operation (costly)
    void push(int x) {
        q.push(x);
        int size = q.size();
        // Rotate all elements except the last one to the back
        for (int i = 0; i < size - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
    }

    // Pop operation (top element)
    void pop() {
        if (q.empty()) {
            cout << "Stack Underflow\n";
            return;
        }
        q.pop();
    }

    // Get the top element
    int top() {
        if (q.empty()) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return q.front();
    }

    // Check if stack is empty
    bool isEmpty() {
        return q.empty();
    }

    // Display stack
    void display() {
        if (q.empty()) {
            cout << "Stack is Empty\n";
            return;
        }
        queue<int> temp = q;
        cout << "Stack (top to bottom): ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
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

    cout << "Top element: " << s.top() << endl;  // Output: 20

    return 0;
}
