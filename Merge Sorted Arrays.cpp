#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeSortedArrays(const vector<int>& array1, const vector<int>& array2) {
    vector<int> mergedArray;  
    int i = 0, j = 0;  

    while (i < array1.size() && j < array2.size()) {
        if (array1[i] < array2[j]) {
            mergedArray.push_back(array1[i]);
            i++;
        } else {
            mergedArray.push_back(array2[j]);
            j++;
        }
    }


    while (i < array1.size()) {
        mergedArray.push_back(array1[i]);
        i++;
    }


    while (j < array2.size()) {
        mergedArray.push_back(array2[j]);
        j++;
    }

    return mergedArray;
}

int main() {
    vector<int> arr1 = {0, 3, 4, 31};
    vector<int> arr2 = {3, 4, 6, 30};

    vector<int> result = mergeSortedArrays(arr1, arr2);


    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
