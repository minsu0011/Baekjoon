#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<algorithm>
using namespace std;
///////////////////////////////////////////
int n;
///////////////////////////////////////////
int pivo(int x) {
	if (x == 1 || x == 2) return 1;
	if (x == 0) return 0;
	return pivo(x - 1) + pivo(x - 2);
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	///////////////////////////////////////////
	cin >> n;
	cout << pivo(n);
	return 0;
}