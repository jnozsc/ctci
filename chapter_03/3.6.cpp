#include <stack>
using namespace std;

class MyStack {
    stack<int> stack_first;
    stack<int> stack_second;

public:
    MyStack() {
        stack<int> stack_first;
        stack<int> stack_second;
    }

    void push(int value) {
        if (this->stack_first.empty()) {
            this->stack_first.push(value);
        } else {
            while (!this->stack_first.empty()) {
                if (value >= stack_first.top()) {
                    this->stack_first.push(value);
                    break;
                } else {
                    this->stack_second.push(this->stack_first.top());
                    this->stack_first.pop();
                }
            }
            this->stack_first.push(value);
            while (!this->stack_second.empty()) {
                this->stack_first.push(this->stack_second.top());
                this->stack_second.pop();
            }
        }
    }

    void pop() {
        if (this->stack_first.empty()) return;
        else this->stack_first.pop();
    }

    bool empty() {
        return this->stack_first.empty();
    }

    int top() {
        return this->stack_first.top();
    }
};
