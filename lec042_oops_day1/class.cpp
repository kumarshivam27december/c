/*
oops
class and object
--------------------------------------------------

10 student
with regid,name,year,stream -> 40 total variable

--------------------------------------------------
if there are 10000 student then total no of 40000
variables
--------------------------------------------------

more mismatch can be happen

-----------------------------------------------------

rather than keeping somuch  variable
 keeping a single data type.
------------------------------------------------------
object are real entity that aquire memory.
object are variables.
------------------------------------------------------

*/
#include <bits/stdc++.h>
using namespace std;
class student{
 public:
  int reg;
  string name;
  static string college ; // it can be declared only
  // and this can't be initialised here
};
string student::college = "LPU";

int main(){
student a;
student b;
cout<<"Enter reg no of a : ";
cin>>a.reg;
cout<<"Enter reg no of b : ";
cin>>b.reg;
cout<<"Enter name of a : ";
cin>>a.name;
cout<<"Enter name of b : ";
cin>>b.name;

cout<<a.reg<<"\t"<<b.reg<<endl;
cout<<a.name<<"\t"<<b.name<<endl;
cout<<"Enter new name of b: ";
cin>>b.name;
cout<<a.name<<"\t"<<b.name<<endl;
cout<<a.college<<"\t"<<b.college<<endl;
cout<<"Enter new college name : ";
cin>>a.college;
cout<<a.college<<"\t"<<b.college<<endl;
return 0;
}
