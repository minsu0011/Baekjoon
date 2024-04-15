#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
int arr[10010];
int n, k;
int ans = 0;
long long ps(long long front, long long rear) {
	long long mid, piece;
	while (front <= rear) {
		mid = (front + rear) / 2;
		piece = 0;
		for (int i = 1; i <= k; i++) piece += (arr[i] / mid);
		if (piece >= n) {
			if (ans < mid) ans = mid;
			front = mid + 1;
		}
		else rear = mid - 1;
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int length = 0;
	cin >> k;
	cin >> n;
	for (int i = 1; i <= k; i++)
		cin >> arr[i];
	cout << ps(1, 2147483647);
}