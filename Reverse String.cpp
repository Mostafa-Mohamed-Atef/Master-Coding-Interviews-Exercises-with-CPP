#include <iostream>
#include <string>
using namespace std;

string reverse(string x) {
        string reversed = "";
        for (int i=x.length();i>=0;i-- ) {
            reversed += x[i];
        }
        return reversed;
}
int main()
{
    string x = "Hi My name is X";
    
    cout << reverse(x)<<endl;
    return 0;
}