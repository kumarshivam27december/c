#include<bits/stdc++.h>
using namespace std;


class student{

    int reg;

    public :

    student(int reg){
        this->reg = reg;
    }

    friend void display(student s);
    //friend void teacher :: accessReg(student s);

    friend class mentor;


};

class mentor{

public:

void access(student s){

        cout<<s.reg<<"\n";
}


};

int main(){

        student s1(24);

        mentor m;
        m.access(s1);
        return 0;
}