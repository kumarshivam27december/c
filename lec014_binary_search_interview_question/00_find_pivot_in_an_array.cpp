#include <stdio.h>
 
int getPivotElement(int *array, int left, int right){
   if (right < left) /* Array not rotated */  
       return -1;
    
   /* Only element in sub array */
   if (right == left) 
       return left;
  
   /* Find the mid element */
   int middle = (left + right)/2;
    
   /* Only the pivot element will be 
      more than it's next element */
   if (middle < right && array[middle] > array[middle + 1])
       return middle;
 
   if (middle > left && array[middle] < array[middle - 1])
       return middle-1;
     
   if (array[left] >= array[middle]){
      /* Pivot element is between left and mid index */
       return getPivotElement(array, left, middle-1);
   } else {
       /* Pivot element is between mid and right index */
       return getPivotElement(array, middle + 1, right);
   }
}
 
int main(){
    int array[11] = {16, 18, 22, 25, 1, 3, 5, 6, 7, 10, 14};
  
    printf("Pivot Element : %d \n", array[getPivotElement(array, 0, 10) + 1]);
 
    return 0;
}