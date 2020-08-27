/*
    라면공장
 */

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;

	priority_queue<int> supplyPQueue;

	int j=0;
	for (int i=0; i<k; i++) {
		// 공급 받는 일정일 때, queue에 저장한다.
		if (i == dates[j]) {
			supplyPQueue.push(supplies[j]);
			j += 1;
		}

		// 저장된 stock 이 i보다 작아진다면
		// queue에 저장했던 밀가루를 pop
		if (stock < i) {
			stock += supplyPQueue.top();
			supplyPQueue.pop();
			answer += 1;
		}
	}
	return answer;
}