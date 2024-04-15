#include<stdio.h>
#include<iostream>
using namespace std;
int x[100003];
int xsum[100003];
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	long long int res = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> x[i];
	for (int i = 1; i <= n; i++) xsum[i] = xsum[i - 1] + x[i];
	for (int i = 1; i <= n - 1; i++)
		res += (xsum[n] - xsum[i]) * x[i];
	cout << res;
	return 0;
}