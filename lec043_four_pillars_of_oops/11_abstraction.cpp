#include <iostream>
using namespace std;

class Abstraction {
private:
    int a, b;

public:
    void set(int x, int y) {
        a = x;
        b = y;
    }

    void display() {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
    }
};

int main() {
    Abstraction obj;
    obj.set(10, 20);
    obj.display();

    return 0;
}
/*
advantage of abstraction
-> only you can make changes ti your data or function,
 and no one else can
->it makes the application secure by not allowing
 anyone else to see the background details
->increases the reusability of the code
->avoids dublicate of your code
*/