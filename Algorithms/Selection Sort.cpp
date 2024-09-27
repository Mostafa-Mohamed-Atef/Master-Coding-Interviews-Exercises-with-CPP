#include <iostream>
#include <vector>
using namespace std;
vector<int> selectionSort(vector<int> arr) {
    for (int i = 0; i<arr.size(); i++) {
        int smallest = arr[i];   
        int smallestIndex = i;   
        for (int j=i+1; j<arr.size();j++) {
            if (arr[j] < arr[smallestIndex]) {
                smallestIndex = j; 
                smallest = arr[j];
            }
        }
        swap(arr[i], arr[smallestIndex]);
    }
    return arr;
}

int main() {
    vector<int> arr = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};
    vector<int> result = selectionSort(arr);


    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}