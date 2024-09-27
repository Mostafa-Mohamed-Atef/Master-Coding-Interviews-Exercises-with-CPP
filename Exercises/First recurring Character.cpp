#include <iostream>
#include <string>
#include <map>
using namespace std;
//o(n+m) my solution
int counter(int arr[]) {
    map<int,int> repeated;
    for (int i=0; i<10;i++) {
        if (repeated.count(arr[i])) {
            repeated[arr[i]] ++;
        }
        else {
            repeated[arr[i]] = 1;
        }
    }
    for (const auto& j : repeated) {
        if (j.second>1) {
            return j.first;
        }
    }
    return -1;
}
//O(n) andrei solution
int counter(int arr[]) {
    map<int, int> repeated;
    for (int i = 0; i<10; i++) {
        if (repeated.count(arr[i])) {
            return arr[i];
        }
        else {
            repeated[arr[i]] = 1;
        }
        
    }
    return -1;
}
int main()
{
    int arr[10] = {2,5,2,3,4,5,2,3,4,4};
    
    cout << counter(arr);
    return 0;
}
