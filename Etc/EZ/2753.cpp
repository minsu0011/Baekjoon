#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int year;
	cin >> year;
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)cout << "1";
	else cout << "0";
	return 0;
}