/*
Introduction
This blog will discuss the time complexity of Recursion and backtracking. Recursion and Backtracking based coding problems are widely asked in various coding contests and various interviews.

Recursion
The process in which a function calls itself directly or indirectly is known as Recursion, and the function which calls itself is known as a recursive function. You can learn more about recursion here. In function, there must be a base condition to terminate the recursive call of the function.

Must Read Recursion in Data Structure

Pseudo Code of Recursion
Let's write the pseudo code to find the Nth Fibonacci number using recursion to know how recursion works.
*/

int Fibonacci(int n){
    
    /*Base Condition*/
    if(n==1 or n==0) return 1;
    
    /*Recursive Call*/
    return Fibonacci(n-1) + Fibonacci(n-2);
}
/*
Explanation
For any integer ‘N’, the function calls itself two times i.e, for ‘N-1’ and ‘N-2’. In this way, the recursive call expands until (like a tree) the value of ‘N’ is greater than 1, which is also the base condition to terminate the recursive call. Below is the recursive tree for N = 4.

The time complexity of recursion
The time complexity of recursion depends on the number of times the function calls itself. If a function calls itself two times then its time complexity is O(2 ^ N). if it calls three times then its time complexity is O(3 ^ N) and so on.

Also check out - Rod Cutting Problem and Rabin Karp Algorithm

Backtracking
Backtracking is a technique used to solve the problems in which we need to build all the possible solutions and remove those solutions that fail to satisfy the problem's constraints at any point in time. You can learn more about backtracking here.

Application of Backtracking
The following types of problems can be solved using backtracking

All those problems where we need to find a feasible solution.
Optimization problems.
Problems in which we need to find all the possible solutions.
The time complexity of Backtracking
The time complexity of backtracking depends on the number of times the function calls itself.

For example, if the function calls itself two times, then its time complexity is O(2 ^ N), and if it calls three times, then O(3 ^ N) and so on. Hence the time complexity of backtracking can be defined as O(K ^ N), where ‘K’ is the number of times the function calls itself.

 

Also see, Morris Traversal for Inorder.

FAQs
What are Fibonacci Numbers?
In the Fibonacci number series, every number is the sum of the preceding two numbers. The first few Fibonacci numbers are 0,1,1,2,3,5,8….. .
 
How many times function Fibonacci() invoked in N = 4?
There is a total of 9 times the function Fibonacci() invoked as there are eight recursive calls.
 
How can we implement Backtracking? 
Backtracking can be implemented using Recursion. With the help of recursion, backtracking generates all the possible solutions of any problem.
 
Are recursion and backtracking different?
No, recursion is the process in which a function calls itself whereas backtracking is the technique that is implemented using recursion.
 
What is the base condition in Recursion?
Base condition is the condition where the recursive call terminated. For example, in the Fibonacci number, the base condition occurs when the value of ‘N’ is less than or equal to 1.


*/



