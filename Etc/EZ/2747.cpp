#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int pivo[50];
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	pivo[1] = 1;
	for (int i = 1; i <= n - 1; i++) {
		pivo[i + 1] = pivo[i] + pivo[i - 1];
	}
	cout << pivo[n];
	return 0;
}