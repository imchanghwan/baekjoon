#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int n;
queue<char> result;
stack<int> s;
queue<int> q;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		q.push(x);
	}
	int i = 1;
	for (int i = 1; i <= n; i++) {
		s.push(i);
		result.push('+');
		while (!s.empty() && !q.empty() && q.front() == s.top()) {
			q.pop();
			s.pop();
			result.push('-');
		}
	}

	if (!q.empty()) cout << "NO" << endl;
	else {
		while (!result.empty()) {
			cout << result.front() << '\n';
			result.pop();
		}
	}
};
