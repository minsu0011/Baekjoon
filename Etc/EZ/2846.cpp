#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector <int> road;
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	int res = 0;
	int start = 0, end = 0;
	int ans = 0;
	int t = 0;
	cin >> n;
	road.resize(n);
	for (int i = 0; i < n; i++)
		cin >> road[i];

	while (t < n - 2) {
		for (int j = t; j < n - 1; j++) {
			if (road[j] < road[j + 1]) {
				ans++;
				start = road[t];
				end = road[j + 1];
				if (j == n - 2) {
					if (end - start > res)res = end - start;
					t = n;
				}
			}
			else {
				if (end - start > res) res = end - start;
				end = 0;
				start = 0;
				t = j + 1;
				j = n;
			}
		}
	}
	if (ans == 0) {
		cout << "0";
		return 0;
	}
	cout << res;
	return 0;
}