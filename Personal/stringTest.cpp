#include <iostream>
#include <string>

using namespace std;

int main() {
    string str = "0123456"; // 기본적인 생성자
    string::iterator iter1 = str.begin();
    string::iterator iter2 = str.end();
    
    iter1 += 1;
    iter2 -= 1;
    str.erase(iter1, iter2);
    cout << str;

    return 0;
}