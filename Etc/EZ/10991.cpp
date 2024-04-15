#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= n - i - 1; j++)
			cout << " ";
		for (int k = 1; k <= i; k++) cout << " *";
		cout << "\n";
	}
	for (int i = 1; i <= n; i++) {
		if (i != n) cout << "* ";
		else cout << "*";
	}
	return 0;
}