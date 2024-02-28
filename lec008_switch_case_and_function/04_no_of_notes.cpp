#include <iostream>

using namespace std;

int main()
{
  
  
  int num;
  cin>>num;
  int n=num;
  int count100=0;
  int count50=0;
  int count10=0;
  
  while(n>100)
  {
      count100++;
      n-=100;
  }
 
  
  while(n>50)
  {
      count50++;
      n-=50;
  }
  while(n>=10)
  {
      count10++;
      n-=10;
  }
  
cout<<"no of 100 count are "<<count100<<endl;
cout<<"no of 50 count are "<<count50<<endl;
cout<<"no of 10 count are "<<count10<<endl;

  
}
