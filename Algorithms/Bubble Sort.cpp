#include <iostream>
#include <vector>
using namespace std;

vector<int> bubbleSort(vector<int> arr) {
    for(int i = 0; i<arr.size()-1; i++) { //O(n^2)
        for (int j =0; j<arr.size()-i-1; j++) {
            if(arr[j]>arr[j+1]) {
                swap(arr[j],arr[j+1]);
            }
        }
    }
    return arr;
}

int main() {
    vector<int> arr = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};
    vector<int> result = bubbleSort(arr);


    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}