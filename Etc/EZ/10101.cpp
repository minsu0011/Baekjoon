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
	int ra, rb, rc;
	cin >> ra >> rb >> rc;
	if (ra == 60 && rb == 60 && rc == 60) cout << "Equilateral";
	else if (ra + rb + rc == 180) {
		if (ra == rb || ra == rc || rb == rc) cout << "Isosceles";
		else cout << "Scalene";
	}
	else cout << "Error";
	return 0;
}