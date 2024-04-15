#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
long long arr[10010];
long long ans = 0;
long long n = 0;
long long m = 0;
long long tp = 0;
long long ps(long long front, long long rear) {
	long long mid = 0;
	long long tmp = 0;
	while (front <= rear) {
		mid = (front + rear) / 2;
		tmp = 0;
		for (int i = 1; i <= n; i++) {
			if (mid > arr[i]) tmp += arr[i];
			else tmp += mid;
		}
		if (tmp > m) {
			rear = mid - 1;
		}
		else {
			if (ans < mid) ans = mid;
			front = mid + 1;
		}
	}
	return ans;
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 0;
	cin >> n;
	for (long long i = 1; i <= n; i++)cin >> arr[i];
	cin >> m;
	sort(arr + 1, arr + n + 1);
	cout << ps(1, arr[n]);
	return 0;
}