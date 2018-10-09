#include <bits/stdc++.h>

using namespace std;

class MyQueue {
public:
    const int size;
    int *arr;
    int start, end;

    MyQueue(int n) : size(n) {
        arr = new int[n];
        start = 0, end = 0;
    }

    void push(int n) {
        arr[end] = n;
        end = (end + 1) % size;
        if (start == end) pop();
    }

    void pop() {
        if (empty())throw "queue is empty!! can not get value";
        start = (start + 1) % size;
    }

    int front() {
        return arr[start];
    }

    bool empty() {
        return start == end;
    }

    ~MyQueue() {
        delete arr;
    }
};

int main() {
    MyQueue queue(1001);
    queue.push(1);
    queue.push(2);
    cout << queue.front() << endl;
    queue.pop();
    queue.pop();
    cout << queue.empty() << endl;
    return 0;
}
