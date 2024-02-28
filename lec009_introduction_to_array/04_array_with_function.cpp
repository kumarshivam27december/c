#include <iostream>
using namespace std;
//in the arr[] below  you should never put a value 
void printArray(int arr[], int size)
{
    
    // print the array
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
cout<<"\nprinting done"<<endl;
}
int main()
{
    int second[3]={5,7,11};
    cout<<"printing second array"<<endl;
    printArray(second,3);
    int third[15]={2, 7};   
    cout<<"printing third array "<<endl;
    printArray(third,15);
    int fourth[10]={0};
    cout<<"printing fourth array "<<endl;
    printArray(fourth,10);
    int fifth[10]={1};
    cout<<"printing fifth array "<<endl;
    printArray(fifth,10);
    cout<<"\nEverything is fine"<<endl;

    int thirdsize=sizeof(third)/sizeof(int);
    cout<<"size of fifth is "<<thirdsize<<endl;



    int fifthsize=sizeof(fifth)/sizeof(int);
    cout<<"size of fifth is "<<fifthsize<<endl;






}