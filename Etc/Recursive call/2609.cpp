#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector <int> research;
int gcm(int a, int b) {
	int t = 0;
	while (true) {
		t = a % b;
		if (t == 0) return b;
		a = b;
		b = t;
	}
}
int lcm(int a, int b) {
	return (a / gcm(a, b)) * b;
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n1, n2;
	cin >> n1 >> n2;
	cout << gcm(n1, n2) << "\n" << lcm(n1, n2);
	return 0;
}