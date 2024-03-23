#include <iostream>
#define N 20
using namespace std;
class queue{
    int *arr;
    int front;
    int back;
    public:
    queue(int size){
        arr = new int[size];
        front = -1;
        back = -1;
    }

    void push(int x){
        if (back==N-1)
        {
            cout<<"Queue Overflow"<<endl;
            return;
        }

        back++;
        arr[back]=x;

        if (front==-1)
        {
            front++;
        }
        
        
    }
    
    void pop(){
        if (front==-1 || front>back)
        {
            cout<<"Queue underflow";
            return;
        }

        front++;
        
    }

    bool empty(){
        return (front==-1|| front>back);
    }

    int peek(){
        if (front==-1 || front>back)
        {
            cout<<"Queue is empty ";
            return -1;
        }
        
        return arr[front];
    }

};
int main()
{

    queue q(N);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    cout<<q.peek()<<" ";
    q.pop();

    cout<<q.peek()<<" ";
    q.pop();

    cout<<q.peek()<<" ";
    q.pop();

    cout<<q.peek()<<" ";
    q.pop();

    cout<<q.peek()<<" ";
    q.pop();
    
    cout<<q.peek()<<" ";

    return 0;
}