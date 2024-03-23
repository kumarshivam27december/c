#include <iostream>
using namespace std;
class Stack{
    public:
    int *arr;
    int top;
    int size;
    Stack(int size){
        this->size=size;
        arr = new int[size];
        top=-1;
    }
    
    void push(int data){

        //check of it is empty or not
        if (size-top>1)
        {
            top++;
            arr[top] = data;
        }else
        {
            cout<<"Stack overflow"<<endl;
        }
        
        
    }


    void pop(){
        //if there is atleast one element present in the stack
        //then only we can pop
        if (top>=0){
            top--;
        }else{
            cout<<"stack underflow"<<endl;
        }
        
    }

    bool isEmpty(){
        if (top<0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
        
        
    }

    int peek(){
        if (top>=0)
        {
            return arr[top];
        }
        else{
            cout<<"The stack is empty "<<endl;
            return -1;
        }
        
    }
};

int main()
{
    Stack st(6);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    st.push(0);
    st.push(-1);
    st.pop();
    cout<<"The peak of the element is "<<st.peek()<<endl;
    if (st.isEmpty())
    {
       cout<<"the stack is empty"<<endl;
    }else{
        cout<<"The stack is not empty"<<endl;
    }

    while (!st.isEmpty())
    {
        cout<<st.peek()<<" ";
        st.pop();
    }
    
    
    return 0;
}