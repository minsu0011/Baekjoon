#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;
int height[15];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int heightsum = 0;
	int rest = 0;
	int nota, notb;
	for (int i = 1; i <= 9; i++) {
		cin >> height[i];
		heightsum += height[i];
	}
	rest = heightsum - 100;
	sort(height + 1, height + 10);
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			if (i == j) continue;
			else if (height[i] + height[j] == rest) {
				nota = i;
				notb = j;
			}
		}
	}
	for (int i = 1; i <= 9; i++)
		if (i != nota && i != notb)
			cout << height[i] << '\n';
	return 0;
}