#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<algorithm>
using namespace std;
///////////////////////////////////////////
int T;
int n[11];
///////////////////////////////////////////
int f(int x) {
	if (x == 1) return 1;
	if (x == 2) return 2;
	if (x == 3) return 4;
	return f(x - 1) + f(x - 2) + f(x - 3);
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	///////////////////////////////////////////
	cin >> T;
	for (int t = 1; t <= T; t++)
		cin >> n[t];
	for (int t = 1; t <= T; t++) {
		cout << f(n[t]) << '\n';
	}
	return 0;
}