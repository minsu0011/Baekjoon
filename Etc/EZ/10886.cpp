#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector <int> research;
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	int t = 0;
	int cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t;
		research.push_back(t);
	}
	for (int i = 0; i < n; i++) {
		if (research[i] == 1)cnt++;
	}
	if (cnt > n / 2) cout << "Junhee is cute!";
	else cout << "Junhee is not cute!";
	return 0;
}