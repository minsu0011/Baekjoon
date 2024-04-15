#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector <int> vec;
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 0;
	int t1, t2;
	int c = 0;
	int arr[2];
	int cnt = 0;
	int tmp = 0;
	for (int i = 1; i <= 28; i++) {
		cin >> t;
		vec.push_back(t);
	}
	t = 0;

	for (int i = 1; i <= 30; i++) {
		for (int j = 0; j < 28; j++) {
			if (vec[j] == i)cnt++;
		}
		if (cnt == 0) {
			arr[t] = i;
			t++;
		}
		cnt = 0;
	}

	if (arr[0] > arr[1]) {
		tmp = arr[0];
		arr[0] = arr[1];
		arr[1] = tmp;
	}
	cout << arr[0] << "\n" << arr[1];
	return 0;
}