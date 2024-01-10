#include <iostream>
#include <vector>

using namespace std;

/*
문제 풀이 아이디어
1초일때는 폭탄 위치는 그대로
시간이 짝수일 때는 모두 폭탄
3초후부터 폭탄이 터짐
2초전 폭탄 위치를 저장후
3초후 폭탄의 터진 위치를 저장을 반복

시간복잡도 O(N^3)
R*C*N 최대 2^3*10*6 = 800만 < 1억 1초도 안걸림
*/

int r, c, n;
vector<string> v; // 초기 폭탄 위치

/*
2초전의 폭탄이 있는 위치를 넣으면 3초후 폭탄이 터진 후 위치를 반환하는 함수
v는 2초전의 폭탄 위치
*/
vector<string> boom(vector<string> &v)
{
	// 모든 위치를 폭탄
	string str(c, 'O');
	vector<string> res(r, str);

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (v[i][j] == 'O') { // 해당 위치가 폭탄일 경우
				res[i][j] = '.'; // 폭탄이 있던 자리
				if (i - 1 >= 0) { // 폭탄이 있는 위치 y-1(위) 0이상이어야 함
					res[i - 1][j] = '.';
				}
				if (j - 1 >= 0) { // 폭탄이 있는 위치 x-1(좌) 0이상이어야 함
					res[i][j - 1] = '.';
				}
				if (i + 1 < r) { // 폭탄이 있는 위치 y+1(아래) r보다 작아 함
					res[i + 1][j] = '.';
				}
				if (j + 1 < c) { // 폭탄이 있는 위치 x+1(우) c보다 작아 함
					res[i][j + 1] = '.';
				}
			}
		}
	}
	return res;
}

int main()
{
	cin >> r >> c >> n;
	for (int i = 0; i < r; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}

	// 모든 칸이 폭탄
	string str(c, 'O');
	vector<string> res(r, str); // 2초후 폭탄 위치

	if (n == 1) res = v; // 1초일때는 초기 폭탄위치와 같음
	else if (n % 2 == 0) res = res; // 시간이 짝수일 때는 항상 모든칸이 폭탄
	else { // 3초이상 홀수만 폭탄이 터짐
		for (int i = 3; i <= n; i++) {
			if (i % 2 == 0) { // 현재 시간이 짝수라면 터져야되는 폭탄위치를 저장, 2초전의 폭탄 위치 저장
				v = res;
			}
			else { // 현재 시간이 홀수라면 2초전에 저장한 위치의 폭탄을 터뜨린 위치를 res에 저장
				res = boom(v);
			}
		}
	}

	for (int i = 0; i < r; i++) {
		cout << res[i] << endl;
	}
}
