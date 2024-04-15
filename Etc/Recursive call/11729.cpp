#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
///////////////////////////////////////////
int N, K;
///////////////////////////////////////////
void hanoi_count(int n) {
	if (n == 1) {
		K++;
		return;
	}
	hanoi_count(n - 1);
	K++;
	hanoi_count(n - 1);
}
void hanoi_sequence(int n, int from, int to, int by) {
	if (n == 1) {
		cout << from << " " << to << '\n';
		return;
	}
	hanoi_sequence(n - 1, from, by, to);
	cout << from << " " << to << '\n';
	hanoi_sequence(n - 1, by, to, from);
}
////////////////////////////////////////////
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	///////////////////////////////////////////
	cin >> N;
	hanoi_count(N);
	cout << K << '\n';
	hanoi_sequence(N, 1, 3, 2);
	return 0;
}