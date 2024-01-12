#include <iostream>
#include <vector>

using namespace std;

/*
문제 풀이 아이디어

트럭의 무게를 저장하는 배열을 다리 뒤에 대기하는 트럭 줄이라 생각하고
매 시간마다 가장 첫줄의 트럭이 다리위로 올라갈 수 있으면 다리위에 있는 트럭의 무게와 올라간 시간을 저장하는 배열에 넣고 대기 줄에서 제거 후
다리위의 트럭 무게 합에 더해 다리의 최대하중을 업데이트 한다.
트럭이 다리를 건너는 시간이 되면 다리위의 트럭 무게 합에서 빼고 다리 다리위의 트럭 배열에서 제거 한다.
트럭이 다리에서 내려오는 과정을 올라가는 과정보다 먼저 해주어야 한다. 트럭이 다리에서 먼저 내려와야 최대하중이 업데이트되어 동시에 뒤에 트럭이 다리위로 올라갈 수 있다.

시간 복잡도 O(N^2)
최악의 경우는 n과 w가 최대일 때 이다. 
왜냐하면 다리의 최대하중이 가장 작은 10이라 가정하고 
모든 트럭의 무게가 5보다 커서 동시에 다리위에 올라올 수 있는 트럭 수가 한개일 때 
트럭은 한대씩 다리를 다 건널 때 까지 다음 트럭은 다리위로 못 올라가기 때문이다. 
그러면 가장 오래걸리는 시간은 n * w + 1 이 되므로 시간 복잡도는 O(N^2) 된다.
n*w+1 = 10^5 + 1 < 10^8 이라 1초미만이다.
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
	
	vector<pair<int,int>> bridge; // 다리에 올라간 트럭의 무게, 올라갔을 때 시간
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
