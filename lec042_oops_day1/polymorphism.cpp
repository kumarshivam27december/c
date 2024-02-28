#include <bits/stdc++.h>
using namespace std;

class student{

public :

int reg;
string name;
int marks = 0;


void operator+(int num){

this->marks += num;
}

void operator++(){
cout<<"Inside prefix"<<"\n";
this->reg += 1;
}

void operator++(int){
cout<<"Inside postfix"<<"\n";
this->reg += 1;
}
};

int main() {

student s1;
s1.reg = 10;
//student s2(11, "Rahul");

//s1+3;
++s1;
s1++;

cout<<s1.reg<<"\n";
return 0;
}