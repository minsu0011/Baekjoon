#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector <int> vec1;
vector <int> vec2;
vector <int> check;
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t1 = 0;
	int t2 = 0;
	int cnt = 0;
	int res = 0;
	for (int i = 1; i <= 10; i++) {
		cin >> t1;
		t2 = t1 % 42;
		vec1.push_back(t1);
		vec2.push_back(t2);
	}
	check.push_back(vec2[0]);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < check.size(); j++) {
			if (vec2[i] == check[j]) cnt++;
		}
		if (cnt == 0)check.push_back(vec2[i]);
		cnt = 0;
	}
	cout << check.size();
	return 0;
}