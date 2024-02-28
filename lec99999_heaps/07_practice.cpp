#include <iostream>
using namespace std;
class heap{
    public:
    int arr[100];
    int size;
    heap(){
        arr[0] =-1;
        size = 0;
    }

    void insert(int value){
        size++;
        int index  = size;
        
        arr[index] = value;
        while(index>1){
            int parent = index/2;
            if (arr[parent]<arr[index])
            {
               swap(arr[parent],arr[index]);
               index  = parent;
            }else{
                return;
            }
            
        }
    }

    void deletion(int element){
        if (size==0)
        {
            cout<<"empty";
            return;
        }

        int index = -1;
        for(int i=1;i<=size;i++){
            if (arr[i]==element)
            {
                index = i; 
                break;
            }
            
        }

        if (index==-1)
        {
            cout<<"elememt not found";
            return;
        }

        //step 1
        arr[index]= arr[size];
        size--;

        int i = index;
        while(i<size){
            int leftch = 2*i;
            int rightch = 2*i+1;
            if (leftch<size && arr[i]<arr[leftch] && arr[leftch]>arr[index])
            {
                swap(arr[leftch],arr[index]);
                i=index;
            }
            else if (rightch<size && arr[i]<arr[rightch] && arr[rightch]>arr[index])
            {
                swap(arr[rightch],arr[index]);
                i=index;
            }
            else{
                return;
            }
    
            
        }


        
        
        
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
};

void heapify(int arr[],int size,int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;
    if (left<=size && arr[largest]<arr[left])
    {
        largest = left;
    }else if (right<=size && arr[largest]<arr[right])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr,size,largest);
    }

}

void heapsort(int arr[],int size){
    int n = size;
    while(n>1){
        swap(arr[n],arr[1]);
        n--;

        heapify(arr,n,1);
    }

}
int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deletion(55);
    h.print();
    h.deletion(54);
    h.print();



    //heap creation
    int arr1[6] = {-1,50,55,53,52,54};
    int n = 5;
    for (int i = n/2; i > 0 ; i--)
    {
        heapify(arr1,n,i);
    }


    cout<<"printing the array now"<<endl;


    for (int i = 1; i <= n; i++)
    {
       cout<<arr1[i]<<" ";
    }cout<<endl;


    //heapsort
    cout<<"After heap sort"<<endl;
    heapsort(arr1,n);
    for (int i = 1; i <= n; i++)
    {
       cout<<arr1[i]<<" ";
    }cout<<endl;

    return 0;
}