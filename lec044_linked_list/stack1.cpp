#include <iostream>
#include<stack>
using namespace std;
class stack{
	public:
		int size;
		int top;
		int *arr;
		
	stack(int size){
		this->size=size;
		arr=new int[size];
		top=-1;
	}

void push(int d){
	if (top==-1){
		top++;
		arr[top]=d;
	}
	else{
		cout<<"stack is full";
	}
}
void pop(){
	if (top>=0){
		top--;
	}
	else{
		cout<<"stack is already empty";
	}
}
int peek(){
	if (top>=0){
		return arr[top];
	}
	else{
		cout<<"stack is empty";
	}
}
bool isempty(){
	if (top==-1){
		return true;
	}
	else{
		return false;
	}
}
};
int main(){
	// //stack st(5);
	// st.push(1);
	// st.push(2);
	// st.push(3);
	
	// st.pop();
	
	// st.peek();
	
	// st.isempty();
	
	return 0;
}