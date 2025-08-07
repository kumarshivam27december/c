#include <bits/stdc++.h>
using namespace std;
bool isKeyPresent(vector<int>& arr, int key) {
    	int i = 0;
    	int j = arr.size()-1;
        while(i<=j){
		int m =  i +(j-i)/2;
		if(arr[m]==key){
			return true;
		}

		else if(arr[m]>key){
			j = m-1;
		}else{
			i = m+1;
		}
	}
	return false;
}

int findKeyIndex(vector<int>& arr, int key) {
	int i = 0;
	int j = arr.size()-1;
	while(i<=j){
		int m =  i+ (j-i)/2;
		if(arr[m]==key){
			return m;
		}else if(arr[m]>key){
			
		}
	}
	return -1;
}

pair<int, int> findFirstAndLastPosition(vector<int>& arr, int key) {
    return {-1, -1};
}

int findPivotInRotatedArray(vector<int>& arr) {
    return -1;
}

int findPeakElement(vector<int>& arr) {
    return -1;
}

int searchInSortedRotatedArray(vector<int>& arr, int key) {
    return -1;
}

double medianOfTwoSortedArrays(vector<int>& a, vector<int>& b) {
    return -1.0;
}

int kokoEatingBananas(vector<int>& piles, int h) {
    return -1;
}

int paintersPartition(vector<int>& boards, int painters) {
    return -1;
}

int aggressiveCowsPlacement(vector<int>& stalls, int cows) {
    return -1;
}

int bookAllocationProblem(vector<int>& pages, int students) {
    return -1;
}

int integerSquareRoot(int n) {
    return -1;
}

pair<int, int> lowerAndUpperBound(vector<int>& arr, int key) {
    return {-1, -1};
}

void isKeyPresentInArray() {
    int n, key;
    cin >> n;
    vector<int> arr(n);
    for (int& x : arr) cin >> x;
    cin >> key;
    if (isKeyPresent(arr, key)) {
        cout << "Yes the key is present in the array\n";
    } else {
        cout << "No the key ain't in the array\n";
    }
}

void indexOfKeyInArray() {
    int n, key;
    cin >> n;
    vector<int> arr(n);
    for (int& x : arr) cin >> x;
    cin >> key;
    cout << "Index: " << findKeyIndex(arr, key) << endl;
}

void firstAndLastOccurrence() {
    int n, key;
    cin >> n;
    vector<int> arr(n);
    for (int& x : arr) cin >> x;
    cin >> key;
    auto [first, last] = findFirstAndLastPosition(arr, key);
    cout << "First: " << first << " Last: " << last << endl;
}

void findPivotInRotated() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& x : arr) cin >> x;
    cout << "Pivot Index: " << findPivotInRotatedArray(arr) << endl;
}

void peakElementInMountainArray() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& x : arr) cin >> x;
    cout << "Peak Index: " << findPeakElement(arr) << endl;
}

void searchInRotatedSortedArray() {
    int n, key;
    cin >> n;
    vector<int> arr(n);
    for (int& x : arr) cin >> x;
    cin >> key;
    cout << "Index: " << searchInSortedRotatedArray(arr, key) << endl;
}

void findMedianOfTwoSortedArrays() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    cin >> m;
    vector<int> b(m);
    for (int& x : b) cin >> x;
    cout << "Median: " << medianOfTwoSortedArrays(a, b) << endl;
}

void kokoBananaEatingSpeed() {
    int n, h;
    cin >> n;
    vector<int> piles(n);
    for (int& x : piles) cin >> x;
    cin >> h;
    cout << "Min Eating Speed: " << kokoEatingBananas(piles, h) << endl;
}

void paintersPartitionProblem() {
    int n, painters;
    cin >> n;
    vector<int> boards(n);
    for (int& x : boards) cin >> x;
    cin >> painters;
    cout << "Min Time: " << paintersPartition(boards, painters) << endl;
}

void aggressiveCowsProblem() {
    int n, cows;
    cin >> n;
    vector<int> stalls(n);
    for (int& x : stalls) cin >> x;
    cin >> cows;
    cout << "Max Min Distance: " << aggressiveCowsPlacement(stalls, cows) << endl;
}

void bookAllocation() {
    int n, students;
    cin >> n;
    vector<int> pages(n);
    for (int& x : pages) cin >> x;
    cin >> students;
    cout << "Min Max Pages: " << bookAllocationProblem(pages, students) << endl;
}

void squareRootBinarySearch() {
    int n;
    cin >> n;
    cout << "Square Root: " << integerSquareRoot(n) << endl;
}

void lowerUpperBoundConcept() {
    int n, key;
    cin >> n;
    vector<int> arr(n);
    for (int& x : arr) cin >> x;
    cin >> key;
    auto [lower, upper] = lowerAndUpperBound(arr, key);
    cout << "Lower Bound: " << lower << " Upper Bound: " << upper << endl;
}

int main() {
    isKeyPresentInArray();            // 1. Binary Search Present/Not
    indexOfKeyInArray();             // 2. Index of Key
    firstAndLastOccurrence();        // 3. First & Last Occurrence
    findPivotInRotated();            // 4. Pivot in Rotated Array
    peakElementInMountainArray();    // 5. Peak Element
    searchInRotatedSortedArray();    // 6. Search in Rotated Sorted
    findMedianOfTwoSortedArrays();   // 7. Median of Sorted Arrays
    kokoBananaEatingSpeed();         // 8. Koko Eating Bananas
    paintersPartitionProblem();      // 9. Painter's Partition
    aggressiveCowsProblem();         // 10. Aggressive Cows
    bookAllocation();                // 11. Book Allocation
    squareRootBinarySearch();        // 12. Square Root via Binary Search
    lowerUpperBoundConcept();        // 13. Lower & Upper Bound

    return 0;
}
