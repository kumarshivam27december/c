#include <iostream>
#include <algorithm>

// Function to find the frequency count of each element in the array
void findFrequency(int arr[], int n, int freq[], int count[]) {
    // Initialize the frequency and count arrays
    for (int i = 0; i < n; i++) {
        freq[i] = -1;
        count[i] = 1;
    }

    // Find the frequency count of each element
    for (int i = 0; i < n; i++) {
        int element = arr[i];
        bool isDuplicate = false;
        
        // Check if the element already exists in the frequency array
        for (int j = 0; j < n; j++) {
            if (element == freq[j]) {
                count[j]++;
                isDuplicate = true;
                break;
            }
        }

        // If the element does not exist in the frequency array, add it
        if (!isDuplicate) {
            for (int j = 0; j < n; j++) {
                if (freq[j] == -1) {
                    freq[j] = element;
                    break;
                }
            }
        }
    }
}

// Function to sort the elements according to their frequency
void sortElements(int freq[], int count[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (count[j] < count[j + 1]) {
                std::swap(count[j], count[j + 1]);
                std::swap(freq[j], freq[j + 1]);
            }
        }
    }
}

// Function to print the sorted elements according to their frequency
void printSortedElements(int freq[], int count[], int n) {
    std::cout << "Element  Frequency\n";
    for (int i = 0; i < n; i++) {
        if (freq[i] != -1) {
            std::cout << freq[i] << "        " << count[i] << "\n";
        }
    }
}

// Main function
int main() {
    int arr[] = { 2, 3, 1, 4, 2, 3, 1, 2, 3, 1, 5, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int freq[n];
    int count[n];

    findFrequency(arr, n, freq, count);
    sortElements(freq, count, n);
    printSortedElements(freq, count, n);

    return 0;
}

#include <iostream>

struct Element {
   int value;
   int frequency;
};

bool compareElements(const Element& a, const Element& b) {
   if (a.frequency == b.frequency) {
      return a.value < b.value;
   }
   return a.frequency > b.frequency;
}

void sortArrayByFrequency(int arr[], int size) {
   Element elements[size];
   int elementsCount = 0;

   for (int i = 0; i < size; i++) {
      bool elementExists = false;

      for (int j = 0; j < elementsCount; j++) {
         if (elements[j].value == arr[i]) {
            elements[j].frequency++;
            elementExists = true;
            break;
         }
      }

      if (!elementExists) {
         elements[elementsCount].value = arr[i];
         elements[elementsCount].frequency = 1;
         elementsCount++;
      }
   }

   for (int i = 0; i < elementsCount - 1; i++) {
      int maxIndex = i;
      for (int j = i + 1; j < elementsCount; j++) {
         if (compareElements(elements[j], elements[maxIndex])) {
            maxIndex = j;
         }
      }
      std::swap(elements[i], elements[maxIndex]);
   }
   
   int index = 0;
   for (int i = 0; i < elementsCount; i++) {
      for (int j = 0; j < elements[i].frequency; j++) {
         arr[index++] = elements[i].value;
      }
   }
}

int main() {
   int arr[] = {2, 3, 3, 1, 4, 2, 2, 4, 4, 5};
   int size = sizeof(arr) / sizeof(arr[0]);

   sortArrayByFrequency(arr, size);
   
   std::cout << "Sorted array: ";
   for (int i = 0; i < size; i++) {
      std::cout << arr[i] << " ";
   }
   std::cout << std::endl;
   
   return 0;
}
