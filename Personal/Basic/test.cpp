#include <iostream>
#include <string>

using namespace std;

int main() {
    string str = "ABDFcde";
    for (char c : str) {
        if ( 'A' <= c && c <= 'Z') {
            c = c - 'A' + 'a';
        }
    }
    cout << str;
    return 0;
}