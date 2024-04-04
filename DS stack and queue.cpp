#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    stack<int> myStack;

    myStack.push(5);
    myStack.push(10);
    myStack.push(15);

    cout << "Stack size: " << myStack.size() << endl;

    while (!myStack.empty()) {
        cout << "Popped element: " << myStack.top() << endl;
        myStack.pop();
    }

    cout << "Stack size after popping: " << myStack.size() << endl;

    cout << endl;

    queue<int> myQueue;
    myQueue.push(5);
    myQueue.push(10);
    myQueue.push(15);

    cout << "Queue size: " << myQueue.size() << endl;

    while (!myQueue.empty()) {
        cout << "Dequeued element: " << myQueue.front() << endl;
        myQueue.pop();
    }

    cout << "Queue size after dequeuing: " << myQueue.size() << endl;

    return 0;
}
