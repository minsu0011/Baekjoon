#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
int a[100010] = { 0, };
int binary(int front, int rear, int value);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	int tmp;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		cout << binary(0, n - 1, tmp) << '\n';
	}
	return 0;
}
int binary(int front, int rear, int value) {
	int mid = (front + rear) / 2;
	if (front > rear) return 0;
	if (value > a[mid]) return binary(mid + 1, rear, value);
	else if (value < a[mid]) return binary(front, mid - 1, value);
	else return 1;
}