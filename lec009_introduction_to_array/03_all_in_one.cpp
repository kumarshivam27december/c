#include <iostream>
using namespace std;
void printarray(){

}
int main()
{
    //declare
    int number[15];

    //accessing an array
    cout<<"value at 14 index "<<number[14]<<endl;


    //cout<<"value at 20 index "<<number[20]<<endl;
    

    //initialising an array
    int second[3]={5,7,11};


    //accessing an element
    cout<<"value at 2 index "<<second[2]<<endl;

    int third[15]={2,7};

    // print the array
    cout<<"printing the array "<<endl;
    for(int i=0;i<15;i++)
{
    cout<<third[i]<<" ";
}


//initialising all location with 0
cout<<endl;
int fourth[10]={0};
for(int i=0;i<10;i++)
{
    cout<<fourth[i]<<" ";
}


//initialising all location with 1
cout<<endl;
int fifth[10]={1};
for(int i=0;i<10;i++)
{
    cout<<fifth[i]<<" ";
}
// this method only will give the first value as 1 else everything as 0     



     cout<<"\nEverything is fine"<<endl;
}