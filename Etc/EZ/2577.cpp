#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector <int> cnt;
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b, c;
	cin >> a >> b >> c;
	int mul = a * b * c;
	cnt.resize(12);
	for (int i = 1; i <= 100; i++) {
		cnt[mul % 10]++;
		mul /= 10;
		if (mul == 0)break;
	}
	for (int i = 0; i < 10; i++) cout << cnt[i] << "\n";
	return 0;
}