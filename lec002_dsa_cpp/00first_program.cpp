#include <iostream>
using namespace std;
int main() {
  /*
using: You are going to use it.
namespace: To use what? A namespace.
std: The std namespace (where features of the C++ Standard Library, such as string or vector, are declared).
After you write this instruction, if the compiler sees string it will know that you may be referring to std::string, and if it sees vector, it will know that you may be referring to std::vector. (Provided that you have included in your compilation unit the header files where they are defined, of course.)

If you don't write it, when the compiler sees string or vector it will not know what you are refering to. You will need to explicitly tell it std::string or std::vector, and if you don't, you will get a compile error.

When you make a call to using namespace <some_namespace>; all symbols in that namespace will become visible without adding the namespace prefix. A symbol may be for instance a function, class or a variable.

E.g. if you add using namespace std; you can write just cout instead of std::cout when calling the operator cout defined in the namespace std.

This is somewhat dangerous because namespaces are meant to be used to avoid name collisions and by writing using namespace you spare some code, but loose this advantage. A better alternative is to use just specific symbols thus making them visible without the namespace prefix. Eg:
  
#include <iostream>
using std::cout;

int main() {
  cout << "Hello world!";
  return 0;
} 
  
  
  
  */
cout<<"Namaste dunia"<<endl;
 int a=56;
  cout<<a<<endl;
  char ch='b';
  cout<<ch<<endl;
  bool first=true;
  cout<<first<<endl;
  float f=2.9747;
  cout<<f<<endl;
  double d=37.983;
  cout<<d<<endl;
  int size1 =sizeof(a);
  cout<<size1<<endl;
  int size2=sizeof(ch);
  cout<<size2<<endl;
  int size3=sizeof(first);
  cout<<size3<<endl;
  int size4=sizeof(f);
  cout<<size4<<endl;
  int size5=sizeof(d);
  cout<<size5<<endl;

  //typecasting
  int char1='a';
  cout<<char1<<endl;
  char ch2=98;
  cout<<ch2<<endl;
  char ch3=123456;// in last byte the value 64 is stored hereby it will print ascii value of 64 i.e. @ also because it cannot store value larger than 2^8-1
  cout<<ch3<<endl;
  
 //unsigned int 
   int num=-112;
  cout<<num<<endl;
  signed int num1=-112;
  cout<<num1<<endl;
  unsigned int num2=-112;
  cout<<num2<<endl;// this will give larger value because since it is negative number the compiler will takes it's 2's compliment creating the msb(most significant bit as 1) and hence creating a huge value for num2 here

  // also by default it is always signed
  // in unsigned the compiler take value from 0 to 2^32-1 taking only positive number

  //operators

  int num12=2/5;
  cout<<num12<<endl;
  cout<<2/5<<endl;
  cout<<2.0/5<<endl;
  float num13=2.0/5;
  cout<<num13<<endl;
  double num14=2.0/5;
  cout<<num14<<endl;
  double num15=2/5;
  cout<<num15<<endl;
  float num16=2/5;
  cout<<num16<<endl;
  int num17=2.0/5;
  cout<<num17<<endl;
  float num18=2.0/5;
  cout<<num18<<endl;

  //  logical operator &&,||,!
  int num19=!678;
  cout<<num19<<endl;
  int num20=!0;
  cout<<num20<<endl;
  int num21=!1;
  cout<<num21<<endl;



  
}