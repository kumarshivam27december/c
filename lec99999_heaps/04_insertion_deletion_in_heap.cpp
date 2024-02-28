#include <iostream>
using namespace std;
class heap{
    public:
    int arr[100];
    int size;
    heap(){
        arr[0] = -1;
        size=0;
    }

    void insert(int value){
        size++;
        int index = size;
        arr[index] = value;

        //compare
        while(index>1){
            int parent = index/2;
            if (arr[parent] < arr[index])
            {
               swap(arr[parent],arr[index]);
               index = parent;
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

    void deletion(){
        if (size==0)
        {
            cout<<"nothing"<<endl;
            return;
        }

        //step 1
        arr[1] = arr[size];
        //step 2
        size--;
        //step 3
        //take root to the original position
        int i = 1;
        while (i<size)
        {
            int leftindex = 2*i;
            int rightindex = 2*i+1;

            if (leftindex < size && arr[i]<leftindex)
            {
               swap(arr[leftindex],arr[i]);
               i = leftindex;
            }
            else if (rightindex < size && arr[i]<rightindex)
            {
               swap(arr[rightindex],arr[i]);
               i = rightindex;
            } else{
                return;
            }           
        }
        
    }

    void deletion(int element){

        if (size==0)
        {
            cout<<"empty heap"<<endl;
            return;
        }

        int index = -1;
        for (int i = 1; i <= size; i++)
        {
            if (arr[i]==element)
            {
               index = i;
               break;
            }
            
        }

        if (index == -1)
        {
            cout<<"element not found";
            return;
        }

        //step 1
        arr[index] = arr[size];
        //step 2
        size--;


        int i = index;
        while (i<=size)
        {
          int leftindex = 2*i;
          int rightindex = 2*i+1;
          if (leftindex<size && arr[i]<arr[leftindex] && arr[leftindex] > arr[index])
          {
            swap(arr[leftindex],arr[index]);
            i = leftindex;
          }
          else if (rightindex<size && arr[i]<arr[rightindex] && arr[rightindex] > arr[index])
          {
            swap(arr[rightindex],arr[index]);
            i = rightindex;
          }
          else{
            return;
          }
        }
        
        
        
        
        
    }
};

void heapify(int arr[],int size,int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if (left <= size && arr[largest]< arr[left])
    {
        largest = left;
    }

    if (right<= size && arr[largest] < arr[right])
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
        //step 1 
        swap(arr[n],arr[1]);
        n--;

        //step 2
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
    h.deletion();
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