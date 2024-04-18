/*
STL Functions for Heap Operations
make_heap(): Converts given range to a heap.
push_heap(): Arrange the heap after insertion at the end.
pop_heap(): Moves the max element at the end for deletion.
sort_heap(): Sort the elements of the max_heap to ascending order.
is_heap(): Checks if the given range is max_heap.
is_heap_until(): Returns the largest sub-range that is max_heap.

*/


/*

// C++ code to demonstrate the working of
// make_heap(), front()
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Initializing a vector
    vector<int> v1 = { 20, 30, 40, 25, 15 };
 
    // Converting vector into a heap
    // using make_heap()
    make_heap(v1.begin(), v1.end());
 
    // Displaying the maximum element of heap
    // using front()
    cout << "The maximum element of heap is : ";
    cout << v1.front() << endl;
 
    return 0;
}


*/


/*

// C++ program to demonstrate the use of push_heap()
// function
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void print(vector<int>& vc)
{
	for (auto i : vc) {
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> vc{ 20, 30, 40, 10 };

	make_heap(vc.begin(), vc.end());
	cout << "Initial Heap: ";
	print(vc);

	vc.push_back(50);
	cout << "Heap just after push_back(): ";
	print(vc);
	push_heap(vc.begin(), vc.end());
	cout << "Heap after push_heap(): ";
	print(vc);

	return 0;
}


*/


/*

#include <bits/stdc++.h>
using namespace std;

void print(vector<int>& vc)
{
	for (auto i : vc) {
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	// initial vector
	vector<int> vc{ 40, 10, 20, 50, 30 };

	// making heap
	make_heap(vc.begin(), vc.end());
	cout << "Initial Heap: ";
	print(vc);

	// using pop_heap() function to move the largest element
	// to the end
	pop_heap(vc.begin(), vc.end());
	cout << "Heap after pop_heap(): ";
	print(vc);

	// actually removing the element from the heap using
	// pop_back()
	vc.pop_back();
	cout << "Heap after pop_back(): ";
	print(vc);

	return 0;
}




*/


/*

// C++ code to demonstrate the working of
// sort_heap()
#include <bits/stdc++.h>
using namespace std;
int main()
{

	// Initializing a vector
	vector<int> v1 = { 20, 30, 40, 25, 15 };

	// Converting vector into a heap
	// using make_heap()
	make_heap(v1.begin(), v1.end());

	// Displaying heap elements
	cout << "The heap elements are: ";
	for (int& x : v1)
		cout << x << " ";
	cout << endl;

	// sorting heap using sort_heap()
	sort_heap(v1.begin(), v1.end());

	// Displaying heap elements
	cout << "The heap elements after sorting are: ";
	for (int& x : v1)
		cout << x << " ";

	return 0;
}



*/


/*

std::is_heap(begin_iterator, end_iterator);

std::is_heap_until(begin_iterator, end_iterator);



*/


/*


// C++ code to demonstrate the working of
// is_heap() and is_heap_until()
#include <bits/stdc++.h>
using namespace std;
int main()
{

	// Initializing a vector
	vector<int> v1 = { 40, 30, 25, 35, 15 };

	// Declaring heap iterator
	vector<int>::iterator it1;

	// Checking if container is heap
	// using is_heap()
	is_heap(v1.begin(), v1.end())
		? cout << "The container is heap "
		: cout << "The container is not heap"; // ternary operator
	cout << endl;

	// using is_heap_until() to check position
	// till which container is heap
	auto it = is_heap_until(v1.begin(), v1.end());

	// Displaying heap range elements
	cout << "The heap elements in container are : ";
	for (it1 = v1.begin(); it1 != it; it1++)
		cout << *it1 << " ";

	return 0;
}



*/