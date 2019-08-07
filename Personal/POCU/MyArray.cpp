#include <iostream>
#include "MyArray.h"

using namespace std;

namespace samples{
    void MyArrayExample(){
        MyArray<int> scores;
        scores.Add(10);
        scores.Add(50);

        cout << "scores - size: " <<scores.GetSize() << endl;
    }
}