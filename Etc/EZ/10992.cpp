#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << "*";
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (i != n)cout << " ";
		else cout << "*";
	}
	cout << "\n";
	for (int i = 2; i <= n - 1; i++) {
		for (int j = 1; j <= n - i; j++) cout << " ";
		cout << "*";
		for (int j = n - i + 2; j <= n + i - 2; j++) cout << " ";
		cout << "*\n";
	}
	for (int i = 1; i <= 2 * n - 1; i++) cout << "*";
	return 0;
}