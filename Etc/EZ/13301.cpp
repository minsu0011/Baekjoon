#include<iostream>
using namespace std;
long long int pivo[85];
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	long long int res = 0;
	cin >> n;
	pivo[1] = 1;
	for (int i = 1; i <= n; i++) pivo[i + 1] = pivo[i] + pivo[i - 1];
	res = pivo[n + 1] * 2 + pivo[n] * 2;
	cout << res;
	return 0;
}