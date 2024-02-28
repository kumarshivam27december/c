/*
Memory used by a program is sometimes as important as running time,
 particularly in constrained environments such as mobile devices. 
For example if we need to create an array of size n, it will require O(n)
 space. If we need a two-dimensional array of size n x n , it will require O(n2). 
Stack space in recursive calls counts too as extra space required by a program. 
For example : 
 


int sum(int n)
{
   if (n <= 0)
       return 0;
   return n + sum(n-1);
}
In the above example function, each call adds a new level to the stack. 
 

     Sum(5)
    ->sum(4)
            ->sum(3)
            ->sum(2)
                ->sum(1)
                       ->sum(0)
Each of these calls is added to the call stack and takes up actual memory. 
So code like this would take O(n) time and O(n) auxiliary space. 
However, just because you have n calls total doesn’t mean it takes O(n) space.
 Consider the below functions, which adds adjacent elements between 0 and n : 
Example: 
 


// A non-recursive code that makes n calls
// but takes O(1) extra space.
int pairSumSequence(int n)
{
    int sum = 0;
    for (int i=0; i<n; i++)
        sum += pairSum(i, i+1);
    return sum;
}
 
int pairSum(int a, int b)
{
    return a + b ;
}
In this example there will be roughly O(n) calls to pairSum. However, 
those calls do not exist simultaneously on the call stack, so we need only O(1) space. 

*/