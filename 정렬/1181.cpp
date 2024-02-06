#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
정렬함수 O(NlogN) 20000*log20000
unique O(N) 20000
O(N^2logN) 4*10^8*log20000 2초 이내
*/

int n;
string str;
vector<string> arr;

bool cmp(string &a, string &b) {
	if (a.length() == b.length()) {
		return a < b;
	}
	return a.length() < b.length();
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		arr.push_back(str);
	}

	sort(arr.begin(), arr.end(), cmp);
	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << endl;
	}

}
