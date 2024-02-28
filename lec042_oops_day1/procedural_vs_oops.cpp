#include <bits/stdc++.h>
using namespace std;
//procedural approach
int areaofrectangle(int l,int b){
	return l*b;
}

//oops approach
class rectangle{
	int l;
	int b;
  public:
    rectangle(int a,int b){
	  this->l=a;
	  this->b=b;
    }
    int areaofrect(){
    	return l*b;
    }
};
int main(){
//procedural approach
  int length =5;
  int breadth = 10;
  int areaproc = areaofrectangle(length,breadth);
  cout<<"procedural approach - Area: "<<areaproc<<endl;


//oops approach
rectangle rect(5,10);
int areaoop = rect.areaofrect();
cout<<"oops approach - Area: "<<areaoop<<endl;

return 0;
}
