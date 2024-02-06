#include <iostream>

using namespace std;

/*
4중 반복문 시간복잡도 N^2*M^2 = 50^4 = 6,250,000
최종 W,B 두개 반복 2*6,250,000 = 12500000
시간복잡도 O(N^2*M^2)
*/

int n, m; // 8~50
char chess[50][50];

int repaint(int I_start, int J_start, char w) {
	int cnt = 0;
	int I_end = I_start + 8;
	int J_end = J_start + 8;
	for (int i = I_start; i < I_end; i++) {
		for (int j = J_start; j < J_end; j++) {
			if (chess[i][j] != w) {
				cnt++;
			}
			w == 'B' ? w = 'W' : w = 'B';
		}
		w == 'B' ? w = 'W' : w = 'B';
	}

	return cnt;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> chess[i][j];
		}
	}

	int min = 32;
	for (int w = 0; w < 2; w++) {
		char word = 'W';
		if (w == 1) word = 'B';
		for (int i = 0; n - i >= 8; i++) {
			for (int j = 0; m - j >= 8; j++) {
				int re = repaint(i, j, word);
				if (re < min) min = re;
			}
		}
	}
	cout << min << '\n';
}
