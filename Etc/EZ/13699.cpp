#include<iostream>
using namespace std;
long long int t[40];
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	long long int tmp = 0;
	cin >> N;
	t[0] = 1;
	t[1] = 1;
	for (int n = 1; n <= N; n++) {
		for (int i = 0; i < n; i++)
			tmp += t[i] * t[n - i - 1];
		t[n] = tmp;
		tmp = 0;
	}
	cout << t[N];
	return 0;
}