#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
스스로 풀지못함..
정답 보면서 코드 이해는 했음
*/

vector<Answer> v;

int n; // 질문 수

int main()
{
	cin >> n;

	vector<bool> a(1000, true);
	for (int i = 123; i <= 999; i++) {
		string str = to_string(i);
		if (str[0] == str[1] || str[1] == str[2] || str[2] == str[0]) {
			a[i] = false;
		}

		if (str.find('0') != string::npos) {
			a[i] = false;
		}
	}

	for (int i = 0; i < n; i++) {
		string num;
		int strike, ball;
		cin >> num >> strike >> ball;

		for (int j = 123; j <= 987; j++) {
			string str = to_string(j);

			int strike_cnt = 0;
			int ball_cnt = 0;

			if (a[j]) {
				for (int x = 0; x < 3; x++) {
					for (int y = 0; y < 3; y++) {
						if (x == y && str[x] == num[y]) {
							strike_cnt++;
						}
						if (x != y && str[x] == num[y]) {
							ball_cnt++;
						}
					}
				}
				if (strike != strike_cnt || ball != ball_cnt) {
					a[j] = false;
				}
			}
		}

	}
	int res = 0;
	for (int i = 123; i <= 987; i++) {
		if (a[i])	res++;
	}
	cout << res << endl;
}
