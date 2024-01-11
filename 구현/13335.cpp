#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/*
문제 풀이 아이디어

단위시간마다 트럭을 하나씩 다리위로 추가
추가했을때 다리의 최대하중보다 작거나 같아야됨
단위시간이 다리길이를 만큼 증가하면 트럭을 하나씩 제거

시간 복잡도 O(N^2)
최대로 오래걸리는 시간은 트럭 수 * 다리 길이 + 1 이다.
n*w+1 = 1000*100+1 =10^5+1
*/


int n, w, L; // 트럭의 수, 다리의 길이, 다리의 최대하중
vector<int> truck;

int main()
{
	cin >> n >> w >> L;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		truck.push_back(x);
	}
	vector<pair<int,int>> bridge; // 무게, 시간
	int sum = 0; // 다리위의 트럭 무게 합
	int time = 0; // 단위시간
	while (!(truck.empty() && bridge.empty()))
	{
		time++;
		// 단위시간이 다리길이 만큼 증가하면 다리위의 요소 제거
		if (!bridge.empty() && time - bridge.front().second == w) {
			sum -= bridge.front().first;
			bridge.erase(bridge.begin()); // 다리위에서 트럭 제거
		}
		// 트럭을 올리는 작업이 먼저가 아닌 이유는 트럭이 먼저 다리에서 내려와야 뒤에 있는 트럭이 다리위로 올라 올 수 있기 때문이다.

		//현재 다리의 최대하중 = 다리의 최대하중 - 다리위에 있는 트럭들의 합
		int CL = L - sum;
		// 트럭의 무게가 다리 최대하중보다 작거나 같아야 한다.
		if (!truck.empty() && truck.front() <= CL) {
			bridge.push_back(make_pair(truck.front(), time)); // 다리위에 트럭 올리기
			sum += truck.front();
			truck.erase(truck.begin()); // 대기하는 트럭 요소 제거
		}
	}

	cout << time << endl;
}
