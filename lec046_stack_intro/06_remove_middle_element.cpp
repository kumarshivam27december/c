#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int>& inputstack, int count, int size) {
    // Base case: check if the count is equal to half of the size
    if (count == size / 2) {
        inputstack.pop();
        return;
    }

    int num = inputstack.top();
    inputstack.pop();

    // Recursive call
    solve(inputstack, count+1, size);

    inputstack.push(num);
}

void deleteatmiddle(stack<int>& inputstack, int n) {
    int count = 0;
    solve(inputstack, count, n);
}

int main() {
    stack<int> inputstack;

    // Push elements into the stack
    inputstack.push(1);
    inputstack.push(2);
    inputstack.push(3);
    inputstack.push(4);
    inputstack.push(5);

    // Original stack
    cout << "Original Stack: ";
    while (!inputstack.empty()) {
        cout << inputstack.top() << " ";
        inputstack.pop();
    }
    cout << endl;

    // Push elements again into the stack
    inputstack.push(1);
    inputstack.push(2);
    inputstack.push(3);
    inputstack.push(4);
    inputstack.push(5);

    // Delete middle element
    deleteatmiddle(inputstack, inputstack.size());

    // Modified stack
    cout << "Modified Stack: ";
    while (!inputstack.empty()) {
        cout << inputstack.top() << " ";
        inputstack.pop();
    }
    cout << endl;

    return 0;
}
