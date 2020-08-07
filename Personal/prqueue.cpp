// priority queue 컨테이너 연습

#include <iostream> 
#include <queue>
#include <vector>

using namespace std;

typedef struct _vec {
    int x;
    int y;
    int z;
}vec;

bool operator<(vec t, vec u) {
    return t.y < t.z;
}

int main() {    
    priority_queue<int, vec, greater<int> > a;

    for (int i=0; i<10; i++) {
        a.push(i);
    }

    while(!a.empty()) {
        cout << a.top() << " ";
        a.pop();
    }

    return 0;
}