#include <iostream>
using namespace std;

class CircularQueue {
    int* arr;
    int currSize, cap;
    int f, r;

public:
    CircularQueue(int size) {
        cap = size;
        arr = new int[cap];
        currSize = 0;
        f = 0;
        r = -1;
    }

    void push(int data) {
        if (currSize == cap) {
            cout << "Queue is full!\n";
            return;
        }
        r = (r + 1) % cap;
        arr[r] = data;
        currSize++;
    }

    void pop() {
        if (currSize == 0) {
            cout << "Queue is empty!\n";
            return;
        }
        f = (f + 1) % cap;
        currSize--;
    }

    int front() {
        if (currSize == 0) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return arr[f];
    }

    bool empty() {
        return currSize == 0;
    }

    void display() {
        if (currSize == 0) {
            cout << "Queue is empty!\n";
            return;
        }

        int count = 0;
        int i = f;

        while (count < currSize) {
            cout << arr[i] << " ";
            i = (i + 1) % cap;
            count++;
        }
        cout << endl;
    };

    ~CircularQueue() {
        delete[] arr;
    }
};

int main() {
    CircularQueue cq(3);

    cq.push(1);
    cq.push(2);
    cq.push(3);

    cq.display();

    cq.pop();
    cq.display();

    return 0;
}
