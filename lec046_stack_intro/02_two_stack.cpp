#include <iostream>
using namespace std;

class twostack {
public:
    int* arr;
    int top1;
    int top2;
    int size;

    twostack(int size) {
        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    void push1(int data) {
        // At least one empty space is present
        if (top2 - top1 > 1) {
            top1++;
            arr[top1] = data;
        }
        else {
            cout << "Stack overflow" << endl;
        }
    }

    void push2(int data) {
        // At least one empty space is present
        if (top2 - top1 > 1) {
            top2--;
            arr[top2] = data;
        }
        else {
            cout << "Stack overflow" << endl;
        }
    }

    int pop1() {
        if (top1 >= 0) {
            int value = arr[top1];
            top1--;
            return value;
        }
        else {
            return -1;
        }
    }

    int pop2() {
        if (top2 < size) {
            int value = arr[top2];
            top2++;
            return value;
        }
        else {
            return -1;
        }
    }
};

int main() {
    // Create a twostack object with size 10
    twostack ts(10);

    // Push elements into stack 1
    ts.push1(5);
    ts.push1(10);
    ts.push1(15);

    // Push elements into stack 2
    ts.push2(20);
    ts.push2(25);

    // Pop elements from stack 1
    cout << "Popped element from stack 1: " << ts.pop1() << endl;
    cout << "Popped element from stack 1: " << ts.pop1() << endl;

    // Pop elements from stack 2
    cout << "Popped element from stack 2: " << ts.pop2() << endl;
    cout << "Popped element from stack 2: " << ts.pop2() << endl;

    return 0;
}
