#include <stack>

class MyQueue {
    stack<int> stack_first;
    stack<int> stack_second;

  public:
    MyQueue() {
        stack<int> stack_first;
        stack<int> stack_second;
    }

    void clearQueue() {
        while (!this->stack_first.empty()) {
            this->stack_first.pop();
        }
    }

    void push(int value) {
        this->stack_first.push(value);
    }

    void pop() {
        if (this->stack_first.empty()) return;
        while (!this->stack_first.empty()) {
            this->stack_second.push(this->stack_first.top());
            this->stack_first.pop();
        }
        stack_second.pop();
        while (!stack_second.empty()) {
            this->stack_first.push(this->stack_second.top());
            this->stack_second.pop();
        }
    }

    bool empty() {
        return this->stack_first.empty();
    }

    int back() {
        if (this->stack_first.empty()) return -1;
        return this->stack_first.top();
    }

    int front() {
        if (this->stack_first.empty()) return -1;
        while (!this->stack_first.empty()) {
            this->stack_second.push(this->stack_first.top());
            this->stack_first.pop();
        }
        int result = stack_second.top();
        while (!stack_second.empty()) {
            this->stack_first.push(this->stack_second.top());
            this->stack_second.pop();
        }
        return result;
    }
};