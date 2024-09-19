#include <iostream>
using namespace std;

string reverseString(string x) {
    if (x.empty()) {
        return x;
    }
    return reverseString(x.substr(1)) + x[0];
}
int main() {
    cout<<reverseString("yoyo master")<<endl;
}